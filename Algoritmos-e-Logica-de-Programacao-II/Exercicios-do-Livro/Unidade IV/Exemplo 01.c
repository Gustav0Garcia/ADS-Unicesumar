#include <stdio.h>
#include <locale.h>	

int main()
{
	int vertorA[10];
	int i;

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < 10; i++)
	{
		printf("Digite o %d elemento do vetor: ", i + 1);
		scanf("%d", &vertorA[i]);
	}
	printf("\nVetor preenchido\n");

	for (i = 0; i < 10; i++)
	{
		printf("\nO elemento da posição %d é: %d", i + 1, vertorA[i]);
	}
	printf("\n");
	return(0);
}