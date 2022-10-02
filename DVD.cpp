#include <Windows.h>

void DrawBox(int x, int y, int a, COLORREF color); //смотри Line.cpp

// функция рисует элипс внутри прямоугольника по заданым координатам и заданым длиной и шириной нужного цвета
void DrawEllipse(int x,int y,int width,int height, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());// получаем контекст
	HPEN pen = CreatePen(BS_SOLID, 1, color);//создаём перо
	HBRUSH brush = CreateSolidBrush(color);//создаём кисть
	SelectObject(hdc, pen);//устанавливаем перо
	SelectObject(hdc, brush);//устанавливаем кисть
	Ellipse(hdc, x, y, x+width, y+height);//рисуем элипс
	//сбрасываем то что нужно
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(GetConsoleWindow(), hdc);
}

//демонстрационная программа рисует движущиййся элипс бьющийся о стенки квадрата
void RunEllipse(int x, int y, int width, int height, COLORREF color) {
	int k = 1, b = y-k*x,dx = 1;// k,b - задают прямую по которой движется элипс, dx - задаёт направление движения
	int count = 0;//число ударов
	for (int i = 0+x;count < 8 ; i+=dx) {// двишаем элипс пока не насчитаем 8 ударов
		DrawBox(0, 0, 500, RGB(255, 255, 255)); // рисуем квадрат
		DrawEllipse(i, k*i+b, width, height, color);// рисуем элипс
		Sleep(10);//задержка
		DrawEllipse(i, k * i + b, width, height, RGB(0, 0, 0));//стираем элипс
		
		if (i >= 500 - width || i <= 0) {// если достигли правой или левой стенки меняем напрвление
			dx *= -1;
		}
		if (i >= 500-width || k * i + b >= 500-height || i <= 0 || k * i + b <= 0) {// если достигли стенки меняем траекторию
			k *= -1;
			b += -2*k*i;
			count++;// считаем удар
		}
	}
}