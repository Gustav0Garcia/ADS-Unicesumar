/*
Construir uma fun��o para imprimir um menu com as op��es abaixo:

1 � Cadastrar
2 - Alterar
3 � Excluir
4 - Listar

A segunda Fun��o gerar um cabe�alho conforme ilustrado abaixo:

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
	printf("\n1 � Cadastrar");
	printf("\n2 - Alterar");
	printf("\n3 � Excluir");
	printf("\n4 - Listar");
	printf("\nEscolha a op��o:");
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
