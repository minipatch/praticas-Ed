#include "filacircular.hpp"

Circular::Circular(){
    this->inicio = -1;
    this->fin = -1;
}


bool Circular::Vazia(){
    return inicio == -1 && fin == -1;
}


bool Circular::Cheia(){
    return (fin + 1) % MAXSIZE == inicio;
}


void Circular::empilha(int preencher){
    if(Cheia()){
        std::cout<<"esta cheio"<<std::endl;
        return;
    }    
    if (Vazia()) {
        inicio = 0;
        fin = 0;
    }
    else{
        fin = (fin +1)% MAXSIZE;
    }
    vetor[fin] = preencher;
}


void Circular::desempilhar(){
    if(Vazia()){
        std::cout<<"esta vazia"<<std::endl;
        return ;
    }
        else if(inicio==fin){
        inicio =-1;
        fin = -1;
    }
    else{
        inicio = (inicio+1) % MAXSIZE;
    }
}



int Circular::getInicio(){
    return inicio;
}

int Circular::getFin(){
    return fin;
}

int Circular::getValor(){
    if(Vazia()){
        std::cout<<"vazia"<<std::endl;
    }
    return vetor[inicio];
}

void Circular::imprimir(){
    if(Vazia()){
        std::cout<<"vazia"<<std::endl;
        return;
    }

    std::cout<<inicio<<fin<<std::endl;
    int  i = inicio;
    while(i!=fin){
        std::cout<<vetor[i]<<std::endl;
        i= (i+1)%MAXSIZE;
    }
    std::cout<<vetor[fin]<<std::endl;
}

