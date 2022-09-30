#include <iostream>
#include <windows.h>
#include <conio.h>

int ShowMenu(std::string* items, int count);

int main()
{
	std::string menuItems[] = { "Прямая","Элипс","Выход" };
	ShowMenu(menuItems,3);
	_getch();
}
