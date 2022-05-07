#include <stdio.h>
#include <locale.h>

int main()
{
	int cargo;
	float salario, aumento, salarioFinal;

	salarioFinal = 0;
	aumento = 0;

	setlocale(LC_ALL, "portuguese");

	printf("Digite o n�mero do cargo do funcion�rio: ");
	scanf("%d", &cargo);
	printf("\nDigite o valor do sal�rio do funcion�rio: ");
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
		printf("\nO T�cnico de Seguran�a teve aumento de R$%.2f e agora recebe R$%.2f\n", aumento, salarioFinal);
		break;
	default:
		printf("\nN�mero do cargo inv�lido\n");
		break;
	}
	return(0);
}