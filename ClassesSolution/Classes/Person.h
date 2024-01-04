#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>

#define MAX_NAME 50

namespace sdds {
	class Person {
		int m_id;
		char* m_fullName;
		long long m_cpf;
		time_t m_birthday;
	public:
		Person();
		Person(const Person& person);
		Person operator=(const Person& person);
		~Person();

		void copy(char*& dest, const char* src);
		void readArr(int* arr, int size);
		bool isString(const char* word);

		int createID(int newID);
		char* fullName();
		long long insertCPF();
		time_t birthday(int d, int m, int y);

	};
}

#endif // !PERSON_H
