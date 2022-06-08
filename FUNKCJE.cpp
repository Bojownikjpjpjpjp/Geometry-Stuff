#include<math.h>
#include<iostream>

#include"FUNKCJE.h"
#include "PUNKT.h"
#include "LINIA.h"


bool czy_calkowita(double a) {//zaokragla w gore i w dol i porownuje zaokraglenia. zwraca true jesli sa rowne
    double a_min = floor(a);
    double a_max = ceil(a);
    if (a_min == a_max) {
        return true;
    }
    else {
        return false;
    }
}

bool czy_ujemna(double a) {//zwraca true dla liczby ujemnej i false dla dodatniej lub rownej 0
    if (a < 0) { return true; }
    else { return false; }
}

void sprawdz_podwojne_zero(double &wart) {
    if (wart == -0.0) {
        wart = 0.0;
    }
}
//konstruktor struktury linia przelicza wspó³czynniki.
void policz_i_wstaw_wspolczynniki_prostej(PUNKT p1, PUNKT p2, double* tab) {
    LINIA funkcja = LINIA(p1, p2);
    tab[0] = funkcja.A;
    tab[1] = funkcja.B;
    tab[2] = funkcja.C;
}
#pragma region wzajemne_po³o¿enie_punktu_i_prostej
void z_ktorej_strony_prostej(LINIA prosta, PUNKT p3) {
    double suma = prosta.A * p3.x + prosta.B * p3.y + prosta.C;
    if (suma == 0) { std::cout << "\npunkt lezy na prostej"; }
    if (suma < 0) { std::cout << "\npunkt lezy po lewej stronie prostej"; }
    if (suma > 0) { std::cout << "\npunkt lezy po prawej stronie prostej"; }
    std::cout << "\n  przy liczeniu: " << suma << "\n";
}
bool z_lewej_strony_prostej_input_linia(LINIA prosta, PUNKT p3) {
    double suma = prosta.A * p3.x + prosta.B * p3.y + prosta.C;
    //d::cout << "\n  przy liczeniu: " << suma << "\n";
    if (suma == 0) { std::cout << "\npunkt lezy na prostej"; return true; }
    else if (suma < 0) { std::cout << "\npunkt lezy po lewej stronie prostej"; return true; }
    else { std::cout << "\npunkt lezy po prawej stronie prostej"; return false; }
}



bool z_lewej_strony_prostej_input_tablica(double* tab, PUNKT p3) {
    double suma = tab[0] * p3.x + tab[1] * p3.y + tab[2];
    //d::cout << "\n  przy liczeniu: " << suma << "\n";
    if (suma == 0) { std::cout << "\npunkt lezy na prostej"; return true; }
    else if (suma < 0) { std::cout << "\npunkt lezy po lewej stronie prostej"; return true; }
    else { std::cout << "\npunkt lezy po prawej stronie prostej"; return false; }
}
bool z_prawej_strony_prostej_input_linia(LINIA prosta, PUNKT p3) {
    double suma = prosta.A * p3.x + prosta.B * p3.y + prosta.C;
    //d::cout << "\n  przy liczeniu: " << suma << "\n";
    if (suma == 0) { std::cout << "\npunkt lezy na prostej"; return true; }
    else if (suma < 0) { std::cout << "\npunkt lezy po lewej stronie prostej"; return false; }
    else { std::cout << "\npunkt lezy po prawej stronie prostej"; return true; }
}
bool z_prawej_strony_prostej_input_tablica(double* tab, PUNKT p3) {
    double suma = tab[0] * p3.x + tab[1] * p3.y + tab[2];
    //d::cout << "\n  przy liczeniu: " << suma << "\n";
    if (suma == 0) { std::cout << "\npunkt lezy na prostej"; return true; }
    else if (suma < 0) { std::cout << "\npunkt lezy po lewej stronie prostej"; return false; }
    else { std::cout << "\npunkt lezy po prawej stronie prostej"; return true; }
}
#pragma endregion

