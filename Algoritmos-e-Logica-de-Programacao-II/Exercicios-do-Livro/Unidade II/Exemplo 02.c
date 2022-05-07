#include<stdio.h>
#include<math.h>
#include<locale.h>

int main()
{
	int quadrado, num;
	float raiz;

	setlocale(LC_ALL, "portuguese");

	printf("Digite um número inteiro: ");
	scanf("%d", &num);

	if (num % 2 == 0)
	{
		raiz = sqrt(num);
		printf("\nO número é par.");
		printf("\nA raíz quadrada é: %.3f\n", raiz);
	}
	else
	{
		quadrado = num * num;
		printf("\nO número é ímpar.");
		printf("\nO número ao quadrado é: %d\n", quadrado);
	}
	return(0);
}