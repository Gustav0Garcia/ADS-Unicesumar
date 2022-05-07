/*
Fazer um algoritmo que calcule e imprima o salário reajustado de um funcionário 
de acordo com as seguintes regras:
 • Salário de até R$300,00 reajuste de 50%;
 • Salário maiores que R$300,00 reajuste de 30%;
*/

#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>

float reajustarSalario(float salario);

int main(){
	setlocale(LC_ALL, "Portuguese");
	float salario;
	
	printf("Informe salário (xxx,xx): ");
	scanf("%f", &salario);
	printf("%.2f",reajustarSalario(salario));
	printf("\n");
	system("pause");
	return 0;
}
float reajustarSalario(float salario){
	float reajuste;
	
	if(salario < 3000){
		reajuste = salario + ((salario * 50)/100);
	}else{
		reajuste = salario + ((salario * 30)/100);
	}
	return reajuste;
}
