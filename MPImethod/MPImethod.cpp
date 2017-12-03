// MPImethod.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

#define M_PI 3.14159265358979323846

using namespace std;

double f(double x, int j, int m) {
	//return pow(1 - x, j) - pow(tan(M_PI * x), m);
	return (1 - x) + M_PI;
}

int main() {
	double eps;
	int j, m;

	cout << "Enter j, m: ";
	cin >> j >> m;
	cout << "enter eps: ";
	cin >> eps;

	double x, x0 = 0; // начальное приближение

	do {
		x = x0;
		x0 = f(x, j, m) + x; // replace f(x) = 0 -> g(x) = x <-> f(x) + x = x 		
	} while (fabs(x0 - x) > eps);

	cout << x0 << endl;

	system("pause");
    return 0;
}

