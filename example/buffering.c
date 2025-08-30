#include <SDL2/SDL.h>
#include "../mug.h"

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }

    SDL_Window *win = NewWin("Mug!", 0, 0, 800, 600);
    SDL_Renderer *ren = NewRen(win);
    int t = 255;
    int test[9][9][3] = {{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t},},};
    Mug_Imagedata img = MakeImg(9, 9, -1);
    LoadImg(&img, test);
 
    SDL_Event e;
    int running = 1;
    SetBack(ren, 0, 0, 0);
    int x = 0;
    int y = 0;
    int buffered = 0;
    while (running) {
        if (x > 800){x = 0; y += 10;}
        if (y > 600){y = 0; x = 0; buffered = 1;}
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            } 
        }
        //SetBack(ren, 0, 0, 0);
        RenderImg(ren, img, x, y);
        x += 10;
        if(buffered){
            Release(ren);
            buffered = 0;
        }
    }

    FreeImg(&img);
    EndwRen(win, ren);
    EndNo(0);
    return 0;
}

