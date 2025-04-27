//
// Created by Adam G. on 4/27/25.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL.h>
#include <array>
#include <string>
#include <iostream>


class Controller {
public:
    Controller();
    ~Controller();

    bool Init();             // must call once after SDL_Init
    void Update();           // call every frame

    // Buttons
    bool Cross() const;
    bool Circle() const;
    bool Square() const;
    bool Triangle() const;
    bool L1() const;
    bool R1() const;
    bool L3() const;
    bool R3() const;
    bool Share() const;
    bool Options() const;
    bool PSButton() const;
    bool MicrophoneButton() const;
    bool DpadUp() const;
    bool DpadDown() const;
    bool DpadLeft() const;
    bool DpadRight() const;

    // Sticks
    float LeftX() const;
    float LeftY() const;
    float RightX() const;
    float RightY() const;

    // Triggers
    float L2() const;
    float R2() const;

    // Sensors
    float GyroPitch() const;   // rotation x
    float GyroYaw() const;     // rotation y
    float GyroRoll() const;    // rotation z

    float AccelX() const;
    float AccelY() const;
    float AccelZ() const;

    void SetLED(Uint8 r, Uint8 g, Uint8 b);

    // Rumble
    void Rumble(Uint16 lowFreq, Uint16 highFreq, Uint32 durationMs);

    // Raw access
    SDL_GameController* Raw();

private:
    SDL_GameController* gc = nullptr;
    std::array<float, 3> gyro{};
    std::array<float, 3> accel{};
};

#endif //CONTROLLER_H
