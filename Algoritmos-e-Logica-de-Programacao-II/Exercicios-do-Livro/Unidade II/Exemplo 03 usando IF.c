#include <stdio.h>
#include <locale.h>

int main()
{
	float n1, n2, resultado;
	int op;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o primeiro número:\n");
	scanf("%f", &n1);
	printf("Digite o segundo número:\n");
	scanf("%f", &n2);
	printf("\nEscolha a operação:\n \n1 - Soma \n2 - Subtração \n3 - Multiplicação \n4 - Divisão \n");
	printf("\nOperação: ");
	scanf("%d", &op);

	if (op == 1)
	{
		resultado = n1 + n2;
		printf("\nA soma é: %.3f\n", resultado);
	}
	else
	{
		if (op == 2)
		{
			resultado = n1 - n2;
			printf("\nA subtração é: %.3f\n", resultado);
		}
		else
		{
			if (op == 3)
			{
				resultado = n1 * n2;
				printf("\nA multiplicação é: %.3f\n", resultado);
			}
			else
			{
				if (op == 4)
				{
					resultado = n1 / n2;
					printf("\nA divisão é: %.3f\n", resultado);
				}
				else
				{
					printf("\nOpção inválida.\n");
				}
			}
		}
	}
	return(0);
}