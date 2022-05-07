/*
Construa um código em linguagem C que some dois vetores de 
15 posições, e armazene o resultado em um terceiro vetor.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

int main(){
	setlocale(LC_ALL, "Portuguese");
	int vetor1[MAX], vetor2[MAX], vetor3[MAX];
	
	int i;
	system("cls");
	printf("Informe o vetor 1:\n");
	for(i=0; i < MAX; i++){
		printf("Valor %d/%d: ", i+1, MAX);
		scanf("%d", &vetor1[i]);
	}
	system("cls");
	printf("Informe o vetor 2:");
	for(i=0; i < MAX; i++){
		printf("Valor %d/%d: ", i+1, MAX);
		scanf("%d", &vetor2[i]);
	}
	system("cls");
	printf("VETOR 1 + VETOR 2 = VETOR 3");
	for(i=0; i < MAX; i++){
		vetor3[i]= vetor1[i] + vetor2[i];
		printf("\n%d + %d = %d", vetor1[i], vetor2[i], vetor3[i]);
	}
	system("pause");
	return 0;
}
