#include <stdio.h>
#include <locale.h>

struct produto
{
	int codigo, saldo;
	char descricao[50];
	float preco;
};

int main()
{
	struct produto ficha[10];
	int i;

	setlocale(LC_ALL, "portuguese");

	for (i = 0; i < 10; i++)
	{
		printf("\nDigite o código do produto %d: ", i + 1);
		scanf("%d", &ficha[i].codigo);
		fflush(stdin);

		printf("\nDigite a descrição do produto: ");
		scanf("%s", ficha[i].descricao);
		fflush(stdin);

		printf("\nDigite o preço do produto: ");
		scanf("%f", &ficha[i].preco);
		fflush(stdin);

		printf("\nDigite o saldo do produto: ");
		scanf("%d", &ficha[i].saldo);
	}
	for (i = 0; i < 10; i++)
	{
		printf("\nProduto: %d \nCódigo: %d \nDescrição: %s \nPreço: %.2f \nSaldo: %d\n", i + 1, ficha[i].codigo, ficha[i].descricao, ficha[i].preco, ficha[i].saldo);
	}
	return(0);
}