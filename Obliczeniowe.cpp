#include <iostream>
#include <math.h>
#include <time.h>
#include <cstdlib>

#include"FUNKCJE.h"
#include"PUNKT.h"
#include"LINIA.h"
#include"WIELOKAT.h"

using namespace std;

PUNKT losuj_punkt() {
    double dz = 18000.3;
    PUNKT temp = PUNKT((rand() - 16383) / dz, (rand() - 16383) / dz);
        return temp;
}
LINIA generuj_linie_z_2_punktow(PUNKT p1, PUNKT p2) {
    LINIA linia = LINIA(p1, p2);
    return linia;
}
LINIA generuj_linie_z_2_losowych_punktow() {
    LINIA linia = LINIA(losuj_punkt(), losuj_punkt());
    return linia;
}
LINIA generuj_prosta_z_lini(LINIA linia_1) {
    LINIA prosta = LINIA();
    prosta.PROSTA(linia_1.a, linia_1.b, linia_1.A, linia_1.B, linia_1.C);
    return prosta;
}
bool czy_w_trojkacie(PUNKT w1, PUNKT w2, PUNKT w3, PUNKT p) {
    //double tab[3];
    //int counter = 0;
    double suma = 0;
    suma += policz_pole_trojkata(w1, w2, p);
    suma += policz_pole_trojkata(w2, w3, p);
    suma += policz_pole_trojkata(w3, w1, p);
    //policz_i_wstaw_wspolczynniki_prostej(w1, w2, tab);
    //if (z_lewej_strony_prostej_input_tablica(tab, p)) { counter++; };
    //policz_i_wstaw_wspolczynniki_prostej(w2, w3, tab);
    //if (z_lewej_strony_prostej_input_tablica(tab, p)) { counter++; };
    //policz_i_wstaw_wspolczynniki_prostej(w3, w1, tab);
    //if (z_lewej_strony_prostej_input_tablica(tab, p)) { counter++; };
    //
    cout << "\nsuma= " << suma;
    if (round(1000000*suma) ==round(1000000*policz_pole_trojkata(w1,w2,w3))) { return true; }

    return false;
}
void solve()
{
    srand(time(NULL));
    //poniżej sztywne punkty i linie
        /*
    PUNKT punkt1 = PUNKT( 4, 3 );
    PUNKT punkt2 = PUNKT( 2, 6 );
    PUNKT punkt3 = PUNKT( 8, 9 );
    PUNKT punkt4 = PUNKT( 0, 9 );
    PUNKT punkt5 = PUNKT( 3, 4.5 );
    LINIA linia1 = LINIA( punkt1, punkt2 );
    LINIA linia2 = LINIA( punkt2, punkt3 );
    LINIA linia3 = LINIA( punkt3, punkt1 );
    */
    //poniżej testy funkcji
    /*
    cout << "\n linia 1";
    linia1.wypisz();
    cout << "\n linia 2";
    linia2.wypisz();
    cout << "\n linia 3";
    linia3.wypisz();

    cout << "\n\n translacja  linii 1 o wektor [4,5]";
    linia1.translacja_o_wektor(4, 5);
    linia1.wypisz();
    cout << "\n";
    czy_w_prostej(linia1, punkt2);
    czy_w_odcinku(linia1, punkt4);
    czy_w_odcinku(linia1, punkt5);
    linia3.rotacja_p2_wzgledem_p1(2);


    z_ktorej_strony_prostej(linia1, punkt3);
    z_ktorej_strony_prostej(linia2, punkt3);
    z_ktorej_strony_prostej(linia3, punkt3);
    punkt_przeciecia_prostych_cramer(linia1.A, linia1.B, linia1.C, linia2.A,linia2.B, linia2.C);

    punkt_przeciecia_lini_cramer(1, 2, 4, 5, 2, 1, -3, 8);
    punkt_przeciecia_lini_cramer(1, 2, 4, 8, 0, 0, 2, 4);
    punkt_przeciecia_lini_cramer(-1, -2, 8, 16, -1, 0.5, 6, -3);



    cout<<"\n pole trojkata z punktow 2, 3, 4: "<<policz_pole_trojkata(punkt2, punkt3, punkt4);
    cout<<"\n pole trojkata z punktow 3, 4, 2: "<<policz_pole_trojkata(punkt3, punkt4, punkt2);
    cout<<"\n pole trojkata z punktow 4, 2, 3: "<<policz_pole_trojkata(punkt4, punkt2, punkt3);
    */
   

    /*
    PUNKT punkt_testowy = losuj_punkt();
    PUNKT p1 = losuj_punkt();
    PUNKT p2 = losuj_punkt();

    z_ktorej_strony_prostej(generuj_linie_z_2_punktow(p1,p2), punkt_testowy);


    punkt_testowy.wypisz();
    p1.wypisz();
    p2.wypisz();
    generuj_linie_z_2_punktow(p1, p2).wypisz();
    generuj_prosta_z_lini(generuj_linie_z_2_punktow(p1, p2)).wypisz();
    //for (int i = 0; i < 40; i++) {
    //    cout << rand() / 2000.0 << " ";
    //}
    */
}

