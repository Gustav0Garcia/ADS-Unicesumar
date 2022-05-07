#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define TAM 20

int main()
{
	float media[TAM], notas[TAM][4], somat, mediat, soma;
	int i, j;

	setlocale(LC_ALL, "Portuguese");

	somat = 0;
	mediat = 0;

	for (i = 0; i < TAM; i++)
	{
		soma = 0;

		for (j = 0; j < 4; j++)
		{
			printf("Informe a nota %d do aluno %d: ", j+1, i+1);
			scanf("%f", &notas[i][j]);
			fflush(stdin);
			soma += notas[i][j];
		}
		media[i] = soma / 4;
		somat += media[i];
	}
	mediat = somat / TAM;

	for (i = 0; i < TAM; i++)
	{
		printf("\nA média do aluno %d é: %.2f\n", i + 1, media[i]);
		system("pause");
	}
	printf("\nA média da turma é: %.2f\n", mediat);
	system("pause");
	return(0);
}