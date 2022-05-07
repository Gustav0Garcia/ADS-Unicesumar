#include <stdio.h>
#include <math.h>

int main() {

	int valor;

	printf("Digite um numero inteiro: ");
	scanf_s("%d", &valor);
	printf("\nA potencia de %d e %.2f", valor, pow(valor, 2));
	printf("\nA potencia de %d e %.2f", valor, sqrt(valor));
	return 0;
}