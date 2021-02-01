#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include "PlikXml.h"
#include "Przychod.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class PlikZPrzychodami : public PlikXml {

public:

    PlikZPrzychodami(string nazwaPliku) : PlikXml(nazwaPliku) {};

    vector <Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

    void dopiszPrzychodDoPliku(Przychod przychod);


    /*
    void rejestracja();
    void wyswietlWszystkichUzytkownikow();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszNoweHasloDoPliku(string noweHaslo, int idZalogowanegoUzytkownika);*/
};



#endif
