//
// Created by Adam G. on 4/26/25.
//

#include "Visual.h"

namespace Visual {
    void DrawText(SDL_Renderer *rd, int x, int y, const std::string &text, const SDL_Color &color, TTF_Font *font,
                  int wrapLength) {
        SDL_Surface *surf = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), color, wrapLength);

        if (!surf) {
            return;
        }

        int w, h;

        SDL_Texture *tex = SDL_CreateTextureFromSurface(rd, surf);
        w = surf->w;
        h = surf->h;

        SDL_FreeSurface(surf);

        SDL_Rect dst{x, y, w, h};
        SDL_RenderCopy(rd, tex, nullptr, &dst);
        SDL_DestroyTexture(tex);
    }

    void DrawButton(SDL_Renderer *rd, int x, int y, int w, int h, bool pressed, SDL_Color baseColor,
                    SDL_Color pressColor) {
        SDL_Rect base = {x, y, w, h};

        SDL_Color color = pressed ? pressColor : baseColor;

        SDL_SetRenderDrawColor(rd, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(rd, &base);
    }

    void DrawCompassButtons(SDL_Renderer *rd, int x, int y, int w, int h, SDL_Color baseColor, SDL_Color pressColor,
                            std::array<int, 4> face) {
        for (int i = 0; i < 4; ++i) {
            SDL_Rect r = {x, y, w, h};

            if (i == 0) r.y += 45;
            if (i == 1) r.x += 45;
            if (i == 2) r.y -= 45;
            if (i == 3) r.x -= 45;

            DrawButton(rd, r.x, r.y, w, h, face[i], baseColor, pressColor);
        }
    }

    void DrawJoystick(SDL_Renderer *rd, int x, int y, int radius, SDL_Color baseColor, SDL_Color pressColor, float ax,
                      float ay, int pressed) {
        SDL_Rect border{x - radius, y - radius, radius * 2, radius * 2};
        SDL_SetRenderDrawColor(rd, 200, 200, 200, 80);
        SDL_RenderDrawRect(rd, &border);

        int halfRadius = radius / 2;

        int sx = radius * ax;
        int sy = radius * ay;

        DrawButton(rd, x + sx - halfRadius / 2, y + sy - halfRadius / 2, halfRadius, halfRadius, pressed, baseColor,
                   pressColor);
    }

    void DrawTrigger(SDL_Renderer *rd, int x, int y, int w, int h, SDL_Color baseColor, SDL_Color pressColor,
                     float a) {
        SDL_Rect border{x, y, w, h};
        SDL_SetRenderDrawColor(rd, 200, 200, 200, 80);
        SDL_RenderDrawRect(rd, &border);

        bool pressed = a >= .98;
        const int sy = y + h - w - float(a) * float(h - w);

        DrawButton(rd, x, sy, w, w, pressed, baseColor, pressColor);
    }

    void DrawTouchpad(SDL_Renderer *rd, SDL_GameController *gc, int x, int y, int w, int h, SDL_Color baseColor,
                      SDL_Color pressColor, SDL_Color mouseColor) {
        Uint8 down;
        float tx, ty, pressure;
        int pressed = SDL_GameControllerGetButton(gc, SDL_CONTROLLER_BUTTON_TOUCHPAD);
        SDL_Color color = pressed ? pressColor : baseColor;

        SDL_Rect border{x, y, w, h};
        SDL_SetRenderDrawColor(rd, color.r, color.g, color.b, color.a);
        SDL_RenderDrawRect(rd, &border);

        int fingers = SDL_GameControllerGetNumTouchpadFingers(gc, 0);

        for (int i = 0; i < fingers; i++) {
            if (SDL_GameControllerGetTouchpadFinger(gc, 0, i, &down, &tx, &ty, &pressure) == 0 && down) {
                SDL_Rect dot{x + int(tx * (w - 10)), y + int(ty * (h - 10)), 10, 10};
                SDL_SetRenderDrawColor(rd, mouseColor.r, mouseColor.g, mouseColor.b, mouseColor.a);
                SDL_RenderFillRect(rd, &dot);
            }
        }
    }
}
