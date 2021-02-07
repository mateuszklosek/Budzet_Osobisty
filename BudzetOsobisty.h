#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"
#include "BudzetMenadzer.h"

using namespace std;

class BudzetOsobisty {
    UzytkownikMenadzer uzytkownikMenadzer;

    BudzetMenadzer *budzetMenadzer;
    MetodyPomocnicze metodyPomocnicze;
    const string NAZWA_PLIKU_Z_PRZYCHODAMI;
    const string NAZWA_PLIKU_Z_WYDATKAMI;

public:
    BudzetOsobisty(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami, string nazwaPlikuZWydatkami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami), NAZWA_PLIKU_Z_WYDATKAMI(nazwaPlikuZWydatkami){
    budzetMenadzer = NULL;
    };
    ~BudzetOsobisty()
    {
        delete budzetMenadzer;
        budzetMenadzer = NULL;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int pobierzIdZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void dodajPrzychod();
    void dodajWydatek();
    void wyswietlWszystkiePrzychody();
    int wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlIdZalogowanegoUzytkownika();
    void bilansZObecnegoMiesiaca();
    void bilansZPoprzedniegoMiesiaca();
    void bilansZWybranegoOkres();


};
