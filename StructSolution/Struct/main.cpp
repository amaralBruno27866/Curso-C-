#include <iostream>
#include <cstring>

constexpr auto MAX_PERSON = 10;

using namespace std;

typedef struct people {
	char name[255];
	int age;
}t_people;

int main() {
	int check = 0;
	int option = 0;
	int i = 0;

	t_people people[MAX_PERSON];

	while (check == 0) {
		cout << "Adding a new persong" << endl;
		cout << "Type # 1 for YES" << endl;
		cout << "Type # 2 for NO" << endl;
		cout << " >> ";
		cin >> option;
		cout << endl;

		if (i != MAX_PERSON) {
			if (option == 1) {
				cout << "Name: ";
				cin >> people[i].name;
				cout << "Age: ";
				cin >> people[i].age;
				i++;
				cout << endl;
			}
			else {
				check = option;
			}
		}
		else {
			check = 2;
		}
	}

	int n_people = i;

	cout << "List of added persons" << endl;

	for (int i = 0; i < n_people; i++) {
		cout << people[i].name << " " << people[i].age << endl;
	}

	return 0;
}