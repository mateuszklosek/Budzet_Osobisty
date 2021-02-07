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
        do {
            date = metodyPomocnicze.getLine();
            if (metodyPomocnicze.isDateCorrect(date) == true) {
                przychod.setDate(metodyPomocnicze.dateToInt(date));
            } else {
                cout << "Niepoprawana data, wpisz jeszcze raz!: " << endl;
            }

        } while (metodyPomocnicze.isDateCorrect(date) == false);
        break;
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
    cout << "Numer ID:         " << przychody[liczba].getIncomeId() << endl;
    cout << "Data:             " << metodyPomocnicze.dateToString(date) << endl;
    cout << "Rodzaj:           " << przychody[liczba].getItem() << endl;
    cout << "Wartosc [PLN]:    " << metodyPomocnicze.commaToDot(przychody[liczba].getAmount()) << endl;
}

int BudzetMenadzer::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void BudzetMenadzer::sortujPrzychody() {

    sort(przychody.begin(), przychody.end(), porownanieDatPrzychodow);

}

int BudzetMenadzer::pobierzIdOstatniegoPrzychodu() {
    return plikZPrzychodami.pobierzIdOstatniegoPrzychodu();
}

void BudzetMenadzer::bilansZObecnegoMiesiaca() {

    system("cls");
    //sortujPrzychody();

    double sumaPrzychodow=0;
    double sumaWydatkow=0;

    string currentDate = metodyPomocnicze.localDate();
    int currentDateInt = metodyPomocnicze.dateToInt(currentDate);

    cout << "             >>> PRZYCHODY <<<" << endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < przychody.size(); i++) {
        if(currentDateInt/100 == przychody[i].getDate()/100) {
            wyswietlPrzychod(i);
            sumaPrzychodow += metodyPomocnicze.stringToDouble(przychody[i].getAmount());
        }
    }
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "              >>> WYDATKI <<<" << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < wydatki.size(); i++) {
        if(currentDateInt/100 == wydatki[i].getDate()/100) {
            wyswietlWydatek(i);
            sumaWydatkow += metodyPomocnicze.stringToDouble(wydatki[i].getAmount());
        }
    }
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "Suma przychodow [PLN]:  " << sumaPrzychodow << endl;
    cout << "Suma wydatkow [PLN]:    " << sumaWydatkow << endl;
    cout << "Bilans [PLN]:           " << sumaPrzychodow - sumaWydatkow << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    system("pause");
}

void BudzetMenadzer::bilansZPoprzedniegoMiesiaca() {

    system("cls");
    //sortujPrzychody();

    string currentDate = metodyPomocnicze.localDate();
    int currentDateInt = metodyPomocnicze.dateToInt(currentDate);
    double sumaPrzychodow=0;
    double sumaWydatkow=0;

    cout << "             >>> PRZYCHODY <<<" << endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < przychody.size(); i++) {
        if((currentDateInt/100)%100 == 1) {
            if(((currentDateInt/10000)-1)*100+12 == przychody[i].getDate()/100) {
                wyswietlPrzychod(i);
                sumaPrzychodow += metodyPomocnicze.stringToDouble(przychody[i].getAmount());
            }
        } else {
            if((currentDateInt/100)-1 == przychody[i].getDate()/100) {
                wyswietlPrzychod(i);
                sumaPrzychodow += metodyPomocnicze.stringToDouble(przychody[i].getAmount());
            }
        }
    }

    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "              >>> WYDATKI <<<" << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < wydatki.size(); i++) {
        if((currentDateInt/100)%100 == 1) {
            if(((currentDateInt/10000)-1)*100+12 == wydatki[i].getDate()/100) {
                wyswietlWydatek(i);
                sumaWydatkow += metodyPomocnicze.stringToDouble(wydatki[i].getAmount());
            }
        } else {
            if((currentDateInt/100)-1 == wydatki[i].getDate()/100) {
                wyswietlWydatek(i);
                sumaWydatkow += metodyPomocnicze.stringToDouble(wydatki[i].getAmount());
            }
        }
    }
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "Suma przychodow [PLN]:  " << sumaPrzychodow << endl;
    cout << "Suma wydatkow [PLN]:    " << sumaWydatkow << endl;
    cout << "Bilans [PLN]:           " << sumaPrzychodow - sumaWydatkow << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    system("pause");

}

