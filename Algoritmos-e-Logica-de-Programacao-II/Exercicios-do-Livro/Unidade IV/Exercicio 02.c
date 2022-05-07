#include<stdio.h>

int main()
{
	int vetor[3], i, j, aux;

	for (i = 0; i < 3; i++)
	{
		vetor[i] = 0;
	}
	aux = 0;

	for (i = 0; i < 3; i++)
	{
		printf("Digite o %d valor do vetor: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (vetor[i] < vetor[j])
			{
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("\nvetor[%d] = %d\n", i + 1, vetor[i]);
	}
	return(0);
}