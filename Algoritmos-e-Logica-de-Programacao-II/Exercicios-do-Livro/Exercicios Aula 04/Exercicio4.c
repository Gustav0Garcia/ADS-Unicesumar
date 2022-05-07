/*
Construa um código em C, que determine quantos números
são maiores que 10 em uma matriz de 3 x 2
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINHA 3
#define MAX_COLUNA 2
int main(){
	setlocale(LC_ALL, "Portuguese");
	int matriz[MAX_LINHA][MAX_COLUNA];
	
	int i, j, cont;
	system("cls");
	
	cont=0;
	printf("Informe os valores:\n");
	for(i=0; i < MAX_LINHA; i++){
		for(j=0; j < MAX_COLUNA; j++){
			printf("Valor [%d][%d]= ", i+1, j+1);
			scanf("%d", &matriz[i][j]);
			
			if(matriz[i][j] > 10){
			cont+=1;
		}
		}
	}
	system("cls");
	
	printf("\nExistem %d números maiores que 10", cont);
	system("pause");
	return 0;
}
