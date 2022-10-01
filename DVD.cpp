#include <Windows.h>

void DrawBox(int x, int y, int a, COLORREF color);

void DrawEllipse(int x,int y,int width,int height, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN pen = CreatePen(BS_SOLID, 1, color);
	HBRUSH brush = CreateSolidBrush(color);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x, y, x+width, y+height);
	auto err = GetLastError();
	DeleteObject(pen);
	DeleteObject(brush);
}

void RunEllipse(int x, int y, int width, int height, COLORREF color) {
	int k = 1, b = y-k*x,dx = 1;
	int count = 0;
	for (int i = 0+x;count < 4 ; i+=dx) {
		DrawBox(0, 0, 500, RGB(255, 255, 255));
		DrawEllipse(i, k*i+b, width, height, color);
		Sleep(10);
		DrawEllipse(i, k * i + b, width, height, RGB(0, 0, 0));
		
		if (i >= 500 - width || i <= 0) {
			dx *= -1;
		}
		if (i >= 500-width || k * i + b >= 500-height || i <= 0 || k * i + b <= 0) {
			k *= -1;
			b += -2*k*i;
			count++;
		}
	}
}