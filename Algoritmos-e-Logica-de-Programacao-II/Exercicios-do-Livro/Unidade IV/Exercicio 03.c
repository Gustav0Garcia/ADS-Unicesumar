#include<stdio.h>
#include<string.h>
#define max 10
#pragma warning(disable : 4996)

int main()
{
	char palavra[max], letra;
	int i;

	printf("Digite uma palavra: ");
	scanf("%s", palavra);
	strlwr(palavra);

	if (strlen(palavra) % 2 == 1)
	{
		for (i = 0; i < max; i++)
		{
			letra = palavra[i];
			switch (letra)
			{
			case 'a':
				printf("\n%c", letra);
				break;
			case 'e':
				printf("\n%c", letra);
				break;
			case 'i':
				printf("\n%c", letra);
				break;
			case 'o':
				printf("\n%c", letra);
				break;
			case 'u':
				printf("\n%c", letra);
				break;
			}
		}
	}
	printf("\n");
	return(0);
}