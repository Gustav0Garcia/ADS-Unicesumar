#include <stdio.h>
#include <locale.h>

int main()
{
	int op;
	float total;

	total = 0;

	setlocale(LC_ALL, "portuguese");

	printf("1 - Italiano \n2 - Japon�s \n3 - Salvadorenho\n");
	printf("\nInforme o prato desejado: ");
	scanf("%d", &op);

	switch (op)
	{
	case 1:
		total = total + 750;
		break;
	case 2:
		total = total + 324;
		break;
	case 3:
		total = total + 545;
		break;
	default:
		printf("\Op��o de prato inv�lida.\n");
		break;
	}
	printf("\n1 - Ch� \n2 - Suco de laranja \n3 - Refrigerante\n");
	printf("\nInforme a bebida desejada: ");
	scanf("%d", &op);

	switch (op)
	{
	case 1:
		total = total + 30;
		break;
	case 2:
		total = total + 80;
		break;
	case 3:
		total = total + 90;
		break;
	default:
		printf("\Op��o de bebida inv�lida.\n");
		break;
	}
	printf("\nO total de calorias �: %.2f\n", total);
	return(0);
}