#include <stdio.h>
#include <locale.h>

int main()
{
	int num, maior, menor;

	setlocale(LC_ALL, "portuguese");

	maior = 0;
	menor = 0;

	printf("Digite o primeiro número: ");
	scanf("%d", &num);
	
	maior = num;
	menor = num;

	printf("Digite o segundo número: ");
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
	printf("Digite o terceiro número: ");
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
	printf("Digite o quarto número: ");
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
	printf("Digite o quinto número: ");
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
	printf("\nO maior é: %d", maior);
	printf("\nO menor é: %d\n", menor);
	return(0);
}