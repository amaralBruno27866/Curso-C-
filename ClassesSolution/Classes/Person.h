#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>

#define MAX_NAME 50
#define MAX_CPF 11
#define MAX_ID 4

namespace sdds {
	class Person {
		int m_id;
		char* m_fullName;
		long long m_cpf;
		int m_day, m_month, m_year;
	public:
		Person();
		Person(const Person& person);
		Person operator=(const Person& person);
		~Person();

		void copy(char*& dest, const char* src);
		void copyN(int*& dest, const int* src);
		void readArr(int* arr, int size);
		bool isString(const char* word);
		bool isNumber(const int* num, int size);

		int createID(int newID);
		char* fullName();
		long long insertCPF(long long newCPF);

	};
}

#endif // !PERSON_H
