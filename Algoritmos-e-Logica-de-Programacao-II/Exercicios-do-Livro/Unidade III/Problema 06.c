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

	printf("Informe o sal�rio ou -1 para sair.\nSal�rio: ");
	scanf("%f", &salario);

	while (salario != -1)
	{
		printf("\nInforme o n�mero de filhos: ");
		scanf("%d", &filhos);
		npessoas++;

		if (salario > msalario)
		{
			msalario = salario;
		}

		somaf = somaf + filhos;
		somas = somas + salario;

		printf("\nInforme o sal�rio ou -1 para sair.\nSal�rio: ");
		scanf("%f", &salario);
	}
	printf("\nA m�dia de sal�rios �: %.2f", somas / npessoas);
	printf("\nA m�dia de filhos �: %.2f", somaf / npessoas);
	printf("\nO maior sal�rio �: %.2f\n", msalario);
	return(0);
}