/*
Defina uma estrutura que ir� representar bandas de m�sica:
Essa estrutura deve ter o nome da banda, que tipo de m�sica ela
toca, o n�mero de integrantes e em que posi��o do ranking essa
banda est� dentre as suas 5 bandas favoritas.
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
