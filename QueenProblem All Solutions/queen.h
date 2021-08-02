#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cordenadas{
	int x;
	int y;	
}Cordenadas;

//criando uma pilha com as cordenadas X e Y ao invés de INT como na aula
typedef struct pilha{
	//A pilha terá que guardar as posicoes da matriz, [x] e [y] 
	int topo;
	int tamanho; //tamanho vai ser o valor da coluna/linha 
	Cordenadas * vetor;
}Pilha;


typedef struct position{
	int x;
	int y;
	int info;
}Position;

//Matriz = vetor de vetor com uma informação em cada posição
typedef struct matriz {
    int cols; // number of cols
    int rows; // number of lines
    //Position tabuleiro[][]
    Position ** tabuleiro;
} Matriz;




/**		Funcoes Estetica   		**/
void printaMenu();




/**		Funcoes da Matriz 		**/
Matriz * alocarMatriz (int val);
	
void printMatriz (Matriz * m);		




/**		Funcoes da Pilha		**/
Pilha * create_stack (int tam);

int empty_stack (Pilha *p);

int full_stack (Pilha *p);

//Push = Empilhar
void push (Pilha *p, int x, int y);

//Pop = Retirar
Cordenadas * pop (Pilha *p);

void print_stack(Pilha *p);

void destroy_stack (Pilha *p);




/**		Funcoes das Rainhas		**/
int isSafe(Matriz * m, int rows, int cols);   //Funcao auxiliar que retorna 0(invalida) ou 1(valida)

Pilha * solveQueensProblem(Matriz * m, Pilha * p, int cont);
//Pilha * solveQueensProblem(Matriz * m, Pilha * p);

int verificaResposta(Matriz * m);

//Acabou nao sendo necessaria4
//void zeraMatriz(Matriz * m);