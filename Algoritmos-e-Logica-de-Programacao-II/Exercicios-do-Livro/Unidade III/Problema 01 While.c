#include <stdio.h>
#include <locale.h>

int main()
{
	int par, impar, num;

	setlocale(LC_ALL, "portuguese");

	par = 0;
	impar = 0;

	printf("Informe o número: ");
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
		printf("\nInforme o número: ");
		scanf("%d", &num);
		fflush(stdin);
	}
	printf("\nA quantidade de par é: %d", par);
	printf("\nA quantidade de impar é: %d\n", impar);
	return(0);
}