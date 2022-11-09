﻿#include <windows.h> //хедер с функциями api
#include <iostream>
#include "Menu.h" //хедеры вспомогательных функций
#include "Examples.h"

int main()// точка входа
{
	std::string menuItems[] = { "Прямая","Элипс","Таблица","График","Выход"}; // список пунктов меню
	double** table = tabulate(-10, 10, 200);
	for (;;) { //бесконечгый цикл
		int choise = ShowMenu(menuItems, 5); // получаем выбор пользователя (см. Menu.h)
		system("cls");//очистка экрана
		switch (choise)// выполняем действия в зависемости ои выбора
		{
		case 0:// выбрали "Прямая"
			RunLine(100,100,300); //Рисуем бегущую линию
			Sleep(1000); //задерка перед очисткой
			break; // break чтобы не перйти в другой case
		case 1:// выбрили "Элипс"
			RunEllipse(1, 1, 50, 10, RGB(0, 0, 255));//Рисуем бегущий элипс
			break;// break чтобы не перйти в другой case
		case 2:
			printTable(table, 200);
			break;
		case 3:
			drawGrafic(table, 200);
			break;
		default:// выбрали "Выход"
			return 0;//завершаем программу
		}
		system("cls");// очистка экрана
	}
}
