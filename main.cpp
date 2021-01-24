#include <iostream>

using namespace std;

#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"

int main() {
    char wybor;

    UzytkownikMenadzer uzytkownikMenadzer("users.xml");
    MetodyPomocnicze metodyPomocnicze;


    while (true) {


        if (uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika() == 0) {
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
                uzytkownikMenadzer.rejestracjaUzytkownika();
                break;
            case '2':
                uzytkownikMenadzer.logowanieUzytkownika();
                system("pause");
                break;
            case '3':
                uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
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
            system("cls");
            cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
            cout << "---------------------------" << endl;
            /* cout << "1. Dodaj adresata" << endl;
            cout << "2. Wyszukaj po imieniu" << endl;
            cout << "3. Wyszukaj po nazwisku" << endl;
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
            /* case '1':
                 KsiazkaAdresowa.dodajAdresata();
                 break;
             case '2':
                 KsiazkaAdresowa.wyszukajAdresatowPoImieniu();
                 break;
             case '3':
                 KsiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                 break;
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
                 uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
                 break;
            case '8':
                uzytkownikMenadzer.wylogowanieUzytkownika();
                break;
            }
        }
    }


    return 0;
}
