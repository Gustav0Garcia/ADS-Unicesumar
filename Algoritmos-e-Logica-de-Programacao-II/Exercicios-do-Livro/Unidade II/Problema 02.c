#include <stdio.h>
#include <locale.h>

int main()
{
	char nome[30], sobrenome[30];
	int idade;

	setlocale(LC_ALL, "Portuguese");

	printf("Informe o nome: ");
	scanf("%s", nome);
	printf("\nInforme o sobrenome: ");
	scanf("%s", sobrenome);
	printf("\nInforme a idade: ");
	scanf("%d", &idade);

	printf("\nNome: %s %s", nome, sobrenome);
	printf("\nIdade: %d\n", idade);

	if (idade <= 18)
	{
		printf("\nO valor do plano é: R$50,00\n");
	}
	else
	{
		if ((idade >= 19) && (idade <= 29))
		{
			printf("\nO valor do plano é: R$70,00\n");
		}
		else
		{
			if ((idade >= 30) && (idade <= 45))
			{
				printf("\nO valor do plano é: R$90,00\n");
			}
			else
			{
				if ((idade >= 46) && (idade <= 65))
				{
					printf("\nO valor do plano é: R$130,00\n");
				}
				else
				{
					printf("\nO valor do plano é: R$170,00\n");
				}
			}
		}
	}
	return(0);
}