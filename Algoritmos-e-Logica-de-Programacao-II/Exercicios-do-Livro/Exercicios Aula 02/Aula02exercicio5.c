#include<stdio.h>
int main(){
   float vendas, somaVendas;
   
   somaVendas = 0;
   printf("Informe o valor de venda: ");
   scanf("%f", &vendas);
   
   while(vendas != 0){
   		somaVendas = somaVendas + vendas;
		printf("Informe o valor de venda: ");
   		scanf("%f", &vendas);	
   }
 	printf("Valor acumulado do dia: R$ %.2f", somaVendas);
	return 0;
}
