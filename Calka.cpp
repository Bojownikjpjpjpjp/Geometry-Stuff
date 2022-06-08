#include <math.h>
#include "Calka.h"
#include "Punkt.h"
double Calka::f(double x) {
	//return ((x*x)*pow(sin(x),3));
	return (exp((x * x)) * (x - 1));

}
double Calka::licz_calke(double a, double b, int n) {
	double suma = 0;
	double a1 = a;
	double dx = ((b - a) / n);
	if (dx < 0) {
		dx *= -1;
	}
	double b1 = a1 + dx;
	double suma_podstaw = 0;
	for (int i = 0; i < n; i++) {
		suma_podstaw = f(a1) + f(b1);
		suma += (suma_podstaw * dx / 2);
		a1 += dx;
		b1 += dx;
	}
	return suma;
}
//nieudany pomys³
double Calka::licz_calke_z_punktow(PUNKT p1, PUNKT p2) {
	double suma = 0;
	int n = 1000;
	double a1 = p1.x;
	double dx = ((p2.x - p1.x) / n);
	if (dx < 0) {
		dx *= -1;
	}
	double b1 = a1 + dx;
	double suma_podstaw = 0;
	for (int i = 0; i < n; i++) {
		suma_podstaw = f(a1) + f(b1);
		suma += (suma_podstaw * dx / 2);
		a1 += dx;
		b1 += dx;
	}
	return suma;
}