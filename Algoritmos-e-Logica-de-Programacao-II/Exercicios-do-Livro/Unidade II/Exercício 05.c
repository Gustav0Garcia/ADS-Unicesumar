#include <stdio.h>
#include <locale.h>

int main()
{
	int codEstado, peso, codCarga;
	float imposto, taxaImp, preco, precoQuilo, total;

	taxaImp = 0;
	precoQuilo = 0;
	imposto = 0;
	total = 0;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o código do Estado: ");
	scanf("%d", &codEstado);
	printf("\nDigite o peso da carga em toneladas: ");
	scanf("%d", &peso);
	printf("\nDigite o código da carga: ");
	scanf("%d", &codCarga);

	switch (codEstado)
	{
	case 1:
		taxaImp = 0.2;
		break;
	case 2:
		taxaImp = 0.15;
		break;
	case 3:
		taxaImp = 0.1;
		break;
	case 4:
		taxaImp = 0.05;
		break;
	default:
		taxaImp = 0;
		printf("\nCódigo de estado inválido\n");
		break;
	}
	if (codCarga >= 10 && codCarga <= 20)
	{
		precoQuilo = 180;
	}
	else
	{
		if (codCarga >= 21 && codCarga <= 30)
		{
			precoQuilo = 120;
		}
		else
		{
			if (codCarga >= 31 && codCarga <= 40)
			{
				precoQuilo = 230;
			}
			else
			{
				precoQuilo = 0;
				printf("\nCódigo de carga inválido\n");
			}
		}
	}
	imposto = peso * 1000 * precoQuilo * taxaImp;
	preco = peso * 1000 * precoQuilo;
	total = preco + imposto;

	printf("\nPeso em kg: %d\nPreço: %.2f\nImposto: %.2f\nTotal: %.2f\n", peso * 1000, preco, imposto, total);
	return(0);
}