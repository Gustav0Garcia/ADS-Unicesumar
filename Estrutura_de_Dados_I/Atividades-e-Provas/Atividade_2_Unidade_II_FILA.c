//2. Uma agência bancária quer inovar seu atendimento, criando mais conforto para seus clientes. Para isso, foram colocadas diversas cadeiras na recepção
//do banco. Quando um cliente chega, o atendente lança no computador o seu nome e o horário que chegou. Assim que um caixa fica livre, a recepcionista
//olha no sistema e chama o primeiro cliente da fila. Dessa forma, é possível que os clientes esperem confortavelmente sentados pelo seu atendimento, não
//importando o local onde se encontrem dentro da agência bancária.
//a) Faça uma estrutura para o controle da fila. Você precisa guardar o nome e a hora que o cliente chegou. Use um vetor para armazenar os dados e dois
//números inteiros, um para controlar o início e outro o final da fila.
//b) Defina a variável que será um vetor do tipo fila de clientes.
//c) Crie uma função enfileirar, lembrando que é preciso verificar se há espaço na fila (o número de cadeiras na recepção é limitado).
//d) Elabore a função desenfileirar cliente, não se esqueça de que é necessário verificar se ainda existem clientes para serem atendidos.
//e) Faça uma função que apresente na tela a lista de todos os clientes que estão aguardando atendimento na recepção.

//a)
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#pragma warning(disable : 4996)

//Constantes
#define tamanho 5

//Estrutura do cliente
struct tcliente{
    char nome[50];
    char hora[6];
};

//Estrutura da Fila
struct tfila{
    struct tcliente dados[tamanho];
    int ini;
    int fim;
};

//b
//Variáveis globais
struct tfila fila;
int op;

//Prototipação
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

//Função principal
int main(){
    setlocale(LC_ALL, "Portuguese");

    op = 3;
    fila.ini = 0;
    fila.fim = 0;

    while (op != 0) {
    	system("Cls");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op) {
        case 1:
            fila_entrar();
            break;
        case 2:
            fila_sair();
            break;
        }
    }
    return(0);
}

//c
//Adicionar elemento ao final da Fila
void fila_entrar(){
	system("Cls");
	if(fila.fim == tamanho){
		printf("\nA fila está cheia, volte outro dia!\n\n");
		system("Pause");
	}
	else{
		fflush(stdin);
		printf("Digite o nome do cliente que chegou: ");
		gets(fila.dados[fila.fim].nome); //utilizei gets, pois scanf não estava apresentando o nome e a hora no conteúdo da Fila
		fflush(stdin);
		printf("Digite a hora da chegada do cliente: ");
		gets(fila.dados[fila.fim].hora);
		fflush(stdin);
		fila.fim++;
	}
}

//d
//Retirar o primeiro elemento da Fila
void fila_sair(){
	if(fila.ini == fila.fim){
		printf("\nFila vazia, mas logo aparece alguém!\n\n")/
		system("Pause");
	}
	else{
		int i;
		for(i=0; i < tamanho; i++){
			strcpy(fila.dados[i].nome, fila.dados[i+1].nome);
			strcpy(fila.dados[i].hora, fila.dados[i+1].hora);
		}
		strcpy(fila.dados[fila.fim].nome, "");
		strcpy(fila.dados[fila.fim].hora, "");
		fila.fim--;
	}
}

//e
//Mostrar conteúdo da Fila
void fila_mostrar(){
	int i;
	for(i=0; i<tamanho; i++){
		printf("[Cliente %s chegou as %s horas]\n", fila.dados[i].nome, fila.dados[i].hora); 
	}
}

//Apresenta o menu de opções
void menu_mostrar(){
        printf("\n\nEscolha uma opção:\n");
    printf("1 - Incluir cliente e hora na fila\n2 - Excluir primeiro cliente e hora da fila\n0 - Sair\n\n");
}
