#include <stdio.h>
#include <locale.h>

int main()
{
	int par, impar, num;

	setlocale(LC_ALL, "portuguese");

	par = 0;
	impar = 0;

	printf("Informe o n�mero: ");
	scanf("%d", &num);
	fflush(stdin);

	while (num != 0)
	{
		if (num % 2 == 0)
		{
			par++;
		}
		else
		{
			impar++;
		}
		printf("\nInforme o n�mero: ");
		scanf("%d", &num);
		fflush(stdin);
	}
	printf("\nA quantidade de par �: %d", par);
	printf("\nA quantidade de impar �: %d\n", impar);
	return(0);
}