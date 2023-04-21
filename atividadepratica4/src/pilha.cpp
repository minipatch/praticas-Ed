#include "pilha.hpp"

pilha::pilha()
{   
}



bool pilha::Vazia()
{
    return c.Vazia();
}



void pilha::empilha(int valor)
{
        c.empilha(valor);
}

void pilha::desempilhar()
{
    if (Vazia())
    {
        std::cout << "pilha esta vazia" << std::endl;
        return;
    }

    int  size = c.getFin() - c.getInicio() +1;
    
    for(int i =0;i < size-1;i++){
        int valor = c.getValor();    
        c.desempilhar();
        c.empilha(valor);
    }
    c.desempilhar();
}


void pilha::imprimir(){
    if(Vazia()){
        std::cout <<"vazia"<<std::endl;
        return;
    }
    
    int aux =  c.getFin() - c.getInicio()+1;
    for(int i =0 ; i<aux; i++){
        int value = c.getValor();
        c.desempilhar();
        c.empilha(value);
        std::cout<<value<<std::endl;    
    }
        
    
}

void pilha::destroipilha()
{
    c=Circular();
}

Circular pilha::getCircular(){
    return c;
}