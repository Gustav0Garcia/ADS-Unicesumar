//1. Faça um pequeno programa para testar seus conhecimentos sobre ponteiros e alocação dinâmica na memória.
//a) Defina um ponteiro do tipo inteiro.
//b) Faça alocação dinâmica para o ponteiro recém - criado.
//c) Preencha a memória com o valor 42.
//d) Imprima o endereço do ponteiro na memória e o valor contido nele.

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