#include "Wydatek.h"

void Wydatek::setExpenseId(int newExpenseId)
{
    expenseId = newExpenseId;
}

void Wydatek::setUserId (int newUserId)
{
    userId = newUserId;
}
void Wydatek::setDate(int newDate)
{
    date = newDate;
}

void Wydatek::setItem (string newItem)
{
    item = newItem;
}
void Wydatek::setAmount(string newAmount)
{
    amount = newAmount;
}

int Wydatek::getExpenseId()
{
    return expenseId;
}
int Wydatek::getUserId()
{
    return userId;
}
int Wydatek::getDate()
{
    return date;
}
string Wydatek::getItem()
{
    return item;
}
string Wydatek::getAmount()
{
    return amount;
}
