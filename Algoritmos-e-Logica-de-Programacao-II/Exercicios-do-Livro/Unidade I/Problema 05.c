#include <stdio.h>

int main() {
	float b1, b2, altura, area;
	area = 0;

	printf("Informe o valor da base maior: ");
	scanf_s("%f", &b1);
	printf("\nInforme o valor da base menor: ");
	scanf_s("%f", &b2);
	printf("\nInforme o da altura: ");
	scanf_s("%f", &altura);

	area = ((b1 + b2) * altura) / 2;

	printf("\nA area do trapezio e: %.2f", area);
	return 0;
}