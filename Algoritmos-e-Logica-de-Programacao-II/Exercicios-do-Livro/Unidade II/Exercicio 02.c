#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	int num;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o número: ");
	scanf("%d", &num);

	if (num % 3 == 0)
	{
		printf("\nO número é divisível por 3.\n");
	}
	if (num % 7 == 0)
	{
		printf("\nO número é divisível por 7.\n");
	}
	return(0);
}