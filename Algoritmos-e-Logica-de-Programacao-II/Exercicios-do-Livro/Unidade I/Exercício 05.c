#include <stdio.h>
#include <math.h>

#define PI 3.141593

int main()
{
	float r;

	printf("Digite o valor do raio: ");
	scanf_s("%f", &r);

	printf("\nValor da area: %.2f", PI * pow(r, 2));
	printf("\nValor do perimetro: %.2f", 2 * PI* r);
	return 0;
}