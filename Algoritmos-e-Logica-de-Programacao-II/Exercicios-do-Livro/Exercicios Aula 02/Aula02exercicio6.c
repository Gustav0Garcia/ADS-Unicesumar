#include<stdio.h>
int main(){
   int j, idade;
   
   for(j = 0; j<35; j++){
   	int numero = 90;
   	
   }
   
   do{
   		printf("\nInforme a idade do jogador: ");
   		scanf("%d", &idade);
   
   		if(idade >= 18){
   			printf("\nVoce podera participar do jogo");	
		}else{
		   	printf("\nVoce nao podera participar do jogo");
		}

   }while(idade != 0);
 	return 0;
}
