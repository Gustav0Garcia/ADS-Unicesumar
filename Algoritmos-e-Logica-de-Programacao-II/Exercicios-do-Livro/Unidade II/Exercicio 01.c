#include <stdio.h>
#include <locale.h>

int main()
{
	int num, maior, menor;

	setlocale(LC_ALL, "portuguese");

	maior = 0;
	menor = 0;

	printf("Digite o primeiro n�mero: ");
	scanf("%d", &num);
	
	maior = num;
	menor = num;

	printf("Digite o segundo n�mero: ");
	scanf("%d", &num);
	if (num > maior)
	{
		maior = num;
	}
	else
	{
		if (num < menor)
		{
			menor = num;
		}	
	}
	printf("Digite o terceiro n�mero: ");
	scanf("%d", &num);
	if (num > maior)
	{
		maior = num;
	}
	else
	{
		if (num < menor)
		{
			menor = num;
		}
	}
	printf("Digite o quarto n�mero: ");
	scanf("%d", &num);
	if (num > maior)
	{
		maior = num;
	}
	else
	{
		if (num < menor)
		{
			menor = num;
		}
	}
	printf("Digite o quinto n�mero: ");
	scanf("%d", &num);
	if (num > maior)
	{
		maior = num;
	}
	else
	{
		if (num < menor)
		{
			menor = num;
		}
	}
	printf("\nO maior �: %d", maior);
	printf("\nO menor �: %d\n", menor);
	return(0);
}