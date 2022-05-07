#include<stdio.h>
int main(){
   char nome[30];
   int i;
   
   printf("Informe o seu nome: ");
   scanf("%s", nome);
   
   for (i = 1; i <= 5; i++){
   	printf("\nNome: %s", nome);	
   }
 
	return 0;
}
