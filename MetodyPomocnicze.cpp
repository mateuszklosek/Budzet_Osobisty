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

