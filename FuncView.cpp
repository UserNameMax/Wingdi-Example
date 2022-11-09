#include <stdio.h>
#include "Keyboard.h"
#include "Examples.h"
#include <Windows.h>

const int x0 = 300, y0 = 300, k = 30;

void DrawLine(int x1, int y1, int x2, int y2, COLORREF color);

void printTable(double** table, int n) {
	printf("|%6s|%10s|\n", "x", "f(x)");
	for (int i = 0; i < n; ++i) {
		printf("|%6.2lf|%10.4lf|\n",table[0][i], table[1][i]);
	}
	GetKey();
}

void SysToScreen(double* x,double* y) {
	*x = k* * x + x0;
	*y = y0 - k* *y;
}

void drawGrafic(double** table, int n) {
	double p1[2] = {-10,0}, p2[2] = { 10,0 };
	SysToScreen(&p1[0], &p1[1]);
	SysToScreen(&p2[0], &p2[1]);
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(255, 255, 255));

	p1[0] = 0; p1[1] = -10;
	p2[0] = 0; p2[1] = 10;
	SysToScreen(&p1[0], &p1[1]);
	SysToScreen(&p2[0], &p2[1]);
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(255, 255, 255));

	p2[0] = table[0][0]; p2[1] = table[1][0];
	SysToScreen(&p2[0], &p2[1]);
	for (int i = 0; i < n-1; ++i) {
		p1[0] = p2[0];	 p1[1] = p2[1];
		p2[0] = table[0][i + 1]; p2[1] = table[1][i + 1];
		SysToScreen(&p2[0], &p2[1]);
		DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(255, 0, 0));
	}
	GetKey();
}