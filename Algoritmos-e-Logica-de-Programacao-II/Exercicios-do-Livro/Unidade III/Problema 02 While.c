#include <stdio.h>
#include <locale.h>

int main()
{
	float nota, soma, media;
	int cod, i, nnota, naprovado, nreprovado;

	setlocale(LC_ALL, "portuguese");

	naprovado = 0;
	nreprovado = 0;

	printf("Informe o n�mero de notas da disciplina: ");
	scanf("%d", &nnota);
	printf("Informe o c�digo do aluno: ");
	scanf("%d", &cod);
	soma = 0;
	while (cod != 0)
	{
		soma = 0;
		for (i = 1; i <= nnota; i++)
		{
			printf("Infome a %d nota do aluno: ", i);
			scanf("%f", &nota);
			soma = soma + nota;
		}
		media = soma / nnota;
		if (media >= 6)
		{
			naprovado++;
		}
		else
		{
			nreprovado++;
		}
		printf("Informe o c�digo do aluno: ");
		scanf("%d", &cod);
	}
	printf("\nO n�mero de aprovados �: %d", naprovado);
	printf("\nO n�mero de reprovados �: %d\n", nreprovado);
	return(0);
}