void punkt_przeciecia_prostych_cramer(double a1, double b1, double c1, double a2, double b2, double c2) {
    double w, wx, wy, x, y;
    if (a1 == a2) { std::cout << "\nfunkcje rownolegle"; }
    if (a1 == a2 && b1 == b2) { std::cout << "\nlinie sie pokrywaja"; }
    w = ((a1 * b2) - (b1 * a2));
    wx = ((-c1 * b2) - (b1 * -c2));
    wy = ((a1 * -c2) - (-c1 * a2));
    sprawdz_podwojne_zero(w);
    sprawdz_podwojne_zero(wx);
    sprawdz_podwojne_zero(wy);
    if (w != 0) {
        x = wx / w;
        y = wy / w;
        std::cout << "\n punkt przeciecia: x:" << x << " y:" << y;
    }
    else {
        std::cout << "\n wyznacznik sie wyzerowal, wyrazenie jest bez sensu";
        return;
    }
}
void punkt_przeciecia_lini_cramer(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y) {
    PUNKT p1 = PUNKT(p1x, p1y);
    PUNKT p2 = PUNKT(p2x, p2y);
    PUNKT p3 = PUNKT(p3x, p3y);
    PUNKT p4 = PUNKT(p4x, p4y);
    LINIA linia1 = LINIA(p1, p2);
    LINIA linia2 = LINIA(p3, p4);
    double w, wx, wy, x, y;
    if (linia1.a == linia2.a) { std::cout << "\nfunkcje rownolegle"; }
    if (linia1.a == linia2.a && linia1.b == linia2.b) { std::cout << "\nlinie sie pokrywaja"; }

    w = ((linia1.A * linia2.B) - (linia1.B * linia2.A));
    wx = ((-linia1.C * linia2.B) - (linia1.B * -linia2.C));
    wy = ((linia1.A * -linia2.C) - (-linia1.C * linia2.A));
    sprawdz_podwojne_zero(w);
    sprawdz_podwojne_zero(wx);
    sprawdz_podwojne_zero(wy);
    std::cout << "\nw: " << w << " wx: " << wx << " wy: " << wy;
    if (w != 0) {
        x = wx / w;
        y = wy / w;
        if (x == -0) { x *= -1; }
        std::cout << "\n punkt przeciecia prostych: x:" << x << " y:" << y;
    }
    else {
        std::cout << "\n wyznacznik sie wyzerowal, wyrazenie jest bez sensu\n";
        return;
    }
    /*cout << "\nprosta 1\n";
    linia1.wypisz();
    cout << "\nprosta 2\n";
    linia2.wypisz();*/
    PUNKT punkt_przeciecia = PUNKT(x, y);
    if (czy_w_odcinku(linia1, punkt_przeciecia) && czy_w_odcinku(linia2, punkt_przeciecia)) { std::cout << "\n odcinki przecinaja sie"; }
    else {
        std::cout << "\nodcinki nie przecinaja sie";
    }
}
PUNKT punkt_przeciecia_lini_cramer_zwraca_punkt(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y) {
    PUNKT p1 = PUNKT(p1x, p1y);//wspó³rzêdna w pó³prostej w prawo
    PUNKT p2 = PUNKT(p2x, p2y);//wspó³rzêdna w pó³prostej w lewo
    PUNKT p3 = PUNKT(p3x, p3y);
    PUNKT p4 = PUNKT(p4x, p4y);
    LINIA linia1 = LINIA(p1, p2);
    LINIA linia2 = LINIA(p3, p4);
    PUNKT ERRORPUNKT = PUNKT(666.666, 666.666);
    double w=0;
    double wx=0;
    double wy=0;
    double x=ERRORPUNKT.x;
    double y=ERRORPUNKT.y;
    if (linia1.a == linia2.a) { std::cout << "\nfunkcje rownolegle"; }
    if (linia1.a == linia2.a && linia1.b == linia2.b) { std::cout << "\nlinie sie pokrywaja"; }
 //   p4.wypisz();
//    cout << "\nprosta 1\n";
//linia1.wypisz();
//cout << "\nprosta 2\n";
//linia2.wypisz();
    w = ((linia1.A * linia2.B) - (linia1.B * linia2.A));
    wx = ((-linia1.C * linia2.B) - (linia1.B * -linia2.C));
    wy = ((linia1.A * -linia2.C) - (-linia1.C * linia2.A));
    sprawdz_podwojne_zero(w);
    sprawdz_podwojne_zero(wx);
    sprawdz_podwojne_zero(wy);
    std::cout << "\nw: " << w << " wx: " << wx << " wy: " << wy;
    if (w == INFINITY || wx == INFINITY || wy == INFINITY) {
        if (linia2.a == INFINITY) {
            if (linia1.a != 0 && linia1.a != INFINITY) {
                x = linia2.p2.x;
                y = linia1.a * x;
            }
            else if (linia1.a == 0 || linia1.a == -0) {
                x = linia2.p2.x;
                y = linia1.p1.y;
            }
        }
        //else if (linia1.a == INFINITY) {
        //    if (linia2.a != 0 && linia2.a != INFINITY) {
        //        x = linia1.p2.x;
        //        y = linia2.a * x;
        //    }
        //    else if (linia2.a == 0 || linia2.a == -0) {
        //        x = linia1.p2.x;
        //        y = linia2.p1.y;
        //    }
        //}
        else { 
            return ERRORPUNKT; 
        }
    }
    else if (w == 0) {
        std::cout << "\n wyznacznik sie wyzerowal, wyrazenie jest bez sensu\n";
        return ERRORPUNKT;
    }
    else if (w != 0) {
        x = wx / w;
        y = wy / w;
        if (x == -0) { x = 0; }
        
    }
    sprawdz_podwojne_zero(x);
    sprawdz_podwojne_zero(y);
    std::cout << "\n punkt przeciecia prostych: x:" << x << " y:" << y;

    PUNKT punkt_przeciecia = PUNKT(x, y);
    if (czy_w_odcinku(linia1, punkt_przeciecia) && czy_w_odcinku(linia2, punkt_przeciecia)) {
        //std::cout << "\n odcinki przecinaja sie"; 
    }
    else {
        //std::cout << "\nodcinki nie przecinaja sie";
    }
    return punkt_przeciecia;
}
//funkcja sprawdza ju¿ tylko czy x punktu jest pomiêdzy x1 i x2, bo jeœli le¿y na odcinku to na pewno le¿y na prostej
bool czy_w_odcinku(LINIA prosta, PUNKT p) {
    if (czy_w_prostej(prosta, p)) {
        //nie mam dostêpu do punktu, dla którego sprawdzam, mam tylko prost¹ i punkt, ktry le¿y na prostej sprawdzanej krawêdzi

        if (((prosta.p1.x <= p.x && p.x <= prosta.p2.x) || (prosta.p2.x <= p.x && p.x <= prosta.p1.x)) &&((prosta.p1.y <= p.y && p.y <= prosta.p2.y) || (prosta.p2.y <= p.y && p.y <= prosta.p1.y))) {
            //std::cout << "\npunkt lezy na odcinku";
            return true;
        }
        else {
           // std::cout << "\npunkt nie lezy na odcinku";
            return false;
        }
    }
    else {
        return false;
    }
}

