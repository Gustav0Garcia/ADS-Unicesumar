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
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Definindo a estrutura da pilha
struct cores{
	int cod;
	char nome[8];
};

struct no{
    int dado;
    struct no *proximo;
};

//Definindo variáveis
typedef struct no *ptr_no;
ptr_no pilha;
ptr_no pilha2;

int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha, ptr_no pilha2);
void pilha_mostrar(ptr_no pilha, ptr_no pilha2);

//Função principal
int main(){
	//Selecionando a linguagem
	setlocale(LC_ALL, "Portuguese");
    //Inicializando máquina de números randômicos
    op = 1;
    //Criando os primeiros nós das pilhas
    pilha = (ptr_no) malloc(sizeof(struct no));
    pilha->dado = 0;
    pilha->proximo = NULL;
    pilha2 = (ptr_no) malloc(sizeof(struct no));
    pilha2->dado = 0;
    pilha2->proximo = NULL;
    //Laço principal
    while(op != 0){
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    system("Pause");
    return(0);
}

//Mostrar o menu de opções
void menu_mostrar(){
    pilha_mostrar(pilha, pilha2);
    printf("\n\nMenu:\n\n1 - Inserir no final da Pilha 01\n2 - Remover no final da pilha\n0 - Sair\n\nEscolha a opção desejada: ");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            pilha_inserir(pilha);
        break;
        case 2:
            pilha_remover(pilha, pilha2);
        break;
    }
}

//Inserir um elemento no final da Pilha 01
void pilha_inserir(ptr_no pilha){
    while((pilha->proximo != NULL)){
        pilha =  pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(struct no));
    pilha = pilha->proximo;
    printf("\n\nDigite o código da cor: ");
    scanf("%d", &pilha->dado);
    fflush(stdin);
    pilha->proximo = NULL;
}

//Remove um elemento da pilha 01 e transfere pra pilha 02 (não estou entendendo como copiar pilha, estudar mais)
void pilha_copiar(ptr_no pilha, ptr_no pilha2){

    }


    
}

//Desenha o conteúdo das pilhas na tela
void pilha_mostrar(ptr_no pilha, ptr_no pilha2){
    system("cls");
    //Pilha 01
    printf("[Pilha 01]\n");
    while(pilha->proximo != NULL){
       	printf("    [%d]\n", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("    [%d]", pilha->dado);
    //Pilha 02
    printf("\n\n[Pilha 02]\n");
    while(pilha2->proximo != NULL){
        printf("    [%d]\n", pilha2->dado);
        pilha2 = pilha2->proximo;
    }
    printf("    [%d]", pilha2->dado);
}
