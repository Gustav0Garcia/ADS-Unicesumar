#include <stdio.h>
#include <string.h>

int main()
{
	char nome[50];
	int tamanho;

	printf("Digite o seu nome completo: ");
	gets(nome);

	tamanho = strlen(nome);

	printf("\nO cumprimento do nome: %d\n", tamanho);
	return(0);
}