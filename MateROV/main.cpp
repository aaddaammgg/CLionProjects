#include <boost/asio.hpp>

#include <SDL.h>
#include <iostream>
#include <array>
#include <iomanip>
#include <SDL_ttf.h>
#include <sstream>
#include <chrono>


#include "Visual.h"
#include "Controller.h"

using namespace boost;

#pragma pack(push, 1)
struct ROVPacket {
    uint8_t start = 0xAA;
    float tleft = 0;
    float tright = 0;
    float tup_left = 0;
    float tup_right = 0;
    float claw = 0;
    float rotate = 0;
    // float checksum = 0;
    uint8_t end = 0x55;
};
#pragma pack(pop)


asio::serial_port *serial = nullptr;

// ls /dev/tty.*

// std::string serialPortPath = "/dev/ttys006";
std::string serialPortPath = "/dev/tty.usbmodem11501";
int baudRate = 115200;

bool tryConnect(asio::io_context &io) {
    try {
        if (serial) {
            delete serial;
            serial = nullptr;
        }

        serial = new asio::serial_port(io, serialPortPath);
        serial->set_option(asio::serial_port_base::baud_rate(baudRate));
        std::cerr << "[Serial] Connected to " << serialPortPath << "\n";
        return true;
    } catch (...) {
        std::cerr << "[Serial] Connection failed\n";
        if (serial) {
            delete serial;
            serial = nullptr;
        }
        return false;
    }
}


// uint8_t computeChecksum(const ROVPacket &p) {
//     const uint8_t *data = reinterpret_cast<const uint8_t *>(&p);
//     uint8_t sum = 0;
//
//     for (size_t i = 1; i < sizeof(ROVPacket) - 2; ++i) {
//         sum ^= data[i];
//     }
//     return sum;
// }

static const char *DUALSENSE_MAPPING =
        "050000004c0500000ce6000001000000,"
        "DualSense Wireless Controller,"
        "a:b2,b:b1,x:b0,y:b3,"
        "back:b8,start:b9,guide:b12,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,"
        "leftshoulder:b4,rightshoulder:b5,leftstick:b10,rightstick:b11,"
        "lefttrigger:a2,righttrigger:a5,leftx:a0,lefty:a1,rightx:a3,righty:a4,"
        "touchpad:b13,misc1:b14,"
        "platform:Mac OS X";

bool readLineWithTimeout(asio::io_context &io, asio::serial_port &port, std::string &line, int timeout_ms = 50) {
    asio::streambuf buf;
    boost::system::error_code ec;
    bool done = false;

    asio::steady_timer timer(io);
    timer.expires_after(std::chrono::milliseconds(timeout_ms));

    timer.async_wait([&](const boost::system::error_code &) {
        if (!done) {
            port.cancel();  // force read to end
        }
    });

    asio::async_read_until(port, buf, '\n', [&](const boost::system::error_code &error, std::size_t) {
        ec = error;
        done = true;
        timer.cancel();
    });

    io.run();
    io.restart();

    if (!ec && done) {
        std::istream is(&buf);
        std::getline(is, line);
        return true;
    }

    return false;
}

