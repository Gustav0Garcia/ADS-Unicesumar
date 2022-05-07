#include <stdio.h>
#include <locale.h>

int main()
{
	int idade, npessoas, npessoasi, npessoass, op;
	float somai, media;

	npessoas = 0;
	npessoass = 0;
	npessoasi = 0;
	somai = 0;

	setlocale(LC_ALL, "Portuguese");

	printf("Informe a idade ou 0 para sair: ");
	scanf("%d", &idade);

	while (idade != 0)
	{
		do
		{
			printf("\nInforme a opinião: ");
			scanf("%d", &op);
		} while ((op != 1) && (op != 2) && (op != 3));
		
		npessoas++;
		
		if (op == 1)
		{
			somai = somai + idade;
			npessoass++;
		}
		else
		{
			if (op == 3)
			{
				npessoasi++;
			}

		}
		printf("\nInforme a idade ou 0 para sair: ");
		scanf("%d", &idade);
	}
	media = (somai / npessoass);
	printf("\nO número de pessoas insatisfeitas é: %d", npessoasi);
	printf("\nO número de pessoas satisfeitas é: %d", npessoass);
	printf("\nA média de idade das pessoas satisfetias é: %.2f\n", media);
	return(0);
}