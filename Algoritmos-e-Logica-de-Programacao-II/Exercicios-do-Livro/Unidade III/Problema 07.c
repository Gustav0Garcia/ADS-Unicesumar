#include <stdio.h>
#include <locale.h>

int main()
{
	int idade, npessoas;
	float altura, somaa, somai;
	char sexo;

	somaa = 0;
	somai = 0;
	npessoas = 0;

	setlocale(LC_ALL, "portuguese");

	printf("Informe a idade ou 0 para sair: ");
	scanf("%d", &idade);

	while (idade != 0)
	{
		printf("\nInforme a altura: ");
		scanf("%f", &altura);
		npessoas++;
		somai = somai + idade;
		somaa = somaa + altura;

		printf("\nInforme a idade ou 0 para sair: ");
		scanf("%d", &idade);
	}
	printf("\nA m�dia de altura �: %.2f", somaa / npessoas);
	printf("\nA m�dia de idade �: %.2f\n", somai / npessoas);
	return(0);
}