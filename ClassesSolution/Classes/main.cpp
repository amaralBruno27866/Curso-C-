#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Person.h"

using namespace sdds;
using namespace std;

int main() {
	int id = 0;
	long long cpf = 0;

	Person p;

	p.createID(id);
	p.fullName();
	p.insertCPF(cpf);

	return 0;
}