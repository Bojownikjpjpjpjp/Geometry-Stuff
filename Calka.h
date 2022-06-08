#ifndef CALKA_CLASS_H
#define CALKA_CLASS_H
#include"PUNKT.h"
class Calka {
public:
    static double f(double x);
	static double licz_calke(double a, double b, int n);
	static double licz_calke_z_punktow(PUNKT p1, PUNKT p2);
};
#endif // !CALKA
