/*
Construa um código em linguagem C que multiplique duas
matrizes de ordem 3, e armazene o seu resultado em uma
terceira matriz de mesma ordem.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINHA 3
#define MAX_COLUNA 3

int main(){
	setlocale(LC_ALL, "Portuguese");
	int matriz1[MAX_LINHA][MAX_COLUNA], matriz2[MAX_LINHA][MAX_COLUNA], matriz3[MAX_LINHA][MAX_COLUNA];
	
	int i, j;
	system("cls");
	printf("Informe os valores da Matriz 1:\n");
	for(i=0; i < MAX_LINHA; i++){
		for(j=0; j < MAX_COLUNA; j++){
			printf("Valor [%d][%d]= ", i+1, j+1);
			scanf("%d", &matriz1[i][j]);
		}
	}
	system("cls");
	printf("Informe os valores da Matriz 2:\n");
	for(i=0; i < MAX_LINHA; i++){
		for(j=0; j < MAX_COLUNA; j++){
			printf("Valor [%d][%d]= ", i+1, j+1);
			scanf("%d", &matriz2[i][j]);
		}
	}
	system("cls");
	for(i=0; i < MAX_LINHA; i++){
		for(j=0; j < MAX_COLUNA; j++){
			matriz3[i][j] = matriz1[i][j] * matriz2[i][j];
		}
	}
	system("cls");
	printf("Mutiplicação de matriz:\n");
	for(i=0; i < MAX_LINHA; i++){
		for(j=0; j < MAX_COLUNA; j++){
			printf("\n[%d] * [%d] = %d", matriz1[i][j], matriz2[i][j], matriz3[i][j]);
		}
	}
	system("pause");
	return 0;
}
