#include "queen.h"

//STRUCTS UTILIZADAS
/*

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

typedef struct position
{
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
*/


void printaMenu(){
	printf("***************************************************************************\n");
	printf("**************** Todas solucoes para a matriz NxN *************************\n");
	printf("***************************************************************************\n");
}


  /***********************************/
 /**	   Funcoes da Pilha 	   **/
/***********************************/

//Criando e Inicializando a pilha 
Pilha* create_stack (int size){
	Pilha * p = (Pilha *) malloc(sizeof(Pilha));
	p->vetor = (Cordenadas *) malloc(size * (sizeof(Cordenadas)));
	p->tamanho = size;
	//(zero -> n-1)
	p->topo=0;
	return p;
}

/*Função para testar se a pilha está vazia!*/
int empty_stack (Pilha *p) {
	//Topo =0
	return (p->topo == 0);
}

/*Função para testar se a pilha está cheia!*/
int full_stack (Pilha *p) {
	//Topo=tamanho 
	return (p->topo == p->tamanho);
}

/*Função para empilhar um elemento!*/
void push (Pilha *p, int x, int y) {
	if (full_stack(p)) {
		printf ("Pilha cheia\n");
		exit(1);
	}
	p->vetor[p->topo].x = x;
	p->vetor[p->topo].y = y;
	p->topo++;
	//printf("X: %d   Y:%d\n",p->vetor[p->topo].x , p->vetor[p->topo].y);
}

/*Função para desempilhar um elemento!*/
Cordenadas * pop (Pilha *p) {
	if (empty_stack(p)) {
		printf ("Pilha vazia\n");
		exit(1);
	}else{

		p->topo --;
		return (p->vetor);
	}
}

/* Funcao auxiliar para ver se a pilha ta guardando as posicoes certo **/
void print_stack(Pilha *p){
	printf("Pilha com os valores validos da matriz\n");
	//for(int i = p->topo-1; i >= 0; i--){
	for(int i = 0; i < p->topo-1; i++){
		//printf("%d\n", p->topo);
		printf(" x:%d y:%d\n",p->vetor[i].x,p->vetor[i].y);
	}
	printf("________________________________________________________\n");
	printf("\n");
}

/*Função para liberar a memória alocada.*/
void destroy_stack (Pilha *p) {
	free(p->vetor);
	free(p);
}





  /***********************************/
 /**	  Funcoes da Matriz 	   **/
/***********************************/

//Aloca a matriz de Position
Matriz * alocarMatriz (int val){	
	int i=0, j=0;
	//Criando um MAT sem ser por referência e passando a copia (que já é o suficiente)
	Matriz * mat = (Matriz*) malloc(sizeof(Matriz)); 
	mat->tabuleiro = (Position **) malloc(sizeof(Position*) * val); 

	for(i=0;i<val;i++){
		mat->tabuleiro[i] = (Position*) malloc(sizeof(Position) * val);
	}

	//Incializa o valor de cols e rows
	mat->cols = val;	
	mat->rows = val;
	
	for (i = 0; i < val; i++)
	{
		for (j = 0; j < val; j++)
		{
			/* code inicializar valores*/
			mat->tabuleiro[i][j].x = i;
			mat->tabuleiro[i][j].y = j;
			mat->tabuleiro[i][j].info = 0;
			//printf("\ni:%d j:%d", i,j);
		}
	}
	return mat;
}

///Printa a matriz no terminal
void printMatriz (Matriz * m){
	//Para cada linha imprimir linha e sua coluna 
	printf("\n");
	for(int i=0; i<m->rows; i++){
		for(int j=0; j<m->cols; j++){
			printf("%d  ", m->tabuleiro[i][j].info);
		}
		printf("\n");
	}
	printf("\n");
}

//zeraMatriz(&tabuleiro); chamar passando por referencia pra realmente zerar a matriz
//Zera a matriz para recomeçar a verificacao
/*	void zeraMatriz(Matriz * m){
		for(int i=0; i<m->rows; i++){
			for(int j=0; j<m->cols; j++){
				m->tabuleiro[i][j].info=0;
			}	
		}
	}*/





  /***********************************/
 /**	  Funcoes da Rainha 	   **/
/***********************************/

