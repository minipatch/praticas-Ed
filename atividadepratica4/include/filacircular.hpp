#ifndef FILACIRULAR_HPP
#define FILACIRCULAR_HPP

#include <iostream>


const int MAXSIZE = 10;

class Circular{
    private:
        int inicio;
        int fin;

        int valor;

        int vetor[MAXSIZE];

    public:

        Circular();

        bool Vazia();
        bool Cheia();

        void empilha(int preencher);

        void desempilhar();

        int getInicio();
        int getFin();

        int getValor(); 


        void imprimir();
};



#endif