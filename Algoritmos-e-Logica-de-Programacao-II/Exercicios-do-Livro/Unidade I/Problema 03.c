#include <stdio.h>

int main() {

	float deposito, taxa, rendimento, total;

	printf("Informe o valor do deposito: ");
	scanf_s("%f", &deposito);
	printf("\nInforme a taxa de juros: ");
	scanf_s("%f", &taxa);

	rendimento = deposito * (taxa / 100);
	total = rendimento + deposito;

	printf("\nO total e: %.2f", total);

	return 0;
}