#ifndef BUDZETMENADZER_H
#define BUDZETMENADZER_H

#include "Uzytkownik.h"
#include "PlikZPrzychodami.h"
#include "PlikZWydatkami.h"
#include "MetodyPomocnicze.h"
#include "Przychod.h"
#include "Wydatek.h"
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

class BudzetMenadzer {

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Przychod> przychody;
    vector <Wydatek> wydatki;
    Przychod przychod;
    Wydatek wydatek;
    PlikZPrzychodami plikZPrzychodami;
    PlikZWydatkami plikZWydatkami;
    MetodyPomocnicze metodyPomocnicze;



public:
    BudzetMenadzer(string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami ,int idZalogowanegoUzytkownika) : plikZPrzychodami(nazwaPlikuZPrzychodami), plikZWydatkami(nazwaPlikuZWydatkami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        przychody = plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        wydatki = plikZWydatkami.wczytajWydatkiZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        sortujPrzychody();
        sortujWydatki();
    };
void dodajPrzychod();
Przychod podajDaneNowegoPrzychodu();
void wyswietlWszystkiePrzychody();
void wyswietlPrzychod(int i);
int wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
void sortujPrzychody();
int pobierzIdOstatniegoPrzychodu();
void bilansZObecnegoMiesiaca();
void bilansZPoprzedniegoMiesiaca();
void bilansZWybranegoOkresu();
void dodajWydatek();
Wydatek podajDaneNowegoWydatku();
void wyswietlWydatek(int i);
int wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
void sortujWydatki();


struct PorownaniePrzychodow{
bool operator()(Przychod przychod1, Przychod przychod2)
{if(przychod1.getDate() < przychod2.getDate())
{
    return true;
}
else{
    return false;
}
}
}porownanieDatPrzychodow;


struct PorownanieWydatkow{
bool operator()(Wydatek wydatek1, Wydatek wydatek2)
{if(wydatek1.getDate() < wydatek2.getDate())
{
    return true;
}
else{
    return false;
}
}
}porownanieDatWydatkow;


};


#endif

