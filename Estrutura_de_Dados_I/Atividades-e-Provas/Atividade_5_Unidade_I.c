/* 5. Crie um programa que leia uma vari�vel e crie dois vetores din�micos, um com o tamanho lido e outro com o dobro desse tamanho.
Preencha esses vetores respectivamente com pot�ncias de 2 e pot�ncias de 3.
a) Crie uma vari�vel inteira e dois ponteiros do tipo inteiro.
b) Pergunte ao usu�rio o tamanho do vetor din�mico e leia esse valor na vari�vel inteira.
c) Aloque dinamicamente os dois vetores usando a fun��o malloc.
d) Fa�a um la�o de repeti��o para preencher o primeiro vetor com pot�ncias de 2.
e) Fa�a um segundo la�o de repeti��o para preencher o outro vetor com pot�ncias de 3.
f ) N�o se esque�a de usar a biblioteca math.h para poder usar o c�lculo de pot�ncia(pow). */

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
		printf("Posi��o %d: %d\n", i+1, v1[i]);
	}

	printf("\n\nVetor 02: \n");
	for (i = 0; i < tam * 2; i++) {
		v2[i] = pow(3, i);
		printf("Posi��o %d: %d\n", i+1, v2[i]);
	}
	printf("\n\n");
	system("Pause");
	return(0);
}
