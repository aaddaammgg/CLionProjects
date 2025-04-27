#include <SDL.h>
#include <iostream>
#include <array>
#include <iomanip>
#include <SDL_ttf.h>
#include <sstream>

#include "Visual.h"

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

    SDL_GameController *gc = nullptr;
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
        if (SDL_IsGameController(i)) {
            gc = SDL_GameControllerOpen(i);
            break;
        }
    }

    if (!gc) {
        std::cerr << "No controller\n";
        return 1;
    }

    // Enable gyro/accel
    SDL_GameControllerSetSensorEnabled(gc, SDL_SENSOR_GYRO, SDL_TRUE);
    SDL_GameControllerSetSensorEnabled(gc, SDL_SENSOR_ACCEL, SDL_TRUE);

    float gyro[3] = {};
    float accel[3] = {};

    auto last = std::chrono::high_resolution_clock::now();
    float fps = 0.0f;

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // draw frame
        SDL_SetRenderDrawColor(rd, 15, 15, 15, 255);
        SDL_RenderClear(rd);

        SDL_GameControllerGetSensorData(gc, SDL_SENSOR_GYRO, gyro, 3);
        SDL_GameControllerGetSensorData(gc, SDL_SENSOR_ACCEL, accel, 3);

        std::ostringstream os;
        os << "Gyro (pitch,yaw,roll): "
                << std::fixed << std::setprecision(2)
                << gyro[0] << " " << gyro[1] << " " << gyro[2] << "\n";
        os << "Accel (x,y,z): "
                << accel[0] << " " << accel[1] << " " << accel[2];

        Visual::DrawText(rd, 10, 450, os.str(), {255, 255, 255, 255}, font);

        // frame timing
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now - last;
        last = now;

        // Use exponential moving average to smooth FPS (0.05 is a smoothing factor)
        fps = fps * 0.95f + (1.0f / diff.count()) * 0.05f;

        Visual::DrawText(rd, 20, 20, std::to_string(fps), {255, 255, 255, 255}, font);

        // D-pad
        const std::array<int, 4> dpad = {
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_UP),
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_RIGHT),
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_DOWN),
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_LEFT)
        };

        Visual::DrawCompass(rd, 50, 160, 35, 35,
                            {100, 100, 100, 255},
                            {200, 200, 40, 255},
                            dpad);

        // Face buttons (South, East, North, West)
        const std::array<int, 4> face = {
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_A), // Cross
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_B), // Circle
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_Y), // Triangle
            SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_X) // Square
        };

        Visual::DrawCompass(rd, 650, 160, 35, 35,
                            {100, 100, 100, 255},
                            {40, 200, 40, 255},
                            face);

        // Sticks

        Visual::DrawStick(rd, 225, 320, 40,
                          {120, 180, 220, 255},
                          {40, 200, 40, 255},
                          SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTX),
                          SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTY),
                          SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_LEFTSTICK));

        Visual::DrawStick(rd, 525, 320, 40,
                          {120, 180, 220, 255},
                          {255, 0, 0, 255},
                          SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTX),
                          SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTY),
                          SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_RIGHTSTICK));

        // Triggers

        Visual::DrawTrigger(rd, 210 - 20 - 5, 70, 30, 75,
                            {120, 180, 220, 255},
                            {255, 0, 0, 255},
                            SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERLEFT));

        Visual::DrawTrigger(rd, 530 + 5, 70, 30, 75,
                    {120, 180, 220, 255},
                    {255, 0, 0, 255},
                    SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERRIGHT));

        // Shoulders (this function should just be buttons)
        auto drawButton = [&](int cx, int cy, int cw, int ch, int pressed) {
            SDL_Rect knob{cx, cy, cw, ch};
            SDL_SetRenderDrawColor(rd, pressed ? 255 : 100, pressed ? 0 : 100, pressed ? 0 : 100, 255);
            SDL_RenderFillRect(rd, &knob);
        };

        drawButton(220 - 20 - 5, 10, 20, 20, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_BACK));
        drawButton(530 + 5, 10, 20, 20, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_START));

        drawButton(210 - 20 - 5, 40, 30, 20, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_LEFTSHOULDER));
        drawButton(530 + 5, 40, 30, 20, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER));

        drawButton(735 / 2 - 15 / 2, 210, 30, 15, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_GUIDE));
        drawButton(735 / 2 - 15 / 2, 230, 30, 15, SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_MISC1));

        // Touchpad
        Uint8 down;
        float tx, ty, pressure;
        int pressed = SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_TOUCHPAD);

        int x = 220, y = 10;

        // int(400 + (tx - 0.5f) * 300) - 5, int(100 + (ty - 0.5f) * 180) - 5

        SDL_Rect border{x, y, 310, 195};
        SDL_SetRenderDrawColor(rd, pressed ? 255 : 200, pressed ? 0 : 200, pressed ? 0 : 200, 80);
        SDL_RenderDrawRect(rd, &border);

        if (SDL_GameControllerGetTouchpadFinger(gc, 0, 0, &down, &tx, &ty, &pressure) == 0 && down) {
            SDL_Rect dot{int(375 + (tx - 0.5f) * 300) - 5, int(100 + (ty - 0.5f) * 180), 10, 10};
            SDL_SetRenderDrawColor(rd, 250, 50, 250, 255);
            SDL_RenderFillRect(rd, &dot);
        }

        SDL_RenderPresent(rd);
        SDL_Delay(15);
    }

    TTF_CloseFont(font);
    TTF_Quit();

    SDL_GameControllerClose(gc);
    SDL_DestroyRenderer(rd);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
