#include <stdio.h>
#include <locale.h>

int main()
{
	int num, i, qtdade;

	qtdade = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("Informe o n�mero: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			qtdade++;
		}
	}
	if (qtdade == 2)
	{
		printf("\nO n�mero � primo.\n");
	}
	else
	{
		printf("\nO n�mero n�o � primo.\n");
	}
	return(0);
}