#include "BudzetOsobisty.h"

void BudzetOsobisty::rejestracjaUzytkownika() {
    uzytkownikMenadzer.rejestracjaUzytkownika();
}

void BudzetOsobisty::wypiszWszystkichUzytkownikow() {
    uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}

int BudzetOsobisty::pobierzIdZalogowanegoUzytkownika() {
    uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika();
}

void BudzetOsobisty::wylogowanieUzytkownika() {
    uzytkownikMenadzer.wylogowanieUzytkownika();
    delete budzetMenadzer;
    budzetMenadzer = NULL;
}

int BudzetOsobisty::logowanieUzytkownika() {
    uzytkownikMenadzer.logowanieUzytkownika();
    budzetMenadzer = new BudzetMenadzer (NAZWA_PLIKU_Z_PRZYCHODAMI, NAZWA_PLIKU_Z_WYDATKAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
}
void BudzetOsobisty::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}

void BudzetOsobisty::dodajPrzychod() {
    budzetMenadzer -> dodajPrzychod();
}

void BudzetOsobisty::dodajWydatek() {
    budzetMenadzer -> dodajWydatek();
}


void BudzetOsobisty::wyswietlWszystkiePrzychody() {
    budzetMenadzer -> wyswietlWszystkiePrzychody();
}

int BudzetOsobisty::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    budzetMenadzer -> wczytajPrzychodyZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void BudzetOsobisty::wyswietlIdZalogowanegoUzytkownika(){
cout << pobierzIdZalogowanegoUzytkownika() << endl;
cout << budzetMenadzer -> pobierzIdOstatniegoPrzychodu() << endl;
system("pause");
}

void BudzetOsobisty::bilansZObecnegoMiesiaca(){
budzetMenadzer -> bilansZObecnegoMiesiaca();
}

void BudzetOsobisty::bilansZPoprzedniegoMiesiaca(){
budzetMenadzer -> bilansZPoprzedniegoMiesiaca();
}

void BudzetOsobisty::bilansZWybranegoOkres(){
budzetMenadzer -> bilansZWybranegoOkresu();
}