/**			O ROWS E COLS E DA POSICAO DA RAINHA QUE ESTAMOS ANALISANDO ! 			**/
//Verificar se apartir da posicao em que estamos, tem alguma outra rainha na area de ataque
//Verifica se a posicao m[rows][cols] é valida
int isSafe(Matriz * m, int rows, int cols){
	int i=0;
	int j=0;
	for (i = 0; i<m->cols; i++) {
		//se tiver rainha na coluna retorna 0
		if(m->tabuleiro[rows][i].info == 1){ //daria pra fazer sem essa comparacao ja que vai ser so 0 e 1
			//verificacao para confirmar o funcionamento
			//m.tabuleiro[rows][i].info =1;
			//printMatriz(m);
			return 0;//Posicao invalida
		}
	}//Verificando mesma linha


	for (i = 0; i<m->rows; i++) {
		//se tiver rainha na coluna retorna 0
		if(m->tabuleiro[i][cols].info == 1){ 
			//verificacao para confirmar o funcionamento
			//m.tabuleiro[i][cols].info = 1;
			return 0;//Posicao invalida
		}
	}//Verificando a mesma coluna


 	//***** Verificando as diagonais *****
 	//fazendo i e j junto pois os dois estao totalmente atrelados
	for (i=rows, j=cols; i>=0 && j>=0; i--, j--){
		if (m->tabuleiro[i][j].info==1){
			//m.tabuleiro[i][j].info = 1;
			//setando 1 para visualizar se esta funcionando certo :m.tabuleiro[i][j].info =1 ;
			return 0;
		}
	}//Diagonal esquerda de cima conferida

	for (i=rows, j=cols; i>=0 && j<=m->cols-1; i--, j++){
		if (m->tabuleiro[i][j].info==1){
			//m.tabuleiro[i][j].info = 1;
			//setando 1 para visualizar se esta funcionando certo :m.tabuleiro[i][j].info =1 ;
			return 0;
		}
	}//Diagonal direita de cima

	for (i=rows, j=cols; i<=m->rows-1 && j>=0 ; i++, j--){
		if(m->tabuleiro[i][j].info == 1){
			//m.tabuleiro[i][j].info =1;
			return 0;
		}
	}//Diagonal esquerda de baixo 

	for (i=rows, j=cols; i<=m->cols-1 && j<=m->cols-1; i++, j++){
		if(m->tabuleiro[i][j].info == 1){
			//m.tabuleiro[i][j].info = 1;
			return 0;
		}
	}//Diagonal direita de baixo 
	//printf("\nvalor valido\n");
	//Retorna que pode posicionar sem problema
	return 1;
}

//Passar por referencia (copia tambem daria): verificaResposta(&matriz);
int verificaResposta(Matriz * m){
	int totalEsperado = 0;
	for(int i=0; i<m->rows; i++){
		for(int j=0; j<m->cols; j++){
			if(m->tabuleiro[i][j].info==1){
				//Considerando que so vai ter 1 numero 1 por linha -> garantir no posicionamento 
				totalEsperado++;
			}
		}
	}
	if(totalEsperado == m->rows){
		//numero um igual numero de linhas
		return 1;
	}else
	return 0;	
}


Pilha * solveQueensProblem(Matriz * m, Pilha * p, int cont){
	
	/**		Caso Base		**/
	if(cont == m->cols && verificaResposta(m)){
		printf("Matriz resultante:");
		printMatriz(m);
		if(m->cols == 1){
			printf("Pilha com os valores validos da matriz \n x:0 y:0\n");
		}else{
		print_stack(p);}
		return p;
	}

	//varrendo todas as possibilidades: Como esta indo de linha em linha, verifica de coluna em coluna !!	
	for(int coluna = 0; coluna<m->cols; coluna++){
		push(p,cont,coluna);

		if(isSafe(m,cont,coluna)){ // retorna (1) ou (0) significa que é seguro
			m->tabuleiro[cont][coluna].info=1;
			//printf("Posicao Valida -> X:%d Y:%d \n", cont ,coluna);
			/**		Chama recursivo		**/
			//Retorna pilha e eu estou so chamando 
			solveQueensProblem(m ,p ,cont+1);
		}
		//Não pode ser if else pq se não ele depende do if e se sai da função sem fazer nada
			//se nao for valido ele tira da pilha e tenta o proximo
			m->tabuleiro[cont][coluna].info = 0;
			pop(p);
	}
}