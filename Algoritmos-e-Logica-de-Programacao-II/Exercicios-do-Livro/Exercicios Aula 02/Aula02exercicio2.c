#include<stdio.h>
int main(){
   int numero;
   
   printf("Informe um valor: ");
   scanf("%d", &numero);
   
   if(numero > 0){
   		printf("Valor Valido, voce informou o numero %d", numero);
   }else if(numero == 0){
	   	printf(" %d eh um Valor inválido. Informar um numero inteiro positivo", numero);
   }else{
   		printf(" %d eh um Valor inválido. Informar um numero inteiro positivo", numero);
   }
    
      return 0;
}
