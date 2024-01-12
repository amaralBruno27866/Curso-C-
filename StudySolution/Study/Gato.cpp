#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#include "Gato.h"

using namespace std;
namespace sdds {
	Gato::Gato() : m_tipo(nullptr), m_patas(0), m_movimento(false) { }

	Gato::Gato(const Gato& gato) : m_tipo(nullptr), m_patas(0), m_movimento(false) {
		if (this != &gato) {
			m_tipo = nullptr;
			m_patas = 0;
			m_movimento = false;
		}
	}

	Gato& Gato::operator=(const Gato& cat) {
		if (this != &cat) {
			animalCpy(m_tipo, cat.m_tipo);
			m_patas = cat.m_patas;
			m_movimento = cat.m_movimento;
		}
		return *this;
	}

	Gato::~Gato() {
		delete[] m_tipo;
		m_tipo = nullptr;
	}

	void Gato::fazerSom() const {
		std::cout << "Miau Miau" << endl;
	}

	void Gato::animalCpy(char* cpy, const char* org) {
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

	std::ostream& Gato::display(std::ostream& ostr) const {
		ostr << "Tipo: " << m_tipo << endl;
		ostr << "Patas: " << m_patas << endl;
		ostr << "Movimento: " << (m_movimento ? "Sim" : "Não");
		return ostr;
	}

	std::istream& Gato::read(std::istream& istr) {
		cout << "Digite o tipo do cachorro: ";
		istr >> m_tipo;
		cout << "Digite o número de patas do cachorro: ";
		istr >> m_patas;
		cout << "O cachorro está se movendo? (1 para sim, 0 para não): ";
		istr >> m_movimento;
		return istr;
	}
}