#include <stdio.h>
#include <locale.h>

int main()
{
	float salario, reajuste, salarioReaj;

	reajuste = 0;
	salarioReaj = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("============================================\n=                                          =\n= Empresa: Ind�stria de Amaciante de Pedra =\n= Aluno: Gustavo Garcia                    =\n= RA: 21025427-5                           =\n=                                          =\n============================================\n\n");

	printf("\nAlgoritmo para c�lculo simplificado do reajuste salarial\n________________________________________________________\n\n\n");

	printf("Informe o sal�rio l�quido ou 0 para sair: ");
	scanf("%f", &salario);

	while (salario != 0)
	{
		reajuste = salario * 0.075;
		salarioReaj = salario + reajuste;

		if (salarioReaj <= 1750)
		{
			printf("\nSal�rio Liquido: R$ %.2f", salario);
			printf("\nReajuste: R$ %.2f", reajuste);
			printf("\nProv�vel sal�rio com reajuste: R$ %.2f", salarioReaj);
			printf("\nAbono para sal�rios at� R$ 1750,00: R$ 150,00");
			printf("\nProv�vel sal�rio com reajuste e abono: R$ %.2f\n", salarioReaj + 150);
		}
		else
		{
			printf("\nSal�rio Liquido: R$ %.2f", salario);
			printf("\nReajuste: R$ %.2f", reajuste);
			printf("\nProv�vel sal�rio com reajuste: R$ %.2f\n", salarioReaj);
		}
		printf("\nInforme um novo sal�rio l�quido ou 0 para sair: ");
		scanf("%f", &salario);
	}
	printf("\nInd�stria de Amaciante de Pedra, h� 30 anos amaciando pedras!\n");
	return(0);
}