#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	int num;
	float raiz;

	setlocale(LC_ALL, "portuguese");

	printf("\nDigite um n�mero inteiro: ");
	scanf_s("%d", &num);

	if (num % 2 == 0)
	{
		raiz = sqrt(num);
		printf("\nA ra�z quadrada �: %.3f\n", raiz);
	}
	return(0);
}