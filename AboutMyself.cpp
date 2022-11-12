#include <Windows.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>

std::string name = "������";
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
    font.lfHeight = 40;// ������������� ������ ������ ��� �������
    font.lfWidth = 0;// ������������� ������� ������ �������� � ������
    font.lfEscapement = 0;// ������������� ����, ����� �������� ������� � ���� X ����������
    font.lfOrientation = 0;// ������������� ����, ����� �������� ������ ������� ������� � ���� X ����������
    font.lfWeight = 100;// ������������� ������� ������ � ��������� �� 0 �� 1000
    font.lfItalic = 0;// ������������� ��������� �����
    font.lfUnderline = 0;// ������������� ������������ �����
    font.lfStrikeOut = 0;// ������������� ����������� �����
    font.lfCharSet = RUSSIAN_CHARSET;// ������������� ����� ��������
    font.lfOutPrecision = 0;// ������������� �������� ������
    font.lfClipPrecision = 0;// ������������� �������� ���������
    font.lfQuality = 0;// ������������� �������� ������
    font.lfPitchAndFamily = 0;// ������������� ������ �������� � ��������� ������
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