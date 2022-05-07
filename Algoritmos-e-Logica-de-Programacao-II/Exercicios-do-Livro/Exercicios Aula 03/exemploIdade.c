#include <stdio.h>
#define MAX 5
int main(){
	int idade[MAX];
	int i, somaIdade;
	float media;
	somaIdade = 0;
	
	for(i = 0; i < MAX; i++){
		printf("Informe a idade do aluno %d: ", i+1);
		scanf("%d", &idade[i]);
		somaIdade += idade[i];	
	}
	media = somaIdade/5;
		printf("Media = %.2f", media);
	if(media > 18){
		printf("Nivel dificil");
	}else if(media > 15){
			printf("Nivel medio");
	}else{
			printf("Nivel facil");
	}
	return 0;
}
