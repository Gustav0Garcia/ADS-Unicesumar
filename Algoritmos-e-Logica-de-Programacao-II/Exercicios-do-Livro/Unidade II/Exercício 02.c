#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	int num;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o n�mero: ");
	scanf("%d", &num);

	if (num % 3 == 0)
	{
		printf("\nO n�mero � divis�vel por 3.\n");
	}
	if (num % 7 == 0)
	{
		printf("\nO n�mero � divis�vel por 7.\n");
	}
	return(0);
}