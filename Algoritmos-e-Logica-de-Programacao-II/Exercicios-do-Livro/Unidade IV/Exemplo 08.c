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

	printf("Digite o código do produto: ");
	scanf("%d", &ficha.codigo);
	fflush(stdin);
	printf("\nDigite a descrição do produto: ");
	scanf("%s", ficha.descricao);
	fflush(stdin);
	printf("\nDigite o preço do produto: ");
	scanf("%f", &ficha.preco);
	fflush(stdin);
	printf("\nDigite o saldo do produto: ");
	scanf("%d", &ficha.saldo);

	printf("\nCódigo: %d", ficha.codigo);
	printf("\nDescrição: %s", ficha.descricao);
	printf("\nPreço: %.2f", ficha.preco);
	printf("\nSaldo: %d\n", ficha.saldo);
	
	return(0);
}