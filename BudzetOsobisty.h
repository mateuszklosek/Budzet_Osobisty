#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"
#include "BudzetMenadzer.h"

using namespace std;

class BudzetOsobisty {
    UzytkownikMenadzer uzytkownikMenadzer;

    BudzetMenadzer *budzetMenadzer;
    MetodyPomocnicze metodyPomocnicze;
    const string NAZWA_PLIKU_Z_PRZYCHODAMI;

public:
    BudzetOsobisty(string nazwaPlikuZUzytkownikami, string nazwaPlikuZPrzychodami) : uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_PRZYCHODAMI(nazwaPlikuZPrzychodami){
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
    void wyswietlWszystkiePrzychody();
    int wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlIdZalogowanegoUzytkownika();


};
