#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include "Address.h"

using namespace std;
namespace sdds {
	Address::Address()
	{
		m_street = nullptr;
		m_num = 0;
		m_neighborhood = nullptr;
		m_city = nullptr;
		m_state = nullptr;
		m_cep = 0;
		m_country = nullptr;
	}

	Address::Address(const Address& address) : m_street(nullptr), m_num(0), m_neighborhood(nullptr), m_city(nullptr), m_state(nullptr), m_cep(0), m_country(nullptr)
	{
		if (this != &address) {
			delete[] m_street;
			copy(m_street, address.m_street);

			m_num = address.m_num;

			delete[] m_neighborhood;
			copy(m_neighborhood, address.m_neighborhood);

			delete[] m_city;
			copy(m_city, address.m_city);

			delete[] m_state;
			copy(m_state, address.m_state);

			m_cep = address.m_cep;

			delete[] m_country;
			copy(m_country, address.m_country);
		}
	}

	Address Address::operator=(const Address& address)
	{
		if (this != &address) {
			delete[] m_street;
			copy(m_street, address.m_street);

			m_num = address.m_num;

			delete[] m_neighborhood;
			copy(m_neighborhood, address.m_neighborhood);

			delete[] m_city;
			copy(m_city, address.m_city);

			delete[] m_state;
			copy(m_state, address.m_state);

			m_cep = address.m_cep;

			delete[] m_country;
			copy(m_country, address.m_country);
		}
		return *this;
	}

	Address::~Address()
	{
		delete[] m_street;
		m_street = nullptr;

		delete[] m_neighborhood;
		m_neighborhood = nullptr;

		delete[] m_city;
		m_city = nullptr;

		delete[] m_state;
		m_state = nullptr;

		delete[] m_country;
		m_country = nullptr;
	}

	void Address::copy(char*& dest, const char* src)
	{
		delete[] dest;
		dest = nullptr;
		if (src != nullptr && src[0] != '\0') {
			dest = new char[strlen(src) + 1];
			strcpy(dest, src);
		}
	}

	void Address::readArr(int* arr, int size)
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

	bool Address::isString(const char* word)
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

	char* Address::newAddress()
	{
		return nullptr;
	}

	void Address::readStreet()
	{
		char street[MAX_TEXT];
		cout << "Insert the street name: ";
		cin >>street;
	}
	void Address::readHouseNumber()
	{
		int house = 0;
		cout << "Insert the house / build / apartament number: ";
		cin >> house;
	}

	void Address::readNeighborhood()
	{
		char neighborhood[MAX_TEXT];
		cout << "Insert the neighborhood name: ";
		cin >> neighborhood;
	}

	void Address::readCity()
	{
		char city[MAX_TEXT];
		cout << "Insrte the city name: ";
		cin >> city;
	}

	void Address::readState()
	{
		char state[MAX_STATE] = {};
		int choice = 0;
		bool isValid = false;

		cout << "Select the state from the list" << endl;
		cout << endl;
		cout << "+-----+---------------------+----+" << endl;
		cout << "| Cod |      State Name     | SL |" << endl;
		cout << "+-----+---------------------+----+" << endl;
		cout << "| #01 | Acre                | AC |" << endl;
		cout << "| #02 | Alagoas             | AL |" << endl;
		cout << "| #03 | Amapa               | AP |" << endl;
		cout << "| #04 | Amazonas            | AM |" << endl;
		cout << "| #05 | Bahia               | BA |" << endl;
		cout << "| #06 | Ceara               | CE |" << endl;
		cout << "| #07 | Distrito Federal    | DF |" << endl;
		cout << "| #08 | Espirito Santo      | ES |" << endl;
		cout << "| #09 | Goias               | GO |" << endl;
		cout << "| #10 | Maranhao            | MA |" << endl;
		cout << "| #11 | Mato Grosso         | MT |" << endl;
		cout << "| #12 | Mato Grosso do Sul  | MS |" << endl;
		cout << "| #13 | Minas Gerais        | MG |" << endl;
		cout << "| #14 | Para                | PA |" << endl;
		cout << "| #15 | Paraiba             | PB |" << endl;
		cout << "| #16 | Parana              | PR |" << endl;
		cout << "| #17 | Pernambuco          | PE |" << endl;
		cout << "| #18 | Piaui               | PI |" << endl;
		cout << "| #19 | Rio de Janiero      | RJ |" << endl;
		cout << "| #20 | Rio Grande do Norte | RN |" << endl;
		cout << "| #21 | Rio Grande do Sul   | RS |" << endl;
		cout << "| #22 | Rondonia            | RO |" << endl;
		cout << "| #23 | Roraima             | RR |" << endl;
		cout << "| #24 | Santa Catarina      | SC |" << endl;
		cout << "| #25 | Sao Paulo           | SP |" << endl;
		cout << "| #26 | Sergipe             | SE |" << endl;
		cout << "| #27 | Tocantins           | TO |" << endl;
		cout << "+-----+---------------------+----+" << endl;
		cout << endl;

		cout << "Make a choise" << endl;
		do {
			cout << ">>> ";
			cin >> choice;
			if (choice < 1 || choice > 27) {
				cout << "Insert a valid input" << endl;
			}
			else {
				isValid = true;
			}
		} while (isValid == false);

		switch (choice)
		{
		case 1:
			strcpy(state, "AC");
			break;
		case 2:
			strcpy(state, "AL");
			break;
		case 3:
			strcpy(state, "AP");
			break;
		case 4:
			strcpy(state, "AM");
			break;
		case 5:
			strcpy(state, "BA");
			break;
		case 6:
			strcpy(state, "CE");
			break;
		case 7:
			strcpy(state, "DF");
			break;
		case 8:
			strcpy(state, "ES");
			break;
		case 9:
			strcpy(state, "GO");
			break;
		case 10:
			strcpy(state, "MA");
			break;
		case 11:
			strcpy(state, "MT");
			break;
		case 12:
			strcpy(state, "MS");
			break;
		case 13:
			strcpy(state, "MG");
			break;
		case 14:
			strcpy(state, "PA");
			break;
		case 15:
			strcpy(state, "PB");
			break;
		case 16:
			strcpy(state, "PR");
			break;
		case 17:
			strcpy(state, "PE");
			break;
		case 18:
			strcpy(state, "PI");
			break;
		case 19:
			strcpy(state, "RJ");
			break;
		case 20:
			strcpy(state, "RN");
			break;
		case 21:
			strcpy(state, "RS");
			break;
		case 22:
			strcpy(state, "RO");
			break;
		case 23:
			strcpy(state, "RR");
			break;
		case 24:
			strcpy(state, "SC");
			break;
		case 25:
			strcpy(state, "SP");
			break;
		case 26:
			strcpy(state, "SE");
			break;
		case 27:
			strcpy(state, "TO");
			break;
		}

		strncpy(m_state, state, sizeof(m_state) + 1);
		m_state[sizeof(m_state) - 1] = '\0';
	}

	void Address::readCEP()
	{
		int CEP = 0;
		cout << "Insert the CEP with 5 digits: ";
		cin >> CEP;
	}

	void Address::readCountry()
	{
		char country[MAX_COUNTRY];
		cout << "Insert the country with 3 digits (e.g. CAN = Canada): ";
		cin >> country;
	}

	bool Address::isAddressValid()
	{
		return false;
	}
}