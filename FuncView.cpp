#include <stdio.h>
#include "Keyboard.h"

void printTable(double** table, int n) {
	printf("|%6s|%10s|\n", "x", "f(x)");
	for (int i = 0; i < n; ++i) {
		printf("|%6.2lf|%10.4lf|\n",table[0][i], table[1][i]);
	}
	GetKey();
}