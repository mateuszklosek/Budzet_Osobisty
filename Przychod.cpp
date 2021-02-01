#include "Przychod.h"

void Przychod::setIncomeId(int newIncomeId)
{
    incomeId = newIncomeId;
}

void Przychod::setUserId (int newUserId)
{
    userId = newUserId;
}
void Przychod::setDate(int newDate)
{
    date = newDate;
}

void Przychod::setItem (string newItem)
{
    item = newItem;
}
void Przychod::setAmount(string newAmount)
{
    amount = newAmount;
}

int Przychod::getIncomeId()
{
    return incomeId;
}
int Przychod::getUserId()
{
    return userId;
}
int Przychod::getDate()
{
    return date;
}
string Przychod::getItem()
{
    return item;
}
string Przychod::getAmount()
{
    return amount;
}
