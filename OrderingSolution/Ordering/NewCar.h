#ifndef NEW_CAR
#define NEW_CAR

#include <iostream>
#include <cstring>

namespace sdds {
    class NewCar {
        NewCar* carArray; // Ponteiro para o array de NewCar
        int carCount; // Contador para acompanhar o n�mero de carros no array
        int id; // ID inserido pelo usu�rio para identificar o carro no sistema
        char* name; // Nome do ve�culo
        char* brand; // Marca do ve�culo
        char* color; // Cor do ve�culo
        char* plate; // Placa do ve�culo
        double price; // Pre�o do ve�culo

    public:
        NewCar(); // Construtor padr�o
        NewCar(const NewCar& newcar); // Construtor de c�pia
        NewCar& operator=(const NewCar& newcar); // Operador de atribui��o
        ~NewCar(); // Destrutor padr�o

        void copy(char*& dest, const char* src); //Fas a copia de uma string de maneira manual
        void addingNewCar(); // Cria um novo carro
        NewCar* getArrayCar(); // Fun��o para obter o ponteiro para o array de carros
        void menu(); // Menu de op��es
        void printList(); // Exibe a lista de carros adicionados
        void orderingByName(); // Ordena a lista por nome
        void orderingByID(); // Ordena a lista por ID

    private:
        void copyArray(const NewCar& other);
        /*static int compareByName(const void* a, const void* b);
        static int compareByID(const void* a, const void* b);*/
    };
}
#endif // !NEW_CAR