#include <windows.h>
#include <string>
#include "Keyboard.h"// хедер функций клавиатуры
#include "Menu.h"

// Функция устанавливает шрифт, цвет фона, цвет для вывода текста и прочие параметры типа подчеркивания
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

    SelectObject(hdc, CreateFontIndirect(&font));// установка шрифта
    SetBkColor(hdc, BkCollor);// установка цвета цвета заднего фона
    SetTextColor(hdc, TextCollor);// установка цвета текста
}

// Функция для вывода пуктов меню
// x, y - координаты первого символа
void PrintMenu(HDC hdc,std::string* items,int count,int x,int y){
	for (int i = 0; i < count; ++i) {
		TextOutA(hdc, x, y, items[i].c_str(), items[i].size()); //печать i-ого пункта
		y += stdTextHeight;
	}
	EndPath(hdc);
}

int ShowMenu(std::string* items, int count){
	HDC hdc = GetDC(GetConsoleWindow()); // получаем контекст отображения
    setTextSettings(hdc);// устанавливаем параметры теста
	PrintMenu(hdc,items,count,100,100);// выводим пункты меню
    Keys pressedKey; //хранилице нажатой клавиши
    int choise = 0; // выбраный пункт
    TextOutA(hdc, 80, 100, ">", 1); // выводим стрелку 
    EndPath(hdc);
    while ((pressedKey = GetKey()) != Enter){ // выполняем цикл пока не нажат ENTER
        setTextSettings(hdc, RGB(0, 0, 0), RGB(0, 0, 0)); // устанавливаем чёрный цвет для текста
        TextOutA(hdc, 80, 100 + choise * 20, ">", 1); // стираем старую стрелку
        switch (pressedKey) {
        // при смещение стрелки берётся остаток, чтобы стрелка не вышла за допустимые границы
        case Up:
            choise = (choise + count - 1) % count; // поднимаем стрелку вверх (добавляем count, чтобы не получить отрицательный остаток)
            break;
        case Down:
            choise = (choise + 1) % count;// опускаеи стрелку вниз
            break;
        }
        setTextSettings(hdc, RGB(0, 0, 0), RGB(255, 255, 255)); // возвращаем белый цвет текста
        TextOutA(hdc, 80, 100 + choise * 20, ">", 1);// выводим новую стрелку
        EndPath(hdc);
    }
    ReleaseDC(GetConsoleWindow(), hdc);// освобождаем контекст
	return choise; // возвращвем выбор
}