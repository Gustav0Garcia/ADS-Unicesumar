/* Existem várias formas de se implementar uma árvore binária. A mais simples delas é usar um vetor de nós. Dessa forma, cada nó possui pelo menos três valores: uma referência para o pai do nó, 
uma referência para o filho à esquerda do nó e mais uma outra referência para o filho à direita do respectivo nó. O atributo "pai" vai apontar para a posição na qual o pai do nó se encontra, no vetor. 
O atributo "esquerda" vai armazenar a posição da raiz da sub-árvore à esquerda do nó, e o atributo "direita" guarda a posição da raiz da sub-árvore direita do nó, no vetor. 
Além disso, é relevante estabelecer um atributo "dado" que irá armazenar o conteúdo do nó.
É possível adicionar algumas regras à inserção de dados em uma árvore para que ela se torne ordenada. Assim, sempre que um novo dado estiver para ser adicionado junto à árvore, ele será comparado com o nó raiz. 
Se ele é menor do que a raiz, deverá ser adicionado na sub-árvore esquerda, caso contrário na sub-árvore direita.
Considere que, no seu primeiro estágio, ao realizar um teste no seu programa que implementa árvores binárias, você inseriu os números de seu RA (da esquerda para a direita) como se cada algarismo fosse um nó na árvore. 
Dessa forma, altere o código-fonte dado para que seu programa, durante a execução, monte uma árvore binária a partir dos dígitos de seu RA. O seu programa não deve realizar a inserção automaticamente ordenada, 
ou seja, não é preciso desenvolver um método que realize a inserção ordenadamente. Você mesmo pode construir a árvore (via inserções simples, porém seguindo as regras de inserção ordenada), 
de maneira a compor a árvore ordenada com os números de seu RA. Além disso, você precisará criar uma função que seja capaz de realizar o percurso pré-ordem na árvore recém-criada, 
partindo da raiz e imprimindo na tela os nós visitados de acordo com esse método.
Por exemplo, considere que seu RA é igual a 61207895. Abaixo temos um exemplo de como sua árvore ordenada deveria ser, bem como o resultado do caminhamento pré-ordem quando executado a partir da raiz da respectiva árvore. 
Visitação pré-ordem: 6 1 0 2 7 5 8 9 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

//Constantes
#define E 0
#define D 1
#define R -1

//Struct dos nós
typedef struct NO {
	int dado;
	struct NO* esq;
	struct NO* dir;
	struct NO* pai;
} NO;

//Struct da árvore
typedef struct ARVORE{
	NO* raiz;
}ARVORE;

//Definindo a estrutura da fila para apresentar os valores inseridos
typedef struct no{
    int dado;
    struct no *proximo;
}*ptr_no;

//Definindo variáveis
ptr_no fila;
ARVORE a;
int op;

//Protótipação
void inicializaArvore(ARVORE arv);
void inicializaNo(NO* n, int val);
void insereNoArvoreOrdenada(int valor);
void preOrdem(NO* raiz);
void menu_mostrar(void);
void fila_inserir(ptr_no fila,int op);
void fila_mostrar(ptr_no fila);

//Função que sempre deve ser chamada ao se criar uma nova árvore
void inicializaArvore(ARVORE arv)
{
	arv.raiz = NULL;
}

//Função utilizada para inicializar um novo nó na árvore
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

/* Função que realiza a inserção de maneira ordenada
Valores menores  vão à esquerda
Valores maiores ou iguais vão à direita */
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
				printf("No inserido à esquerda do No %d", pai->dado);
				pai->esq = novoNo;
				return;
			}
		}
		else{
			corrente = corrente->dir;
			if(!corrente){
				printf("No inserido à direita do No %d", pai->dado);
				pai->dir = novoNo;
				return;
			}
		}
	}
}

//Executa o caminhamento pré-ordem a partir do nó indicado por "raiz"
void preOrdem(NO* raiz){
	if(raiz){
		printf("%d | ", raiz->dado);
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}

void menu_mostrar(void){
	printf("\n\n__________________________________________________________________________________________________\n\n\tMenu\n\n1 - Inserir valores na árvore\n2 - Realizar busca pré ordem\n0 - Sair\n\n__________________________________________________________________________________________________\n\n");
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

//Desenha o conteúdo da fila na tela
void fila_mostrar(ptr_no fila){
    system("cls");
    printf("__________________________________________________________________________________________________\n\nValores informados (Desconsiderar o 0)\n\n| ");
    while(fila->proximo != NULL){
        printf("%d | ", fila->dado);
        fila = fila->proximo;
    }
    printf("%d | ", fila->dado);
}

//Função principal
int main(){
	
	setlocale(LC_ALL, "");
	
	char aux = 5;
	clock_t t; //variável para armazenar o tempo
	inicializaArvore(a);
	
	//Criando o primeiro nó da fila
    fila = (ptr_no) malloc(sizeof(struct no));
    fila->dado = 0;
    fila->proximo = NULL;
	do{
		system("cls");
		fila_mostrar(fila);
		menu_mostrar();
		printf("Informar a opção: ");
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
				printf("Busca Pré Ordem: \n\n| ");
				t = clock(); //Calcula o tempo inicial antes da organização pré ordem
				preOrdem(a.raiz);
				t = clock() -t; //Calcula o tempo final depois da organização pré ordem
				printf("\n\nTempo em milissegundos da execução Pré Ordem: %lf\n\n__________________________________________________________________________________________________", (((clock() - t) / (double)CLOCKS_PER_SEC/1000))); //Informa o tempo, foi dividido em 1000 para informar em milissegundos
				printf("\n\n");
				system("pause");
				break;
			default:
				if(aux > '2'){
					fila_mostrar(fila);
					menu_mostrar();
					printf("Opção inválida\n\n__________________________________________________________________________________________________\n\n");
					system("pause");
				}
				break;
		}
	}while(aux != '0');
	system("cls");
	printf("=================================================================\n=\t\t\t\t\t\t\t\t=\n=\t Curso: Análise e Desenvolvimento de Sistemas\t\t=\n=\t Matéria: Estrutura de Dados II\t\t\t\t=\n=\t Aluno: Gustavo Garcia\t\t\t\t\t=\n=\t RA: 21025427-5\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n_________________________________________________________________\n\n");
	return(0);
}
