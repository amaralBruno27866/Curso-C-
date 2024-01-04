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
		m_birthday = 0;
	}

	Person::Person(const Person& person) : m_id(0), m_fullName(nullptr), m_cpf(0), m_birthday(0)
	{
		if (this != &person) {
			m_id = person.m_id;
			delete[] m_fullName;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_birthday = person.m_birthday;
		}
	}

	Person Person::operator=(const Person& person)
	{
		if (this != &person) {
			m_id = person.m_id;
			delete[] m_fullName;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_birthday = person.m_birthday;
		}
		return *this;
	}

	Person::~Person()
	{
		delete[] m_fullName;
		m_fullName = nullptr;
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

	void Person::readArr(int* arr, int size)
	{
		for (int i = 0; i < size; i++) {
			do {
				if (!(cin >> arr[i])) {
					cout << "Error, please, insert a valid value" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			} while (cin.fail());
		}
	}

	bool Person::isString(const char* word)
	{
		bool isValid = false;

		for (size_t i = 0; i < strlen(word); i++) {
			if (!std::isalpha(word[i]) && !std::isspace(word[i])) {
				cout << "Invalid character: " << word[i] << endl;
				cout << "Only letters and spaces are allowed!" << endl;
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
			cout << "Insert the first name: " << endl;
			cout << ">>> ";
			cin >> firstName;
		} while (!isString(firstName));

		do {
			cout << "Insert the last name: " << endl;
			cout << ">>> ";
			cin >> lastName;
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

	long long Person::insertCPF()
	{
		long long newCPF;
		bool isValid = false;

		do {
			cout << "Enter your 11-digit CPF number: " << endl;
			cout << ">>> ";
			cin >> newCPF;

			if (newCPF < 10000000000 || newCPF > 99999999999) {
				cout << "The CPF entered is not valid." << endl;
				isValid = false;
			}
			else {
				m_cpf = newCPF;
				isValid = true;
			}
		} while (isValid == false);

		return m_cpf;
	}

	time_t Person::birthday(int d, int m, int y)
	{
		bool isValid;

		do {
			isValid = true;

			cout << "Insert your birthday" << endl;
			cout << "Day:   ";
			cin >> d;
			cout << "Month: ";
			cin >> m;
			cout << "Year:  ";
			cin >> y;

			if (m == 2) {
				if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
					if (d < 1 || d > 29) {
						cout << "Invalid day for Februayr in a leap year...";
						isValid = false;
					}
				}
				else {
					if (d < 1 || d > 28) {
						cout << "Invalid day for Februayr in a non-leap year...";
						isValid = false;
					}
				}
			}

			if (m == 4 || m == 6 || m == 9 || m == 11) {
				if (d < 1 || d > 30) {
					cout << "Invalid day for this month...";
					isValid = false;
				}
			}

			if (d < 1 || d > 31) {
				cout << "Invalid day for this month...";
				isValid = false;
			}
		} while (isValid == false);

		struct tm myBirthday = { 0 };
		myBirthday.tm_mday = d;
		myBirthday.tm_mon = m - 1;
		myBirthday.tm_year = y - 1900;

		time_t bithdayDate = mktime(&myBirthday);

		m_birthday = bithdayDate;

		return m_birthday;
	}
}
