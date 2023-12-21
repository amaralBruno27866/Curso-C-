#ifndef HEADER_H
#define HEADER_H

#include <iostream>

#define MAX_SIZE 10
#define MAX_TEXT 255

namespace sdds {
    int* myArray(int*& arr);
    void printArray(int*& arr);
    void runArray(int*& arr);
    void pointToPoint(int*& arr);
    void clearMemory(int*& arr);

    char* myText(char*& text);
    void readText(char*& text);
    void cleamText(char*& text);
    void readReverse(char*& text);
    char* concat(char*& word1, char*& word2);

    void menuInt();
    void menuChar();
}

#endif // !HEADER_H