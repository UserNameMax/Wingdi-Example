#pragma once
#include <Windows.h>
// примеры рисования графики
void RunLine(int x, int y, int a);
void RunEllipse(int x, int y, int width, int height, COLORREF color);
double** tabulate(double a, double b, int n);
void printTable(double** table, int n);
void drawGrafic(double** table, int n);