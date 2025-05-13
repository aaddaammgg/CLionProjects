#include <boost/asio.hpp>
#include <SDL.h>
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <iostream>
#include <chrono>
#include "Visual.h"
#include "Controller.h"
// #include "CameraManager.h"

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
    uint8_t end = 0x55;
};
#pragma pack(pop)

asio::serial_port *serial = nullptr;

// ls /dev/tty.*

std::string serialPortPath = "/dev/ttys007";
// std::string serialPortPath = "/dev/tty.usbmodem11301";
const int baudRate = 115200;

bool tryConnect(asio::io_context &io) {
    try {
        delete serial;

        serial = new asio::serial_port(io, serialPortPath);
        serial->set_option(asio::serial_port_base::baud_rate(baudRate));
        std::cerr << "[Serial] Connected to " << serialPortPath << "\n";

        return true;
    } catch (...) {
        std::cerr << "[Serial] Connection failed\n";

        delete serial;
        serial = nullptr;

        return false;
    }
}

unsigned int packetsSent = 0;

void RenderDockSpace(float fps) {
    ImGuiDockNodeFlags dockspaceFlags = ImGuiDockNodeFlags_None;

    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImGui::SetNextWindowPos(viewport->WorkPos);
    ImGui::SetNextWindowSize(viewport->WorkSize);
    ImGui::SetNextWindowViewport(viewport->ID);

    ImGuiWindowFlags windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));



    ImGui::Begin("DockSpace", nullptr, windowFlags);
    ImGui::PopStyleVar(3);

    ImGuiID dockspaceID = ImGui::GetID("MainDockSpace");
    ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f), dockspaceFlags);

    if (ImGui::BeginMenuBar()) {
        ImGui::Text("FPS: %.1f", fps);
        ImGui::Separator();
        ImGui::Text("Packets Sent: %d", packetsSent);

        // if (ImGui::BeginMenu("Cameras")) {
        //     const std::vector<std::string>& cams = camera1.listAvailableCameras();
        //
        //     for (int i = 0; i < static_cast<int>(cams.size()); ++i) {
        //         std::string label = "Open " + cams[i] + " in slot 0";
        //         if (ImGui::MenuItem(label.c_str())) {
        //             camera1.requestCamera(0, i);
        //         }
        //
        //         label = "Open " + cams[i] + " in slot 1";
        //         if (ImGui::MenuItem(label.c_str())) {
        //             camera1.requestCamera(1, i);
        //         }
        //     }
        //
        //     ImGui::EndMenu();
        // }

        ImGui::EndMenuBar();
    }

    ImGui::End();
}

struct PacketCalib {
    float min = -1.0f;
    float max = 1.0f;

    float apply(float value) const {
        return std::clamp(value, min, max);
    }
};

struct CalibConfig {
    PacketCalib tleft, tright, tup_left, tup_right, claw, rotate;
} calib;


