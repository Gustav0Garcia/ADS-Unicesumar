#include <stdio.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main()
{
	char nome[80], sobrenome[80];

	setlocale(LC_ALL, "Portuguese");


	printf("Digite o seu nome: ");
	gets(nome);
	printf("\nDigite o seu sobrenome: ");
	gets(sobrenome);
	strcat(nome, sobrenome);
	printf("\nApós concatenar as strings, temos que nome é: %s\n", nome);

	if (strstr(sobrenome, nome) == 0)
	{
		printf("\nAgora o sobrenome está contino na variável nome.\n");
	}
	strlwr(nome);
	printf("\nO nome em minúsculo é: %s\n", nome);
	strupr(nome);
	printf("\nO nome em maiúsculo é: %s\n", nome);
	return(0);
}