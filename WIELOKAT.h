#ifndef WIELOKAT_CLASS_H
#define WIELOKAT_CLASS_H

#include"PUNKT.h"
#include"LINIA.h"

class WIELOKAT {
public:
    int ilosc_wierzcholkow = 1;
    PUNKT* punkty = new PUNKT[1000];
    LINIA* krawedzie = new LINIA[1000];
    WIELOKAT(int ilosc_wierzcholkow, PUNKT punkty[]);
    WIELOKAT(int ilosc_wierzcholkow);
    WIELOKAT();
    void generuj_krawedzie();
    double licz_pole_wielokata();

    bool czy_punkt_w_wielokacie(PUNKT punkt);
    static WIELOKAT generuj_otoczke_z_chmury(PUNKT punkty[]);
};


#endif


