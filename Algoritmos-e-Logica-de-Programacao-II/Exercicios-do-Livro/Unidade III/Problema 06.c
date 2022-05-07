#include <stdio.h>
#include <locale.h>

int main()
{
	int filhos, npessoas;
	float salario, somas, somaf, msalario;

	npessoas = 0;
	somaf = 0;
	somas = 0;
	msalario = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("Informe o salário ou -1 para sair.\nSalário: ");
	scanf("%f", &salario);

	while (salario != -1)
	{
		printf("\nInforme o número de filhos: ");
		scanf("%d", &filhos);
		npessoas++;

		if (salario > msalario)
		{
			msalario = salario;
		}

		somaf = somaf + filhos;
		somas = somas + salario;

		printf("\nInforme o salário ou -1 para sair.\nSalário: ");
		scanf("%f", &salario);
	}
	printf("\nA média de salários é: %.2f", somas / npessoas);
	printf("\nA média de filhos é: %.2f", somaf / npessoas);
	printf("\nO maior salário é: %.2f\n", msalario);
	return(0);
}