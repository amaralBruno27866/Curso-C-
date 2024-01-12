#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#include "Animal.h"
#include "Cachorro.h"
#include "Gato.h"

using namespace std;
using namespace sdds;

int main() {
    sdds::Cachorro cachorro;
    cachorro.fazerSom();
    cin >> cachorro;
    cout << cachorro << endl;

    sdds::Gato gato;
    gato.fazerSom();
    cin >> gato;
    cout << gato << endl;

    return 0;
}
