#ifndef MUG_H
#define MUG_H
#define OPENGLSUPPORT 0 // TODO: opengl support
#include <SDL2/SDL.h>
#include <stdlib.h>

typedef struct {
    int x[1];
    int y[1];
    int color[3]; 
    int flag;
} Mug_Point;

typedef struct {
    int x[2];
    int y[2];
    int color[3]; // R G B
    int flag;
    //int thi // TODO: implement thickness
} Mug_Line;

typedef struct {
    int x[3]; // x1 x2 x3
    int y[3]; // y1 y2 y3
    int color[3]; // R G B
    int flag;
} Mug_Trig;

typedef struct {
    int x[4]; // x1 x2 x3 x4
    int y[4]; // y1 y2 y3 y4
    int color[3]; 
    int flag;
} Mug_Rect;

typedef struct{ // TODO: Implement Text Rendering
    char c;
    int size[2]; // h w
    int pos[2];  // x y
    int flag;
} Mug_Letter; // NOTE: this is not an mug_ch, just mapping and how should letter (render) be!
typedef struct {
    Mug_Letter* list;
    int size;
} Mug_Font;
typedef struct { 
    int pallettotal;
    int **colorpallet;
} Mug_Pallet;
typedef struct { // NOTE: only works with bitmaps!
    int flag;
    int size[2]; // H W
    int ***img; // bitmap, height, width, color
} Mug_Imagedata;
typedef enum {
    MUG_POINT,
    MUG_LINE,
    MUG_TRIG,
    MUG_RECT
} Mug_Type;
typedef union {
    Mug_Point point;
    Mug_Line line;
    Mug_Trig trig;
    Mug_Rect rect;
} Mug_Area;
typedef struct {
    Mug_Area* area;
    Mug_Type type;
    void (*func)(Mug_Area* area); 
} Mug_TouchArea;

void EndNo(int ret);
void EndWin(SDL_Window* win);
void EndRen(SDL_Renderer* ren);
void EndwRen(SDL_Window* win, SDL_Renderer* ren);

SDL_Window* NewWin(const char* title, int x, int y, int h, int w);
SDL_Renderer* NewRen(SDL_Window* w);
void SetBack(SDL_Renderer* ren, int r, int g, int b);
Mug_Rect MakeRect(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int r, int g, int b);
Mug_Trig MakeTringle(int x1, int x2, int x3, int y1, int y2, int y3, int r, int g, int b);
Mug_Line MakeLine(int x1, int x2, int y1, int y2, int r, int g, int b);
Mug_Point MakePoint(int x, int y, int r, int g, int b);
Mug_Letter MakeLetter(char c, int x, int y, int w, int h);
Mug_Area MakeArea(Mug_Type t, int cord[], int color[3]);
Mug_TouchArea MakeTouch(Mug_Area* a, Mug_Type t, void (*func)(Mug_Area* arg));
void DrawPointMan(SDL_Renderer *ren, int x, int y, int r, int g, int b);
void DrawPoint(SDL_Renderer *ren, Mug_Point p);
void DrawLineMan(SDL_Renderer* ren, int x1, int x2, int y1, int y2, int r, int g, int b);
void DrawLine(SDL_Renderer* ren, Mug_Line m);
void DrawTringle(SDL_Renderer *ren, Mug_Trig t);
void DrawRect(SDL_Renderer *ren, Mug_Rect s);
void DrawLineMul(SDL_Renderer* ren, Mug_Line* ms, int count);
void DrawLetter(SDL_Renderer* ren, char c);
//void SetFont(Mug_Font f, const char* abspath);
void HandleClick(Mug_TouchArea list[], int count, int click_x, int click_y);
void Hide();
void Release(SDL_Renderer* ren);
Mug_Imagedata MakeImg(int h, int w, int flag);
void LoadImg(Mug_Imagedata *img, int data[][img->size[1]][3]);
void FreeImg(Mug_Imagedata *m);
void RenderImg(SDL_Renderer* ren, Mug_Imagedata img, int x, int y);


#endif
