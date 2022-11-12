#include <stdio.h>

double fi(double x) {
	return x;
}

double square(double a, double b) {
	return (b - a) * fi(a);
}

double trapSq(double a, double b) {
	return (b - a) * (fi(a) + fi(b)) / 2;
}

double integral(double a, double b, int n, bool isTrapSq = false) {
	auto sq = (isTrapSq) ? trapSq : square;
	double result = 0;
	double dx = (b - a) / n;
	for (double x = a; x <= b + 0.000001; x += dx) {
		result += sq(x, x + dx);
	}
	return result;
}

void itegralDialog() {
	double a, b;
	int n;
	printf("Введите границы: ");
	scanf_s("%lf %lf", &a, &b);
	printf("Введите число отрезков: ");
	scanf_s("%i", &n);
	printf("%20s%20s\n%20.4lf%20.4lf","Метод прямоугольнтков","Метод трапеций", integral(a, b, n), integral(a, b, n, true));
}