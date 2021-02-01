#ifndef PRZYCHOD_H
#define PRZYCHOD_H


using namespace std;

#include <iostream>

class Przychod {

    int incomeId;
    int userId;
    int date;
    string item;
    string amount;

public:

void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setDate (int newDate);
void setItem(string newItem);
void setAmount(string newAmount);
int getIncomeId();
int getUserId();
int getDate();
string getItem();
string getAmount();
};

#endif
