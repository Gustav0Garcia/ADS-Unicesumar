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

	switch (op)
	{
		case 1:
			resultado = n1 + n2;
			printf("A soma �: %.3f\n", resultado);
			break;
		case 2:
			resultado = n1 - n2;
			printf("A subtra��o �: %.3f\n", resultado);
			break;
		case 3:
			resultado = n1 * n2;
			printf("A multiplica��o �: %.3f\n", resultado);
			break;
		case 4:
			resultado = n1 / n2;
			printf("A divis�o �: %.3f\n", resultado);
			break;
		default:
			printf("Op��o inv�lida.\n");
			break;
	}
	return(0);
}