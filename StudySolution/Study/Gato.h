#ifndef GATO_H
#define GATO_H_H

#include <iostream>
#include <cstring>

#include "Animal.h"

namespace sdds {
	class Gato : public Animal {
		char* m_tipo;
		int m_patas;
		bool m_movimento;
	public:
		Gato();
		Gato(const Gato& gato);
		Gato& operator=(const Gato& cat);
		~Gato();
		void fazerSom() const override;
		void animalCpy(char* cpy, const char* org) override;
		std::ostream& display(std::ostream& ostr) const override;
		std::istream& read(std::istream& istr) override;
	};
}
#endif // GATO_H_H
