#include <iostream>
#include "modulo.h"

using namespace std;

int main() {
	int option = 0;
	int exit = 0;
	int n = 0, x = 0;

	do {
		cout << "Escolha uma das opcoes:" << endl;
		cout << " # 1 - Fatorial" << endl;
		cout << " # 2 - Area quadrado" << endl;
		cout << " # 3 - Area retangulo" << endl;
		cout << " # 4 - Exit" << endl;
		cout << " >>> ";
		cin >> option;
		printf("\n");

		switch (option) {
		case 1:
			sdds::fatorial(n);
			break;
		case 2:
			sdds::area_quadrado(n);
			break;
		case 3:
			sdds::area_retangulo(n, x);
			break;
		case 4:
			exit = option;
			break;
		}
	} while (exit == 0);

	return 0;
}