#include <iostream>

using namespace std;

static void test();
bool par(int num);

int main() {
	int check = 1;
	int x = 0;

	test();

	do {
		cout << "Would like to test again? [1 = Yes | 2 = No]: -> ";
		cin >> x;
		cout << endl;

		switch (x) {
		case 1:
			test();
			break;
		case 2:
			check = 0;
			break;
		}
	} while (check == 1);

	return 0;
}

bool par(int num) {
	bool value;

	if (num % 2 == 0) {
		value = true;
	}
	else {
		value = false;
	}

	return value;
}

static void test() {
	int n = 0;

	cout << "Insert a integer number: ";
	cin >> n;
	cout << endl;

	if (par(n)) {
		cout << "This number " << n << "is PAR" << endl;
		cout << endl;
	}
	else {
		cout << "This number " << n << "is IMPAR" << endl;
		cout << endl;
	}
}