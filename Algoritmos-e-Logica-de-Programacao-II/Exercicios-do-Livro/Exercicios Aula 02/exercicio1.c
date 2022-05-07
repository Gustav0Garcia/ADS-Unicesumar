#include<stdio.h>
int main(){
   int numero;
   printf("Informe um valor: ");
   scanf("%d", &numero);
   
    if(numero == 1)
   	    printf("Numero informado: um");
    else if(numero==2)
	    printf("Numero informado: dois");
	else if(numero==3)
	    printf("Numero informado: tres");
	else
	    printf("Codigo invalido");
   
   return 0;
}
