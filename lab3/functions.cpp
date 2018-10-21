#include "functions.h"

void PutPixel(HDC *hdc, int x, int y, struct Data data) {
    Rectangle(*hdc,
              (x * data.size),
              ((data.height - y) * data.size),
              ((x + 1) * data.size),
              ((data.height - y - 1) * data.size));
}

static void CircleLogic(int ix0, int iy0, int x, int y, HDC *hdc, Data data) {//Алгоритм Брезенхема для окружностей №2
    int x1 = ix0 + x, y1 = iy0 + y, x2 = ix0 - x, y2 = iy0 - y;
    PutPixel(hdc, x1, y1, data);
    PutPixel(hdc, x1, y2, data);
    PutPixel(hdc, x2, y2, data);
    PutPixel(hdc, x2, y1, data);
    PutPixel(hdc, y1, x1, data);
    PutPixel(hdc, y1, x2, data);
    PutPixel(hdc, y2, x2, data);
    PutPixel(hdc, y2, x1, data);

}

void DrawCircle(int x_init, int y_init, int radius, HDC *hdc, Data data) {
//http://www.codenet.ru/progr/video/alg/alg4.php Алгоритм Брезенхема для окружностей
    int x, y, diameter;
    x = 0;
    y = radius;
    diameter = 3 - (radius << 1);//*2

    while (x <= y) {
        CircleLogic(x_init, y_init, x, y, hdc, data);
        if (diameter < 0) {
            diameter += (x << 2) + 6;
        } else {
            diameter += ((x - y) << 2) + 10;
            --y;
        }
        x++;
    }

}

void DrawGrid(HDC *hdc, struct Data data) {

    int x, y, x1, y1;
    x = y = x1 = y1 = 0;//устанавливаем начальное положение пера

    //рисование по y
    for (int i = 0; i <= (data.height); i++) {
        MoveToEx(*hdc, x, y, NULL);
        LineTo(*hdc, x + (data.width * data.size), y);
        y += (data.size);
    }

    //рисование по x
    for (int j = 0; j <= data.width; j++) {
        MoveToEx(*hdc, x1, y1, NULL);
        LineTo(*hdc, x1, y1 + (data.height * data.size));
        x1 += (data.size);
    }
}

//void DrawTriangle(HDC *hdc, Data data, int Ax, int Ay, int Bx, int By, int Cx, int Cy)
//{a
//    LineCoord line;
//    int tmp;
//    int Y[3] = { Ay,By,Cy };
//    int X[3] = { Ax,Bx,Cx };
//    for (int i = 0; i<2; i++)
//        for (int j = 0; j<2; j++)
//            if (Y[j]<Y[j + 1])
//            {
//                tmp = Y[j + 1];
//                Y[j + 1] = Y[j];
//                Y[j] = tmp;
//                tmp = X[j + 1];
//                X[j + 1] = X[j];
//                X[j] = tmp;
//            }
//    Cy = Y[0]; By = Y[1]; Ay = Y[2];
//    Cx = X[0]; Bx = X[1]; Ax = X[2];
//
