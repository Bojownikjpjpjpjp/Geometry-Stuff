#ifndef LINIA_CLASS_H
#define LINIA_CLASS_H

#include"PUNKT.h"

class LINIA {
public:
    PUNKT p1, p2;
    double a, b, A, B, C;
    double odwrotnosc_a = 1;
    double odwrotnosc_b = 1;
    void kolejnosc();
    //dwie funkcje przeliczajace wzr�r prostej

    void policz_a();
    void policz_b();
    void policz_B();
    void policz_A();

    void policz_C();
    void policz_odwrotnosc_a();
    //konstruktor od razu przelciza prost�
    LINIA(PUNKT punkt1, PUNKT punkt2);
    void PROSTA(double a, double b, double A, double B, double C);
    void przelicz_linie();
    LINIA();
    //nachylenie pozostanie bez zmian, zmieni si� b
    void translacja_o_wektor(int vx, int vy);
    //wz�r na rotacje jest wyprowadzony wzgl�dem punktu 00, wi�c najpierw jest "uzyskanie podobnych warunk�w", p�niej rotacja, a p�nej powr�t do punktu wyj�cia
    void rotacja_p2_wzgledem_p1(double kat);
    void wypisz();


};
#endif


