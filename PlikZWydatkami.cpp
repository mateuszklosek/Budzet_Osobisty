#include "PlikZWydatkami.h"


void PlikZWydatkami::dopiszWydatekDoPliku(Wydatek wydatek) {

    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists) {
        xml.AddElem("Expenses");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ExpenseId", wydatek.getExpenseId());
    xml.AddElem("UserId", wydatek.getUserId());
    xml.AddElem("Date", wydatek.getDate());
    xml.AddElem("Item", wydatek.getItem());
    xml.AddElem("Amount", wydatek.getAmount());
    xml.OutOfElem();
    xml.Save(pobierzNazwePliku());

    idOstatniegoWydatku++;
    system("pause");
}

vector <Wydatek> PlikZWydatkami::wczytajWydatkiZalogowanegoUzytkownikaZPliku(int idZalgowanegoUzytkownika) {
    Wydatek wydatek;
    vector <Wydatek> wydatki;


    xml.Load(pobierzNazwePliku());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") ) {
        xml.IntoElem();
        xml.FindElem( "ExpenseId" );
        MCD_STR strExpenseId = xml.GetData();
        xml.FindElem( "UserId" );
        MCD_STR strUserId = xml.GetData();
        if(idZalgowanegoUzytkownika == atoi(strUserId.c_str())) {
            xml.FindElem( "Date" );
            MCD_STR strDate = xml.GetData();
            xml.FindElem( "Item" );
            MCD_STR strItem = xml.GetData();
            xml.FindElem( "Amount" );
            MCD_STR strAmount = xml.GetData();
            wydatek.setUserId(atoi(strUserId.c_str()));
            wydatek.setExpenseId(atoi(strExpenseId.c_str()));
            wydatek.setDate(atoi(strDate.c_str()));
            wydatek.setItem(strItem);
            wydatek.setAmount(strAmount);
            wydatki.push_back(wydatek);
        }
        xml.OutOfElem();
        idOstatniegoWydatku =  atoi(strExpenseId.c_str());
    }
    return wydatki;
}


int PlikZWydatkami::pobierzIdOstatniegoWydatku() {
    return idOstatniegoWydatku;
}

