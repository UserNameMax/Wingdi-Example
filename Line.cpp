#include <windows.h>

// функци€ дл€ отрисовки квадрата по координатам (x,y) с длиной стороны a, цвета color
void DrawBox(int x, int y, int a, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());// получаем контекст
	HPEN pen = CreatePen(BS_SOLID, 1, color); // создаЄм перо нужного цвета
	POINT points[] = { {x,y},{x + a,y},{x + a,y + a},{x,y + a},{x,y} }; // массив точек квадрата
	SelectObject(hdc, pen);//устанавливаем перо
	Polyline(hdc, points, 5);//рисуем квадрат как ломаную
	DeleteObject(pen);//сбрасываем перо
	ReleaseDC(GetConsoleWindow(), hdc);//сбрасываем контекст
}

// функци€ дл€ отрисовки отрезка с концами (x1,y1) (x2,y2) цвета color
void DrawLine(int x1, int y1, int x2, int y2, COLORREF color) {
	HDC hdc = GetDC(GetConsoleWindow());// получаем контекст
	HPEN pen = CreatePen(BS_SOLID, 1, color);// создаЄм перо нужного цвета
	SelectObject(hdc, pen);//устанавливаем перо
	MoveToEx(hdc, x1, y1,NULL);//устанавливаем перов в первую точку
	LineTo(hdc, x2, y2);//ведЄм перо во вторую точку
	DeleteObject(pen);//сбрасываем перо
	ReleaseDC(GetConsoleWindow(), hdc);//сбрасываем контекст
}

// ‘ункци€ обновлени€ экрана, рисующа€ квадрат и отрезок соедин€ющий точки p1 и p2
void UpdateScreen(int x, int y, int a, int p1[2],int p2[2]) {
	DrawBox(x, y, a, RGB(0, 255, 0));//рисуем зелЄный квадрат
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(255, 0, 0));//рисуем красную линую
	Sleep(10);//задержка
	DrawLine(p1[0], p1[1], p2[0], p2[1], RGB(0, 0, 0));//стираем линию
}

// демонстрационна€ функци€
//перелаЄм координаты квадрата и длину его стороны
void RunLine(int x,int y, int a){
	int p1[] = { x,y + a / 2 }, p2[] = { x + a / 2,y }; // задаЄм концы отрезка
	while (p2[0] < x+a) {// пока втора€ точка бежит по верхнему отрезку
		UpdateScreen(x, y, a, p1, p2);
		// смещаем точки
		--p1[1];
		++p2[0];
	}
	while (p1[0] < x+a) {// пока перва€ точка бежит по верхнему отрезку
		UpdateScreen(x, y, a, p1, p2);
		++p1[0];
		++p2[1];
	}
	while (p2[0] > x) {// пока втора€ точка бежит по нижнему отрезку
		UpdateScreen(x, y, a, p1, p2);
		++p1[1];
		--p2[0];
	}
	while (p1[0] > x) {// пока перва€ точка бежит по нижнему отрезку
		UpdateScreen(x, y, a, p1, p2);
		--p1[0];
		--p2[1];
	}
}