//funkcja liczy czy punkt znajduje siê na prostej
bool czy_w_prostej(LINIA prosta, PUNKT p) {
    if (prosta.a == INFINITY) {
        if (p.x == prosta.A) {
            return true;
        }
    }
    else if (((prosta.a * p.x) + prosta.b) == p.y||(((prosta.A*p.x)+(prosta.B*p.y)+prosta.C)==0)) {
       // std::cout << "\npunkt lezy na prostej";
        return true;
    }
    else {
        //std::cout << "\npunkt nie lezy na prostej";
        return false;
    }
}

double policz_pole_trojkata(PUNKT p1, PUNKT p2, PUNKT p3) {
    PUNKT v1, v2;
    double pole = 0;
    v1 = { (p2.x - p1.x),(p2.y - p1.y) };
    v2 = { (p3.x - p1.x),(p3.y - p1.y) };
    pole += (0.5 * ((v1.x * v2.y) - (v1.y * v2.x)));
    if (pole < 0) { pole *= -1; }
    //std::cout << "\npole = " << pole;
    return pole;
}
bool czy_punkt_w_zbiorze(PUNKT p1, PUNKT* zbior) {
    for (int i = 0; i < sizeof(zbior); i++) {
        if (p1 == zbior[i]) {
            return true;
        }
    }
    return false;
}
double policz_wyznacznik_2_punkty(PUNKT p1, PUNKT p2) {
    return ((p1.x*p2.y)-(p1.y*p2.x));
}
double dlugosc_odcinka(PUNKT p1, PUNKT p2) {
    double x = p2.x - p1.x;
    double y = p2.y - p1.y;
    double dlugosc = sqrt((x * x) + (y * y));
    if (dlugosc < 0) {
        dlugosc *= -1;
    }
    return dlugosc;
}

PUNKT znajdz_najnizszy_punkt_z_tablicy(PUNKT* punkty) {
    double x_min, y_min;
    x_min = punkty[0].x;
    y_min = punkty[0].y;
    PUNKT init_k1;
    for (int i = 0; i <= sizeof(punkty); i++) {
        if (y_min >= punkty[i].y) {
            if (y_min == punkty[i].y) {
                if (x_min >= punkty[i].x) {
                    if (x_min == punkty[i].x) {
                        continue;
                    }
                    x_min = punkty[i].x;
                    continue;
                }
                continue;
            }
            x_min = punkty[i].x;
            y_min = punkty[i].y;
            continue;
        }
    }
    init_k1.x = x_min;
    init_k1.y = y_min;
    return init_k1;
}
PUNKT znajdz_najwyzszy_punkt_z_tablicy(PUNKT* punkty) {
    double x_max, y_max;
    PUNKT init_k2;
    x_max = punkty[0].x;
    y_max = punkty[0].y;
    for (int i = 0; i <= sizeof(punkty); i++) {
        if (y_max <= punkty[i].y) {
            if (y_max == punkty[i].y) {
                if (x_max <= punkty[i].x) {
                    if (x_max == punkty[i].x) {
                        continue;
                    }
                    x_max = punkty[i].x;
                    continue;
                }
                continue;
            }
            x_max = punkty[i].x;
            y_max = punkty[i].y;
            continue;
        }
    }

    init_k2.x = x_max;
    init_k2.y = y_max;
    return init_k2;
}
