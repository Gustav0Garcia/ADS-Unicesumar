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

	switch (op)
	{
		case 1:
			resultado = n1 + n2;
			printf("A soma é: %.3f\n", resultado);
			break;
		case 2:
			resultado = n1 - n2;
			printf("A subtração é: %.3f\n", resultado);
			break;
		case 3:
			resultado = n1 * n2;
			printf("A multiplicação é: %.3f\n", resultado);
			break;
		case 4:
			resultado = n1 / n2;
			printf("A divisão é: %.3f\n", resultado);
			break;
		default:
			printf("Opção inválida.\n");
			break;
	}
	return(0);
}