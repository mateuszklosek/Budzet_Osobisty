#include "Uzytkownik.h"

void Uzytkownik::ustawId(int noweId)
{
    if (noweId >= 0)
        id = noweId;
}

void Uzytkownik::ustawLogin (string nowyLogin)
{
    login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo)
{
    haslo = noweHaslo;
}

void Uzytkownik::setName (string newName)
{
    name = newName;
}
void Uzytkownik::setSurname(string newSurname)
{
    surname = newSurname;
}

int Uzytkownik::pobierzId()
{
    return id;
}
string Uzytkownik::pobierzLogin()
{
    return login;
}
string Uzytkownik::pobierzHaslo()
{
    return haslo;
}
string Uzytkownik::getName()
{
    return name;
}
string Uzytkownik::getSurname()
{
    return surname;
}
