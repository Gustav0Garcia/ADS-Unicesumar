#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int num, i, fat;

	fat = 1;

	printf("Informe o n�mero: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		fat = fat * i;
	}
	printf("\nO fatorial �: %d\n", fat);
	return(0);
}