#ifndef PUNKT_CLASS_H
#define PUNKT_CLASS_H



class PUNKT {
public:
    double x, y;
    PUNKT(double wx, double wy);
    PUNKT();
    void set(PUNKT p);

    bool operator ==(PUNKT& p2);

    void wypisz();
    //odbicia wzglêdem osi i pocz¹tku uk³adu
    void odbicie_ox();
    void odbicie_oy();
    void odbicie_oo();

};
#endif

