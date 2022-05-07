/*
Desenvolver uma função em Linguagem C, que receba um login e senha, e 
devolva se o mesmo está autenticado. 
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

char * autenticar(char loginUsuario[10], char senhaUsuario[10]){
	
	char login[10], senha[10];
	strcpy(login, "rafael");
	strcpy(senha, "123");
		
	if(strcmp(login, loginUsuario) == 0)
		if(strcmp(senha, senhaUsuario)==0)
			return "Usuário Autenticado";
		else
			return "Senha inválida para este usuário";
	else
		return "Usuario Inválido";
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	printf("%s", autenticar("rafael", "123"));
	printf("\n");
	system("pause");
	return 0;
}
