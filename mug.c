#include <SDL2/SDL.h>
#include <stdlib.h>
#include "mug.h"

void EndNo(int ret){SDL_Quit();exit(ret);}
void EndWin(SDL_Window* win){SDL_DestroyWindow(win);}
void EndRen(SDL_Renderer* ren){SDL_DestroyRenderer(ren);}
void EndwRen(SDL_Window* win, SDL_Renderer* ren){EndWin(win); EndRen(ren);}

Mug_Point MakePoint(int x, int y,/*int t*/ int r, int g, int b){
    Mug_Point p;
    p.x = x;
    p.y = y;
    //p.thi = thick;
    p.color[0] = r; p.color[1] = g; p.color[2] = b;
    return p;
}

Mug_Trig MakeTringle(int x1, int x2, int x3, int y1, int y2, int y3, int r, int g, int b){
    Mug_Trig t;
    t.x[0] = x1; t.y[0] = y1;
    t.x[1] = x2; t.y[1] = y2;
    t.x[2] = x3; t.y[2] = y3;
    t.color[0] = r; t.color[1] = g; t.color[2] = b;
    return t;
}

Mug_Line MakeLine(int x1, int y1, int x2, int y2, int r, int g, int b){
    Mug_Line l;
    l.x[0] = x1; l.y[0] = y1;
    l.x[1] = x2; l.y[1] = y2;
    l.color[0] = r; l.color[1] = g; l.color[2] = b;
    return l;
}

SDL_Window* NewWin(const char* title, int x, int y, int h, int w){
    SDL_Window* win = SDL_CreateWindow(title, x, y, h, w, 0);
    if (!win){EndNo(1);}
    return win;
}
SDL_Renderer* NewRen(SDL_Window* w){
    SDL_Renderer* ren = SDL_CreateRenderer(w, -1, 0);
    if(!ren){EndWin(w); EndNo(1);}
    return ren;
}
void SetBack(SDL_Renderer* ren, int r, int g, int b){
    SDL_SetRenderDrawColor(ren, r, g, b, 0);
    SDL_RenderClear(ren);
}

void DrawTringle(SDL_Renderer *ren, Mug_Trig t){
    SDL_SetRenderDrawColor(ren, t.color[0], t.color[1], t.color[2], 255);
    SDL_RenderDrawLine(ren, t.x[0], t.y[0], t.x[1], t.y[1]);
    SDL_RenderDrawLine(ren, t.x[1], t.y[1], t.x[2], t.y[2]);
    SDL_RenderDrawLine(ren, t.x[2], t.y[2], t.x[0], t.y[0]);
}

void DrawLineMan(SDL_Renderer* ren, int x1, int x2, int y1, int y2, int r, int g, int b){
    SDL_SetRenderDrawColor(ren, r, g, b, 0);
    SDL_RenderDrawLine(ren, x1, y1, x2, y2); 
}

void DrawLine(SDL_Renderer* ren, Mug_Line m){
    SDL_SetRenderDrawColor(ren, m.color[0], m.color[1], m.color[2], 255);
    SDL_RenderDrawLine(ren, m.x[0], m.y[0], m.x[1], m.y[1]);
}
void DrawLineMul(SDL_Renderer* ren, Mug_Line* ms, int count){
    for (int i = 0; i < count; i++){
        DrawLine(ren, ms[i]);
    }
}
void DrawPointMan(SDL_Renderer *ren, int x, int y, int r, int g, int b){
    SDL_SetRenderDrawColor(ren, r, g, b, 0);
    SDL_RenderDrawPoint(ren, x, y);
}
void DrawPoint(SDL_Renderer *ren, Mug_Point p){
    SDL_SetRenderDrawColor(ren, p.color[0], p.color[1], p.color[2], 255);
    SDL_RenderDrawPoint(ren, p.x, p.y);
}

void Release(SDL_Renderer* ren){
    SDL_RenderPresent(ren);
}
Mug_Letter MakeLetter(char c, int x, int y, int w, int h){
    Mug_Letter letter;
    letter.c = c;
    letter.pos[0] = x; letter.pos[1] = y;
    letter.size[0] = h; letter.size[1] = w;
    return letter;
}
