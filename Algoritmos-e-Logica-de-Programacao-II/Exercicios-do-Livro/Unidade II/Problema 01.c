#include <stdio.h>
#include <locale.h>

int main()
{
	int num;

	setlocale(LC_ALL, "portuguese");

	printf("Informe o n�mero: \nN�mero: ");
	scanf("%d", &num);

	if (num % 5 == 0)
	{
		printf("\nO n�mero %d � divis�vel por 5.\n", num);
	}
	else
	{
		printf("O n�mero %d n�o � divis�vel por 5.\n", num);
	}
	return(0);
}