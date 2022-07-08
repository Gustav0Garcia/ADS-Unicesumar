/* Existem v�rias formas de se implementar uma �rvore bin�ria. A mais simples delas � usar um vetor de n�s. Dessa forma, cada n� possui pelo menos tr�s valores: uma refer�ncia para o pai do n�, 
uma refer�ncia para o filho � esquerda do n� e mais uma outra refer�ncia para o filho � direita do respectivo n�. O atributo "pai" vai apontar para a posi��o na qual o pai do n� se encontra, no vetor. 
O atributo "esquerda" vai armazenar a posi��o da raiz da sub-�rvore � esquerda do n�, e o atributo "direita" guarda a posi��o da raiz da sub-�rvore direita do n�, no vetor. 
Al�m disso, � relevante estabelecer um atributo "dado" que ir� armazenar o conte�do do n�.
� poss�vel adicionar algumas regras � inser��o de dados em uma �rvore para que ela se torne ordenada. Assim, sempre que um novo dado estiver para ser adicionado junto � �rvore, ele ser� comparado com o n� raiz. 
Se ele � menor do que a raiz, dever� ser adicionado na sub-�rvore esquerda, caso contr�rio na sub-�rvore direita.
Considere que, no seu primeiro est�gio, ao realizar um teste no seu programa que implementa �rvores bin�rias, voc� inseriu os n�meros de seu RA (da esquerda para a direita) como se cada algarismo fosse um n� na �rvore. 
Dessa forma, altere o c�digo-fonte dado para que seu programa, durante a execu��o, monte uma �rvore bin�ria a partir dos d�gitos de seu RA. O seu programa n�o deve realizar a inser��o automaticamente ordenada, 
ou seja, n�o � preciso desenvolver um m�todo que realize a inser��o ordenadamente. Voc� mesmo pode construir a �rvore (via inser��es simples, por�m seguindo as regras de inser��o ordenada), 
de maneira a compor a �rvore ordenada com os n�meros de seu RA. Al�m disso, voc� precisar� criar uma fun��o que seja capaz de realizar o percurso pr�-ordem na �rvore rec�m-criada, 
partindo da raiz e imprimindo na tela os n�s visitados de acordo com esse m�todo.
Por exemplo, considere que seu RA � igual a 61207895. Abaixo temos um exemplo de como sua �rvore ordenada deveria ser, bem como o resultado do caminhamento pr�-ordem quando executado a partir da raiz da respectiva �rvore. 
Visita��o pr�-ordem: 6 1 0 2 7 5 8 9 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Struct dos n�s
typedef struct NO {
	int dado;
	struct NO* esq;
	struct NO* dir;
	struct NO* pai;
} NO;

//Struct da �rvore
typedef struct ARVORE{
	NO* raiz;
}ARVORE;

//Definindo a estrutura da fila para apresentar os valores inseridos
typedef struct no{
    int dado;
    struct no *proximo;
}*ptr_no;

//Definindo vari�veis
ptr_no fila;
ARVORE a;
int op;

//Prot�tipa��o
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void menu_mostrar(void);
void fila_inserir(ptr_no fila,int op);
void fila_mostrar(ptr_no fila);

//Fun��o que sempre deve ser chamada ao se criar uma nova �rvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Fun��o utilizada para inicializar um novo n� na �rvore
void inicializaNo(NO* n, int val){
	if(!n)
	{
		printf("Falha de alocacao.\n");
		return;
	}
	n->pai = NULL;
	n->esq = NULL;
	n->dir = NULL;
	n->dado = val;
}

/* Fun��o que realiza a inser��o de maneira ordenada
Valores menores  v�o � esquerda
Valores maiores ou iguais v�o � direita */
void insereNoArvoreOrdenada(int valor)
{
	NO* corrente = a.raiz;
	NO* pai;

	NO* novoNo = (NO*) malloc(sizeof(NO));
	inicializaNo(novoNo, valor);
	printf("\nInserindo No %d\n", novoNo->dado);
	
	if(corrente == NULL)
	{
		a.raiz = novoNo;
		printf("No inserido na raiz");
		return;
	}
	
	while(corrente){
		pai = corrente;
		if(novoNo->dado < corrente->dado){
			corrente = corrente->esq;
			if(!corrente){
				printf("No inserido � esquerda do No %d", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido � direita do No %d", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

//Executa o caminhamento pr�-ordem a partir do n� indicado por "raiz"
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d | ", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void menu_mostrar(void){
	printf("\n\n__________________________________________________________________________________________________\n\n\tMenu\n\n1 - Inserir valores na �rvore\n2 - Realizar busca pr� ordem\n0 - Sair\n\n__________________________________________________________________________________________________\n\n");
}

//Insere um elemento no final da fila
void fila_inserir(ptr_no fila, int op){
    while(fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(struct no));
    fila = fila->proximo;
    fila->dado = op;
    fila->proximo = NULL;
}

//Desenha o conte�do da fila na tela
void fila_mostrar(ptr_no fila){
    system("cls");
    printf("__________________________________________________________________________________________________\n\nValores informados (Desconsiderar o 0)\n\n| ");
    while(fila->proximo != NULL){
        printf("%d | ", fila->dado);
        fila = fila->proximo;
    }
    printf("%d | ", fila->dado);
}

//Fun��o principal
int main(){
	
	setlocale(LC_ALL, "");
	
	char aux = 5;
	clock_t t; //vari�vel para armazenar o tempo
	inicializaArvore(a);
	
	//Criando o primeiro n� da fila
    fila = (ptr_no) malloc(sizeof(struct no));
    fila->dado = 0;
    fila->proximo = NULL;
	do{
		system("cls");
		fila_mostrar(fila);
		menu_mostrar();
		printf("Informar a op��o: ");
		aux = getchar();	
		switch(aux){
			case '1':
					fila_mostrar(fila);
					menu_mostrar();
					printf("Informe o valor a ser inserido: ");
					scanf("%d", &op);
					fila_inserir(fila, op);
					insereNoArvoreOrdenada(op);
					printf("\n\n__________________________________________________________________________________________________\n\n");
					system("pause");
					system("cls");
				break;
			case '2':
				fila_mostrar(fila);
				menu_mostrar();
				printf("Busca Pr� Ordem: \n\n| ");
				t = clock(); //Calcula o tempo inicial antes da organiza��o pr� ordem
				preOrdem(a.raiz);
				t = clock() -t; //Calcula o tempo final depois da organiza��o pr� ordem
				printf("\n\nTempo em milissegundos da execu��o Pr� Ordem: %lf\n\n__________________________________________________________________________________________________", (((clock() - t) / (double)CLOCKS_PER_SEC/1000))); //Informa o tempo, foi dividido em 1000 para informar em milissegundos
				printf("\n\n");
				system("pause");
				break;
			default:
				if(aux > '2'){
					fila_mostrar(fila);
					menu_mostrar();
					printf("Op��o inv�lida\n\n__________________________________________________________________________________________________\n\n");
					system("pause");
				}
				break;
		}
	}while(aux != '0');
	system("cls");
	printf("=================================================================\n=\t\t\t\t\t\t\t\t=\n=\t Curso: An�lise e Desenvolvimento de Sistemas\t\t=\n=\t Mat�ria: Estrutura de Dados II\t\t\t\t=\n=\t Aluno: Gustavo Garcia\t\t\t\t\t=\n=\t RA: 21025427-5\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n_________________________________________________________________\n\n");
	return(0);
}
