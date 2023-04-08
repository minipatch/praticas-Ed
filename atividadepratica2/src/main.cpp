#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <getopt.h>
#include "fatorial.h"
#include "fibonacci.h"
#include "msgassert.h"

using namespace std;

// definicoes de operacoes a serem testadas
#define OPFATORIAL 1
#define OPFIBONACCI 2

typedef struct opt{
  int opescolhida;
  int numero;
} opt_tipo;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"OPCOES:\n");
  fprintf(stderr,"\t-t \t\t(fatorial) \n");
  fprintf(stderr,"\t-b \t\t(fibonacci) \n");
}


void parse_args(int argc,char ** argv, opt_tipo * opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opt->opescolhida = -1;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "t:b:")) != EOF){
       switch(c) {
         case 't':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPFATORIAL;
            opt->numero = atoi(optarg);
                  break;
         case 'b':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPFIBONACCI;
            opt->numero = atoi(optarg);
                  break;
         default:
                  uso();
                  exit(1);

       }
       // verificacao da consistencia das opcoes
       erroAssert(opt->opescolhida>0,"necessario escolher operacao");
     }
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao das operacoes
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
  clock_t time_req;
  opt_tipo opt;
  // avaliar linha de comando
  parse_args(argc,argv,&opt);

  // execucao dependente da operacao escolhida
  switch (opt.opescolhida){
    case OPFATORIAL:
         time_req = clock();
         cout << "FATORIAL\n";
         cout << "\tRecursivo: " << Factorial_recursive(opt.numero) << endl;
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
         time_req = clock();
         cout << "\tIterativo: " << Factorial_iterative(opt.numero) << endl; 
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
	 break;
    case OPFIBONACCI:
         time_req = clock();
         cout << "FIBONACCI\n";
         cout << "\tRecursivo: " << Fibonacci_recursive(opt.numero) << endl; 
         time_req = clock() - time_req;
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
         time_req = clock();
         cout << "\tIterativo: " << Fibonacci_iterative(opt.numero) << endl; 
         cout << "\t\tTempo de relógio gasto -> " << 
         ((float)time_req/CLOCKS_PER_SEC) * 1000 << " milisseconds" << endl;
	 break;
   default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
         uso();
	 exit(1);
  }

  return 0;
}