int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1");
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"); // 0=nearest, 1=linear, 2=best (if supported)


    SDL_Window* window = SDL_CreateWindow("MateROV", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    ImFontConfig font_cfg;
    font_cfg.OversampleH = 4;
    font_cfg.OversampleV = 4;
    font_cfg.PixelSnapH = false;

    io.Fonts->AddFontFromFileTTF("/System/Library/Fonts/Menlo.ttc", 18.0f, &font_cfg);

    ImGui::StyleColorsDark();

    ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer2_Init(renderer);

    ImGui::GetStyle().AntiAliasedLines = true;
    ImGui::GetStyle().AntiAliasedFill  = true;

    Controller ctrl;
    ctrl.setKMFallback(true);
    ctrl.Init();

    asio::io_context io_context;
    tryConnect(io_context);

    bool quit = false;
    SDL_Event e;

    ROVPacket pkt;
    ROVPacket lastSentPacket{};
    auto lastReconnectAttempt = std::chrono::steady_clock::now() - std::chrono::seconds(5);

    int rotateHeldFrames = 0;
    bool rotateLastFrameUp = false;
    bool rotateLastFrameDown = false;

    // CameraManager camera1(renderer);
    // camera1.populateCameraList();
    // camera1.requestCamera(0, 0); // auto-connect first camera to slot 0
    // camera1.requestCamera(1, 1); // auto-connect second camera to slot 1
    //
    //
    // int selectedCamIndex = -1;
    // bool cameraOpened = false;


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            ImGui_ImplSDL2_ProcessEvent(&e);
            ctrl.PollEvent(&e);

            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        // {
        //     ImGui::Begin("Dual Camera Viewer");
        //
        //     const std::vector<std::string>& cams = camera1.listAvailableCameras();
        //     static int selectedCamIndex[2] = {-1, -1};
        //
        //     if (!cams.empty()) {
        //         std::vector<const char*> items;
        //         for (const auto& s : cams) {
        //             items.push_back(s.c_str());
        //         }
        //
        //         for (int i = 0; i < 2; ++i) {
        //             ImGui::PushID(i);
        //             if (selectedCamIndex[i] == -1) selectedCamIndex[i] = i;
        //             if (ImGui::Combo("Camera Slot", &selectedCamIndex[i], items.data(), static_cast<int>(items.size()))) {
        //                 camera1.requestCamera(i, selectedCamIndex[i]);
        //             }
        //             ImGui::PopID();
        //         }
        //
        //         // Render both textures side by side
        //         ImGui::Separator();
        //         ImVec2 avail = ImGui::GetContentRegionAvail();
        //         float width = (avail.x - 10.0f) / 2.0f;
        //
        //         for (int i = 0; i < 2; ++i) {
        //             camera1.updateFrame(i);
        //             SDL_Texture* tex = camera1.getTexture(i);
        //             if (tex) {
        //                 int texW = 0, texH = 0;
        //                 SDL_QueryTexture(tex, nullptr, nullptr, &texW, &texH);
        //                 float aspect = (float)texH / texW;
        //                 ImGui::Image((ImTextureID)(intptr_t)tex, ImVec2(width, width * aspect));
        //             } else {
        //                 ImGui::TextColored(ImVec4(1, 0, 0, 1), "Camera %d not available.", i);
        //             }
        //
        //             if (i == 0) {
        //                 ImGui::SameLine();
        //             }
        //         }
        //     }
        //
        //     ImGui::End();
        // }



        {
            float fps = ImGui::GetIO().Framerate;
            RenderDockSpace(fps);
        }

        {
            ImGui::Begin("ROV Packet Stats");
            ImGui::Text("Left Thruster: %+.2f", pkt.tleft);
            ImGui::Text("Right Thruster: %+.2f", pkt.tright);
            ImGui::Text("Up Thruster Left: %+.2f", pkt.tup_left);
            ImGui::Text("Up Thruster Right: %+.2f", pkt.tup_right);
            ImGui::Text("Claw: %+.2f", pkt.claw);
            ImGui::Text("Rotate: %+.2f", pkt.rotate);
            ImGui::End();
        }

        {
            ImGui::Begin("Sensor Stats");
            ImGui::Text("Gyro (pitch, yaw, roll): %+.2f, %+.2f, %+.2f", ctrl.GyroPitch(), ctrl.GyroYaw(), ctrl.GyroRoll());
            ImGui::Text("Accel (x, y, z): %+.2f, %+.2f, %+.2f", ctrl.AccelX(), ctrl.AccelY(), ctrl.AccelZ());
            ImGui::End();
        }

        auto now = std::chrono::steady_clock::now();
        if (!serial || !serial->is_open()) {
            if (now - lastReconnectAttempt >= std::chrono::seconds(2)) {
                lastReconnectAttempt = now;
                tryConnect(io_context);
            }
        }

        ctrl.Update();

        float x = ctrl.LeftX();
        float y = ctrl.LeftY();
        float raw_left = y + x;
        float raw_right = y - x;

        pkt.tleft = std::clamp(raw_left, -1.0f, 1.0f);
        pkt.tright = std::clamp(raw_right, -1.0f, 1.0f);

        float z = std::clamp(ctrl.RightY(), -1.0f, 1.0f);
        pkt.tup_left = pkt.tup_right = z;

        float openRate = std::pow(ctrl.L2(), 1.5f);
        float closeRate = std::pow(ctrl.R2(), 1.5f);
        pkt.claw += (openRate - closeRate) * 0.01f;
        pkt.claw = std::clamp(pkt.claw, 0.0f, 1.0f);

        bool up = ctrl.DpadUp();
        bool down = ctrl.DpadDown();
        bool freshUp = up && !rotateLastFrameUp;
        bool freshDown = down && !rotateLastFrameDown;

        if (up || down) {
            rotateHeldFrames = (rotateLastFrameUp == up && rotateLastFrameDown == down) ? rotateHeldFrames + 1 : 1;
        } else {
            rotateHeldFrames = 0;
        }
        rotateLastFrameUp = up;
        rotateLastFrameDown = down;

        float delta = 0.0f;

        if (freshUp) {
            delta = 0.01f;
        } else if (freshDown) {
            delta = -0.01f;
        } else if (rotateHeldFrames > 10) {
            float heldSpeed = std::min(0.01f, float(rotateHeldFrames - 10) * 0.0001f);
            delta = (up ? +heldSpeed : 0.0f) - (down ? +heldSpeed : 0.0f);
        }
        // pkt.rotate = std::clamp(pkt.rotate + delta, 0.0f, 1.0f);

        // should change this later on
        pkt.tleft       = calib.tleft.apply(raw_left);
        pkt.tright      = calib.tright.apply(raw_right);
        pkt.tup_left    = calib.tup_left.apply(z);
        pkt.tup_right   = calib.tup_right.apply(z);
        pkt.claw        = calib.claw.apply(pkt.claw);
        pkt.rotate      = calib.rotate.apply(std::clamp(pkt.rotate + delta, 0.0f, 1.0f));


        if (std::memcmp(&pkt, &lastSentPacket, sizeof(ROVPacket)) != 0) {
            try {
                if (serial && serial->is_open()) {
                    asio::write(*serial, asio::buffer(&pkt, sizeof(pkt)));
                    packetsSent++;
                }
                lastSentPacket = pkt;
            } catch (...) {
                delete serial;
                serial = nullptr;
            }
        }

        if (ctrl.L2() > 0.1 || ctrl.R2() > 0.1) {
            ctrl.Rumble(ctrl.L2() * 0xFFFF,
                        ctrl.R2() * 0xFFFF,
                        100);
        }

        {
            ImGui::Begin("Calibration");

            auto sliderGroup = [](const char* label, PacketCalib& calib, float minLim, float maxLim) {
                ImGui::Text("%s", label);
                ImGui::SliderFloat((std::string(label) + " Min").c_str(), &calib.min, minLim, maxLim);
                ImGui::SliderFloat((std::string(label) + " Max").c_str(), &calib.max, minLim, maxLim);
            };

            sliderGroup("TLeft", calib.tleft, -1.0f, 1.0f);
            sliderGroup("TRight", calib.tright, -1.0f, 1.0f);
            sliderGroup("TUp Left", calib.tup_left, -1.0f, 1.0f);
            sliderGroup("TUp Right", calib.tup_right, -1.0f, 1.0f);
            sliderGroup("Claw", calib.claw, 0.0f, 1.0f);
            sliderGroup("Rotate", calib.rotate, 0.0f, 1.0f);

            ImGui::End();

        }

        Visual::DrawImGuiController(ctrl);

        ImGui::Render();
        SDL_SetRenderDrawColor(renderer, 15, 15, 15, 255);
        SDL_RenderClear(renderer);
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(15);
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    if (serial && serial->is_open()) serial->close();
    delete serial;
    return 0;
}
