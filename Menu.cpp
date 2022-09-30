#include <windows.h>
#include <string>
#include "Keyboard.h"
#include "Menu.h"



void setTextSettings(HDC hdc,COLORREF BkCollor= RGB(0, 0, 0), COLORREF TextCollor= RGB(255, 255, 255),
    int Height = stdTextHeight,int Width = 0,int Weight = 100,bool Italic = 0,bool Underline = 0,bool StrikeOut = 0) {
    LOGFONT font;
    font.lfHeight = Height;// Устанавливает высоту шрифта или символа
    font.lfWidth = Width;// Устанавливает среднюю ширину символов в шрифте
    font.lfEscapement = 0;// Устанавливает угол, между вектором наклона и осью X устройства
    font.lfOrientation = 0;// Устанавливает угол, между основной линией каждого символа и осью X устройства
    font.lfWeight = Weight;// Устанавливает толщину шрифта в диапазоне от 0 до 1000
    font.lfItalic = Italic;// Устанавливает курсивный шрифт
    font.lfUnderline = Underline;// Устанавливает подчеркнутый шрифт
    font.lfStrikeOut = StrikeOut;// Устанавливает зачеркнутый шрифт
    font.lfCharSet = RUSSIAN_CHARSET;// Устанавливает набор символов
    font.lfOutPrecision = 0;// Устанавливает точность вывода
    font.lfClipPrecision = 0;// Устанавливает точность отсечения
    font.lfQuality = 0;// Устанавливает качество вывода
    font.lfPitchAndFamily = 0;// Устанавливает ширину символов и семейство шрифта

    SelectObject(hdc, CreateFontIndirect(&font));
    SetBkColor(hdc, BkCollor);
    SetTextColor(hdc, TextCollor);
}

void PrintMenu(HDC hdc,std::string* items,int count,COLORREF color,int x,int y){
	for (int i = 0; i < count; ++i) {
		TextOutA(hdc, x, y, items[i].c_str(), items[i].size());
		y += stdTextHeight;
	}
	EndPath(hdc);
}

int ShowMenu(std::string* items, int count){
	HDC hdc = GetDC(GetConsoleWindow());
    setTextSettings(hdc);
	PrintMenu(hdc,items,count,RGB(255,255,255),100,100);
    Keys pressedKey;
    int choise = 0;
    TextOutA(hdc, 80, 100, ">", 1);
    EndPath(hdc);
    while ((pressedKey = GetKey()) != Enter){
        setTextSettings(hdc, RGB(0, 0, 0), RGB(0, 0, 0));
        TextOutA(hdc, 80, 100 + choise * 20, ">", 1);
        switch (pressedKey) {
        case Up:
            choise = (choise + count - 1) % count;
            break;
        case Down:
            choise = (choise + 1) % count;
            break;
        }
        setTextSettings(hdc, RGB(0, 0, 0), RGB(255, 255, 255));
        TextOutA(hdc, 80, 100 + choise * 20, ">", 1);
        EndPath(hdc);
    }
	return choise;
}