#include <windows.h>

void DrawBox(int x, int y, int a, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN pen = CreatePen(BS_SOLID, 1, color);
	POINT points[] = { {x,y},{x + a,y},{x + a,y + a},{x,y + a},{x,y} };
	SelectObject(hdc, pen);
	Polyline(hdc, points, 5);
	DeleteObject(pen);
}

void DrawLine(int x1, int y1, int x2, int y2, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());
	HPEN pen = CreatePen(BS_SOLID, 1, color);
	SelectObject(hdc, pen);
	MoveToEx(hdc, x1, y1,NULL);
	LineTo(hdc, x2, y2);
	DeleteObject(pen);
}

void UpdateScreen(int x, int y, int a, int p1[2],int p2[2]) {
	DrawBox(x, y, a, RGB(0, 255, 0));
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(255, 0, 0));
	Sleep(10);
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(0, 0, 0));
}

void RunLine(int x,int y, int a){
	int p1[] = { x,y + a / 2 }, p2[] = { x + a / 2,y };
	while (p2[0] < x+a) {
		UpdateScreen(x, y, a, p1, p2);
		--p1[1];
		++p2[0];
	}
	while (p1[0] < x+a) {
		UpdateScreen(x, y, a, p1, p2);
		++p1[0];
		++p2[1];
	}
	while (p2[0] > x) {
		UpdateScreen(x, y, a, p1, p2);
		++p1[1];
		--p2[0];
	}
	while (p1[0] > x) {
		UpdateScreen(x, y, a, p1, p2);
		--p1[0];
		--p2[1];
	}
}