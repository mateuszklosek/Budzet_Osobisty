#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include "PlikXml.h"
#include "Uzytkownik.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

class PlikZUzytkownikami : public PlikXml {

    //CMarkup xml;

public:

    PlikZUzytkownikami(string nazwaPliku) : PlikXml(nazwaPliku) {};

    void rejestracja();
    void wyswietlWszystkichUzytkownikow();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszNoweHasloDoPliku(string noweHaslo, int idZalogowanegoUzytkownika);
};



#endif
