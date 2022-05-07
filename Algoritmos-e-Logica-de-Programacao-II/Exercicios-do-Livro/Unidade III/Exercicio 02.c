#include <stdio.h>	
#include <locale.h>

int main()
{
	int numero, i;
	float resposta, divisor;
	resposta = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("Digite um número: ");
	scanf("%d", &numero);

	for (i = 1; i <= numero; i++)
	{
		divisor = i;
		resposta = resposta + 1 / divisor;
	}
	printf("Resposta: %f\n", resposta);
	return(0);
}