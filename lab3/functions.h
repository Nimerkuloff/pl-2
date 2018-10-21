//
// Created by hehas on 5/7/2018.
//

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <math.h>
#include <gdiplus.h>

struct Data {
    int height;
    int width;
    int size;
};

void DrawGrid(HDC *, Data);

void DrawCircle(int x_init, int y_init, int radius, HDC *hdc, Data gridParameters);

static void CircleLogic(int, int, int, int, HDC *, Data);

void PutPixel(HDC *, int, int, struct Data);





#endif //LAB3_FUNCTIONS_H
