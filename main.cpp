#include <iostream>

using namespace std;

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"
#include "BudzetMenadzer.h"
#include "BudzetOsobisty.h"

int main() {
    char wybor;

    MetodyPomocnicze metodyPomocnicze;
    BudzetOsobisty budzetOsobisty("users.xml", "incomes.xml", "expenses.xml");


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
            cout << "2. Dodaj wydatek" << endl;
            cout << "3. Wyswietl id zalogowanego uzytkownika" << endl;
            cout << "4. Bilans z obecnego miesiaca" << endl;
            cout << "5. Bilans z poprzedniego miesiaca" << endl;
            cout << "6. Bilans z wybranego okresu" << endl;
            cout << "---------------------------" << endl;
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
                budzetOsobisty.dodajWydatek();
                break;

            case '3':
                budzetOsobisty.wyswietlIdZalogowanegoUzytkownika();
                break;

            case '4':
                budzetOsobisty.bilansZObecnegoMiesiaca();
                break;

            case '5':
                budzetOsobisty.bilansZPoprzedniegoMiesiaca();
                break;
            case '6':
               // budzetOsobisty.bilansZWybranegoOkres();
                break;
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
