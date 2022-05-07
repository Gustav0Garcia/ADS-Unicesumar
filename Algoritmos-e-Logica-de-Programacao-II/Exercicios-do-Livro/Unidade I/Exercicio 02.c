#include <stdio.h>

int main() {
	char nome[20];

	printf("Digite o seu nome: ");
	gets(nome);

	printf("\nSeja bem-vindo a disciplina de Algoritmos e Logica de Programacao II, %s",nome);
	return 0;
}