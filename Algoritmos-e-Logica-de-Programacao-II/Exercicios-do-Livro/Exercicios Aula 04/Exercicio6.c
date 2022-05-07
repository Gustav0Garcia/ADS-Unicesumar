/*
Defina uma estrutura que irá representar bandas de música:
Essa estrutura deve ter o nome da banda, que tipo de música ela
toca, o número de integrantes e em que posição do ranking essa
banda está dentre as suas 5 bandas favoritas.
*/
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

struct Banda{
	char nome[30];
	char tipoMusica[30];
	int numeroIntegrantes;
	int posicaoRanking;
};

struct Banda bandas[MAX];

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	system("pause");
	return 0;
}