void BudzetMenadzer::bilansZWybranegoOkresu() {

    system("cls");
    //sortujPrzychody();

    string firstDate, secondDate;
    int firstDateInt, secondDateInt;
    double sumaPrzychodow=0;
    double sumaWydatkow=0;

    cout << "Podaj dolna granice przedzialu (data w formacie rrrr-mm-dd): " << endl;

    do {
        firstDate = metodyPomocnicze.getLine();
        if (metodyPomocnicze.isDateCorrect(firstDate) == false) {
            cout << "Niepoprawana data, wpisz jeszcze raz!: " << endl;
        }
    } while (metodyPomocnicze.isDateCorrect(firstDate) == false);

    cout << "Podaj gorna granice przedzialu (data w formacie rrrr-mm-dd): " << endl;

    do {
        secondDate = metodyPomocnicze.getLine();
        if (metodyPomocnicze.isDateCorrect(secondDate) == false) {
            cout << "Niepoprawana data, wpisz jeszcze raz!: " << endl;
        }
    } while (metodyPomocnicze.isDateCorrect(secondDate) == false);

    firstDateInt = metodyPomocnicze.dateToInt(firstDate);
    secondDateInt = metodyPomocnicze.dateToInt(secondDate);

    cout << "             >>> PRZYCHODY <<<" << endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < przychody.size(); i++) {
        if( firstDateInt <= przychody[i].getDate() && secondDateInt >= przychody[i].getDate()) {
            wyswietlPrzychod(i);
            sumaPrzychodow += metodyPomocnicze.stringToDouble(przychody[i].getAmount());
        }
    }

    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "              >>> WYDATKI <<<" << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    for (int i = 0; i < wydatki.size(); i++) {
        if( firstDateInt <= wydatki[i].getDate() && secondDateInt >= wydatki[i].getDate()) {
            wyswietlWydatek(i);
            sumaWydatkow += metodyPomocnicze.stringToDouble(przychody[i].getAmount());
        }
    }

    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "Suma przychodow [PLN]:  " << sumaPrzychodow << endl;
    cout << "Suma wydatkow [PLN]:    " << sumaWydatkow << endl;
    cout << "Bilans [PLN]:           " << sumaPrzychodow - sumaWydatkow << endl;
    cout << "----------------------------------------------------"<< endl;
    cout << "----------------------------------------------------"<< endl;

    system("pause");
}

void BudzetMenadzer::wyswietlWydatek(int liczba) {

    int date;

    date = wydatki[liczba].getDate();
    cout << "----------------------------------------------------"<< endl;
    cout << "Numer ID:         " << wydatki[liczba].getExpenseId() << endl;
    cout << "Data:             " << metodyPomocnicze.dateToString(date) << endl;
    cout << "Rodzaj:           " << wydatki[liczba].getItem() << endl;
    cout << "Wartosc [PLN]:    " << metodyPomocnicze.commaToDot(wydatki[liczba].getAmount()) << endl;
}

int BudzetMenadzer::wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    plikZWydatkami.wczytajWydatkiZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void BudzetMenadzer::sortujWydatki() {

    sort(wydatki.begin(), wydatki.end(), porownanieDatWydatkow);

}

void BudzetMenadzer::dodajWydatek() {

    cout << " >>> DODAWANIE NOWEGO Wydatku <<<" << endl << endl;
    wydatek = podajDaneNowegoWydatku();
    if (wydatek.getDate() == 0 ) {
        cout << "Data nieprawidlowa !!!" << endl;
        system("pause");
    } else {
        wydatki.push_back(wydatek);
        plikZWydatkami.dopiszWydatekDoPliku(wydatek);
        cout<< "Nowy wydatek zostal dodany!"<<endl;
        system("pause");
    }
}

Wydatek BudzetMenadzer::podajDaneNowegoWydatku() {

    string date;
    char wybor;
    wydatek.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    wydatek.setExpenseId(plikZWydatkami.pobierzIdOstatniegoWydatku()+1);


    cout << "Podaj rodzaj wydatku: ";
    wydatek.setItem(metodyPomocnicze.getLine());

    cout << "Podaj wysokosc wydatku [PLN]: ";
    wydatek.setAmount(metodyPomocnicze.getLine());
    system("cls");
    cout << "    >>> Wybierz co chcesz zrobic <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Podaj dowolna date" << endl;
    cout << "2. Data dzisiejsza" << endl;

    wybor = metodyPomocnicze.getChoice();
    switch (wybor) {
    case '1':
        cout << "Podaj date w formacie rrrr-mm-dd: " << endl;
        do {
            date = metodyPomocnicze.getLine();
            if (metodyPomocnicze.isDateCorrect(date) == true) {
                wydatek.setDate(metodyPomocnicze.dateToInt(date));
            } else {
                cout << "Niepoprawana data, wpisz jeszcze raz!: " << endl;
            }

        } while (metodyPomocnicze.isDateCorrect(date) == false);
        break;
    case '2':
        date = metodyPomocnicze.localDate();
        wydatek.setDate(metodyPomocnicze.dateToInt(date));
        break;
    }

    return wydatek;
}
