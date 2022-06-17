#include<iostream>
#include<math.h>
#include"LINIA.h"
#include"PUNKT.h"
#include"WIELOKAT.h"
#include"FUNKCJE.h"
#include"Obliczeniowe.h"
#include"Calka.h"

WIELOKAT::WIELOKAT(int ilosc_wierzcholkow, PUNKT punkty[]) {
	this->ilosc_wierzcholkow = ilosc_wierzcholkow;
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		this->punkty[i] = punkty[i];
	}	
	for (int i = 0; i < ilosc_wierzcholkow; i++) {
		
		if (i == ilosc_wierzcholkow - 1) {
			//std::cout << "\ninput: " << i << " punkty: ";
			//std::cout << "\nPi: x: " << punkty[i].x << " y: " << punkty[i].y;
			//std::cout << "\nP0: x: " << punkty[0].x << " y: " << punkty[0].y;

			this->krawedzie[i] = generuj_linie_z_2_punktow(this->punkty[i], this->punkty[0]);
			//this->krawedzie[i].wypisz();

		}
		else {
		this->krawedzie[i] = generuj_linie_z_2_punktow(this->punkty[i], this->punkty[i + 1]);
		}
	}
}
WIELOKAT::WIELOKAT(int ilosc_wierzcholkow) {
	this->ilosc_wierzcholkow = ilosc_wierzcholkow;
}
WIELOKAT::WIELOKAT() {

}
void WIELOKAT::generuj_krawedzie() {
	for (int i = 0; i < sizeof(ilosc_wierzcholkow); i++) {

		if (i == sizeof(ilosc_wierzcholkow) - 1) {
			//std::cout << "\ninput: " << i << " punkty: ";
			//std::cout << "\nPi: x: " << punkty[i].x << " y: " << punkty[i].y;
			//std::cout << "\nP0: x: " << punkty[0].x << " y: " << punkty[0].y;

			this->krawedzie[i] = generuj_linie_z_2_punktow(this->punkty[i], this->punkty[0]);
			//this->krawedzie[i].wypisz();

		}
		else {
			this->krawedzie[i] = generuj_linie_z_2_punktow(this->punkty[i], this->punkty[i + 1]);
		}
	}
}
//pole nie skoñczone
double WIELOKAT::licz_pole_wielokata() {
	for (int i = 0; i < this->ilosc_wierzcholkow; i++) {
		if (i == this->ilosc_wierzcholkow - 1) {

		}

	}
	return 0;
}
bool WIELOKAT::czy_punkt_w_wielokacie(PUNKT p) {
	int licznik_przeciec_w_lewo = 0;
	double big = 10.0e250;
	PUNKT tmp_w_lewo, punkt_tmp;
	PUNKT tmp_lewa_polprostej = PUNKT(-1, p.y);

	punkt_tmp = punkt_przeciecia_lini_cramer_zwraca_punkt(tmp_lewa_polprostej.x, tmp_lewa_polprostej.y, p.x, p.y, this->krawedzie[this->ilosc_wierzcholkow - 1].p1.x, this->krawedzie[this->ilosc_wierzcholkow - 1].p1.y, this->krawedzie[this->ilosc_wierzcholkow - 1].p2.x, this->krawedzie[this->ilosc_wierzcholkow - 1].p2.y);

	for (int i = 0; i < this->ilosc_wierzcholkow; i++) {
		//std::cout << "\ni iteracji przed cramerem : " << i;
		//std::cout << "\n drugi punkt krawedzi:";
		//this->krawedzie[i].p2.wypisz();
		tmp_w_lewo = punkt_przeciecia_lini_cramer_zwraca_punkt(tmp_lewa_polprostej.x, tmp_lewa_polprostej.y, p.x, p.y, this->krawedzie[i].p1.x, this->krawedzie[i].p1.y, this->krawedzie[i].p2.x, this->krawedzie[i].p2.y);
		//if b³êdu
		if (tmp_w_lewo.x == 666.666) {
			std::cout << "\n ktorys wyznacznik jest bez sensu, cos poszlo nie tak, zwrocono ERRORPUNKT";
			return false;
		}
		sprawdz_podwojne_zero(tmp_w_lewo.x);
		sprawdz_podwojne_zero(tmp_w_lewo.y);
		sprawdz_podwojne_zero(punkt_tmp.x);
		sprawdz_podwojne_zero(punkt_tmp.y);
		//if sprawdzenia czy punkt przecina odcinek

		if (czy_w_odcinku(this->krawedzie[i], tmp_w_lewo) && czy_w_odcinku(generuj_linie_z_2_punktow(tmp_lewa_polprostej, p), tmp_w_lewo)) {
			licznik_przeciec_w_lewo++;
			//floor(big *punkt_tmp.y) == floor(big *tmp_w_lewo.y) && 
			if ((floor(big * punkt_tmp.y) == floor(big * tmp_w_lewo.y)) &&
				(floor(big * punkt_tmp.x) == floor(big * tmp_w_lewo.x))) {
				licznik_przeciec_w_lewo--;
			}
		}

		punkt_tmp.x = tmp_w_lewo.x;
		punkt_tmp.y = tmp_w_lewo.y;


		std::cout << "\n licznik w lewo: " << licznik_przeciec_w_lewo;
		std::cout << "\nobrot : " << i;
	}


	std::cout << "\n\n licznik w lewo: " << licznik_przeciec_w_lewo;
	if (licznik_przeciec_w_lewo % 2 == 1) {
		std::cout << "\npunkt w wielokacie";
		return true;
	}
	else if (licznik_przeciec_w_lewo % 2 == 0) {
		std::cout << "\npunkt poza wielokatem";
		return false;
	}
	else {
		return false;
	}
}

