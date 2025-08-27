#include <SDL2/SDL.h>
#include "../mug.h"
#include <string.h>

int t = 255;

void Test(SDL_Renderer *ren, Mug_Imagedata* img,char* msg, int x, int y){
    int char_A[5][5][3] = {{{0,0,0},{0,0,0},{t,t,t},{0,0,0},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{t,t,t},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},};
    int char_SP[5][5][3] = {{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}},};
    int char_M[5][5][3] = {{{t,t,t},{t,t,t},{0,0,0},{t,t,t},{t,t,t}},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t}},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t}},{{t,t,t},{0,0,0},{0,0,0},{0,0,0},{t,t,t}},{{t,t,t},{0,0,0},{0,0,0},{0,0,0},{t,t,t}},};
    int char_U[5][5][3] = {{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{0,0,0}},{{0,0,0},{t,t,t},{t,t,t},{t,t,t},{0,0,0}},};
    int char_G[5][5][3] = {{{0,0,0},{t,t,t},{t,t,t},{t,t,t},{t,t,t}},{{0,0,0},{t,t,t},{0,0,0},{0,0,0},{0,0,0}},{{0,0,0},{t,t,t},{0,0,0},{t,t,t},{t,t,t}},{{0,0,0},{t,t,t},{0,0,0},{0,0,0},{t,t,t}},{{0,0,0},{t,t,t},{t,t,t},{t,t,t},{t,t,t}},};
    int char_MUG[5][5][3] = {{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{0,0,0}},{{t,t,t},{0,0,0},{t,t,t},{t,t,t},{t,t,t}},{{t,t,t},{0,0,0},{t,t,t},{0,0,0},{t,t,t}},{{t,t,t},{0,0,0},{t,t,t},{t,t,t},{t,t,t}},{{t,t,t},{t,t,t},{t,t,t},{0,0,0},{0,0,0}},};
    for (int i = 0; i < strlen(msg); i++){
        if (msg[i] == 'A') {
            LoadImg(img, char_A);
            RenderImg(ren, *img, x, y);
            x += 5;
        }else if(msg[i] == 'M'){
            LoadImg(img, char_M);
            RenderImg(ren, *img, x, y);
            x += 6;
        }else if(msg[i] == 'U'){
            LoadImg(img, char_U);
            RenderImg(ren, *img, x, y);
            x += 5;
        }else if(msg[i] == 'G'){
            LoadImg(img, char_G);
            RenderImg(ren, *img, x, y);
            x += 5;
        }else if(msg[i] == 1){
            x += 6;
            LoadImg(img, char_MUG);
            RenderImg(ren, *img, x, y);
            x += 6;
        } else {
            LoadImg(img, char_SP);
            RenderImg(ren, *img, x, y);
            x += 5;
        }
    }
}

int main(int argc, char* argv[]){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        return 1;
    }

    SDL_Window *win = NewWin("Mug!", 0, 0, 800, 600);
    SDL_Renderer *ren = NewRen(win);

    Mug_Imagedata img = MakeImg(5, 5, -1);
  
    char* test = "MUG\1";

    SDL_Event e;
    int running = 1;
    int y = 0;

    while (running) {
        if (y > 700){
            y = 0;
        }
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            } 
        }

        SetBack(ren, 0, 0, 0);
        Test(ren, &img, test, 100, y);
        y += 1;
        Release(ren);
    }

    FreeImg(&img);
    EndwRen(win, ren);
    EndNo(0);
    return 0;
}

