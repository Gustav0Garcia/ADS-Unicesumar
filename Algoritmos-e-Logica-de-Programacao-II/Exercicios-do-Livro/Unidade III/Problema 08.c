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
			printf("\nInforme a opini�o: ");
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
	printf("\nO n�mero de pessoas insatisfeitas �: %d", npessoasi);
	printf("\nO n�mero de pessoas satisfeitas �: %d", npessoass);
	printf("\nA m�dia de idade das pessoas satisfetias �: %.2f\n", media);
	return(0);
}