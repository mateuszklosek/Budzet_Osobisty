#ifndef PLIKXML_H
#define PLIKXML_H

#include <iostream>
#include "Markup.h"

using namespace std;

class PlikXml {


    const string NAZWA_PLIKU;

public:

    CMarkup xml;
    PlikXml(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}
    string pobierzNazwePliku();
};

#endif
