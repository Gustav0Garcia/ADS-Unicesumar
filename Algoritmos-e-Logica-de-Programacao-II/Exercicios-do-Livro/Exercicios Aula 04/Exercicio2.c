/*
Construa um c�digo em C, que determine quantos n�meros
s�o maiores que 100 em um vetor de 10 posi��es.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5

int main(){
	setlocale(LC_ALL, "Portuguese");
	int vetor[MAX];
	
	int i, cont;
	system("cls");
	cont=0;
	printf("Informe os valores:\n");
	for(i=0; i < MAX; i++){
		printf("Valor %d/%d: ", i+1, MAX);
		scanf("%d", &vetor[i]);
	/*}
	for(i=0; i < MAX; i++){*/
		if(vetor[i] > 100){
			cont+=1;
		}
	}
	printf("\nExistem %d n�meros maiores que 100", cont);
	system("pause");
	return 0;
}
