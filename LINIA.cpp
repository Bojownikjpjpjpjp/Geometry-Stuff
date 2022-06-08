#include<iostream>
#include"LINIA.h"
#include"PUNKT.h"
#include"FUNKCJE.h"
void LINIA::kolejnosc() {
    if (this->p1.x > this->p2.x) {
        double temp_x, temp_y;
        temp_x = this->p1.x;
        temp_y = this->p1.y;
        this->p1 = this->p2;
        this->p2.x = temp_x;
        this->p2.y = temp_y;
    }
}
//dwie funkcje przeliczajace wzrór prostej

void LINIA::policz_a() {
    if (p1.x == p2.x) {
        a = INFINITY;
        return;
    }
    this->a = (this->p1.y - this->p2.y) / (this->p1.x - this->p2.x);
}
void LINIA::policz_b() {
    if (this->a != INFINITY) {
        this->b = (this->p1.y - (this->a * this->p1.x));
    }  
}
void LINIA::policz_B() {
    this->B = 1;
}
void LINIA::policz_A() {
    if (this->a == INFINITY) {
        this->A = this->p1.x;
    }
    this->A = -1 * a;
}
void LINIA::policz_C() {
    this->C = (this->b * -1);
}
//void LINIA::policz_odwrotnosc_a() {
//
//    if (a == 0) { odwrotnosc_a = 0; }
//
//    if (czy_calkowita(a)) { return; }
//    //powinno dzia³aæ dla 0<a<1
//    if (czy_ujemna(a)) { odwrotnosc_a = 1 / -a; }
//    else { odwrotnosc_a = 1 / a; }
//}

//konstruktor od razu przelciza prost¹
LINIA::LINIA(PUNKT punkt1, PUNKT punkt2) {
    this->p1 = punkt1;
    this->p2 = punkt2;
    przelicz_linie();
};
LINIA::LINIA() {
    this->p1 = PUNKT();
    this->p2 = PUNKT();
    przelicz_linie();
};
void LINIA::PROSTA(double a, double b, double A, double B, double C) {
    this->a = a;
    this->b = b;
    this->A = A;
    this->B = B;
    this->C = C;

    if (a == 0.0) {
        this->p1.x = -1.0;
        this->p2.x = 1.0;
        this->p1.y = b;
        this->p2.y = b;
    }
    else if (a == INFINITY) {
        this->p1.y = 1.0;
        this->p2.y = -1.0;
        this->B = 0;
        this->p1.x = C;
        this->p2.x = C;
    }
    else {
        this->p1.x = -1.0;
        this->p2.x = 1.0;
        this->p1.y = (a * this->p1.x) + b;
        this->p2.y = (a * this->p2.x) + b;
    }
}
void LINIA::przelicz_linie() {
    kolejnosc();
    policz_a();
    policz_b();
    //policz_odwrotnosc_a();
    policz_A();
    policz_B();
    policz_C();
}

//nachylenie pozostanie bez zmian, zmieni siê b
void LINIA::translacja_o_wektor(int vx, int vy) {
    this->p1.x += vx;
    this->p2.x += vx;
    this->p1.y += vy;
    this->p2.y += vy;
    policz_b();
}
//wzór na rotacje jest wyprowadzony wzglêdem punktu 00, wiêc najpierw jest "uzyskanie podobnych warunków", póŸniej rotacja, a póŸnej powrót do punktu wyjœcia
void LINIA::rotacja_p2_wzgledem_p1(double kat) {
    kat = kat * 3.14 / 180;
    double x_wzgl = this->p2.x - this->p1.x;
    double y_wzgl = this->p2.y - this->p1.y;
    this->p2.x = x_wzgl * cos(kat) - y_wzgl * sin(kat);
    this->p2.y = y_wzgl * cos(kat) + x_wzgl * sin(kat);
    x_wzgl = this->p2.x + this->p1.x;
    y_wzgl = this->p2.y + this->p1.y;
    kolejnosc();
    policz_a();
    policz_b();
    wypisz();
}
void LINIA::wypisz() {
    std::cout << "\npunkty prostej:";
    std::cout << "\np1 : "; this->p1.wypisz();
    std::cout << "\np2 : "; this->p2.wypisz();
    std::cout << "\n parametry prostej: ";
    std::cout << "\na : " << this->a;
    std::cout << "\nb : " << this->b;
    std::cout << "\nA : " << this->A;
    std::cout << "\nB : " << this->B;
    std::cout << "\nC : " << this->C;
}