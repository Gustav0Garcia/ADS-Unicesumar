#include <stdio.h>
#include <locale.h>

struct produto
{
	int codigo;
	char descricao[50];
	float preco;
	int saldo;
};

int main()
{
	struct produto ficha;

	setlocale(LC_ALL, "Portuguese");

	printf("Digite o c�digo do produto: ");
	scanf("%d", &ficha.codigo);
	fflush(stdin);
	printf("\nDigite a descri��o do produto: ");
	scanf("%s", ficha.descricao);
	fflush(stdin);
	printf("\nDigite o pre�o do produto: ");
	scanf("%f", &ficha.preco);
	fflush(stdin);
	printf("\nDigite o saldo do produto: ");
	scanf("%d", &ficha.saldo);

	printf("\nC�digo: %d", ficha.codigo);
	printf("\nDescri��o: %s", ficha.descricao);
	printf("\nPre�o: %.2f", ficha.preco);
	printf("\nSaldo: %d\n", ficha.saldo);
	
	return(0);
}