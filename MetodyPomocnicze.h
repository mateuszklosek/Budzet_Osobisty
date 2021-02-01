#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>


using namespace std;

class MetodyPomocnicze {


public:

    char getChoice();
    string getLine();
    int dateToInt(string date);
    string dateToString(int date);
};

#endif
