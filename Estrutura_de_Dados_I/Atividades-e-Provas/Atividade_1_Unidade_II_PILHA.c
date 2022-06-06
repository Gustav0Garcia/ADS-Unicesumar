/* Quando um livro � devolvido na Biblioteca do Unicesumar, o funcion�rio respons�vel pelo recebimento coloca o livro em cima de uma pilha de livros na
mesa ao lado da recep��o.O auxiliar de bibliotec�rio pega o livro do topo da pilha, verifica o seu c�digo e leva - o para o seu devido local no acervo.
No atual sistema de informa��o, � poss�vel verificar se o livro est� dispon�vel ou se est� emprestado.Entretanto o livro que acabou de ser devolvido ainda
n�o se encontra na prateleira, pois existe um intervalo de tempo entre a devolu��o do mesmo e o momento em que ele � guardado na estante.
A sugest�o do departamento de TI � de criar um programa que fa�a o controle na pilha, assim, pode - se verificar se o livro ainda n�o foi guardado e qual a 
sua posi��o dentro da pilha de livros que aguardam ao lado da recep��o.
a) Crie uma estrutura para a pilha de livros.Lembre - se de que ela tem que ter um vetor para armazenar os dados(c�digo, nome do livro e autor) e dois
n�meros inteiros, um para controlar o in�cio e outro o final da pilha.
b) Defina a vari�vel que ser� um vetor do tipo pilha de livros.
c) Fa�a uma fun��o de empilhamento, lembrando - se de verificar se a pilha atingiu o tamanho m�ximo de livros(a mesa n�o aguenta muito peso).
d) Crie uma fun��o para desempilhamento de livros.N�o se esque�a de que � necess�rio verificar se ainda existem livros para ser guardados.
e) Elabore uma fun��o que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recep��o. */

//a)
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma warning(disable : 4996)

//Constantes
#define tamanho 5

//Estrutura do livro
struct tlivro {
    int codigo;
    char nome[50];
    char autor[50];
};

//Estrutura da Pilha
struct tpilha {
    struct tlivro dados[tamanho];
    int ini;
    int fim;
};

//b)
//Vari�veis globais
struct tpilha pilha; 
int op;

//Prototipa��o
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

//Fun��o principal
int main(){
    setlocale(LC_ALL, "Portuguese");

    op = 1;
    pilha.ini = 0;
    pilha.fim = 0;

    while (op != 0) {
    	system("Cls");
        pilha_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op) {
        case 1:
            pilha_entrar();
            break;
        case 2:
            pilha_sair();
            break;
        }
    }
    return(0);
}

//c)
//Adicionar elemento no final da Pilha
void pilha_entrar() {
	system("Cls");
    if (pilha.fim == tamanho) {
        printf("\nA pilha est� cheia!\n\n");
        system("Pause");
    }
    else {
        printf("\nDigite o c�digo do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].codigo);
        fflush(stdin);
        printf("\nDigite o nome do livro: ");
        scanf("%s", pilha.dados[pilha.fim].nome);
        fflush(stdin);
        printf("\nDigite o nome do autor: ");
        scanf("%s", pilha.dados[pilha.fim].autor);
        fflush(stdin);
        pilha.fim++;
    }
}

//d)
//Retirar o �ltimo elemento da Pilha
void pilha_sair() {
    if (pilha.ini == pilha.fim) {
        printf("\nApilha est� vazia\n\n");
        system("Pause");
    }
    else {
        pilha.dados[pilha.fim - 1].codigo = 0;
        strcpy(pilha.dados[pilha.fim-1].nome, "");
        strcpy(pilha.dados[pilha.fim-1].autor, "");
        pilha.fim--;
    }
}

//Mostrar o conte�do da Pilha
void pilha_mostrar() {
    int i;
    printf("Pilha: [");
    for (i = 0; i < tamanho; i++) {
        printf(" %d ", pilha.dados[i].codigo);
    }
    printf("]\n\n");
}

//Apresenta o menu de op��es
void menu_mostrar() {
        printf("\nEscolha uma op��o:\n");
    printf("1 - Incluir Livro da pilha\n2 - Excluir Livro da pilha\n0 - Sair\n\n");
}
