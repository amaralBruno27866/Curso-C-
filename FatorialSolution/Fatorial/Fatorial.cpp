#include <iostream>

using namespace std;

static void fatorial() {
	int num, fat = 1;
	cout << "Input a number: " << endl;
	cin >> num;
	for (int i = 1; i < num; i++) {
		fat = fat * (i + 1);
	}
	cout << "Fatorial: " << fat << endl;
}

int main() {
	int check = 1, x = 0;

	fatorial();

	do{
		cout << "Would like to test again? [1 = Yes | 2 = No]" << endl;
		cin >> x;

		switch (x) {
		case 1:
			fatorial();
			break;
		case 2:
			check = 0;
			break;
		}
	}while (check == 1);

	return 0;
}