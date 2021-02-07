#ifndef WYDATEK_H
#define WYDATEK_H


using namespace std;

#include <iostream>

class Wydatek {

    int expenseId;
    int userId;
    int date;
    string item;
    string amount;

public:

void setExpenseId(int newExpenseId);
void setUserId(int newUserId);
void setDate (int newDate);
void setItem(string newItem);
void setAmount(string newAmount);
int getExpenseId();
int getUserId();
int getDate();
string getItem();
string getAmount();
};

#endif
