#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Menu.h"
#include "Examples.h"

int main()
{
	std::string menuItems[] = { "Прямая","Элипс","Выход" };
	for (;;) {
		int choise = ShowMenu(menuItems, 3);
		system("cls");
		switch (choise)
		{
		case 0:
			RunLine(100,100,300);
			Sleep(1000);
			break;
		case 1:
			break;
		default:
			return 0;
		}
		system("cls");
	}
}
