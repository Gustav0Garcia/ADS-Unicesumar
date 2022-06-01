//Tanto a fila como a pilha são conjuntos ordenados de itens, porém ambas se diferenciam pelas regras de inserção e remoção de elementos.Na pilha, a entrada e a saída de dados se dão pela mesma extremidade,  chamada de topo da 
//pilha.Na fila, a entrada e a saída ocorrem em lugares opostos : a entrada acontece no final da fila e a saída no seu início. OLIVEIRA, Pietro Martins de; LEON, Rogério de.Estrutura de Dados I.Maringá - PR, Unicesumar, 2019.

//Uma pilha não passa de uma estrutura de dados linear que segue a regra LIFO(Last In First Out).Em uma pilha, tanto a inserção quanto a exclusão ocorrem a partir de apenas uma extremidade, ou seja, a partir do topo.

//Considere o seguinte cenário :
//Imagine que você tem 5 pratos de cores distintas : (1) Vermelho, (2) Verde, (3) Azul, (4) Branco e(5) Laranja e precisa mantê - los um em cima do outro.Você começa colocando o prato de cor vermelha sobre a mesa.
//Este é o primeiro elemento da pilha.Em seguida, você coloca o verde em cima do vermelho.Este é o segundo elemento da pilha.Da mesma forma, você coloca o prato azul seguido do branco e, finalmente, o laranja.
//Note que o primeiro prato que você inseriu na pilha foi o vermelho, e agora você quer ordena - los  de forma inversa : 5, 4, 3, 2 e 1.
//A partir dessas informações você deverá desenvolver um programa em Linguagem C que execute os seguintes passos :
//1 - Preencher uma pilha com os cinco pratos citados acima;
//2 - Imprimir a pilha na ordem em que os elementos foram inseridos(iniciando pela base, e finalizando pelo topo);
//3 – Desempilhar todos os elementos, inserindo - os em uma segunda estrutura de dados do tipo pilha;
//4 - Imprimir a nova pilha na ordem em que os elementos foram inseridos(iniciando pela base, e finalizando pelo topo).


#include <stdio.h>
#include <stdlib.h >
#include <locale.h>

//Contante para o tamanho da pilha
#define tamanho 5


//Registro de estrutura para criar o "tipo pilha"
struct tpilha{
    int dados[tamanho];
    int ini; //vetor para controlar início pilha
    int fim; //vetor para controlar fim da pilha
};

//Variáveis globais
struct tpilha pilha_A;
struct tpilha pilha_B;
int op;

//Prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();
void pilha_transferir();

//Função principal
int main(){

    setlocale(LC_ALL, "Portuguese"); //Configurar idioma em português e permitir acentuação

    op = 1;
    pilha_A.ini = 0;
    pilha_A.fim = 0;
    pilha_B.ini = 0;
    pilha_B.fim = 0;

    while(op != 0){
        system("cls");
        pilha_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch(op){
            case 1:
                pilha_entrar();
            break;
            case 2:
                pilha_sair();
            break;
            case 3:
                pilha_transferir();
            break;
        }
    }
    return(0);
}

//Adicionar um elemento no final da Pilha A
void pilha_entrar(){
    if(pilha_A.fim == tamanho){
        printf("\nPilha lotada!!\n\n");
    }
    else{
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d", &pilha_A.dados[pilha_A.fim]);
        pilha_A.fim++;
    }
}

//Fórmula para inserir valores já pré-definidos, conforme enunciado, na Pilha A
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


//Retirar o último elemendo da Pilha A
void pilha_sair(){
    if(pilha_A.ini == pilha_A.fim){
        printf("\nA pilha A está vazia, impossível desempilhar\n\n");
        system("Pause");
    }
    else{
        pilha_A.dados[pilha_A.fim-1] = 0;
        pilha_A.fim--;
    }
}

//Transferir elementos da Pilha A para Pilha B
void pilha_transferir(){
	int aux = 0; // variável auxiliar para guardar a informação da pilha para ser transferida para outra pilha
    if(pilha_B.fim == tamanho){
        printf("\nNada foi adicionado a fila para inverter\n\n");
        system("pause");
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

//Mostrar o conteúdo da Pilha
void pilha_mostrar(){
    int i;
    //Mostra Pilha A
    printf("Pilha A \n");
    for(i = tamanho-1; i >= 0; i--){
        printf("\n  [%d]", pilha_A.dados[i]);
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
    //Mostrar Pilha B
    printf("\n\nPilha B \n");
    for(i = 0; i < tamanho; i++){
    	printf("\n  [%d]", pilha_B.dados[i]);
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
}

//Mostrar o menu de opções
void menu_mostrar(){
    printf("\n\n\n   Menu\n\n1 - Inserir valor na Pilha A\n2 - Desempilhar Pilha A\n3 - Transferir Pilha A para Pilha B\n0 - Sair\n\nEscolha uma opção: ");
}
