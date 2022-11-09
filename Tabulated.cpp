#include <cmath>

double f(double x) {
	return x * x;
}

double** tabulate(double a, double b, int n) {
	double dx = (b - a) / (n - 1);
	double** result = new double*[2];
	result[0] = new double[n];
	result[1] = new double[n];
	int i = 0;
	for (double x = a; x <= b+0.00001; x += dx,++i) {
		result[0][i] = x;
		result[1][i] = f(x);
	}
	return result;
}