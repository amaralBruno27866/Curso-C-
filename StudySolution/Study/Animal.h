#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

namespace sdds {
	class Animal {
		char* m_tipo;
		int m_patas;
		bool m_movimento;
	public:
		Animal();
		virtual void fazerSom() const = 0;
		virtual void animalCpy(char* cpy, const char* org) = 0;
		virtual std::ostream& display(std::ostream& ostr) const = 0;
		virtual std::istream& read(std::istream& istr) = 0;
	};

	std::ostream& operator<<(std::ostream& os, const Animal& animal);
	std::istream& operator>>(std::istream& is, Animal& animal);
}

#endif