WIELOKAT WIELOKAT::generuj_otoczke_z_chmury(PUNKT punkty[]) {
	double x_min, y_min;
	double x_max, y_max;
	int indeks_otoczki = 1;
	PUNKT* wierzcholki = new PUNKT[10];
	PUNKT* wierzcholki_otoczki = new PUNKT[10];

	PUNKT init_k1 = znajdz_najnizszy_punkt_z_tablicy(punkty);
	PUNKT init_k2 = znajdz_najwyzszy_punkt_z_tablicy(punkty);
	PUNKT init_tmp = init_k1;
	//wyszukiwanie w górê
	wierzcholki_otoczki[0] = init_k1;
	wierzcholki[0] = init_k1;

	int licznik_kolejnego_punktu = 0;
	int kolejny_punkt = 0;
	double alfa_min = 100;
	double kat = 0;
	PUNKT koniec_lini = PUNKT(1, init_k1.y);
	//szukanie najmniejszego kata i przypisywanie punktu do otoczki
	for (int ii = 0; ii < 10; ii++) {
		//porownywanie kata
			licznik_kolejnego_punktu = 0;
			for (int i = 0; i < 10 - indeks_otoczki; i++) {
				if (licznik_kolejnego_punktu == 5){//je¿eli przez kilka obrotów pêtli nie znajdzie siê inny punkt ni¿ initk2 to przerywa pêtlê
					if (punkty[kolejny_punkt] == init_k2) {
						break;
					}
				}
				if (czy_punkt_w_zbiorze(punkty[i], wierzcholki)) {
					continue;
				}
				else {
					kat = asin((2 * policz_pole_trojkata_z_ujemnym_wynikiem(init_tmp, koniec_lini, punkty[i])) / (dlugosc_odcinka(init_tmp, koniec_lini) * dlugosc_odcinka(init_tmp, punkty[i])));
					if (alfa_min > kat) {
						alfa_min = kat;
						kolejny_punkt = i;
						licznik_kolejnego_punktu++;
					}
				}
			}
		
		//dopisanie punktu do punktów otoczki, przesuniêcie pionowej linii na nowy y
		if (czy_punkt_w_zbiorze(punkty[kolejny_punkt], wierzcholki)) {
			continue;
		}
		if (punkty[kolejny_punkt] == init_k2) {
			wierzcholki_otoczki[indeks_otoczki] = punkty[kolejny_punkt];
			wierzcholki[indeks_otoczki] = punkty[kolejny_punkt];
			init_tmp = punkty[kolejny_punkt];
			koniec_lini.y = init_tmp.y;
			alfa_min = 100;
			indeks_otoczki++;
			std::cout << "przerwalo w gore, osiagnelo init_k2";
			std::cout << "\notoczka od gory\n";
			for (int i = 0; i < 10; i++) {
				wierzcholki_otoczki[i].wypisz();
			}
			break;
		}
		wierzcholki_otoczki[indeks_otoczki] = punkty[kolejny_punkt];
		wierzcholki[indeks_otoczki] = punkty[kolejny_punkt];
		init_tmp = punkty[kolejny_punkt];
		koniec_lini.y = init_tmp.y;

		indeks_otoczki++;
		alfa_min = 100;
	}	
	//szukanie najmniejszego kata i przypisywanie punktu do otoczki z góry
	alfa_min = 100;
	init_tmp = init_k2;
	koniec_lini.x = 0;
	koniec_lini.y = init_k2.y;
	for (int ii = 0; ii < 10; ii++) {
		for (int i = 0; i < 10-indeks_otoczki; i++) {
			if ((punkty[i].x == init_k1.x && punkty[i].y == init_k1.y)) {
				kat = asin((2 * policz_pole_trojkata_z_ujemnym_wynikiem(init_tmp, koniec_lini, punkty[i])) / (dlugosc_odcinka(init_tmp, koniec_lini)* dlugosc_odcinka(init_tmp, punkty[i])));
				if (alfa_min > kat) {
					alfa_min = kat;
					kolejny_punkt = i;
				}
				continue;
			}
			if (czy_punkt_w_zbiorze(punkty[i], wierzcholki)) {
				continue;
			}
			kat = asin((2* policz_pole_trojkata_z_ujemnym_wynikiem(init_tmp, koniec_lini, punkty[i])) / (dlugosc_odcinka(init_tmp, koniec_lini) * dlugosc_odcinka(init_tmp, punkty[i])));
			if (alfa_min > kat) {
				alfa_min = kat;
				kolejny_punkt = i;
			}
		}
		//dopisanie punktu do punktów otoczki, przesuniêcie pionowej linii na nowy y

		if (punkty[kolejny_punkt] == init_k1) {
			std::cout << "przerwalo w dol, osiagnelo init_k1";
			std::cout << "\n otoczka z dolem";
			for (int i = 0; i < 10; i++) {
				wierzcholki_otoczki[i].wypisz();
			}
			break;
		}
		if (czy_punkt_w_zbiorze(punkty[kolejny_punkt], wierzcholki)) {
			continue;
		}
		wierzcholki_otoczki[indeks_otoczki] = punkty[kolejny_punkt];
		wierzcholki[indeks_otoczki] = punkty[kolejny_punkt];
		init_tmp = punkty[kolejny_punkt];
		koniec_lini.y = init_tmp.y;

		indeks_otoczki++;
		alfa_min = 100;
	}
	std::cout << "\n cala otoczka\n";
	for (int i = 0; i < 10; i++) {
		wierzcholki_otoczki[i].wypisz();
	}

	WIELOKAT otoczka(10, wierzcholki_otoczki);
	
	return otoczka;
}