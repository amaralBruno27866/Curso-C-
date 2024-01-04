#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <cstring>
#include <string>

#define MAX_TEXT 255
#define MAX_STATE 3
#define MAX_COUNTRY 4

using namespace std;
namespace sdds {
	class Address {
		char* m_street;
		int m_num;
		char* m_neighborhood;
		char* m_city;
		char* m_state;
		int m_cep;
		char* m_country;
	public:
		Address();
		Address(const Address& address);
		Address operator=(const Address& address);
		~Address();

		void copy(char*& dest, const char* src);
		void readArr(int* arr, int size);
		bool isString(const char* word);

		char* newAddress();
		void readStreet();
		void readHouseNumber();
		void readNeighborhood();
		void readCity();
		void readState();
		void readCEP();
		void readCountry();
		bool isAddressValid();
	};
}

#endif // !ADDRESS_H