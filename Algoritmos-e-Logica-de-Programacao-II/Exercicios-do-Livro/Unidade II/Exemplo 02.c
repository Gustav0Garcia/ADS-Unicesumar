#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
	int quadrado, num;
	float raiz;

	setlocale(LC_ALL, "portuguese");

	printf("Digite um n�mero inteiro: ");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		raiz = sqrt(num);
		printf("\nO n�mero � par.");
		printf("\nA ra�z quadrada �: %.3f\n", raiz);
	}
	else
	{
		quadrado = num * num;
		printf("\nO n�mero � �mpar.");
		printf("\nO n�mero ao quadrado �: %d\n", quadrado);
	}
	return(0);
}