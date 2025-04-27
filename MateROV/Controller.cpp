//
// Created by Adam G. on 4/27/25.
//

#include "Controller.h"

Controller::Controller() = default;

Controller::~Controller() {
    if (!gc) {
        return;
    }

    SDL_GameControllerClose(gc);
}

bool Controller::Init() {
    for (int i = 0; i < SDL_NumJoysticks(); ++i) {
        if (SDL_IsGameController(i)) {
            gc = SDL_GameControllerOpen(i);
            break;
        }
    }

    if (!gc) {
        return false; // No Controller found
    }

    // Enable motion sensors
    SDL_GameControllerSetSensorEnabled(gc, SDL_SENSOR_GYRO, SDL_TRUE);
    SDL_GameControllerSetSensorEnabled(gc, SDL_SENSOR_ACCEL, SDL_TRUE);

    return true;
}

void Controller::Update() {
    if (!gc) {
        return;
    }

    SDL_GameControllerGetSensorData(gc, SDL_SENSOR_GYRO, gyro.data(), 3);
    SDL_GameControllerGetSensorData(gc, SDL_SENSOR_ACCEL, accel.data(), 3);
}

// --------- Buttons ---------
bool Controller::Cross() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_A); }
bool Controller::Circle() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_B); }
bool Controller::Square() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_X); }
bool Controller::Triangle() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_Y); }
bool Controller::L1() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_LEFTSHOULDER); }
bool Controller::R1() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER); }
bool Controller::L3() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_LEFTSTICK); }
bool Controller::R3() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_RIGHTSTICK); }
bool Controller::Share() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_BACK); }
bool Controller::Options() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_START); }
bool Controller::PSButton() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_GUIDE); }
bool Controller::MicrophoneButton() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_MISC1); }
bool Controller::DpadUp() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_UP); }
bool Controller::DpadDown() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_DOWN); }
bool Controller::DpadLeft() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_LEFT); }
bool Controller::DpadRight() const { return SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_DPAD_RIGHT); }

// --------- Sticks ---------
float Controller::LeftX() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTX) / 32767.0f; }
float Controller::LeftY() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_LEFTY) / 32767.0f; }
float Controller::RightX() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTX) / 32767.0f; }
float Controller::RightY() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_RIGHTY) / 32767.0f; }

// --------- Triggers ---------
float Controller::L2() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERLEFT) / 32767.0f; }
float Controller::R2() const { return SDL_GameControllerGetAxis(gc, SDL_CONTROLLER_AXIS_TRIGGERRIGHT) / 32767.0f; }

// --------- Sensors ---------
float Controller::GyroPitch() const { return gyro[0]; }
float Controller::GyroYaw() const { return gyro[1]; }
float Controller::GyroRoll() const { return gyro[2]; }

float Controller::AccelX() const { return accel[0]; }
float Controller::AccelY() const { return accel[1]; }
float Controller::AccelZ() const { return accel[2]; }

void Controller::SetLED(Uint8 r, Uint8 g, Uint8 b) {
    if (!gc) {
        return;
    }

    SDL_GameControllerSetLED(gc, r, g, b);
}

// --------- Rumble ---------
void Controller::Rumble(Uint16 lowFreq, Uint16 highFreq, Uint32 durationMs) {
    if (!gc) {
        return;
    }

    SDL_GameControllerRumble(gc, lowFreq, highFreq, durationMs);
}

// --------- Raw ---------
SDL_GameController *Controller::Raw() {
    return gc;
}
