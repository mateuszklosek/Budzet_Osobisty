#include "PlikZPrzychodami.h"


void PlikZPrzychodami::dopiszPrzychodDoPliku(Przychod przychod) {

    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists) {
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeId", przychod.getIncomeId());
    xml.AddElem("UserId", przychod.getUserId());
    xml.AddElem("Date", przychod.getDate());
    xml.AddElem("Item", przychod.getItem());
    xml.AddElem("Amount", przychod.getAmount());
    xml.OutOfElem();
    xml.Save(pobierzNazwePliku());

    idOstatniegoPrzychodu++;
    system("pause");
}

vector <Przychod> PlikZPrzychodami::wczytajPrzychodyZalogowanegoUzytkownikaZPliku(int idZalgowanegoUzytkownika) {
    Przychod przychod;
    vector <Przychod> przychody;


    xml.Load(pobierzNazwePliku());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        MCD_STR strIncomeId = xml.GetData();
        xml.FindElem( "UserId" );
        MCD_STR strUserId = xml.GetData();
        if(idZalgowanegoUzytkownika == atoi(strUserId.c_str())) {
            xml.FindElem( "Date" );
            MCD_STR strDate = xml.GetData();
            xml.FindElem( "Item" );
            MCD_STR strItem = xml.GetData();
            xml.FindElem( "Amount" );
            MCD_STR strAmount = xml.GetData();
            przychod.setUserId(atoi(strUserId.c_str()));
            przychod.setIncomeId(atoi(strIncomeId.c_str()));
            przychod.setDate(atoi(strDate.c_str()));
            przychod.setItem(strItem);
            przychod.setAmount(strAmount);
            przychody.push_back(przychod);
        }
        xml.OutOfElem();
        idOstatniegoPrzychodu =  atoi(strIncomeId.c_str());
    }
    return przychody;
}

/* int PlikZPrzychodami::pobierzIdOstatniegoPrzychoduZPliku() {

    xml.Load(pobierzNazwePliku());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ) {
        xml.IntoElem();
        xml.FindElem( "IncomeId" );
        MCD_STR strIncomeId = xml.GetData();
        idOstatniegoPrzychodu = atoi(strIncomeId.c_str());
        xml.OutOfElem();
    }

    return idOstatniegoPrzychodu;
} */

int PlikZPrzychodami::pobierzIdOstatniegoPrzychodu() {
    return idOstatniegoPrzychodu;
}

