#include <stdio.h>
#include <locale.h>

int main()
{
	int pedido, dia, mes, ano, quantidade;
	float precoUnit, precoTotal;
	pedido = 1;
	precoTotal = 0;

	setlocale(LC_ALL, "portuguese");

	while (pedido != 0)
	{
		printf("\nDigite o número do pedido ou 0 par sair: ");
		scanf("%d", &pedido);

		if (pedido != 0)
		{
			printf("\nDigite o dia do pedido: ");
			scanf("%d", &dia);
			printf("\nDigite o mês do pedido: ");
			scanf("%d", &mes);
			printf("\nDigite o ano do pedido: ");
			scanf("%d", &ano);
			printf("\nDigite o preço unitário: ");
			scanf("%f", &precoUnit);
			printf("\nDigite a quantidade do pedido: ");
			scanf("%d", &quantidade);
			precoTotal = precoTotal + precoUnit * quantidade;
		}
	}
	printf("\nO preço total dos pedidos é: R$ %.2f\n", precoTotal);
	return(0);
}