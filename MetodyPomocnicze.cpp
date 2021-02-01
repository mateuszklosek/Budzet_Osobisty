#include "MetodyPomocnicze.h"

char MetodyPomocnicze::getChoice() {
    string wejscie = "";
    char znak  = {0};

    while (true) {

        getline(cin, wejscie);
        if (wejscie.length() == 1) {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
        return 0;
    }
    return znak;
}

string MetodyPomocnicze::getLine() {
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

int MetodyPomocnicze::dateToInt(string date){
    string newDate, year, day, month;
    int newDateInt;
    year = date.substr(0,4);
    day = date.substr(8,2);
    date.erase(0,5);
    month = date.erase(2,3);
    newDate = year + month + day;
    newDateInt = atoi(newDate.c_str());
    return newDateInt;
}

string MetodyPomocnicze::dateToString(int date){
string year, month, day,newDate;
ostringstream ss;
ss<<date;
string str = ss.str();
year = str.substr(0,4);
day = str.substr(6,2);
month = str.substr(4,2);
newDate = year + "-" +month + "-" +day;
return newDate;
}

