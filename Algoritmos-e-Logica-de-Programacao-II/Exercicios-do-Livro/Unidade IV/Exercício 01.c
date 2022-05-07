#include <stdio.h>
#define max 5

int main()
{
	int i, j, iguais, vet_A[max], vet_B[max];

	iguais = 0;

	for (i = 0; i < max; i++)
	{
		vet_A[i] = 0;
		vet_B[i] = 0;
	}
	for (i = 0; i < max; i++)
	{
		printf("Digite o %d valor do vetor A: ", i + 1);
		scanf("%d", &vet_A[i]);
	}
	printf("\n");

	for (i = 0; i < max; i++)
	{
		printf("Digite o %d valor do vetor B: ", i + 1);
		scanf("%d", &vet_B[i]);
	}
	for (i = 0; i < max; i++)
	{
		for (j = 0; j < max; j++)
		{
			if (vet_A[i] == vet_B[j])
			{
				iguais++;
			}
		}
		if (iguais < 1)
		{
			printf("\nElementos diferentes: %d", vet_A[i]);
		}
		iguais = 0;
	}
	printf("\n");
	return(0);
}