#include <stdio.h>
#include <locale.h>

int main()
{
	int idade;

	setlocale(LC_ALL, "portuguese");

	printf("Informe a idade: ");
	scanf("%d", &idade);

	if (idade < 16)
	{
		printf("\nNão eleitor.\n");
	}
	else
	{
		if (((idade >= 16) && (idade < 18)) || (idade > 65))
		{
			printf("\nEleitor facultativo.\n");
		}
		else
		{
			printf("\nEleitor obrigatório.\n");
		}
	}
	return(0);
}