#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H


using namespace std;

#include <iostream>

class Uzytkownik {
    int id;
    string login;
    string haslo;
    string name;
    string surname;
public:

void ustawId(int noweId);
void ustawLogin (string nowyLogin);
void ustawHaslo(string noweHaslo);
void setName(string newName);
void setSurname(string newSurname);
int pobierzId();
string pobierzLogin();
string pobierzHaslo();
string getName();
string getSurname();
};

#endif
