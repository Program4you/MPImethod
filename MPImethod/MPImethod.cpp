// MPImethod.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <cstdlib>

#define M_PI 3.14159265358979323846

using namespace std;

double f(double x, int j, int m) {
	return pow(1 - x, j) - pow(tan(M_PI * x), m);
}

int main() {
	double eps;
	int j, m;

	cout << "Enter j, m: ";
	cin >> j >> m;
	cout << "enter eps: ";
	cin >> eps;

	double Xn2 = 0;
	double Xn1 = f(Xn2, j, m) + Xn2; // f(x) = 0 <=> f(x) + x = x => g(x) = f(x) + x
	double Xn = f(Xn1, j, m) + Xn1;

	while (pow(Xn - Xn1, 2) / fabs(2 * Xn1 - Xn - Xn2) > eps) {
		Xn2 = Xn1;
		Xn1 = Xn;
		Xn = f(Xn1, j, m) + Xn1;	
	}

	cout << Xn << endl;

	system("pause");
    return 0;
}

