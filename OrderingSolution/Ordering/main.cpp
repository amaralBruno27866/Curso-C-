#include <iostream>
#include <cstring>

#define MAX_CAR 10

using namespace std;

class Car {
public:
	int id;
	char name[100];
	char color[20];
	char plate[8];
	double price;
};

void printList(Car car[], int size) {
	cout << "********** Car List **********" << endl << endl;

	for (int j = 0; j <= size; j++) {
		cout << "+--------+---------------+" << endl;
		cout << "| ID     | " << car[j].id << endl;
		cout << "| Car    | " << car[j].name << endl;
		cout << "| Color  | " << car[j].color << endl;
		cout << "| Plate  | " << car[j].plate << endl;
		cout << "| Price  | " << car[j].price << endl;
		cout << "+--------+---------------+" << endl << endl;
	}
}

void orderingByName(Car car[], int size) {
	Car aux;
	for (int i = size; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (strcmp(car[j - 1].name, car[j].name) == 1) {
				aux = car[j - 1];
				car[j - 1] = car[j];
				car[j] = aux;
			}
		}
	}
	printList(car, size);
}

void orderingByID(Car car[], int size) {
	Car aux;
	for (int i = size; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (car[j - 1].id > car[j].id) {
				aux = car[j - 1];
				car[j - 1] = car[j];
				car[j] = aux;
			}
		}
	}
	printList(car, size);
}

int main() {
	Car car[MAX_CAR] = {};
	int i = 0;
	bool control = false;
	char choice = 0;
	int option = 0;

	while (control == false) {
		cout << "****** Adding a new car ******" << endl;
		cout << "Car ID: ";
		cin >> car[i].id;
		cout << "Car name: ";
		cin >> car[i].name;
		cout << "Car color: ";
		cin >> car[i].color;
		cout << "Car plate: ";
		cin >> car[i].plate;
		cout << "Car price: $";
		cin >> car[i].price;
		cout << endl;

		cout << "Insert a car? <Y> YES or <N> NO: ";
		cin >> choice;
		if (choice != 'Y') {
			control = true;
			cout << endl;
		}
		else {
			i++;
		}
	}

	do {
		cout << "+------------------+" << endl;
		cout << "| Ordering Options |" << endl;
		cout << "+------------------+" << endl;
		cout << "| #1 | By name     |" << endl;
		cout << "| #2 | By ID       |" << endl;
		cout << "| #3 | List        |" << endl;
		cout << "| #4 | Exit        |" << endl;
		cout << "+------------------+" << endl << endl;

		cout << " >>> ";
		cin >> option;

		switch (option) {
		case 1:
			orderingByName(car, i);
			break;
		case 2:
			orderingByID(car, i);
			break;
		case 3:
			printList(car, i);
			break;
		}
	} while (option != 4);
	
	return 0;
}