#include <stdio.h>
#include <string.h>

typedef struct dados
{
	char nome[20];
	float nota[4], media;
}cadastro;

int main()
{
	cadastro boletim[5];
	cadastro boletimTmp;
	int i, j;
	float soma, notas;

	notas = 0;

	for (i = 0; i < 5; i++)
	{
		j = 0;

		printf("\nDigite o %d nome: ", i + 1);
		scanf("%s", boletim[i].nome);
		fflush(stdin);

		soma = 0;

		for (j = 0; j < 4; j++)
		{
			printf("\nDigite a %d nota: ", j + 1);
			scanf("%f", &boletim[i].nota[j]);
			fflush(stdin);
			soma += boletim[i].nota[j];
		}
		boletim[i].media = soma / 4;
		
		printf("\n** %s - %.1f - %.1f - %.1f - %.1f -\n", boletim[i].nome, boletim[i].nota[0], boletim[i].nota[1], boletim[i].nota[2], boletim[i].nota[3]);
	}
	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (boletim[i].media > boletim[j].media)
			{
				boletimTmp = boletim[i];
				boletim[i] = boletim[j];
				boletim[j] = boletimTmp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("\n\n%s - %0.1f", boletim[i].nome, boletim[i].media);
		printf("\n%.1f; %.1f; %.1f; %.1f", boletim[i].nome, boletim[i].nota[0], boletim[i].nota[1], boletim[i].nota[2], boletim[i].nota[3]);
	}
	printf("\n");
	return(0);
}