#ifndef BUDZETMENADZER_H
#define BUDZETMENADZER_H

#include "Uzytkownik.h"
#include "PlikZPrzychodami.h"
#include "MetodyPomocnicze.h"
#include "Przychod.h"
#include <bits/stdc++.h>
#include <algorithm>


using namespace std;

class BudzetMenadzer {

    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Przychod> przychody;
    Przychod przychod;
    PlikZPrzychodami plikZPrzychodami;
    MetodyPomocnicze metodyPomocnicze;



public:
    BudzetMenadzer(string nazwaPlikuZPrzychodami, int idZalogowanegoUzytkownika) : plikZPrzychodami(nazwaPlikuZPrzychodami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        przychody = plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
void dodajPrzychod();
Przychod podajDaneNowegoPrzychodu();
void wyswietlWszystkiePrzychody();
void wyswietlPrzychod(int i);
int wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
//bool sortuj(const Przychod& przychod1,const Przychod& przychod2);
void sortujPrzychody();

struct Porownanie{
bool operator()(Przychod przychod1, Przychod przychod2)
{if(przychod1.getDate() < przychod2.getDate())
{
    return true;
}
else{
    return false;
}
}
}porownanieDat;
};


#endif

/*
   AdresatMenadzer(int idZalogowanegoUzytkownika) : ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }; */
