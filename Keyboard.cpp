#include <conio.h> // для _getch()
#include "Keyboard.h"


Keys GetKey() {
	int i = _getch();// получаем код нажатой клавиши
	
	//возвращаем нужный элемент перечисления 
	if (i == 32) return Space;
	if (i == 13) return Enter;
	if (i == 224) i = _getch();
	if (i == 72) return Up;
	if (i == 75) return Left;
	if (i == 80) return Down;
	if (i == 77) return Right;
	return Other;
}