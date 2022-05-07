#include <stdio.h>
#define MAX_LINHA 3
#define MAX_COLUNA 2

int main(){
	float notas[MAX_LINHA][MAX_COLUNA];
	int i, j;
	
	for(i = 0; i < MAX_LINHA; i++){
		printf("\nNotas do aluno %d\n: ", i+1);
		for(j = 0; j < MAX_COLUNA; j++){
			printf("Informe a nota %d: ", j+1);
			scanf("%f", &notas[i][j]);	
		}
	}	
	printf("\n****************************************");
	printf("\n*         Imprimindo as notas           ");
	printf("\n****************************************");
	
	for(i = 0; i < MAX_LINHA; i++){
		printf("\nNotas do aluno %d: \n", i+1);
		for(j = 0; j < MAX_COLUNA; j++){
			printf("\nNota %d = %.2f ", j+1, notas[i][j]);
		}
	}
	return 0;
}
