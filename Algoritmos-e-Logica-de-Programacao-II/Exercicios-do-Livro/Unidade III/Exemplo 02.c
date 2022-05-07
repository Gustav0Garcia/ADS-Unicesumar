#include <stdio.h>
#include <locale.h>

int main()
{
	char nome[30];
	int i;

	i = 1;

	setlocale(LC_ALL, "portuguese");

	printf("Informe o nome: \n\n");
	scanf("%s", nome);

	while (i != 11)
	{
		printf("\n %d - %s", i, nome);
		i++;
	}
	return(0);
}