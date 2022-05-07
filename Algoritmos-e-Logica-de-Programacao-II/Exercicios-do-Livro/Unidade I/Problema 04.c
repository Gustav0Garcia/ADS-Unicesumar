#include <stdio.h>
#include <math.h>

int main() {
	float n1, n2, total;

	printf("Informe o primeiro numero: ");
	scanf_s("%f", &n1);
	printf("\nInforme o segunfo numero: ");
	scanf_s("%f", &n2);
	total = pow(n1, n2);

	printf("\n%.2f elevado a %.2f: %.2f", n1, n2, total);

	return 0;
}