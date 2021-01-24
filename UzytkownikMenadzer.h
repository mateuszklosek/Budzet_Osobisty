#ifndef UZYTKOWNIKMENADZER_H
#define UZYTKOWNIKMENADZER_H

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"


using namespace std;

class UzytkownikMenadzer {

int idZalogowanegoUzytkownika;
vector <Uzytkownik> uzytkownicy;

PlikZUzytkownikami plikZUzytkownikami;
MetodyPomocnicze metodyPomocnicze;

Uzytkownik podajDaneNowegoUzytkownika();
int pobierzIdNowegoUzytkownika();
bool czyIstniejeLogin(string login);

public:
    UzytkownikMenadzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int pobierzIdZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
