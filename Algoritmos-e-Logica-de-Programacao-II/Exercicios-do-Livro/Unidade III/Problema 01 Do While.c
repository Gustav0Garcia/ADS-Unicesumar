#include<stdio.h>
#include<locale.h>

int main()
{
	int par, impar, num;

	par = 0;
	impar = 0;

	setlocale(LC_ALL, "portuguese");

	do
	{
		printf("Informe o n�mero: ");
		scanf("%d", &num);
		fflush(stdin);

		if (num % 2 == 0)
		{
			par++;
		}
		else
		{
			impar++;
		}
	} while (num != 0);
	printf("\nA quantidade de par �: %d", par);
	printf("\nA quantidade de impar �: %d\n", impar);
	return(0);
}