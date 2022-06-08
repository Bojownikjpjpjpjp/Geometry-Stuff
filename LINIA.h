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
    //dwie funkcje przeliczajace wzrór prostej

    void policz_a();
    void policz_b();
    void policz_B();
    void policz_A();

    void policz_C();
    void policz_odwrotnosc_a();
    //konstruktor od razu przelciza prost¹
    LINIA(PUNKT punkt1, PUNKT punkt2);
    void PROSTA(double a, double b, double A, double B, double C);
    void przelicz_linie();
    LINIA();
    //nachylenie pozostanie bez zmian, zmieni siê b
    void translacja_o_wektor(int vx, int vy);
    //wzór na rotacje jest wyprowadzony wzglêdem punktu 00, wiêc najpierw jest "uzyskanie podobnych warunków", póŸniej rotacja, a póŸnej powrót do punktu wyjœcia
    void rotacja_p2_wzgledem_p1(double kat);
    void wypisz();


};
#endif


