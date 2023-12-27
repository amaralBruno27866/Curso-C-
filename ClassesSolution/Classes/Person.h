#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>

#define MAX_NAME 50

namespace sdds {
	class Person {
		int m_id;
		char* m_fullName;
		int m_cpf;
		int m_day, m_month, m_year;
		time_t m_birthday;
	public:
		Person(); //Construtor padrão
		Person(const Person& person); //Construtor de copia
		Person& operator=(const Person& person); //Construtor de atribuição
		~Person(); //Destrutor
		bool isValid(const char* word);
		bool isNumber(const char* num);
		char* fullName();
		time_t getDate(int day, int month, int year);
		int getCPF(int cpf);
		int getID(int id);
		void copy(char*& dest, const char* src);
	};
}

#endif // !PERSON_H
