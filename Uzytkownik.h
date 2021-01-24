#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H


using namespace std;

#include <iostream>

class Uzytkownik {
    int id;
    string login;
    string haslo;
public:

void ustawId(int noweId);
void ustawLogin (string nowyLogin);
void ustawHaslo(string noweHaslo);
int pobierzId();
string pobierzLogin();
string pobierzHaslo();

};

#endif
