#include <stdio.h>
#include <locale.h>

int main()
{
	int matriz_A[5][5], matriz_B[5][5], i, j, k;

	setlocale(LC_ALL, "Portuguese");

	printf("\nMatriz A\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("[%d,%d]: ", i + 1, j + 1);
			scanf("%d", &matriz_A[i][j]);
		}
	}
	printf("\nMatriz B\n");

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("[%d,%d]: ", i + 1, j + 1);
			scanf("%d", &matriz_B[i][j]);
		}
	}
	printf("\nSoma de Matrizes\n");

	for (i = 0; i < 5; i++)
	{
		printf("|\t");

		for (j = 0; j < 5; j++)
		{
			printf("%d\t", matriz_A[i][j] + matriz_B[i][j]);
		}
		printf("|\n");
	}
	printf("\nSubtração de Matrizes\n");

	for (i = 0; i < 5; i++)
	{
		printf("|\t");

		for (j = 0; j < 5; j++)
		{
			printf("%d\t", matriz_A[i][j] - matriz_B[i][j]);
		}
		printf("|\n");
	}
}