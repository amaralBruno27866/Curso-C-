#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

#include "Animal.h"
#include "Cachorro.h"
#include "Gato.h"

using namespace std;
namespace sdds {
	Animal::Animal() : m_tipo(nullptr), m_patas(0), m_movimento(false) { }

	std::ostream& operator<<(std::ostream& os, const Animal& animal) {
		return animal.display(os);
	}

	std::istream& operator>>(std::istream& is, Animal& animal) {
		return animal.read(is);
	}
}