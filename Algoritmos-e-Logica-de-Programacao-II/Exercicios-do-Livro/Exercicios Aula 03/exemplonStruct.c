#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 3
struct Pessoa{
	int codigo;
	char nome[30];
};
struct Pessoa cadPessoa[MAX];
int i;

int main(){
	
	for(i=0; i < MAX; i++){
		printf("Informe o codigo da pessoa %d: ", i+1);
		scanf("%d", &cadPessoa[i].codigo);	
		printf("Informe o nome da pessoa: ");
		fflush(stdin);
		gets(cadPessoa[i].nome);	
	}
	for(i=0; i < MAX; i++){
		printf("\nCodigo: %d - Nome: %s", cadPessoa[i].codigo, cadPessoa[i].nome);
	}
	return 0;
}
