#include "Przychody.h"

void Przychody::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}

void Przychody::setUserId (int newUserId)
{
    userId = newUserId;
}
void Przychody::setDate(string newDate)
{
    date = newDate;
}

void Przychody::setItem (string newItem)
{
    item = newItem;
}
void Przychody::setAmount(string newAmount)
{
    amount = newAmount;
}

int Przychody::getIncomeId()
{
    return incomeId;
}
int Przychody::getUserId()
{
    return userId;
}
string Przychody::getDate()
{
    return date;
}
string Przychody::getItem()
{
    return item;
}
string Przychody::getAmount()
{
    return amount;
}
