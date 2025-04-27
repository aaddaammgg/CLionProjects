//
// Created by Adam G. on 4/26/25.
//

#include "Visual.h"

namespace Visual {
    void DrawText(SDL_Renderer *rd,
                  int x,
                  int y,
                  const std::string &text,
                  const SDL_Color &color,
                  TTF_Font *font,
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

    void DrawCompass(SDL_Renderer *rd, int x, int y, int w, int h, SDL_Color baseColor, SDL_Color pressColor,
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

    void DrawStick(SDL_Renderer *rd, int x, int y, int radius, SDL_Color baseColor, SDL_Color pressColor, Sint16 ax,
                   Sint16 ay, int pressed) {
        SDL_Rect border{x - radius, y - radius, radius * 2, radius * 2};
        SDL_SetRenderDrawColor(rd, 200, 200, 200, 80);
        SDL_RenderDrawRect(rd, &border);

        const int sx = x + ax / 800;
        const int sy = y + ay / 800;

        DrawButton(rd, sx - radius / 4, sy - radius / 4, radius / 2, radius / 2, pressed, baseColor, pressColor);
    }

    void DrawTrigger(SDL_Renderer *rd, int x, int y, int w, int h, SDL_Color baseColor, SDL_Color pressColor,
                     Sint16 a) {
        SDL_Rect border{x, y, w, h};
        SDL_SetRenderDrawColor(rd, 200, 200, 200, 80);
        SDL_RenderDrawRect(rd, &border);

        bool pressed = a >= (INT_FAST16_MAX - 100);
        const int sy = y + h - w - (float(a) / INT_FAST16_MAX) * float(h - w);

        DrawButton(rd, x, sy, w, w, pressed, baseColor, pressColor);
    }
}
