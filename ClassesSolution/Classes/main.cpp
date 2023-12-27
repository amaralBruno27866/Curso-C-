#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Person.h"

using namespace sdds;
using namespace std;

int main() {
	int num = 0, d = 0, m = 0, y = 0, id = 0;
	Person p;
	p.fullName();
	p.getCPF(num);
	p.getDate(d, m, y);
	p.getID(id);
	cout << p.fullName() << endl;
	cout << p.getCPF(num) << endl;
	cout << p.getDate(d, m, y) << endl;
	cout << p.getID(id) << endl << endl;
	return 0;
}