#pragma once
#include <string>

// стандартная высота шрифта
const int stdTextHeight = 20;

//Функция отображения меню
//items - массив названий пунктов меню
//count - колличество пунктов
//возвращает индекс выбраного пукта
int ShowMenu(std::string* items, int count);
