#include <iostream>
#include "header.h"

using namespace std;

int main() {
	int option = 0;
	int exit = 0;
	int n[MAX_NUMBER];
	char w[MAX_CHAR];

	do {
		cout << "Choose a option:" << endl;
		cout << " # 1 - Number" << endl;
		cout << " # 2 - Text" << endl;
		cout << " # 3 - Exit" << endl;
		cout << " >>> ";
		cin >> option;
		printf("\n");

		switch (option) {
		case 1:
			sdds::myArray(n);
			break;
		case 2:
			sdds::myText(w);
			break;
		case 3:
			exit = option;
			break;
		}
	} while (exit == 0);
}