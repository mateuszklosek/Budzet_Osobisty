#include <iostream>

using namespace std;

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"
#include "BudzetMenadzer.h"
#include "BudzetOsobisty.h"

int main() {
    char wybor;

    MetodyPomocnicze metodyPomocnicze;
    BudzetOsobisty budzetOsobisty("users.xml", "incomes.xml");


    while (true) {


        if (budzetOsobisty.pobierzIdZalogowanegoUzytkownika() == 0) {
            system("cls");
            cout << "    >>> MENU  GLOWNE <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "3. Pokaz wszystkich uzytkownikow" << endl;
            cout << "9. Koniec programu" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = metodyPomocnicze.getChoice();
            switch (wybor) {
            case '1':
                budzetOsobisty.rejestracjaUzytkownika();
                break;
            case '2':
                budzetOsobisty.logowanieUzytkownika();
                break;
            case '3':
                budzetOsobisty.wypiszWszystkichUzytkownikow();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            budzetOsobisty.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(budzetOsobisty.pobierzIdZalogowanegoUzytkownika());
            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            cout << "1. Dodaj przychod" << endl;
            cout << "2. Wyswietl wszytskie przychody" << endl;

            cout << "3. Wyswietl id zalogowanego uzytkownika" << endl;
            /*
            cout << "4. Wyswietl adresatow" << endl;
            cout << "5. Usun adresata" << endl;
            cout << "6. Edytuj adresata" << endl;
            cout << "---------------------------" << endl; */
            cout << "7. Zmien haslo" << endl;
            cout << "8. Wyloguj sie" << endl;
            cout << "---------------------------" << endl;
            cout << "Twoj wybor: ";
            wybor = metodyPomocnicze.getChoice();
            switch (wybor) {
            case '1':
                budzetOsobisty.dodajPrzychod();
                break;

            case '2':
            budzetOsobisty.wyswietlWszystkiePrzychody();
            break;

            case '3':
            budzetOsobisty.wyswietlIdZalogowanegoUzytkownika();
            break;
            /*
            case '4':
            KsiazkaAdresowa.wyswietlWszystkichAdresatow();
            break;
            case '5':
            plikZAdresatami.ustawIdOstatniegoAdresata(KsiazkaAdresowa.usunAdresata());
            break;
            case '6':
            KsiazkaAdresowa.edytujAdresata();
            break; */
            case '7':
                budzetOsobisty.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                budzetOsobisty.wylogowanieUzytkownika();
                break;
            }
        }
    }


    return 0;
}
