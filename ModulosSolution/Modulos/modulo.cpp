#include <iostream>
#include "modulo.h"

namespace sdds {
	int fatorial(int n)	{
		int fat = 1;

		std::cout << "Informe um numero: ";
		std::cout << " >>> ";
		std::cin >> n;

		for (int i = 0; i < n; i++) {
			fat = fat * (i + 1);
		}

		std::cout << "O fatorial de " << n << " eh: " << fat << std::endl;
		printf("\n");

		return fat;
	}

	int area_quadrado(int base)	{
		int result = 0;

		std::cout << "Informe o valor da base: ";
		std::cout << " >>> ";
		std::cin >> base;

		result = base * base;

		std::cout << "A area do quadrado cuja base eh " << base << ", eh igual a: " << result << std::endl;
		printf("\n");

		return result;
	}

	int area_retangulo(int largura, int altura)	{
		int result = 0;

		std::cout << "Informe o valor da largura: ";
		std::cout << " >>> ";
		std::cin >> largura;
		std::cout << "Informe o valor da altura: ";
		std::cout << " >>> ";
		std::cin >> altura;

		result = largura * altura;

		std::cout << "A area do retangulo cuja largura eh " << largura << " e a altura eh " << altura << ", eh igual a: " << result << std::endl;
		printf("\n");

		return result;
	}
}