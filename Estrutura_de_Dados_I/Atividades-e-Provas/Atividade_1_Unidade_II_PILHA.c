/* Quando um livro é devolvido na Biblioteca do Unicesumar, o funcionário responsável pelo recebimento coloca o livro em cima de uma pilha de livros na
mesa ao lado da recepção.O auxiliar de bibliotecário pega o livro do topo da pilha, verifica o seu código e leva - o para o seu devido local no acervo.
No atual sistema de informação, é possível verificar se o livro está disponível ou se está emprestado.Entretanto o livro que acabou de ser devolvido ainda
não se encontra na prateleira, pois existe um intervalo de tempo entre a devolução do mesmo e o momento em que ele é guardado na estante.
A sugestão do departamento de TI é de criar um programa que faça o controle na pilha, assim, pode - se verificar se o livro ainda não foi guardado e qual a 
sua posição dentro da pilha de livros que aguardam ao lado da recepção.
a) Crie uma estrutura para a pilha de livros.Lembre - se de que ela tem que ter um vetor para armazenar os dados(código, nome do livro e autor) e dois
números inteiros, um para controlar o início e outro o final da pilha.
b) Defina a variável que será um vetor do tipo pilha de livros.
c) Faça uma função de empilhamento, lembrando - se de verificar se a pilha atingiu o tamanho máximo de livros(a mesa não aguenta muito peso).
d) Crie uma função para desempilhamento de livros.Não se esqueça de que é necessário verificar se ainda existem livros para ser guardados.
e) Elabore uma função que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recepção. */

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
//Variáveis globais
struct tpilha pilha; 
int op;

//Prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

//Função principal
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
        printf("\nA pilha está cheia!\n\n");
        system("Pause");
    }
    else {
        printf("\nDigite o código do livro: ");
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
//Retirar o último elemento da Pilha
void pilha_sair() {
    if (pilha.ini == pilha.fim) {
        printf("\nApilha está vazia\n\n");
        system("Pause");
    }
    else {
        pilha.dados[pilha.fim - 1].codigo = 0;
        strcpy(pilha.dados[pilha.fim-1].nome, "");
        strcpy(pilha.dados[pilha.fim-1].autor, "");
        pilha.fim--;
    }
}

//Mostrar o conteúdo da Pilha
void pilha_mostrar() {
    int i;
    printf("Pilha: [");
    for (i = 0; i < tamanho; i++) {
        printf(" %d ", pilha.dados[i].codigo);
    }
    printf("]\n\n");
}

//Apresenta o menu de opções
void menu_mostrar() {
        printf("\nEscolha uma opção:\n");
    printf("1 - Incluir Livro da pilha\n2 - Excluir Livro da pilha\n0 - Sair\n\n");
}
