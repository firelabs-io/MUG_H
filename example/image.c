#include <SDL2/SDL.h>
#include "mug/mug.h"
#include <stdio.h>

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }

    SDL_Window *win = NewWin("Mug!", 0, 0, 800, 600);
    SDL_Renderer *ren = NewRen(win);

    Mug_Imagedata img = MakeImg(1, 1, -1);

    int data[1][1][3] = {
    { { 255, 255, 255 } }
    };    


    LoadImg(&img, data);

    SDL_Event e;
    int running = 1;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            } 
        }
        SetBack(ren, 0, 0, 0);
        RenderImg(ren, img, 5, 5);
        Release(ren);
    }

    FreeImg(&img);
    EndwRen(win, ren);
    EndNo(0);
    return 0;
}

