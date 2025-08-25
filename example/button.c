#include <SDL2/SDL.h>
#include "../mug.h"
#include <stdio.h>

void onRectClick(Mug_Area* area){
    SDL_Log("Rectangle clicked!");
    area->rect.flag = 1;
}

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }

    SDL_Window *win = NewWin("Mug!", 0, 0, 800, 600);
    SDL_Renderer *ren = NewRen(win);

    Mug_Rect r = MakeRect(0, 300, 300, 0, 0, 0, 600, 600, 255, 255, 255);

    int coords[8] = {r.x[0], r.x[1], r.x[2], r.x[3], r.y[0], r.y[1], r.y[2], r.y[3]};
    int color[3] = {r.color[0], r.color[1], r.color[2]};
    Mug_Area area = MakeArea(MUG_RECT, coords, color);

    Mug_TouchArea list[] = {
        MakeTouch(&area, MUG_RECT, onRectClick)
    };

    SDL_Event e;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                HandleClick(list, 1, e.button.x, e.button.y);
            }
        }
        SetBack(ren, 0, 0, 0);
        DrawRect(ren, area.rect);  // <--- use the rect inside area
        Release(ren);
    }


    EndwRen(win, ren);
    EndNo(0);
    return 0;
}

