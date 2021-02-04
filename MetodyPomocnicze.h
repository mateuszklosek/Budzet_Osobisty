#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <time.h>
#include <iostream>
#include <iomanip>


using namespace std;

class MetodyPomocnicze {


public:

    char getChoice();
    string getLine();
    int dateToInt(string date);
    string dateToString(int date);
    string localDate();
    int howManyDays(int month, int year);
    bool isDateCorrect(string date);
    double stringToDouble(string amountInString);
    string commaToDot(string amonut);

};

#endif
