//
// Created by Adam G. on 4/26/25.
//

#ifndef VISUAL_H
#define VISUAL_H

#include <string>
#include <array>
#include <SDL.h>
#include <SDL_ttf.h>

namespace Visual {
    void DrawText(SDL_Renderer *rd,
                  int x,
                  int y,
                  const std::string &text,
                  const SDL_Color &color,
                  TTF_Font *font,
                  int wrapLength = 0);

    void DrawButton(SDL_Renderer *rd,
                    int x,
                    int y,
                    int w,
                    int h,
                    bool pressed,
                    SDL_Color baseColor,
                    SDL_Color pressColor);

    void DrawCompassButtons(SDL_Renderer *rd,
                            int x,
                            int y,
                            int w,
                            int h,
                            SDL_Color baseColor,
                            SDL_Color pressColor,
                            std::array<int, 4> face);

    void DrawJoystick(SDL_Renderer *rd,
                      int x,
                      int y,
                      int radius,
                      SDL_Color baseColor,
                      SDL_Color pressColor,
                      Sint16 ax,
                      Sint16 ay,
                      int pressed);

    void DrawTrigger(SDL_Renderer *rd,
                     int x,
                     int y,
                     int w,
                     int h,
                     SDL_Color baseColor,
                     SDL_Color pressColor,
                     Sint16 a);

    void DrawTouchpad(SDL_Renderer *rd,
                      SDL_GameController *gc,
                      int x,
                      int y,
                      int w,
                      int h,
                      SDL_Color baseColor,
                      SDL_Color pressColor,
                      SDL_Color mouseColor
    );
}


#endif //VISUAL_H
