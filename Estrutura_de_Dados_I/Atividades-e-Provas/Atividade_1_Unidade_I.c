//1. Fa�a um pequeno programa para testar seus conhecimentos sobre ponteiros e aloca��o din�mica na mem�ria.
//a) Defina um ponteiro do tipo inteiro.
//b) Fa�a aloca��o din�mica para o ponteiro rec�m - criado.
//c) Preencha a mem�ria com o valor 42.
//d) Imprima o endere�o do ponteiro na mem�ria e o valor contido nele.

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int *pont;

	pont = (int*)malloc(sizeof(int));

	*pont = 42;

	printf("Endereco do ponteiro: %p\nValor do ponteiro: %d\n\n\n", pont, *pont);

	system("Pause");
	return(0);
}