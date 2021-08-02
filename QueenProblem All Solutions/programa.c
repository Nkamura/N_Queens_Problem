#include <stdio.h>
#include <stdlib.h>
#include "queen.h"



int main(){
	printaMenu();
	//Verificação de valor, não faz sentido ter um tabuleiro 0x0 ou com dimensões negativas
	//E também não pode ser 2 e 3 devido ao fato de que se deve ter 1 rainha em cada linha
	int n=-1;
	while(n<=0 || n==2 || n ==3){
		printf("\nDigite a dimensao(N) do tabuleiro (NxN):");
		scanf("%d",&n);	
	}
	
	//Criacao das pilhas
	Pilha * p = create_stack(n+1);

	//Criacao do tabuleiro e inicializacao -> 1 parametro ja que vai ser NxN 
	Matriz * tabuleiro = alocarMatriz(n);

	//começa percorrendo da primeira linha
	int cont = 0;
	solveQueensProblem(tabuleiro,p,cont);	

	destroy_stack(p);

	return 0;
}
