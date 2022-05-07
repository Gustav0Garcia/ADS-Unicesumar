#include <stdio.h>

int main()
{
	int n1, n2;

	printf("Digite o primeiro numero: ");
	scanf_s("%d", &n1);
	printf("Digite o segundo numero: ");
	scanf_s("%d", &n2);

	printf("\nA soma dos numeros e: %d\n", n1 + n2);
	return 0;
}