#include "BudzetMenadzer.h"


void BudzetMenadzer::dodajPrzychod() {

    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    przychod = podajDaneNowegoPrzychodu();

    przychody.push_back(przychod);
    plikZPrzychodami.dopiszPrzychodDoPliku(przychod);
    cout<< "Nowy przychod zostal dodany!"<<endl;
    system("pause");
}

Przychod BudzetMenadzer::podajDaneNowegoPrzychodu() {
    string date;
    //adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    system("pause");
    cout << ID_ZALOGOWANEGO_UZYTKOWNIKA << endl;
    system("pause");
    przychod.setUserId(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    //przychod.setIncomeId(asdasda);

    cout << "Podaj rodzaj przychodu: ";
    przychod.setItem(metodyPomocnicze.getLine());
    //adresat.ustawImie(metodyPomocniczne.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj wysokosc przychodu [PLN]: ";
    przychod.setAmount(metodyPomocnicze.getLine());
    //adresat.ustawNazwisko(metodyPomocniczne.zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj date w formacie rrrr-mm-dd ";
    date = metodyPomocnicze.getLine();
    przychod.setDate(metodyPomocnicze.dateToInt(date));

    return przychod;
}
void BudzetMenadzer::wyswietlWszystkiePrzychody(){
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

void BudzetMenadzer::wyswietlPrzychod(int liczba){
    int date;
    date = przychody[liczba].getDate();
    cout << "----------------------------------------------------"<< endl;
    cout << "Data:             " << metodyPomocnicze.dateToString(date) << endl;
    cout << "Rodzaj:           " << przychody[liczba].getItem() << endl;
    cout << "Wartosc [PLN]:    " << przychody[liczba].getAmount() << endl;
}

int BudzetMenadzer::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){
plikZPrzychodami.wczytajPrzychodyZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void BudzetMenadzer::sortujPrzychody(){

sort(przychody.begin() , przychody.end(), porownanieDat);

}