int main() {
    static ROVPacket lastSentPacket{};

    asio::io_context io;
    // asio::serial_port *serial = nullptr;

    // try {
    //     serial = new asio::serial_port(io, "/dev/ttys003"); // ← adjust for your device
    //     serial->set_option(asio::serial_port_base::baud_rate(115200));
    //     std::cerr << "[Serial] Connected to Arduino.\n";
    // } catch (...) {
    //     std::cerr << "[Serial] No device found. Entering test mode.\n";
    // }

    auto lastReconnectAttempt = std::chrono::steady_clock::now() - std::chrono::seconds(5);

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    TTF_Init();

    TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/Menlo.ttc", 20); // MacOS Specific Font
    if (!font) {
        std::cerr << "Font load failed\n";
        return 1;
    }

    TTF_Font *promptFont = TTF_OpenFont("Resources/Fonts/promptfont.ttf", 28); // https://shinmera.github.io/promptfont/
    if (!promptFont) {
        std::cerr << "Prompt Font load failed\n";
        // return 1;
    }

    SDL_GameControllerAddMapping(DUALSENSE_MAPPING);

    Controller ctrl;

    ctrl.setKMFallback(true);

    if (!ctrl.Init()) {
        std::cerr << "No controller\n";
    }

    std::string title = "SFD ";

    if (ctrl.hasController()) {
        title += "DualSense Mode";
    } else {
        title += "Keyboard/Mouse Mode";
    }

    SDL_Window *win = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 735, 500, 0);
    SDL_Renderer *rd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    auto last = std::chrono::high_resolution_clock::now();
    float fps = 0.0f;

    bool quit = false;
    SDL_Event e;

    ROVPacket pkt;

    // Persistent state for rotation of claw
    int rotateHeldFrames = 0;
    bool rotateLastFrameUp = false;
    bool rotateLastFrameDown = false;


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            ctrl.PollEvent(&e);

            if (e.type == SDL_QUIT) {
                quit = true;
                std::cerr << "Quitting\n";
            }
        }

        auto now = std::chrono::steady_clock::now();
        if (!serial || !serial->is_open()) {
            if (now - lastReconnectAttempt >= std::chrono::seconds(2)) {
                lastReconnectAttempt = now;
                tryConnect(io);
            }
        }


        ctrl.Update();

        // draw frame
        SDL_SetRenderDrawColor(rd, 15, 15, 15, 255);
        SDL_RenderClear(rd);

        std::ostringstream os;
        os << "Gyro (pitch,yaw,roll): "
                << std::showpos << std::fixed << std::setprecision(2)
                << ctrl.GyroPitch() << " " << ctrl.GyroYaw() << " " << ctrl.GyroRoll() << "\n";
        os << "Accel (x,y,z): "
                << ctrl.AccelX() << " " << ctrl.AccelY() << " " << ctrl.AccelZ();

        Visual::DrawText(rd, 10, 400, os.str(), {255, 255, 255, 255}, font);

        std::string c = "↠";

        Visual::DrawText(rd, 0, 0, c, {255, 255, 255, 255}, promptFont);

        // frame timing
        auto now_fps = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now_fps - last;
        last = now_fps;

        // Use exponential moving average to smooth FPS (0.05 is a smoothing factor)
        fps = fps * 0.95f + (1.0f / diff.count()) * 0.05f;

        Visual::DrawText(rd, 20, 20, std::to_string(fps), {255, 255, 255, 255}, font);

        if (ctrl.L2() > 0.1 || ctrl.R2() > 0.1) {
            ctrl.Rumble(ctrl.L2() * 0xFFFF,
                        ctrl.R2() * 0xFFFF,
                        100);
        }

        // D-pad
        const std::array<int, 4> dpad = {
            ctrl.DpadDown(),
            ctrl.DpadRight(),
            ctrl.DpadUp(),
            ctrl.DpadLeft()
        };

        Visual::DrawCompassButtons(rd, 50, 160, 35, 35,
                                   {100, 100, 100, 255},
                                   {200, 200, 40, 255},
                                   dpad);

        // Face buttons (South, East, North, West)
        const std::array<int, 4> face = {
            ctrl.Cross(),
            ctrl.Circle(),
            ctrl.Triangle(),
            ctrl.Square()
        };

        Visual::DrawCompassButtons(rd, 650, 160, 35, 35,
                                   {100, 100, 100, 255},
                                   {40, 200, 40, 255},
                                   face);

        // Sticks

        Visual::DrawJoystick(rd, 225, 320, 40,
                             {120, 180, 220, 255},
                             {40, 200, 40, 255},
                             ctrl.LeftX(),
                             ctrl.LeftY(),
                             ctrl.L3());

        Visual::DrawJoystick(rd, 525, 320, 40,
                             {120, 180, 220, 255},
                             {40, 200, 40, 255},
                             ctrl.RightX(),
                             ctrl.RightY(),
                             ctrl.R3());

        // Triggers

        Visual::DrawTrigger(rd, 210 - 20 - 5, 70, 30, 75,
                            {120, 180, 220, 255},
                            {255, 0, 0, 255},
                            ctrl.L2());

        Visual::DrawTrigger(rd, 530 + 5, 70, 30, 75,
                            {120, 180, 220, 255},
                            {255, 0, 0, 255},
                            ctrl.R2());

        // Regular buttons

        Visual::DrawButton(rd, 220 - 20 - 5, 10, 20, 20,
                           ctrl.Share(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        Visual::DrawButton(rd, 530 + 5, 10, 20, 20,
                           ctrl.Options(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        Visual::DrawButton(rd, 210 - 20 - 5, 40, 30, 20,
                           ctrl.L1(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        Visual::DrawButton(rd, 530 + 5, 40, 30, 20,
                           ctrl.R1(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        Visual::DrawButton(rd, 735 / 2 - 15 / 2, 210, 30, 15,
                           ctrl.PSButton(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        Visual::DrawButton(rd, 735 / 2 - 15 / 2, 230, 30, 15,
                           ctrl.MicrophoneButton(),
                           {100, 100, 100, 255},
                           {255, 0, 0, 255});

        // Touchpad
        Visual::DrawTouchpad(rd, ctrl.Raw(), 220, 10, 310, 195,
                             {100, 100, 100, 255},
                             {255, 0, 0, 255},
                             {250, 50, 250, 255});


        // Normalize joystick: up = +1, down = -1
        float x = ctrl.LeftX();        // left = -1, right = 1
        float y = ctrl.LeftY();       // forward = +1, backward = -1

        // Tank-drive mapping
        float raw_left  = y + x;
        float raw_right = y - x;

        // Clamp to [-1, 1]
        pkt.tleft  = std::max(-1.0f, std::min(1.0f, raw_left));
        pkt.tright = std::max(-1.0f, std::min(1.0f, raw_right));

        // Right joystick for up/down
        float z = ctrl.RightY();  // up = -1, down = 1
        z = std::max(-1.0f, std::min(1.0f, z));

        pkt.tup_left  = z;
        pkt.tup_right = z;

        float openRate = std::pow(ctrl.L2(), 1.5f);
        float closeRate = std::pow(ctrl.R2(), 1.5f);

        float clawSensitivity = 0.01f;   // how fast it changes per frame

        pkt.claw += (openRate - closeRate) * clawSensitivity;

        // Clamp to [0, 1]
        pkt.claw = std::max(0.0f, std::min(1.0f, pkt.claw));

        bool up = ctrl.DpadUp();
        bool down = ctrl.DpadDown();

        bool freshUp   = up   && !rotateLastFrameUp;
        bool freshDown = down && !rotateLastFrameDown;

        if (up || down) {
            if ((up && rotateLastFrameUp) || (down && rotateLastFrameDown)) {
                rotateHeldFrames++;
            } else {
                rotateHeldFrames = 1;
            }
        } else {
            rotateHeldFrames = 0;
        }

        rotateLastFrameUp = up;
        rotateLastFrameDown = down;

        // Default to no change
        float delta = 0.0f;

        if (freshUp) {
            delta = +0.01f;
        } else if (freshDown) {
            delta = -0.01f;
        } else if (rotateHeldFrames > 10) {
            float heldSpeed = std::min(0.01f, float(rotateHeldFrames - 10) * 0.0001f);
            delta = (up ? +heldSpeed : 0.0f) - (down ? +heldSpeed : 0.0f);
        }

        pkt.rotate += delta;
        pkt.rotate = std::clamp(pkt.rotate, 0.0f, 1.0f);

        // pkt.checksum = computeChecksum(pkt);

        bool changed = std::memcmp(&pkt, &lastSentPacket, sizeof(ROVPacket)) != 0;

        if (changed) {
            try {
                if (serial && serial->is_open()) {
                    asio::write(*serial, asio::buffer(&pkt, sizeof(pkt)));

                    // std::string line;
                    // if (readLineWithTimeout(io, *serial, line)) {
                    //     std::cout << "[ARDUINO] " << line << "\n";
                    // }
                } else {
                    // std::cout << "[TEST-MODE] "
                    //           << "tleft=" << pkt.tleft << " "
                    //           << "tright=" << pkt.tright << " "
                    //           << "tup_left=" << static_cast<int>(pkt.tup_left) << " "
                    //           << "tup_right=" << static_cast<int>(pkt.tup_right) << " "
                    //           << "claw=" << static_cast<int>(pkt.claw) << " "
                    //           << "rotate=" << static_cast<int>(pkt.rotate)
                    //           << "\n";
                }

                lastSentPacket = pkt;
            } catch (const system::system_error &e) {
                std::cerr << "[Serial ERROR] " << e.what() << "\n";
                serial->close();
                delete serial;
                serial = nullptr;
            }
        }

        std::ostringstream output;
        output << "[OUTPUT] "
                << std::setprecision(3) << std::fixed << std::showpos
                << "tleft=" << pkt.tleft << " "
                << "tright=" << pkt.tright << " "
                << "tup_left=" << pkt.tup_left << "\n"
                << "tup_right=" << pkt.tup_right << " "
                << "claw=" << pkt.claw << " "
                << "rotate=" << pkt.rotate << " ";
                // << "checksum=" << static_cast<int>(pkt.checksum);


        Visual::DrawText(rd, 10, 450, output.str(), {255, 255, 255, 255}, font);

        SDL_RenderPresent(rd);
        SDL_Delay(15);
    }

    if (serial) {
        if (serial->is_open()) {
            serial->close();
        }
        delete serial;
    }


    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyRenderer(rd);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
