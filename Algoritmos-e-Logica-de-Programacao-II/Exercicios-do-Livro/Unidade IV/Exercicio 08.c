#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define max 20
#define N 30

typedef struct dados
{
	char nome[N], telefone[N], email[N];
}cadastro;

int main()
{
	cadastro cadastros[max];

	int i;

	setlocale(LC_ALL, "portuguese");

	for (i = 0; i < max; i++)
	{
		printf("\nDigite os dados do %d cadastro", i + 1);
		printf("\nNome: ");
		scanf("%30[^\n]", cadastros[i].nome);
		fflush(stdin);
		printf("\nTelefone: ");
		scanf("%30[^\n]", cadastros[i].telefone);
		fflush(stdin);
		printf("\nE-mail: ");
		scanf("%30[^\n]", cadastros[i].email);
		fflush(stdin);
	}
	printf("\n\n** Pessoas Cadastradas **\n\n");
	system("pause");
	system("cls");

	for (i = 0; i < max; i++)
	{
		printf("Nome: %s\nTelefone: %s\nE-mail: %s\n\n", cadastros[i].nome, cadastros[i].telefone, cadastros[i].email);
	}
	printf("\n");
	system("pause");
	return(0);
}