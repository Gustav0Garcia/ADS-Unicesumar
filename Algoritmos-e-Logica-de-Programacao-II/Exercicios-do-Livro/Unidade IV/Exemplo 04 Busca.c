#include <stdio.h>
#include <locale.h>

int main()
{
	int vetorA[10];
	int i, acha, busca;

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < 10; i++)
	{
		printf("Digite o %d elemento: ", i + 1);
		scanf("%d", &vetorA[i]);
	}
	printf("\nInforme o elemento que deseja buscar: ");
	scanf("%d", &busca);
	
	i = 0;
	acha = 0;

	while ((acha == 0) && (i < 10))
	{
		if (vetorA[i] == busca)
		{
			acha = 1;
		}
		else
		{
			i++;
		}
	}
	if (acha == 1)
	{
		printf("\nO elemento %d foi encontrano na posição %d.\n", busca, i+1);
	}
	else
	{
		printf("\nO elemento não foi encontrado.\n");
	}
	return(0);
}