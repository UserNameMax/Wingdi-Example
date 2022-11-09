#include <cmath>

double f(double x) {
	return x - 2 * exp(-x) - sqrt(x);
}

double** tabulate(double a, double b, int n) {
	double dx = (b - a) / (n - 1);
	double** result = new double*[2];
	result[0] = new double[n];
	result[1] = new double[n];
	for (int x = a, i = 0; x <= b+0.00001; x += dx,++i) {
		result[0][i] = x;
		result[1][i] = f(x);
	}
	return result;
}