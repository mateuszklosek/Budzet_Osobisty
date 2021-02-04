#ifndef PLIKZPRZYCHODAMI_H
#define PLIKZPRZYCHODAMI_H

#include "PlikXml.h"
#include "Przychod.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

class PlikZPrzychodami : public PlikXml {
private:

int idOstatniegoPrzychodu;

public:

    PlikZPrzychodami(string nazwaPliku) : PlikXml(nazwaPliku) { idOstatniegoPrzychodu = 0;};

    vector <Przychod> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

    void dopiszPrzychodDoPliku(Przychod przychod);
    int pobierzIdOstatniegoPrzychodu();
    //int pobierzIdOstatniegoPrzychoduZPliku();

};



#endif
