/* 5. Crie um programa que leia uma variável e crie dois vetores dinâmicos, um com o tamanho lido e outro com o dobro desse tamanho.
Preencha esses vetores respectivamente com potências de 2 e potências de 3.
a) Crie uma variável inteira e dois ponteiros do tipo inteiro.
b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável inteira.
c) Aloque dinamicamente os dois vetores usando a função malloc.
d) Faça um laço de repetição para preencher o primeiro vetor com potências de 2.
e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3.
f ) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de potência(pow). */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int tam;
int* v1;
int* v2;

int main() {

	int i;

	setlocale(LC_ALL, "Portuguese");

	printf("Informe o tamanho do vetor: ");
	scanf_s("%d", &tam);

	v1 = (int*)malloc(sizeof(int) * tam);
	v2 = (int*)malloc(sizeof(int) * (tam * 2));

	printf("Vetor 01: \n");
	for (i = 0; i < tam; i++) {
		v1[i] = pow(2, i);
		printf("Posição %d: %d\n", i+1, v1[i]);
	}

	printf("\n\nVetor 02: \n");
	for (i = 0; i < tam * 2; i++) {
		v2[i] = pow(3, i);
		printf("Posição %d: %d\n", i+1, v2[i]);
	}
	printf("\n\n");
	system("Pause");
	return(0);
}
