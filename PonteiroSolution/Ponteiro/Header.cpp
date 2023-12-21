#include <iostream>
#include <cstring>
#include "Header.h"

namespace sdds {
    int* myArray(int*& arr) {
        int i;

        if (arr == nullptr) {
            arr = new int[MAX_SIZE];
        }

        std::cout << "Insert a number: " << std::endl;

        for (i = 0; i < MAX_SIZE; i++) {
            std::cout << " >> ";
            std::cin >> arr[i];
        }

        std::cout << "All positions were occupied" << std::endl;
        std::cout << std::endl;
        return arr;
    }

    void printArray(int*& arr) {
        if (arr != nullptr) {
            for (int i = 0; i < MAX_SIZE; i++) {
                std::cout << i << " - " << arr[i] << std::endl;
            }
        }
        else {
            std::cout << "The array is empty" << std::endl;
            myArray(arr);
        }
        std::cout << std::endl;
    }

    void runArray(int*& arr) {
        int* arrPoint = &arr[0];
        int i = 0;
        if (arr != nullptr) {
            while (i < MAX_SIZE) {
                std::cout << "Position: " << i << " -> " << *arrPoint << std::endl;
                arrPoint++;
                i++;
            }
        }
        else {
            std::cout << "The array is empty" << std::endl;
            myArray(arr);
        }
        std::cout << std::endl;
    }

    void pointToPoint(int*& arr) {
        int* arrPoint = &arr[0];
        int** arrPointPoint = &arrPoint;
        int i = 0;
        if (arr != nullptr) {
            while (i < MAX_SIZE) {
                std::cout << "arrPointPoint | " << **arrPointPoint <<  "\t\t arrPoint | " << *arrPoint << std::endl;
                arrPoint++;
                i++;
            }
        }
        else {
            std::cout << "The array is empty" << std::endl;
            myArray(arr);
        }
        std::cout << std::endl;
    }

    void clearMemory(int*& arr) {
        std::cout << "Cleaning the array" << std::endl;
        if (arr != nullptr) {
            delete[] arr;
            arr = nullptr;
            std::cout << "The array has been cleared" << std::endl;
        }
        else {
            std::cout << "The array is already empty" << std::endl;
        }
        std::cout << std::endl;
    }

    char* myText(char*& text) {
        int exit = 0;
        if (text == nullptr) {
            text = new char[MAX_TEXT];
        }
        do {
            std::cout << "Input a text : ";
            std::cin.ignore(10000, '\n');
            std::cin.getline(text, MAX_TEXT);
            std::cout << std::endl;
            exit = 1;
        } while (exit == 0);
        std::cout << std::endl;
        return text;
    }


    void readText(char*& text) {
        if (text != nullptr) {
            for (int i = 0; i < strlen(text) && text[i] != '\0'; i++) {
                std::cout << text[i];
            }
        }
        else {
            std::cout << "The text is empty" << std::endl;
            myText(text);
        }
        std::cout << std::endl;
    }

    void readReverse(char*& text) {
        if (text != nullptr) {
            size_t size = 0;
            char* pStart;
            char* pEnd;

            size = strlen(text);
            pEnd = &text[size - 1];
            pStart = &text[0];

            while (pEnd >= pStart) {
                std::cout << *pEnd;
                pEnd--;
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "The text is empty" << std::endl;
            myText(text);
        }
        std::cout << std::endl;
    }

    char* concat(char*& word1, char*& word2) {
        word1 = new char[MAX_TEXT];
        word2 = new char[MAX_TEXT];

        std::cout << "Insert the first word: ";
        std::cin >> word1;
        std::cout << "Insert the second word: ";
        std::cin >> word2;

        if (word1 != nullptr && word2 != nullptr) {
            size_t sizeD = strlen(word1);
            size_t sizeO = strlen(word2);

            char* result = new char[sizeD + sizeO + 1];

            char* str = result;
            char* tempDest = word1;
            char* tempOrig = word2;

            while (*tempDest != '\0') {
                *str = *tempDest;
                str++;
                tempDest++;
            }

            while (*tempOrig != '\0') {
                *str = *tempOrig;
                str++;
                tempOrig++;
            }

            *str = '\0';

            if (result != nullptr) {
                std::cout << result << std::endl;
            }

            return result;
        }
        else {
            return nullptr;
        }
        cleamText(word1);
        cleamText(word2);
        std::cout << std::endl;
    }

    void cleamText(char*& text) {
        std::cout << "Cleaning the text" << std::endl;
        if (text != nullptr) {
            delete[] text;
            text = nullptr;
            std::cout << "The text has been cleared" << std::endl;
        }
        else {
            std::cout << "The text is already empty" << std::endl;
        }
        std::cout << std::endl;
    }

    void menuInt() {
        int option;
        int exit = 0;
        int* arr = new int[MAX_SIZE];

        sdds::clearMemory(arr);

        do {
            std::cout << "MENU INTEGER" << std::endl;
            std::cout << " # 1 - Insert info" << std::endl;
            std::cout << " # 2 - Print" << std::endl;
            std::cout << " # 3 - Run" << std::endl;
            std::cout << " # 4 - Point to Point" << std::endl;
            std::cout << " # 5 - Clear" << std::endl;
            std::cout << " # 6 - Back to home" << std::endl;
            std::cout << " >>> ";
            std::cin >> option;
            std::cout << std::endl;

            switch (option) {
            case 1:
                arr = sdds::myArray(arr);
                break;
            case 2:
                sdds::printArray(arr);
                break;
            case 3:
                sdds::runArray(arr);
                break;
            case 4:
                sdds::pointToPoint(arr);
                break;
            case 5:
                sdds::clearMemory(arr);
                break;
            case 6:
                exit = option;
                break;
            }
        } while (exit == 0);
        std::cout << std::endl;
    }

    void menuChar() {
        int option;
        int exit = 0;
        char* text = new char[MAX_TEXT];
        char* dest = new char[255];
        char* orig = new char[255];

        sdds::cleamText(text);
        sdds::cleamText(dest);
        sdds::cleamText(orig);

        do {
            std::cout << "MENU CHARACTER" << std::endl;
            std::cout << " # 1 - Input text" << std::endl;
            std::cout << " # 2 - Read" << std::endl;
            std::cout << " # 3 - Reverse" << std::endl;
            std::cout << " # 4 - Concat" << std::endl;
            std::cout << " # 5 - Clean" << std::endl;
            std::cout << " # 6 - Back to home" << std::endl;
            std::cout << " >>> ";
            std::cin >> option;
            std::cout << std::endl;

            switch (option) {
            case 1:
                text = sdds::myText(text);
                break;
            case 2:
                sdds::readText(text);
                break;
            case 3:
                sdds::readReverse(text);
            case 4:
                sdds::concat(dest, orig);
                break;
            case 5:
                sdds::cleamText(text);
                break;
            case 6:
                exit = option;
                break;
            }
        } while (exit == 0);
        std::cout << std::endl;
    }
}
