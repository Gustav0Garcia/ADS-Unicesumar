#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	int numero, soma, quantidade, maior, menor, pares, impares;
	float media;
	numero = 1;
	quantidade = 0;
	soma = 0;
	maior = 0;
	menor = 1000;
	pares = 0;
	impares = 0;

	setlocale(LC_ALL, "Portuguese");

	while (numero != 0)
	{
		printf("Digite um n�mero: ");
		scanf("%d", &numero);

		if (numero != 0)
		{
			quantidade++;
		}
		soma = soma + numero;
		if (numero % 2 == 1 && numero != 0)
		{
			pares++;
		}
		else
		{
			if (numero % 2 == 1 && numero != 0)
			{
				impares++;
			}
		}
		if (numero > maior && numero != 0)
		{
			maior = numero;
		}
		if (numero < menor && numero != 0)
		{
			menor = numero;
		}
	}
	media = soma / quantidade;
	printf("\nM�dia: %.2f \nMaior: %d \nMenor: %d \nPares: %d \n�mpares: %d\n", media, maior, menor, pares, impares);
	return(0);
}