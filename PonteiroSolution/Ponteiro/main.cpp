#include <iostream>
#include "header.h"

using namespace std;

int main() {
    int option = 0;
    int exit = 0;
    do {
        cout << "Choose a option: " << endl;
        cout << " # 1 - Integer Menu " << endl;
        cout << " # 2 - Character Menu" << endl;
        cout << " # 3 - Exit" << endl;
        cout << ">>> ";
        cin >> option;
        switch (option) {
        case 1:
            sdds::menuInt();
            break;
        case 2:
            sdds::menuChar();
            break;
        case 3:
            exit = option;
            break;
        }
    } while (exit == 0);
    return 0;
}
