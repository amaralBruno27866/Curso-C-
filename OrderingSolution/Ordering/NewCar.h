#ifndef NEW_CAR
#define NEW_CAR

#include <iostream>
#include <cstring>

namespace sdds {
    class NewCar {
        NewCar* carArray; // Ponteiro para o array de NewCar
        int carCount; // Contador para acompanhar o número de carros no array
        int id; // ID inserido pelo usuário para identificar o carro no sistema
        char* name; // Nome do veículo
        char* brand; // Marca do veículo
        char* color; // Cor do veículo
        char* plate; // Placa do veículo
        double price; // Preço do veículo

    public:
        NewCar(); // Construtor padrão
        NewCar(const NewCar& newcar); // Construtor de cópia
        NewCar& operator=(const NewCar& newcar); // Operador de atribuição
        ~NewCar(); // Destrutor padrão

        void copy(char*& dest, const char* src); //Fas a copia de uma string de maneira manual
        void addingNewCar(); // Cria um novo carro
        NewCar* getArrayCar(); // Função para obter o ponteiro para o array de carros
        void menu(); // Menu de opções
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