#ifndef PLIKZWYDATKAMI_H
#define PLIKZWYDATKAMI_H

#include "PlikXml.h"
#include "Wydatek.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class PlikZWydatkami : public PlikXml {
private:

int idOstatniegoWydatku;

public:

    PlikZWydatkami(string nazwaPliku) : PlikXml(nazwaPliku) { idOstatniegoWydatku = 0;};

    vector <Wydatek> wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

    void dopiszWydatekDoPliku(Wydatek Wydatek);
    int pobierzIdOstatniegoWydatku();


};



#endif
