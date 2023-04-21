#include "pilha.hpp"


int main(){
    pilha p1;

    for(int i=0 ;i<10 ;i++){
        int  valor = rand()%10;
        p1.empilha(valor);
    }
    std::cout << "empilhando"<< std::endl;
    p1.imprimir();
    std::cout <<"desempilhando"<<std::endl;
    p1.desempilhar();
    
    p1.imprimir();

    while(!p1.Vazia()){
        p1.desempilhar();
    }
    p1.imprimir();

}