#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NewCar.h"

using namespace std;
namespace sdds {
	NewCar::NewCar()
	{
		carArray = nullptr;
		carCount = 0;
		id = 0;
		name = nullptr;
		brand = nullptr;
		color = nullptr;
		plate = nullptr;
		price = 0.0;
	}

	NewCar::NewCar(const NewCar& newcar) : carArray(nullptr), carCount(0), id(0), name(nullptr), brand(nullptr), color(nullptr), plate(nullptr), price(0.0)
	{
		if (this != &newcar) {
			id = 0;
			copy(name, newcar.name);
			copy(brand, newcar.brand);
			copy(color, newcar.color);
			copy(plate, newcar.plate);
			price = 0.0;
			copyArray(newcar);
		}
	}

	NewCar& NewCar::operator=(const NewCar& newcar)
	{
		if (this != &newcar) {
			delete[] name;
			delete[] brand;
			delete[] color;
			delete[] plate;

			carCount = 0;
			id = 0;
			copy(name, newcar.name);
			copy(brand, newcar.brand);
			copy(color, newcar.color);
			copy(plate, newcar.plate);
			price = 0.0;
		}
		return *this;
	}

	NewCar::~NewCar()
	{
		delete[] carArray;
		carArray = nullptr;
		delete[] name;
		name = nullptr;
		delete[] brand;
		brand = nullptr;
		delete[] color;
		color = nullptr;
		delete[] plate;
		plate = nullptr;
	}

	void NewCar::copy(char*& dest, const char* src)
	{
		delete[] dest;
		dest = nullptr;
		if (src != nullptr && src[0] != '\0') {
			dest = new char[strlen(src) + 1];
			strcpy(dest, src);
		}
	}

	void NewCar::addingNewCar()
	{
		char choice = 0;
		bool control = false;

		while (control == false) {
			cout << "****** Adding a new car ******" << endl;
			
			NewCar newCar;

			cout << "Car ID: ";
			cin >> newCar.id;

			char tempName[50];
			cout << "Car name: ";
			cin >> tempName;
			newCar.name = new char[strlen(tempName) + 1];
			strcpy(newCar.name, tempName);

			char tempBrand[50];
			cout << "Car brand: ";
			cin >> tempBrand;
			newCar.brand = new char[strlen(tempBrand) + 1];
			strcpy(newCar.brand, tempBrand);

			char tempColor[20];
			cout << "Car color: ";
			cin >> tempColor;
			newCar.color = new char[strlen(tempColor) + 1];
			strcpy(newCar.color, tempColor);

			char tempPlate[10];
			cout << "Car plate: ";
			cin >> tempPlate;
			newCar.plate = new char[strlen(tempPlate) + 1];
			strcpy(newCar.plate, tempPlate);

			cout << "Car price: $";
			cin >> newCar.price;

			int newSize = carCount + 1;

			NewCar* newArray = nullptr;

			newArray = new NewCar[newSize];

			for (int i = 0; i < carCount; i++) {
				newArray[i] = carArray[i];
			}

			newArray[carCount].id = newCar.id;

			newArray[carCount].name = new char[strlen(newCar.name) + 1];
			strcpy(newArray[carCount].name, newCar.name);

			newArray[carCount].brand = new char[strlen(newCar.brand) + 1];
			strcpy(newArray[carCount].brand, newCar.brand);

			newArray[carCount].color = new char[strlen(newCar.color) + 1];
			strcpy(newArray[carCount].color, newCar.color);

			newArray[carCount].plate = new char[strlen(newCar.plate) + 1];
			strcpy(newArray[carCount].plate, newCar.plate);

			newArray[carCount].price = newCar.price;

			delete[] carArray;

			carArray = newArray;
			carCount = newSize;

			cout << endl;

			cout << "Insert a car? <Y> YES or <N> NO: ";
			cin >> choice;
			if (choice != 'Y') {
				control = true;
				cout << endl;
			}
		}
	}

	NewCar* NewCar::getArrayCar()
	{
		return carArray;
	}

	void NewCar::menu()
	{
		int option = 0;
		bool valid = false;

		do {
			cout << "+---------------------+" << endl;
			cout << "|    Options Menu     |" << endl;
			cout << "+---------------------+" << endl;
			cout << "| # 1 | New car       |" << endl;
			cout << "| # 2 | Print list    |" << endl;
			cout << "| # 3 | Order by Name |" << endl;
			cout << "| # 4 | Order by ID   |" << endl;
			cout << "| # 5 | Exit          |" << endl;
			cout << "+---------------------+" << endl << endl;

			do {
				cout << " >>> ";
				cin >> option;
				cout << endl;
				if (option < 1 || option > 5) {
					cout << "Insert a valid value" << endl;
				}
				else {
					valid = true;
				}
			} while (valid == false);
			
			switch (option) {
			case 1:
				addingNewCar();
				break;
			case 2:
				printList();
				break;
			case 3:
				orderingByName();
				break;
			case 4:
				orderingByID();
				break;
			}
		} while (option != 5);
	}

	void NewCar::printList()
	{
		cout << "********** Car List **********" << endl << endl;

		for (int j = 0; j < carCount; j++) {
			cout << "+--------+---------------+" << endl;
			cout << "| ID     | " << carArray[j].id << endl;
			cout << "| Car    | " << carArray[j].name << endl;
			cout << "| Brand  | " << carArray[j].brand << endl;
			cout << "| Color  | " << carArray[j].color << endl;
			cout << "| Plate  | " << carArray[j].plate << endl;
			cout << "| Price  | " << carArray[j].price << endl;
			cout << "+--------+---------------+" << endl << endl;
		}
	}

	void NewCar::orderingByName()
	{
		NewCar aux;
		for (int i = carCount; i >= 0; i--) {
			for (int j = 1; j <= i; j++) {
				if (strcmp(carArray[j - 1].name, carArray[j].name) == 0) {
					aux = carArray[j - 1];
					carArray[j - 1] = carArray[j];
					carArray[j] = aux;
				}
			}
		}
		printList();
	}

	void NewCar::orderingByID()
	{
		NewCar aux;
		for (int i = carCount; i >= 0; i--) {
			for (int j = 1; j <= i; j++) {
				if (carArray[j - 1].id > carArray[j].id) {
					aux = carArray[j - 1];
					carArray[j - 1] = carArray[j];
					carArray[j] = aux;
				}
			}
		}
		printList();
	}

	void NewCar::copyArray(const NewCar& other)
	{
		if (other.carArray && other.carCount > 0) {
			carArray = new NewCar[other.carCount];
			for (int i = 0; i < other.carCount; i++) {
				carArray[i] = other.carArray[i];
			}
			carCount = other.carCount;
		}
		else {
			carArray = nullptr;
			carCount = 0;
		}
	}
}
