#include <stdio.h>
#include <locale.h>

int main()
{
	int idade, sexo, estatoCivil, qCasadas, quantidade, qSolteiras, qSeparadas, qViuvas;
	float peso, tPeso, mPeso, tIdade, mIdade;
	idade = 1;
	tPeso = 0;
	tIdade = 0;
	qCasadas = 0;
	qSolteiras = 0;
	qSeparadas = 0;
	qViuvas = 0;
	quantidade = 0;

	setlocale(LC_ALL, "Portuguese");

	while (idade != 0)
	{
		printf("\nDigite a idade ou 0 para sair: ");
		scanf("%d", &idade);

		if (idade != 0)
		{
			quantidade++;
			tIdade = tIdade + idade;

			printf("\nDigite o peso: ");
			scanf("%f", &peso);
			tPeso = tPeso + peso;

			printf("\nDigite o sexo (1-M | 2-F): ");
			scanf("%d", &sexo);
			printf("\nDigite o estado civil (1-Casadas | 2-Solteiras | 3-Separadas | 4-Viúvas): ");
			scanf("%d", &estatoCivil);
			switch (estatoCivil)
			{
			case 1:
				qCasadas++;
				break;
			case 2:
				qSolteiras++;
				break;
			case 3:
				qSeparadas++;
				break;
			case 4:
				qViuvas++;
				break;
			default:
				printf("\nEstado civil inválido");
				break;
			}
		}
	}
	mIdade = tIdade / quantidade;
	mPeso = tPeso / quantidade;
	printf("\nCasadas: %d \nSolteiras: %d \nSeparadas: %d \nViúvas: %d", qCasadas, qSolteiras, qSeparadas, qViuvas);
	printf("\nMédia de peso: %.3f \nMédia de Idade: %.1f\n", mPeso, mIdade);
	return(0);
}