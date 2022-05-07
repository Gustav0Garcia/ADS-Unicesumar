#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define TAM 2

struct funcionario
{
	int matricula;
	char nome[50], setor[30];
	float salario;
};

int main()
{
	struct funcionario ficha[TAM];

	int busca, i, acha;
	char op;

	setlocale(LC_ALL, "Portuguese");

	for (i = 0; i < TAM; i++)
	{
		printf("Digite a matrícula do funcionário: ");
		scanf("%d", &ficha[i].matricula);
		fflush(stdin);
		printf("\nDigite o nome: ");
		scanf("%50s", &ficha[i].nome);
		fflush(stdin);
		printf("\nDigite o setor: ");
		scanf("%30s", &ficha[i].setor);
		fflush(stdin);
		printf("\nDigite o salário: ");
		scanf("%f", &ficha[i].salario);
		fflush(stdin);
	}
	do
	{
		printf("\nDeseja realizar busca (S/N): ");
		scanf("%c", &op);
		fflush(stdin);
	} while ((op != 'S') && (op != 's') && (op != 'N') && (op != 'n'));

	while ((op == 'S') || (op == 's'))
	{
		printf("\nInforme a matrícula que deseja buscar: ");
		scanf("%d", &busca);
		fflush(stdin);
		i = 0;
		acha = 0;

		while ((i < TAM) && (acha == 0))
		{
			if (ficha[i].matricula == busca)
			{
				acha = 1;
			}
			else
			{
				i++;
			}
		}
		if (acha == 1)
		{
			printf("\nO setor é: %s", ficha[i].setor);
			printf("\nO salário é: %f\n", ficha[i].salario);
			system("pause");
		}
		else
		{
			printf("\nMatrícula não cadastrada\n");
			system("pause");
		}
		do
		{
			printf("\nDeseja realizar busca (S/N): ");
			scanf("%c", &op);
			fflush(stdin);
		} while ((op != 'S') && (op != 's') && (op != 'N') && (op != 'n'));
	}
	return(0);
}