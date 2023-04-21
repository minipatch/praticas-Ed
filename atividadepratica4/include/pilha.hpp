#ifndef PILHA_HPP
#define PILHA_HPP

#include "filacircular.hpp"


class pilha{
    private:
        Circular c;

    public:

        pilha();

        bool Vazia();
        bool Cheia();

        void empilha(int valor);

        void desempilhar();

        void imprimir();


        void destroipilha();
        Circular getCircular();
};




#endif 