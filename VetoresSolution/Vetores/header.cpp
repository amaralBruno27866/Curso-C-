#include <iostream>
#include "header.h"

namespace sdds {
	int myArray(int number[MAX_NUMBER])	{
		int i = 0;
		int value = 0;
		while (value != 1) {
			std::cout << "Insert a number: ";
			std::cin >> number[i];
			if (number[i] >= 100) {
				printf("\n");
				value = 1;
			}
		}
		return number[i];
	}

	void myText(char word[MAX_CHAR + 1]) {
		int max_char = MAX_CHAR;
		int value = 0;
		while (value == 0) {
			std::cout << "Insert a word: ";
			std::cin.getline(word, MAX_CHAR + 1);
			int length = strlen(word);
			if (length > max_char) {
				std::cout << "The maximum number of characters has been reached.\n";
				value = 1;
			}
			else {
				max_char -= length;
				std::cout << "You have " << max_char << " characters for use yet. \n";
			}
		}
	}
}
