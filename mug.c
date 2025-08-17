#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include "mug.h"

void EndNo(int ret){SDL_Quit();exit(ret);}
void EndWin(SDL_Window* win){SDL_DestroyWindow(win);}
void EndRen(SDL_Renderer* ren){SDL_DestroyRenderer(ren);}
void EndwRen(SDL_Window* win, SDL_Renderer* ren){EndWin(win); EndRen(ren);}

Mug_Point MakePoint(int x, int y,/*int t*/ int r, int g, int b){
    Mug_Point p;
    p.x[0] = x;
    p.y[0] = y;
    //p.thi = thick;
    p.color[0] = r; p.color[1] = g; p.color[2] = b;
    return p;
}

Mug_Rect MakeRect(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int r, int g, int b){
    Mug_Rect s;
    s.x[0] = x1; s.y[0] = y1;
    s.x[1] = x2; s.y[1] = y2;
    s.x[2] = x3; s.y[2] = y3;    
    s.x[3] = x4; s.y[3] = y4;
    s.color[0] = r; s.color[1] = g; s.color[2] = b;
    return s;
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
Mug_Letter MakeLetter(char c, int x, int y, int w, int h){
    Mug_Letter letter;
    letter.c = c;
    letter.pos[0] = x; letter.pos[1] = y;
    letter.size[0] = h; letter.size[1] = w;
    return letter;
}
SDL_Window* NewWin(const char* title, int x, int y, int h, int w){
    SDL_Window* win = SDL_CreateWindow(title, x, y, h, w, 0);
    if (!win){EndNo(1);}
    return win;
}

Mug_Area MakeArea(Mug_Type type, int coords[], int color[3]){
    Mug_Area a;

    if (type == MUG_POINT){
        a.point.x[0] = coords[0];
        a.point.y[0] = coords[1];
        memcpy(a.point.color, color, sizeof(int)*3);

    } else if (type == MUG_LINE){
        for(int i=0;i<2;i++){ 
            a.line.x[i] = coords[i];
            a.line.y[i] = coords[i+2];
        }
        memcpy(a.line.color, color, sizeof(int)*3);

    } else if (type == MUG_TRIG){
        for(int i=0;i<3;i++){ 
            a.trig.x[i] = coords[i];
            a.trig.y[i] = coords[i+3];
        }
        memcpy(a.trig.color, color, sizeof(int)*3);

    } else if (type == MUG_RECT){
        for(int i=0;i<4;i++){ 
            a.rect.x[i] = coords[i];
            a.rect.y[i] = coords[i+4];
        }
        memcpy(a.rect.color, color, sizeof(int)*3);
    }

    return a;
}
Mug_TouchArea MakeTouch(Mug_Area a, Mug_Type t, void (*func)(Mug_Area arg)){
    Mug_TouchArea ta;
    ta.area = a;
    ta.type = t;
    ta.func = func;
    return ta;
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

void DrawRect(SDL_Renderer *ren, Mug_Rect s){
    SDL_SetRenderDrawColor(ren, s.color[0], s.color[1], s.color[2], 255);
    SDL_RenderDrawLine(ren, s.x[0], s.y[0], s.x[1], s.y[1]);
    SDL_RenderDrawLine(ren, s.x[1], s.y[1], s.x[2], s.y[2]);
    SDL_RenderDrawLine(ren, s.x[2], s.y[2], s.x[3], s.y[3]);
    SDL_RenderDrawLine(ren, s.x[3], s.y[3], s.x[0], s.y[0]);
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
    SDL_RenderDrawPoint(ren, p.x[0], p.y[0]);
}
void HandleClick(Mug_TouchArea list[], int count, int click_x, int click_y){
    for (int i = 0; i < count; i++){

        if (list[i].type == MUG_POINT){
            if (list[i].area.point.x[0] == click_x &&
                list[i].area.point.y[0] == click_y){
                list[i].func(list[i].area);
            }

        } else if (list[i].type == MUG_LINE){
            int x1 = list[i].area.line.x[0], y1 = list[i].area.line.y[0];
            int x2 = list[i].area.line.x[1], y2 = list[i].area.line.y[1];

            int minX = x1 < x2 ? x1 : x2;
            int maxX = x1 > x2 ? x1 : x2;
            int minY = y1 < y2 ? y1 : y2;
            int maxY = y1 > y2 ? y1 : y2;

            if (click_x >= minX && click_x <= maxX &&
                click_y >= minY && click_y <= maxY &&
                (y2 - y1)*(click_x - x1) == (x2 - x1)*(click_y - y1)){
                list[i].func(list[i].area);
            }

        } else if (list[i].type == MUG_TRIG){
            int x0 = list[i].area.trig.x[0], y0 = list[i].area.trig.y[0];
            int x1 = list[i].area.trig.x[1], y1 = list[i].area.trig.y[1];
            int x2 = list[i].area.trig.x[2], y2 = list[i].area.trig.y[2];

            int denom = (y1 - y2)*(x0 - x2) + (x2 - x1)*(y0 - y2);
            int a = ((y1 - y2)*(click_x - x2) + (x2 - x1)*(click_y - y2));
            int b = ((y2 - y0)*(click_x - x2) + (x0 - x2)*(click_y - y2));
            int c = denom - a - b;

            if (denom != 0 && ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))){
                list[i].func(list[i].area);
            }

        } else if (list[i].type == MUG_RECT){
            int minX = list[i].area.rect.x[0], maxX = list[i].area.rect.x[0];
            int minY = list[i].area.rect.y[0], maxY = list[i].area.rect.y[0];

            for (int j = 1; j < 4; j++){
                if (list[i].area.rect.x[j] < minX) minX = list[i].area.rect.x[j];
                if (list[i].area.rect.x[j] > maxX) maxX = list[i].area.rect.x[j];
                if (list[i].area.rect.y[j] < minY) minY = list[i].area.rect.y[j];
                if (list[i].area.rect.y[j] > maxY) maxY = list[i].area.rect.y[j];
            }

            if (click_x >= minX && click_x <= maxX &&
                click_y >= minY && click_y <= maxY){
                list[i].func(list[i].area);
            }

        } else {
            EndNo(2); 
        }
    }
}


void Release(SDL_Renderer* ren){
    SDL_RenderPresent(ren);
}

