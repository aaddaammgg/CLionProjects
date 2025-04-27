#include <SDL.h>
#include <iostream>
#include <array>
#include <iomanip>
#include <SDL_ttf.h>
#include <sstream>

#include "Visual.h"
#include "Controller.h"

static const char *DUALSENSE_MAPPING =
        "050000004c0500000ce6000001000000,"
        "DualSense Wireless Controller,"
        "a:b2,b:b1,x:b0,y:b3,"
        "back:b8,start:b9,guide:b12,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,"
        "leftshoulder:b4,rightshoulder:b5,leftstick:b10,rightstick:b11,"
        "lefttrigger:a2,righttrigger:a5,leftx:a0,lefty:a1,rightx:a3,righty:a4,"
        "touchpad:b13,misc1:b14,"
        "platform:Mac OS X";

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);
    TTF_Init();

    TTF_Font *font = TTF_OpenFont("/System/Library/Fonts/Menlo.ttc", 20); // MacOS Specific Font
    if (!font) {
        std::cerr << "Font load failed\n";
        return 1;
    }

    SDL_GameControllerAddMapping(DUALSENSE_MAPPING);

    SDL_Window *win = SDL_CreateWindow("SDL DualSense", 100, 100, 735, 500, 0);
    SDL_Renderer *rd = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    Controller ctrl;

    if (!ctrl.Init()) {
        std::cerr << "No controller\n";

        return 1;
    }

    auto last = std::chrono::high_resolution_clock::now();
    float fps = 0.0f;

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
                std::cerr << "Quitting\n";
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

        Visual::DrawText(rd, 10, 450, os.str(), {255, 255, 255, 255}, font);

        // frame timing
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now - last;
        last = now;

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

        SDL_RenderPresent(rd);
        SDL_Delay(15);
    }

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyRenderer(rd);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
