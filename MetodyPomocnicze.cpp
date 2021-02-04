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

int MetodyPomocnicze::dateToInt(string date) {
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

string MetodyPomocnicze::dateToString(int date) {
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

string MetodyPomocnicze::localDate() {
    time_t czas;
    struct tm * data;
    char bufor[ 11 ];
    stringstream ss;
    string dzisiejszaData;
    time( & czas );
    data = localtime( & czas );
    strftime( bufor, sizeof( bufor ), "%Y-%m-%d", data );
    ss << bufor;
    ss >> dzisiejszaData;
    return dzisiejszaData;
}

int MetodyPomocnicze::howManyDays(int month, int year) {
    int days=0;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    else if (month == 02) {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
            days = 28;
        else
            days = 29;
    } else
        days = 31;

    return days;
}

bool MetodyPomocnicze::isDateCorrect(string date) {

    int intDate =0, correctDays =0;



    if (date.size() == 10 && date[4] == '-' && date[7] == '-') {
        intDate = dateToInt(date);

        int year = 0, month = 0, days = 0;
        year = intDate/10000;
        month = (intDate - year*10000)/100;
        days = intDate - (intDate/100)*100;
        /*cout << year << "-rok  " << month << "- miesiac " << days << endl;
        cout << howManyDays(month, year) << endl;
        system("pause"); */
        if (howManyDays(month, year) >= days && month <= 12 && year >= 1000){
            return true; }
        else
            return false;
    } else {
        return false;
    }

}

double MetodyPomocnicze::stringToDouble(string amountInString){

double amount = ::atof(amountInString.c_str());
    //cout << setprecision(2) << fixed <<amount << endl;
    return amount;
}

string MetodyPomocnicze::commaToDot(string amount){

    int sizeOfAmount = amount.size();
    for (int i = 0; i <= sizeOfAmount; i++)
    {
    if (amount[i] == ','){
        amount[i] = '.';
        if (sizeOfAmount > i+3){
            amount.erase(i+3,sizeOfAmount-i-3);

        }
    }
    if (amount[i] == '.'){
        if (sizeOfAmount > i+3){
            amount.erase(i+3,sizeOfAmount-i-3);

        }
    }
    }
    //cout << amount << endl;
    return amount;
}
