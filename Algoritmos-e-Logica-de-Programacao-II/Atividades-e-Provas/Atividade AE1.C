#include <stdio.h>
#include <locale.h>

int main()
{
	float salario, reajuste, salarioReaj;

	reajuste = 0;
	salarioReaj = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("============================================\n=                                          =\n= Empresa: Indústria de Amaciante de Pedra =\n= Aluno: Gustavo Garcia                    =\n= RA: 21025427-5                           =\n=                                          =\n============================================\n\n");

	printf("\nAlgoritmo para cálculo simplificado do reajuste salarial\n________________________________________________________\n\n\n");

	printf("Informe o salário líquido ou 0 para sair: ");
	scanf("%f", &salario);

	while (salario != 0)
	{
		reajuste = salario * 0.075;
		salarioReaj = salario + reajuste;

		if (salarioReaj <= 1750)
		{
			printf("\nSalário Liquido: R$ %.2f", salario);
			printf("\nReajuste: R$ %.2f", reajuste);
			printf("\nProvável salário com reajuste: R$ %.2f", salarioReaj);
			printf("\nAbono para salários até R$ 1750,00: R$ 150,00");
			printf("\nProvável salário com reajuste e abono: R$ %.2f\n", salarioReaj + 150);
		}
		else
		{
			printf("\nSalário Liquido: R$ %.2f", salario);
			printf("\nReajuste: R$ %.2f", reajuste);
			printf("\nProvável salário com reajuste: R$ %.2f\n", salarioReaj);
		}
		printf("\nInforme um novo salário líquido ou 0 para sair: ");
		scanf("%f", &salario);
	}
	printf("\nIndústria de Amaciante de Pedra, há 30 anos amaciando pedras!\n");
	return(0);
}