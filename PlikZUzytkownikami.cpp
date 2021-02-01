#include "PlikZUzytkownikami.h"


void PlikZUzytkownikami::dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik) {

    bool fileExists = xml.Load(pobierzNazwePliku());

    if (!fileExists) {
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", uzytkownik.pobierzId());
    xml.AddElem("Login", uzytkownik.pobierzLogin());
    xml.AddElem("Name", uzytkownik.getName());
    xml.AddElem("Surname", uzytkownik.getSurname());
    xml.AddElem("Password", uzytkownik.pobierzHaslo());
    xml.OutOfElem();
    xml.Save(pobierzNazwePliku());
}

vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku() {

    Uzytkownik uzytkownik;
    vector <Uzytkownik> uzytkownicy;


    xml.Load(pobierzNazwePliku());
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        MCD_STR strUserId = xml.GetData();
        xml.FindElem( "Login" );
        MCD_STR strLogin = xml.GetData();
        xml.FindElem( "Name" );
        MCD_STR strName = xml.GetData();
        xml.FindElem( "Surname" );
        MCD_STR strSurname = xml.GetData();
        xml.FindElem( "Password" );
        MCD_STR strPassword = xml.GetData();
        uzytkownik.ustawId(atoi(strUserId.c_str()));
        uzytkownik.ustawLogin(strLogin);
        uzytkownik.setName(strName);
        uzytkownik.setSurname(strSurname);
        uzytkownik.ustawHaslo(strPassword);
        uzytkownicy.push_back(uzytkownik);
        xml.OutOfElem();
    }
    xml.ResetPos();
    return uzytkownicy;
}

void PlikZUzytkownikami::zapiszNoweHasloDoPliku(string noweHaslo, int idZalogowanegoUzytkownika) {

    xml.Load("users.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "UserId" );
        MCD_STR strUserId = xml.GetData();
        if (atoi(strUserId.c_str()) == idZalogowanegoUzytkownika) {
            xml.FindElem( "Password" );
            xml.SetData(noweHaslo);
            break;
        } else {
            xml.OutOfElem();
        }
    }
    xml.Save("users.xml");

}





