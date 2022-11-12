#include <Windows.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

std::string name = "Максим";
std::vector<int> leters;

void swap(int& a, int& b) 
{
    int buf = a;
    a = b;
    b = buf;
}

void initLeters() {
	for (int i = 0; i < name.size(); ++i) {
        leters.push_back(i);
	}
    while ((rand() % 10) != 7) {
        swap(leters[abs(rand()) % leters.size()], leters[abs(rand()) % leters.size()]);
    }
}

HFONT getFont() {
    LOGFONT font;
    font.lfHeight = 40;// Устанавливает высоту шрифта или символа
    font.lfWidth = 0;// Устанавливает среднюю ширину символов в шрифте
    font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
    font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
    font.lfWeight = 100;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
    font.lfItalic = 0;// Устанавливает курсивный шрифт
    font.lfUnderline = 0;// Устанавливает подчеркнутый шрифт
    font.lfStrikeOut = 0;// Устанавливает зачеркнутый шрифт
    font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
    font.lfOutPrecision = 0;// Устанавливает точность вывода
    font.lfClipPrecision = 0;// Устанавливает точность отсечения
    font.lfQuality = 0;// Устанавливает качество вывода
    font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта
    return CreateFontIndirect(&font);
}

void aboutMe(){
    HDC hdc = GetDC(GetConsoleWindow());
	initLeters();
    HFONT font = getFont();
    SelectObject(hdc,font);
    for (int i = 0; i < leters.size(); ++i) {
        TextOutA(hdc, 100+leters[i] * 30, 100, name.c_str() + leters[i], 1);
        EndPath(hdc);
        Sleep(1000);
    }
    DeleteObject(font);
    ReleaseDC(GetConsoleWindow(), hdc);
}