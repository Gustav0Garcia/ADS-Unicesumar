#include<stdio.h>
int main(){
   int numero1, numero2;
   
   printf("Informe o valor do número 1: ");
   scanf("%d", &numero1);//5
   printf("Informe um valor do número 2: ");
   scanf("%d", &numero2);//4
	printf("\nNumero 1 = %d - Numero 2 = %d", numero1, numero2);
	if(numero1 > numero2){
		int aux = numero1;
		numero1 = numero2;
		numero2 = aux;
		printf("\nNumero 1 = %d - Numero 2 = %d", numero1, numero2);
	}else{
		printf("Os numeros ja estao ordenados.");
	}
 
	return 0;
}
