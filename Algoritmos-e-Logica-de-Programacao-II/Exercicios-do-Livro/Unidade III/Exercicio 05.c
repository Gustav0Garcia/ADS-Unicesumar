#include <stdio.h>
#include <locale.h>

int main()
{
	int i;

	setlocale(LC_ALL, "portuguese");

	for (i = 1; i <= 30; i++)
	{
		if (i % 3 == 0)
		{
			printf("\nO n�mero %d � divis�vel por 3\n", i);
		}
		if (i % 7 == 0)
		{
			printf("\nO n�mero %d � divis�vel por 7\n", i);
		}
	}
	return(0);
}