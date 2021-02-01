#ifndef PRZYCHODY_H
#define PRZYCHODY_H


using namespace std;

#include <iostream>

class Przychody {

    int incomeId;
    int userId;
    string date;
    string item;
    string amount;

public:

void setIncomeId(int newIncomeId);
void setUserId(int newUserId);
void setDate (string newDate);
void setItem(string newItem);
void setAmount(string newAmount);
int getIncomeId();
int getUserId();
string getDate();
string getItem();
string getAmount();
};

#endif
