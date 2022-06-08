#ifndef OBLICZENIOWE_H
#define OBLICZENIOWE_H

#include"PUNKT.h"
#include"LINIA.h"
#include"FUNKCJE.h"
void solve();

PUNKT losuj_punkt();
LINIA generuj_prosta_z_lini(LINIA linia_1);
LINIA generuj_linie_z_2_punktow(PUNKT p1, PUNKT p2);
LINIA generuj_linie_z_2_losowych_punktow();
LINIA generuj_prosta_z_lini(LINIA linia_1);
bool czy_w_trojkacie(PUNKT w1, PUNKT w2, PUNKT w3, PUNKT p);
#endif

