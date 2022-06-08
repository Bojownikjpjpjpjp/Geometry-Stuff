#include<iostream>
#include"PUNKT.h"


    PUNKT::PUNKT(double wx, double wy) {
        this->x = wx;
        this->y = wy;
    };

    PUNKT::PUNKT() {
        this->x = 0.0;
        this->y = 0.0;
    };


    void PUNKT::wypisz() {
        std::cout << "\nx = " << this->x;
        std::cout << "\ny = " << this->y;
    }
    //odbicia wzglêdem osi i pocz¹tku uk³adu
    void PUNKT::odbicie_ox() {
        this->y = -(this->y);
    }
    void PUNKT::odbicie_oy() {
        this->x = -(this->x);
    }
    void PUNKT::odbicie_oo() {
        this->y = -(this->y);
        this->x = -(this->x);
    }
    void PUNKT::set(PUNKT p){
        this->x = p.x;
        this->y = p.y;
    }
    bool PUNKT::operator==(PUNKT& p2) {
        if (this->x == p2.x) {
            if (this->y == p2.y) {
                return true;
            }
        }
        return false;
    }
