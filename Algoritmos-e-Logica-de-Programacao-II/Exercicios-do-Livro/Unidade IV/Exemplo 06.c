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
	printf("\nAp�s concatenar as strings, temos que nome �: %s\n", nome);

	if (strstr(sobrenome, nome) == 0)
	{
		printf("\nAgora o sobrenome est� contino na vari�vel nome.\n");
	}
	strlwr(nome);
	printf("\nO nome em min�sculo �: %s\n", nome);
	strupr(nome);
	printf("\nO nome em mai�sculo �: %s\n", nome);
	return(0);
}