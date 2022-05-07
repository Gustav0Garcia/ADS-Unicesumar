/*
Defina um registro empregado para guardar os dados (nome,
sobrenome, data de nascimento, RG, data de admissão, salário) de
um empregado de sua empresa. Defina um vetor de empregados
para armazenar todos os empregados de sua empresa.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

struct Empregado{
	int codigo;
	char nome[30];
	char sobrenome[30];
	char dataNascimento[10];
	char RG[15];
	char dataAdmissao[10];
	float salario
};

struct Empregado empregados[MAX];

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char resp = 's';
	int i = 0;
	while(resp == 's' && i < MAX){
		empregados[i].codigo = i+1;
		printf("Informe o primeiro Nome:");
		fflush(stdin);
		gets(empregados[i].nome);
		printf("Informe o segundo Nome:");
		fflush(stdin);
		gets(empregados[i].sobrenome);
		printf("Informe a data de nascimento (xx/xx/xxxx):");
		fflush(stdin);
		gets(empregados[i].dataNascimento);
		printf("Informe o RG:");
		fflush(stdin);
		gets(empregados[i].RG);
		printf("Informe a data de Admissão (xx/xx/xxxx):");
		fflush(stdin);
		gets(empregados[i].dataAdmissao);
		printf("Informe o Salário:");
		fflush(stdin);
		scanf("%f", &empregados[i].salario);
			
		printf("Continuar a leitura [s] Sim, [n] Não:");
		fflush(stdin);
		scanf("%c", &resp);
	
		if(resp == 's') {
			if(i < MAX){
				i++;	
			}else{
				printf("Limite de cadastro atingido!!!");
				system("pause");
				resp ='n';
			}
		}
	}
	
	int j = 0;
	for(j = 0; j <= i; j++){
		printf("\nCódigo: %d", empregados[j].codigo);
		printf("\nNome: %s", empregados[j].nome);
		printf("\nSobrenome: %s", empregados[j].sobrenome);
		printf("\nData de nascimento: %s", empregados[j].dataNascimento);
		printf("\nRG: %", empregados[j].RG);
		printf("\nData de Admissão: %s", empregados[j].dataAdmissao);
		printf("\nSalário: R$ %.2f",empregados[j].salario);
	}
	system("pause");
	return 0;
}
