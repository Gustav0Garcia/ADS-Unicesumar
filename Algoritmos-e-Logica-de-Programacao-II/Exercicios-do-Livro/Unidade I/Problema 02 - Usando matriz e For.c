#include <stdio.h>

int main()
{
	int nota[4];
	int i, media;

	media = 0;

	for (i = 0; i < 4; i++)
	{
		printf("\nDigite a nota %d: ", i + 1);
		scanf_s("%d", &nota[i]);
		media = media + nota[i];
	}
	printf("A media e: %d", media / 4);
		return 0;
}