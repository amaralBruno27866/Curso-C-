#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Person.h"

using namespace std;
namespace sdds {
	Person::Person() {
		m_id = 0;
		m_fullName = nullptr;
		m_cpf = 0;
		m_day = 0;
		m_month = 0;
		m_year = 0;
		m_birthday = 0;
	}

	Person::Person(const Person& person) : m_id(0), m_fullName(nullptr), m_cpf(0), m_day(0), m_month(0), m_year(0), m_birthday(0){
		if (this != &person) {
			m_id = person.m_id;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_day = person.m_day;
			m_month = person.m_month;
			m_year = person.m_year;
			m_birthday = person.m_birthday;
		}
	}

	Person& Person::operator=(const Person& person) {
		if (this != &person) {
			m_id = person.m_id;
			copy(m_fullName, person.m_fullName);
			m_cpf = person.m_cpf;
			m_day = person.m_day;
			m_month = person.m_month;
			m_year = person.m_year;
			m_birthday = person.m_birthday;
		}
		return *this;
	}

	Person::~Person() {
		delete[] m_fullName;
		m_fullName = nullptr;
	}

	bool Person::isValid(const char* word) {
		for (size_t i = 0; i < strlen(word); ++i) {
			if (!std::isalpha(word[i]) && !std::isspace(word[i])) {
				return false;
			}
		}
		return true;
	}

	bool Person::isNumber(const char* num) {
		for (size_t i = 0; i < strlen(num); i++) {
			if (!std::isdigit(num[i])) {
				return false;
			}
		}
		return true;
	}

	char* Person::fullName() {
		char firstName[MAX_NAME];
		char lastName[MAX_NAME];

		delete[] m_fullName;
		m_fullName = nullptr;

		do {
			cout << "Insert the first name: ";
			cin >> firstName;

		} while (!isValid(firstName));

		do {
			cout << "Insert the last name: ";
			cin >> lastName;

		} while (!isValid(lastName));

		size_t word1 = strlen(firstName);
		size_t word2 = strlen(lastName);

		char* fullName = new char[word1 + word2 + 2];

		strcpy(fullName, firstName);
		strcat(fullName, " ");
		strcat(fullName, lastName);

		m_fullName = fullName;

		return fullName;
	}

	time_t Person::getDate(int day, int month, int year) {
		bool valid = false;

		do {
			cout << "Day: ";
			cin >> day;
			cout << "Month: ";
			cin >> month;
			cout << "Year: ";
			cin >> year;

			if (month == 2) {
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
					if (day < 1 || day > 29) {
						cout << "Invalid day for Februayr in a leap year...";
						day = 0;
						month = 0;
						year = 0;
						valid = false;
					}
				}
				else {
					if (day < 1 || day > 28) {
						cout << "Invalid day for February in a non-leap year...";
						day = 0;
						month = 0;
						year = 0;
						valid = false;
					}
				}
			}

			if (month == 4 || month == 6 || month == 9 || month == 11) {
				if (day < 1 || day > 30) {
					cout << "Invalid day for this month...";
					day = 0;
					month = 0;
					year = 0;
					valid = false;
				}
			}

			if (day < 1 || day > 31) {
				cout << "Invalid day for this month...";
				day = 0;
				month = 0;
				year = 0;
				valid = false;
			}
			valid = true;
		} while (valid == false);

		struct tm birthday = {0};
		birthday.tm_mday = day;
		birthday.tm_mon = month - 1;
		birthday.tm_year = year - 1900;

		time_t birthdayDate = mktime(&birthday);

		m_birthday = birthdayDate;
		
		return birthdayDate;
	}

	int Person::getCPF(int cpf) {
		string newCPF;

		do {
			cout << "Insert the CPF number whit 11 digits: ";
			cin >> newCPF;
		} while (newCPF.length() > 11 || newCPF.length() < 0 || !isNumber(newCPF.c_str()));

		cpf = stoi(newCPF);
		m_cpf = cpf;

		return cpf;
	}

	int Person::getID(int id) {
		string newID;

		do {
			cout << "Insert the ID number with up to 8 digits: ";
			cin >> newID;
		} while (newID.length() > 9 || newID.length() < 0 || !isNumber(newID.c_str()));

		id = stoi(newID);
		m_id = id;

		return id;
	}

	void Person::copy(char*& dest, const char* src) {
		delete[] dest;
		dest = nullptr;
		if (src != nullptr && src[0] != '\0') {
			dest = new char[strlen(src) + 1];
			strcpy(dest, src);
		}
	}
}
