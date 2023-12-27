#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct Person {
	char name[255];
	int age;

	Person() {
		name[0] = '\0';
		age = 0;
	}

	/*
	* Esse construtor aceita um ponteiro para um caractere (ou seja, string C) como nome. A função strncpy é usada para copiar
	* o conteúdo da string C para o membro name da estrutura Person.
	*/
	Person(const char* name, int age) {
		strncpy(this->name, name, sizeof(this->name) - 1);
		this->name[sizeof(this->name) - 1] = '\0';
		this->age = age;
	}

	/*
	* Esse construtor aceita uma string C++ como nome. A função strncpy é usada para copiar o conteúdo da string C++ fornecida
	* para o membro name da estrutura Person. No entanto, como strncpy espera um ponteiro para um caracter como entrada, usamos
	* o método c_str() para obter um ponteiro oara a string C++.
	*/
	Person(string name, int age) {
		strncpy(this->name, name.c_str(), sizeof(this->name) - 1);
		this->name[sizeof(this->name) - 1] = '\0';
		this->age = age;
	}

	/*
	* Em resumo, a principal diferença entre esses dois construtpres é o tipo de string que eles aceitam para parâmetro. O primeiro
	* aceita uma string C, enquanto o segundo aceita uma string C++.
	*/
};

int main() {
	Person p("Bruno", 35);

	cout << p.name << " " << p.age << endl << endl;

	Person x[3];

	for (int i = 0; i < 3; i++) {
		string name;
		cout << "Insert a name: ";
		getline(cin, name);
		cout << "Insert the age: ";
		cin >> x[i].age;
		cin.ignore();
		x[i] = Person(name, x[i].age);
	}

	cout << endl;

	for (int f = 0; f < 3; f++) {
		cout << x[f].name << " " << x[f].age << endl;
	}

	return 0;
}