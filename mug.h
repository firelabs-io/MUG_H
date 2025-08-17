#ifndef MUG_H
#define MUG_H
#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int color[3]; 
} Mug_Point;

typedef struct {
    int x[2];
    int y[2];
    int color[3]; // R G B
    //int thi // TODO: implement thickness
} Mug_Line;

typedef struct {
    int x[3]; // x1 x2 x3
    int y[3]; // y1 y2 y3
    int color[3]; // R G B
} Mug_Trig;

typedef struct {
    int pos[2]; // x y
    int size[2]; // w h
    int color[3]; 
    int IsEmpty;
} Mug_Rect;

typedef struct{ // TODO: Implement Text Rendering
    char c;
    int size[2]; // h w
    int pos[2];  // x y
} Mug_Letter;

void EndNo(int ret);
void EndWin(SDL_Window* win);
void EndRen(SDL_Renderer* ren);
void EndwRen(SDL_Window* win, SDL_Renderer* ren);

SDL_Window* NewWin(const char* title, int x, int y, int h, int w);
SDL_Renderer* NewRen(SDL_Window* w);
void SetBack(SDL_Renderer* ren, int r, int g, int b);
Mug_Trig MakeTringle(int x1, int x2, int x3, int y1, int y2, int y3, int r, int g, int b);
Mug_Line MakeLine(int x1, int x2, int y1, int y2, int r, int g, int b);
Mug_Point MakePoint(int x, int y, int r, int g, int b);
void DrawPointMan(SDL_Renderer *ren, int x, int y, int r, int g, int b);
void DrawPoint(SDL_Renderer *ren, Mug_Point p);
void DrawLineMan(SDL_Renderer* ren, int x1, int x2, int y1, int y2, int r, int g, int b);
void DrawLine(SDL_Renderer* ren, Mug_Line m);
void DrawTringle(SDL_Renderer *ren, Mug_Trig t);
void DrawLineMul(SDL_Renderer* ren, Mug_Line* ms, int count);
void Release(SDL_Renderer* ren);
Mug_Letter MakeLetter(char c, int x, int y, int w, int h);
//void AddCHLetter(Mug_Letter l);
//void FlushLetter(Mug_Letter l);

#endif
