#include <stdio.h>	
#include <locale.h>

int main()
{
	int matrizA[2][10];
	int i, j;

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("Insira elemento da linha %d, coluna %d: ", i+1, j+1);
			scanf("%d", &matrizA[i][j]);
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("\nO elemento da linha %d, coluna %d é: %d", i+1, j+1, matrizA[i][j]);
		}
	}
	printf("\n");
	return(0);
}