#include <stdio.h>
#include <locale.h>

int main()
{
	float n1, n2, resultado;
	int op;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o primeiro n�mero:\n");
	scanf("%f", &n1);
	printf("Digite o segundo n�mero:\n");
	scanf("%f", &n2);
	printf("\nEscolha a opera��o:\n \n1 - Soma \n2 - Subtra��o \n3 - Multiplica��o \n4 - Divis�o \n");
	printf("\nOpera��o: ");
	scanf("%d", &op);

	if (op == 1)
	{
		resultado = n1 + n2;
		printf("\nA soma �: %.3f\n", resultado);
	}
	else
	{
		if (op == 2)
		{
			resultado = n1 - n2;
			printf("\nA subtra��o �: %.3f\n", resultado);
		}
		else
		{
			if (op == 3)
			{
				resultado = n1 * n2;
				printf("\nA multiplica��o �: %.3f\n", resultado);
			}
			else
			{
				if (op == 4)
				{
					resultado = n1 / n2;
					printf("\nA divis�o �: %.3f\n", resultado);
				}
				else
				{
					printf("\nOp��o inv�lida.\n");
				}
			}
		}
	}
	return(0);
}