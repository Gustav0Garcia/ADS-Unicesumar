#include <stdio.h>

int main() 
{
	float nota[4];
	float media;
	int i;

	media = 0;

	for (i=0; i<4; i++)
	{
		printf("\nInforme a nota %d: ", i+1);
		scanf_s("%f", &nota[i]);
		media = media + nota[i];
	}
	printf("\nA media e : %.2f", media / 4);
	return 0;
}