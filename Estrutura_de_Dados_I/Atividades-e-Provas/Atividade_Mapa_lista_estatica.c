//Tanto a fila como a pilha s�o conjuntos ordenados de itens, por�m ambas se diferenciam pelas regras de inser��o e remo��o de elementos.Na pilha, a entrada e a sa�da de dados se d�o pela mesma extremidade,  chamada de topo da 
//pilha.Na fila, a entrada e a sa�da ocorrem em lugares opostos : a entrada acontece no final da fila e a sa�da no seu in�cio. OLIVEIRA, Pietro Martins de; LEON, Rog�rio de.Estrutura de Dados I.Maring� - PR, Unicesumar, 2019.

//Uma pilha n�o passa de uma estrutura de dados linear que segue a regra LIFO(Last In First Out).Em uma pilha, tanto a inser��o quanto a exclus�o ocorrem a partir de apenas uma extremidade, ou seja, a partir do topo.

//Considere o seguinte cen�rio :
//Imagine que voc� tem 5 pratos de cores distintas : (1) Vermelho, (2) Verde, (3) Azul, (4) Branco e(5) Laranja e precisa mant� - los um em cima do outro.Voc� come�a colocando o prato de cor vermelha sobre a mesa.
//Este � o primeiro elemento da pilha.Em seguida, voc� coloca o verde em cima do vermelho.Este � o segundo elemento da pilha.Da mesma forma, voc� coloca o prato azul seguido do branco e, finalmente, o laranja.
//Note que o primeiro prato que voc� inseriu na pilha foi o vermelho, e agora voc� quer ordena - los  de forma inversa : 5, 4, 3, 2 e 1.
//A partir dessas informa��es voc� dever� desenvolver um programa em Linguagem C que execute os seguintes passos :
//1 - Preencher uma pilha com os cinco pratos citados acima;
//2 - Imprimir a pilha na ordem em que os elementos foram inseridos(iniciando pela base, e finalizando pelo topo);
//3 � Desempilhar todos os elementos, inserindo - os em uma segunda estrutura de dados do tipo pilha;
//4 - Imprimir a nova pilha na ordem em que os elementos foram inseridos(iniciando pela base, e finalizando pelo topo).


#include <stdio.h>
#include <stdlib.h >
#include <locale.h>
#include <conio.h>

//Contante para o tamanho da pilha
#define tamanho 5


//Registro de estrutura para criar o "tipo pilha"
struct tpilha{
    int dados[tamanho];
    int ini; //vetor para controlar in�cio pilha
    int fim; //vetor para controlar fim da pilha
};

//Vari�veis globais
struct tpilha pilha_A;
struct tpilha pilha_B;
char op;

//Prototipa��o
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();
void pilha_transferir();

//Fun��o principal
int main(){

    setlocale(LC_ALL, "Portuguese"); //Configurar idioma em portugu�s e permitir acentua��o

    op = 1;
    pilha_A.ini = 0;
    pilha_A.fim = 0;
    pilha_B.ini = 0;
    pilha_B.fim = 0;

    while(op != '0'){
        system("cls");
        pilha_mostrar();
        menu_mostrar();
        printf("\n\n__________________________________________________________________________________________________\n\nEscolha uma op��o: ");
        op = getchar();
        system("cls");
        if(op > '0' && op < '4'){
        	switch(op){
            	case '1':
                	pilha_entrar();
            	break;
            	case '2':
                	pilha_sair();
            	break;
            	case '3':
                	pilha_transferir();
            	break;
        	}
    	}
    }
    printf("=================================================================\n=\t\t\t\t\t\t\t\t=\n=\t Curso: An�lise e Desenvolvimento de Sistemas\t\t=\n=\t Mat�ria: Estrutura de Dados I\t\t\t\t=\n=\t Aluno: Gustavo Garcia\t\t\t\t\t=\n=\t RA: 21025427-5\t\t\t\t\t\t=\n=\t\t\t\t\t\t\t\t=\n=================================================================\n_________________________________________________________________\n\n");
    return(0);
}

//Adicionar um elemento no final da Pilha A
void pilha_entrar(){
	int aux =0;
    if(pilha_A.fim == tamanho){
    	pilha_mostrar();
        menu_mostrar();
        printf("\n\n__________________________________________________________________________________________________\n\nPilha A est� lotada, imposs�vel empilhar!\n\n__________________________________________________________________________________________________\n\nAperte qualquer tecla para voltar!");
		getch();
    }
    else{
    	pilha_mostrar();
        menu_mostrar();
        printf("\n\n__________________________________________________________________________________________________\n\nDigite o valor a ser empilhado: ");
        scanf("%d", &aux);
        if(aux >= 1 && aux <= 5){
        	pilha_A.dados[pilha_A.fim] = aux;
        	pilha_A.fim++;
        	aux = 0;
		}
		else{
			system("cls");
			pilha_mostrar();
       		menu_mostrar();
			printf("\n\n__________________________________________________________________________________________________\n\nInserir valores permitidos!\n\n__________________________________________________________________________________________________\n\nAperte qualquer tecla para voltar!");
			getch();
		}	
	}
}

