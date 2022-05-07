#include <stdio.h>
#include <locale.h>

int main()
{
	int num;

	setlocale(LC_ALL, "portuguese");

	printf("Informe o número: \nNúmero: ");
	scanf("%d", &num);

	if (num % 5 == 0)
	{
		printf("\nO número %d é divisível por 5.\n", num);
	}
	else
	{
		printf("O número %d não é divisível por 5.\n", num);
	}
	return(0);
}