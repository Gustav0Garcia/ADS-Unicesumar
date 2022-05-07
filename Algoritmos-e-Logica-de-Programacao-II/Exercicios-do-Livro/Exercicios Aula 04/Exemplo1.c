/*
A empresa 4code, necessita de uma função que a partir da idade de um 
colaborador informada pelo RH, retorne se o mesmo é obrigado a participar 
das eleições. A regra a ser implantada é: maiores de 18 e menores de 70 anos 
são obrigados a votar. Quando o eleitor completa 18 anos, o voto passa a ser 
obrigatório.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

int validarIdade(){
	
	int idade=15;
	if(idade >= 18 && idade < 70){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int retornoVotar;
	retornoVotar = validarIdade();
	
	if(retornoVotar == 1){
		printf("Votação obrigatória\n");
	}else{
		printf("Voto facultativo\n");
	}
	system("pause");
	return 0;
}
