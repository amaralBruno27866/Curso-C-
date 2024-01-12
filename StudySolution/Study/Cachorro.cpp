#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#include "Cachorro.h"

using namespace std;
namespace sdds{
	Cachorro::Cachorro() : m_tipo(nullptr), m_patas(0), m_movimento(false) { }

	Cachorro::Cachorro(const Cachorro& cao) : m_tipo(nullptr), m_patas(0), m_movimento(false) {
		if (this != &cao) {
			m_tipo = nullptr;
			m_patas = 0;
			m_movimento = false;
		}
	}

	Cachorro& Cachorro::operator=(const Cachorro& dog) {
		if (this != &dog) {
			animalCpy(m_tipo, dog.m_tipo);
			m_patas = dog.m_patas;
			m_movimento = dog.m_movimento;
		}
		return *this;
	}

	Cachorro::~Cachorro() {
		delete[] m_tipo;
		m_tipo = nullptr;
	}

	void Cachorro::fazerSom() const {
		std::cout << "Auuuuu Au Au" << endl;
	}

	std::ostream& Cachorro::display(std::ostream& ostr) const {
		ostr << "Tipo: " << m_tipo << endl;
		ostr << "Patas: " << m_patas << endl;
		ostr << "Movimento: " << (m_movimento ? "Sim" : "Não");
		return ostr;
	}

	void Cachorro::animalCpy(char* cpy, const char* org) {
		if (cpy) {
			delete[] cpy;
		}
		if (org) {
			cpy = new char[strlen(org) + 1];
			strcpy(cpy, org);
		}
		else {
			cpy = nullptr;
		}
	}

	std::istream& Cachorro::read(std::istream& istr) {
		cout << "Digite o tipo do cachorro: ";
		istr >> m_tipo;
		cout << "Digite o número de patas do cachorro: ";
		istr >> m_patas;
		cout << "O cachorro está se movendo? (1 para sim, 0 para não): ";
		istr >> m_movimento;
		return istr;
	}
}