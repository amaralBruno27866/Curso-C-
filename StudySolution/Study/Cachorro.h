#ifndef CACHORRO_H
#define CACHORRO_H

#include <iostream>
#include <cstring>

#include "Animal.h"

namespace sdds {
	class Cachorro : public Animal {
		char* m_tipo;
		int m_patas;
		bool m_movimento;
	public:
		Cachorro();
		Cachorro(const Cachorro& cao);
		Cachorro& operator=(const Cachorro& dog);
		~Cachorro();
		void fazerSom() const override;
		void animalCpy(char* cpy, const char* org) override;
		std::ostream& display(std::ostream& ostr) const override;
		std::istream& read(std::istream& istr) override;
	};
}
#endif // CHACHORRO_H
