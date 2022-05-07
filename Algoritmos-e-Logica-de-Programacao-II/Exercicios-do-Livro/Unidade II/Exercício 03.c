#include <stdio.h>
#include <locale.h>

int main()
{
	int num;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o número: ");
	scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("\nJaneiro\n");
		break;
	case 2:
		printf("\nFevereiro\n");
		break;
	case 3:
		printf("\nMarço\n");
		break;
	case 4:
		printf("\nAbril\n");
		break;
	case 5:
		printf("\nMaio\n");
		break;
	case 6:
		printf("\nJunho\n");
		break;
	case 7:
		printf("\nJulho\n");
		break;
	case 8:
		printf("\nAgosto\n");
		break;
	case 9:
		printf("\nSetembro\n");
		break;
	case 10:
		printf("\nOutubro\n");
		break;
	case 11:
		printf("\nNovembro\n");
		break;
	case 12:
		printf("\nDezembro\n");
		break;
	default:
		printf("\nMês inválido\n");
		break;
	}
	return(0);
}