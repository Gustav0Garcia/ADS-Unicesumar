#include <stdio.h>
#include <locale.h>

int main()
{
	int cargo;
	float salario, aumento, salarioFinal;

	salarioFinal = 0;
	aumento = 0;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o número do cargo do funcionário: ");
	scanf("%d", &cargo);
	printf("\nDigite o valor do salário do funcionário: ");
	scanf("%f", &salario);

	switch (cargo)
	{
	case 1:
		aumento = salario * 0.4;
		salarioFinal = salario + aumento;
		printf("\nO Servente teve aumento de R$%.2f e agora recebe R$%.2f\n", aumento, salarioFinal);
		break;
	case 2:
		aumento = salario * 0.35;
		salarioFinal = salario + aumento;
		printf("\nO Pedreiro teve aumento de R$%.2f e agora recebe R$%.2f\n", aumento, salarioFinal);
		break;
	case 3:
		aumento = salario * 0.20;
		salarioFinal = salario + aumento;
		printf("\nO Mestre de Obras teve aumento de R$%.2f e agora recebe R$%.2f\n", aumento, salarioFinal);
		break;
	case 4:
		aumento = salario * 0.10;
		salarioFinal = salario + aumento;
		printf("\nO Técnico de Segurança teve aumento de R$%.2f e agora recebe R$%.2f\n", aumento, salarioFinal);
		break;
	default:
		printf("\nNúmero do cargo inválido\n");
		break;
	}
	return(0);
}