#pragma once

// Перечисление всех нужных клавишь для удобства написания программы
enum Keys {
	Other = -1,
	Up,
	Left,
	Down,
	Right,
	Enter,
	Space
};

// Функция возвращает нажатую клаыишу
Keys GetKey();