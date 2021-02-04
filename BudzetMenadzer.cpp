#include "BudzetMenadzer.h"


void BudzetMenadzer::dodajPrzychod() {

    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    przychod = podajDaneNowegoPrzychodu();
    if (przychod.getDate() == 0 ) {
        cout << "Data nieprawidlowa !!!" << endl;
        system("pause");
    } else {
        przychody.push_back(przychod);
        plikZPrzychodami.dopiszPrzychodDoPliku(przychod);
        cout<< "Nowy przychod zostal dodany!"<<endl;
        system("pause");
    }

}

Przychod BudzetMenadzer::podajDaneNowegoPrzychodu() {
    string date;
    char wybor;
    przychod.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    przychod.setIncomeId(plikZPrzychodami.pobierzIdOstatniegoPrzychodu()+1);


    cout << "Podaj rodzaj przychodu: ";
    przychod.setItem(metodyPomocnicze.getLine());

    cout << "Podaj wysokosc przychodu [PLN]: ";
    przychod.setAmount(metodyPomocnicze.getLine());
    system("cls");
    cout << "    >>> Wybierz co chcesz zrobic <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Podaj dowolna date" << endl;
    cout << "2. Data dzisiejsza" << endl;

    wybor = metodyPomocnicze.getChoice();
    switch (wybor) {
    case '1':
        cout << "Podaj date w formacie rrrr-mm-dd: " << endl;
        date = metodyPomocnicze.getLine();
        if (metodyPomocnicze.isDateCorrect(date) == true) {
            przychod.setDate(metodyPomocnicze.dateToInt(date));
            break;
        } else {
            przychod.setDate(0);
            break;
        }
    case '2':
        date = metodyPomocnicze.localDate();
        przychod.setDate(metodyPomocnicze.dateToInt(date));
        break;
    }

    return przychod;
}
void BudzetMenadzer::wyswietlWszystkiePrzychody() {
    system("cls");
    sortujPrzychody();
    if (!przychody.empty()) {
        cout << "             >>> PRZYCHODY <<<" << endl;
        for (int i = 0; i < przychody.size(); i++) {
            wyswietlPrzychod(i);
        }
        cout << endl;
    } else {
        cout << endl << "Brak przychodow." << endl << endl;
    }
    system("pause");
}

void BudzetMenadzer::wyswietlPrzychod(int liczba) {
    int date;
    date = przychody[liczba].getDate();
    cout << "----------------------------------------------------"<< endl;
    cout << "Numer ID:             " << przychody[liczba].getIncomeId() << endl;
    cout << "Data:             " << metodyPomocnicze.dateToString(date) << endl;
    cout << "Rodzaj:           " << przychody[liczba].getItem() << endl;
    cout << "Wartosc [PLN]:    " << metodyPomocnicze.commaToDot(przychody[liczba].getAmount()) << endl;
}

int BudzetMenadzer::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void BudzetMenadzer::sortujPrzychody() {

    sort(przychody.begin(), przychody.end(), porownanieDat);

}

int BudzetMenadzer::pobierzIdOstatniegoPrzychodu(){
return plikZPrzychodami.pobierzIdOstatniegoPrzychodu();}
