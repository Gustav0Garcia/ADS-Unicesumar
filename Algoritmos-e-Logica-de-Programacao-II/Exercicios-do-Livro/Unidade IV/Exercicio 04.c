#include<stdio.h>
#include<locale.h>

int main()
{
	char palavra[10];
	int repeticoes, i;

	setlocale(LC_ALL, "Portuguese");

	printf("Digite uma palavra: ");
	gets(palavra);
	printf("\nDigite o n�mero de repeti��es: ");
	scanf("\n%d", &repeticoes);

	for (i = 0; i <= repeticoes; i++)
	{
		printf("%s\n", palavra);
	}
	printf("\n");
	return(0);
}