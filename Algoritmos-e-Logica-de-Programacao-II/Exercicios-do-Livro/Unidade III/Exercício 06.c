#include <stdio.h>
#include <locale.h>

int main()
{
	char frase[30];
	int i, numero;

	setlocale(LC_ALL, "portuguese");

	printf("Digite a frase: ");
	gets(frase);
	printf("\nDigite o número de repetições: ");
	scanf("%d", &numero);

	for (i = 1; i <= numero; i++)
	{
		printf("\n%d - %s", i, frase);
	}
	printf("\n");
	return(0);
}