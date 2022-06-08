#ifndef FUNKCJE_H
#define FUNKCJE_H

#include"PUNKT.h"
#include"LINIA.h"


using namespace std;
bool czy_calkowita(double a);//zaokragla w gore i w dol i porownuje zaokraglenia. zwraca true jesli sa 
bool czy_ujemna(double a);//zwraca true dla liczby ujemnej i false dla dodatniej lub rownej 0
void policz_i_wstaw_wspolczynniki_prostej(PUNKT p1, PUNKT p2, double* tab);

//liczenie punktu przeciêcia prostyh. input wspó³czynniki A1,B1,C1,A2,B2,C3 
void punkt_przeciecia_prostych_cramer(double a1, double b1, double c1, double a2, double b2, double c2);
//liczenie punktu przeciêcia odcinków. input 8 wspó³rzêdnych punktów, pary xy
void punkt_przeciecia_lini_cramer(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y);
//zwracaj¹cy punkt cramer
PUNKT punkt_przeciecia_lini_cramer_zwraca_punkt(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y);
//funkcja sprawdza ju¿ tylko czy x punktu jest pomiêdzy x1 i x2, bo jeœli le¿y na prostej to na pewno le¿y na odcinku
bool czy_w_odcinku(LINIA prosta, PUNKT p);
//funkcja liczy czy punkt znajduje siê na prostej
bool czy_w_prostej(LINIA prosta, PUNKT p);

void sprawdz_podwojne_zero(double &wart);

void z_ktorej_strony_prostej(LINIA prosta, PUNKT p3);
bool z_lewej_strony_prostej_input_linia(LINIA prosta, PUNKT p3);
bool z_lewej_strony_prostej_input_tablica(double* tab, PUNKT p3);
bool z_prawej_strony_prostej_input_linia(LINIA prosta, PUNKT p3);
bool z_prawej_strony_prostej_input_tablica(double* tab, PUNKT p3);

double policz_pole_trojkata(PUNKT p1, PUNKT p2, PUNKT p3);
double policz_wyznacznik_2_punkty(PUNKT p1, PUNKT p2);
double kat_miedzy_liniami(LINIA l1, LINIA l2);
double dlugosc_odcinka(PUNKT p1, PUNKT p2);
bool czy_punkt_w_zbiorze(PUNKT p1, PUNKT* zbior);

PUNKT znajdz_najnizszy_punkt_z_tablicy(PUNKT* punkty);
PUNKT znajdz_najwyzszy_punkt_z_tablicy(PUNKT* punkty);
#endif