//F�rmula para inserir valores j� pr�-definidos, conforme enunciado, na Pilha A
//void pilha_entrar(){
//	int i;
//    if(pilha_A.fim == tamanho){
//        printf("\nPilha lotada!!\n\n");
//    }
//   else{
//    	for(i = 1; i <= tamanho; i++){
//			pilha_A.dados[pilha_A.fim] = i;
//       		pilha_A.fim++;
//   		}
//	}	
//}


//Retirar o �ltimo elemendo da Pilha A
void pilha_sair(){
    if(pilha_A.ini == pilha_A.fim){
    	pilha_mostrar();
        menu_mostrar();
        printf("\n\n__________________________________________________________________________________________________\n\nA pilha A est� vazia, imposs�vel desempilhar!\n\n__________________________________________________________________________________________________\n\nAperte qualquer tecla para voltar!");
        getch();
    }
    else{
        pilha_A.dados[pilha_A.fim-1] = 0;
        pilha_A.fim--;
    }
}

//Transferir elementos da Pilha A para Pilha B
void pilha_transferir(){
	int aux = 0; // vari�vel auxiliar para guardar a informa��o da pilha para ser transferida para outra pilha
    if(pilha_B.fim == tamanho){
    	pilha_mostrar();
        menu_mostrar();
        printf("\n\n__________________________________________________________________________________________________\n\nPilha B est� cheia, nada foi transferido!\n\n__________________________________________________________________________________________________\n\nAperte qualquer tecla para voltar!");
        getch();
    }
    else{
    	aux = pilha_A.dados[pilha_A.fim-1];
        pilha_A.dados[pilha_A.fim-1] = 0;
        pilha_A.fim--;
        pilha_B.dados[pilha_A.fim] = aux;
        pilha_B.fim++;
        aux = 0;
    }

}

//Mostrar o conte�do da Pilha e regras
void pilha_mostrar(){
    int i;
    //Mostra Pilha A e regras no topo
    printf("==================================================================================================\n=\t\t\t\t\t\tRegras:\t\t\t\t\t\t =\n=  Valores permitidos e cores: [1 - Vermelho | 2 - Verde | 3 - Azul | 4 - Branco | 5 - Laranja]  =\n==================================================================================================\n\n__________________________________________________________________________________________________\n\n-------------\n|  Pilha A  |");
    for(i = tamanho-1; i >= 0; i--){
        printf("\n|    [%d]    |", pilha_A.dados[i]);
        if(pilha_A.dados[i] == 5){
        	printf(" - Laranja");
		}
		else{
			if(pilha_A.dados[i] == 4){
        		printf(" - Branco");
       		}
			else{
				if(pilha_A.dados[i] == 3){
       		 		printf(" - Azul");
      	 		}
       			else{
       				if(pilha_A.dados[i] == 2){
       					printf(" - Verde");	
					}
					else{
						if(pilha_A.dados[i] == 1){
							printf(" - Vermelho");	
						}
					}
				}
			}  
  		}
  	}
  	printf("\n-------------\n\n");
    //Mostrar Pilha B
    printf("-------------\n|  Pilha B  |");
    for(i = 0; i < tamanho; i++){
    	printf("\n|    [%d]    |", pilha_B.dados[i]);
        if(pilha_B.dados[i] == 5){
        	printf(" - Laranja");
		}
		else{
			if(pilha_B.dados[i] == 4){
        		printf(" - Branco");
       		}
			else{
				if(pilha_B.dados[i] == 3){
       		 		printf(" - Azul");
      	 		}
       			else{
       				if(pilha_B.dados[i] == 2){
       					printf(" - Verde");	
					}
					else{
						if(pilha_B.dados[i] == 1){
							printf(" - Vermelho");	
						}
					}
				}
			}  
  		}
  	}
  	printf("\n-------------");
}

//Mostrar o menu de op��es
void menu_mostrar(){
    printf("\n\n__________________________________________________________________________________________________\n\n   Menu\n\n1 - Inserir valor na Pilha A\n2 - Desempilhar Pilha A\n3 - Transferir Pilha A para Pilha B\n0 - Sair");
}
