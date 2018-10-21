#include "functions.h"

#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")


int main() {

    //**************
    Data gridParams;
    gridParams.height = 30;
    gridParams.width = 30;
    gridParams.size = 20;
    const int X_CENTER_CIRCLE = gridParams.width / 2;
    const int Y_CENTER_CIRCLE = gridParams.height / 2;
    const int RADIUS = 10;
    HWND some_hwnd = GetConsoleWindow(); // получаем идентификатор окна
    HDC some_hdc = GetDC(some_hwnd); // получаем контекст отображения
    PAINTSTRUCT some_ps;
    HPEN paleOrangePen = CreatePen(PS_DOT, 10, RGB(200, 100, 70));//создаем перо
    HPEN paleGreenPen = CreatePen(PS_DOT, 1, RGB(160, 180, 160));
    //*****************************



    SelectPen(some_hdc, paleGreenPen);
    DrawGrid(&some_hdc, gridParams);

    SelectPen(some_hdc, paleOrangePen);
    DrawCircle(X_CENTER_CIRCLE, Y_CENTER_CIRCLE, RADIUS, &some_hdc, gridParams);

    std::cout << "it is a place for breakpoint";
}


