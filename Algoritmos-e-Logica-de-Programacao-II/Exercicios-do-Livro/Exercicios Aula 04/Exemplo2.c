/*
Construir uma função para imprimir um menu com as opções abaixo:

1 – Cadastrar
2 - Alterar
3 – Excluir
4 - Listar

A segunda Função gerar um cabeçalho conforme ilustrado abaixo:

***********************************************
*Controle de clientes*
***********************************************

*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

void menu(){
	printf("\n1 – Cadastrar");
	printf("\n2 - Alterar");
	printf("\n3 – Excluir");
	printf("\n4 - Listar");
	printf("\nEscolha a opção:");
}
void cabecalho(){
	printf("\n***********************************************");
	printf("\n*Controle de clientes*");
	printf("\n***********************************************");
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	cabecalho();
	menu();
	printf("\n");
	system("pause");
	return 0;
}
