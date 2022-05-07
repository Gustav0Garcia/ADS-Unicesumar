#include <stdio.h>
#include <locale.h>

int main()
{
	char nome[30];
	int i;

	i = 1;

	printf("Informe o nome:\n");
	scanf("%s", nome);

	do
	{
		printf("\n %d - %s", i, nome);
		i++;
	} while (i != 11);
	return(0);
}