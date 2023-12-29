#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Person.h"

using namespace std;
namespace sdds {
	Person::Person()
	{
		m_id = 0;
		m_fullName = nullptr;
		m_cpf = 0;
		m_day = 0;
		m_month = 0;
		m_year = 0;
	}

	Person::Person(const Person& person) : m_id(0), m_fullName(nullptr), m_cpf(0), m_day(0), m_month(0), m_year(0)
	{
		if (this != &person) {
			m_id = person.m_id;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_day = person.m_day;
			m_month = person.m_month;
			m_year = person.m_year;
		}
	}

	Person Person::operator=(const Person& person)
	{
		if (this != &person) {
			m_id = person.m_id;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_day = person.m_day;
			m_month = person.m_month;
			m_year = person.m_year;
		}
		return *this;
	}

	Person::~Person()
	{
		delete[] m_fullName;
		m_fullName = nullptr;
		cout << "m_fullName was deleted" << endl;
	}

	void Person::copy(char*& dest, const char* src)
	{
		delete[] dest;
		dest = nullptr;
		if (src != nullptr && src[0] != '\0') {
			dest = new char[strlen(src) + 1];
			strcpy(dest, src);
		}
	}

	void Person::copyN(int*& dest, const int* src)
	{
		delete[] dest;
		dest = nullptr;
		if (src != nullptr) {
			dest = new int[MAX_CPF + 1];
			for (int i = 0; i <= MAX_CPF; i++) {
				dest[i] = src[i];
			}
		}
	}

	void Person::readArr(int* arr, int size)
	{
		for (int i = 0; i < size; i++) {
			cin >> arr[i];
		}
	}

	bool Person::isString(const char* word)
	{
		for (size_t i = 0; i < strlen(word); i++) {
			if (!std::isalpha(word[i]) && !std::isspace(word[i])) {
				return false;
			}
		}
		return true;
	}

	bool Person::isNumber(const int* num, int size)
	{
		bool isValid = false;
		for (int i = 0; i <= size; i++) {
			if (num[i] < 0 || num[i] > 9) {
				cout << "The number must be between 0 to 9" << endl;
				isValid = false;
			}
			else {
				isValid = true;
			}
		}

		return isValid;
	}

	int Person::createID(int newID)
	{
		do {
			cout << "Insert the ID number with 4 digits: " << endl;
			cout << ">>> ";
			cin >> newID;
		} while (newID < 1000 || newID > 9999);

		m_id = newID;

		return m_id;
	}

	char* Person::fullName()
	{
		char firstName[MAX_NAME];
		char lastName[MAX_NAME];

		delete[] m_fullName;
		m_fullName = nullptr;

		do {
			cout << "Insert the first name: ";
			cin >> firstName;
		} while (!isString(firstName));

		do {
			cout << "Insert the last name: ";
			cin >> firstName;
		} while (!isString(lastName));

		size_t word1 = strlen(firstName);
		size_t word2 = strlen(lastName);

		char* fullName = new char[word1 + word2 + 2];

		strcpy(fullName, firstName);
		strcat(fullName, " ");
		strcat(fullName, lastName);

		m_fullName = fullName;

		return m_fullName;
	}

	long long Person::insertCPF(long long newCPF)
	{
		do {
			cout << "Insert the CPF number with 11 digits: " << endl;
			cout << ">>> ";
			cin >> newCPF;
		} while (newCPF < 10000000000 || newCPF > 99999999999);

		m_cpf = newCPF;

		return m_cpf;
	}
}
