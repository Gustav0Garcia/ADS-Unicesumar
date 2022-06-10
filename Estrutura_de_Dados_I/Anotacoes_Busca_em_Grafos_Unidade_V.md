# **Anotações Estrutura de Dados I - Unidade V**

&nbsp;

## **Busca em Grafos**

&nbsp;

``Grafo é uma estrutura formada por pelo menos um ou mais vértices (nós) e por um conjunto de arestas (arcos) que, por sua vez pode ser vario. Cada aresta liga dois nós do Grafo``.

**Nos algorimos de busca, o Grafo precisa ser conexo, ou seja, a partir de um nó qualquer é possível navegar por suas arestas visitando todos os demais vértices**.

As buscam, em geral, partem de um nó inicial em direção a um nó alvo, fazendo com que tenhamos que percorrer toda uma sequência ordenada de nós e arestas. O p´roprio caminho, em si, pode ser um objeto da busca, isto é, às vezes a solução reside no caminho percorrido, e não em um ó alvo específico.

Serão abordados os métodos de busca em largura e busca em profundidade, para isso, nos códigos-fonte de exemplo, levaremos em conta alguns preceitos: 
    
    A inclusão das bibliotecas stdlib.h, stdio.h e stdbool.h para auxiliar o desenvolvimento; a declaração da constante MAXV para inficar o tamanho do nosso Grafo (número máximo de vértices); a definição do registro str_no, que reprsenta um vértice; a declaração do vetor de structs grafo[MAXV] que é o grafo em si.

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Número máximo de vértices
#define ,AXV 8

//Estrutura de um nó
typedef struct str_no{
    int if;
    struct str_no *proximo;
}str_no;

//Grafo
struct str_no grafo [MAXV];
````


&nbsp;

## **Busca em Profundidade**

&nbsp;

``Essa técnica faz com que todo um segmento do Grafo seja visitado até o final, antes que uma nova porção seja investigada``.

A partir de um primeiro nó, o algoritmo coloca todos os vértices adjacentes em uma pilha e marca o nó atual como visitado, em seguida, o programa pega o nó do top, desempilhando-o, e repete o processo, a busca segue até que o alvo seja encontrado ou que a pilha esteja vazia.

A função ***buscaEmProfundidade*** recebe três parâmetros:

1. ***g*** é a lista de adjacências que representa o Grafo
2. o ***inicio***, nó inicial de onde a busca partirá em direção ao terceiro parâmetro
3. representa o ***alvo*** da busca

````c
void buscaEmProfundidade (struct str_no g[], int inicio, int alvo){
    int pilha[MAXV]; //pilha
    bool visitado[MAXV]; //nós visitados
    int indice = 0; //índice do topo da pilha
    bool achou = false; //flag de controle (não visitados)
    int corrent = inicio;
    struct str_no *ptr;
    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
    //Marcando os nós como 'não visitados'
    for(i=0; i < MAXV; i++){
        visitado[i] = false;
    }
    while(true){
        //Nó corrente não visitado? Marque como visitado
        //Empilhe o nó corrente
        if(!visitado[corrente]){ //comando de negação
            printf("VISITANDO: %d.\n", corrente);
            if(corrente == alvo){
                printf("Alvo encontrato!\n\n\n");
                return;
            }
            visitado[corrent] = true;
            pilha[indice] = corrente;
            indice++;
        } 
        //Buscando por nós adjacentes, não visitados
        achou = false;
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
            if(!visitado[ptr->id]){
                achou = true;
                break;
            }
        }
        if(achou){
            //Atualizando o nó corrente
            corrente = ptr->id;
        }
        else{
            //Não há vértices adjacentes não visitados
            //Tentando desempilhar o vértice do topo
            indice--;
            if(indice == -1){
                //Não há mais vértices não visitados
                printf("Encerrando a busca. \n");
                break;
            }
            corrente = pilha[indice-1];
        }
    }
    return;
}
````

Iniciamente temos uma pilha vazia e então, empilhando o vértice inicial de partida da pequisa. Temos uma variável ***indice***, que é usada para controlar o fluxo na pilha.

O laço de repetição da linha 14 (While (true)) se repete enquanto houverem itens empilhados ou até que a busca seja concluída com sucesso.

Verificamos se o nó ***corrente*** é o alvo e, se for, imprimimos uma mensagem de sucesso na tela, encerrando a função ***buscaEmProfundidade*** com o ***return*** da linha 22, caso contrário, o algoritmo vsita os nós adjacentes ao nó atual e coloca-os na pilha, acontecendo aí, o processo de desempilhamento, no qual o último nó adjacente visitado será o ponto de partida para a próxima rodada da pesquisa. Fazendo com que a busca percorra um caminho no Grafo até encontrar um nó que não tenha mais vértices adjacentes, nesse momento, o algoritmo inicia uma nova busca a partir do último nó empilhado.

&nbsp;

## **Busca em Largura**

&nbsp;

Se assemlha muito à busca em profundidade, mas a principal diferença é que os nós visitados são enfileirados ao invés de empilhados, garantindo, primeiramente, que sejam percorridos todos os nós adjacentes ao nó atual para, só então, visitar os nós mais distantes, repetindo o processo.

A função ***buscaEmLargura*** possue os mesmos parâmetros da função ***buscaEmProfundidade***, coma  diferença de que empregamos uma ***lista*** para guiar a ordem de visitação dos nós, ao invés de uma pilha.

````c
void buscaEmLargura(struct str_no g[], int inicio, int alvo){
    int fila[MAXV]; //fila
    bool visitado[MAXV]; //nós visitados
    int indice = 0; //controle da fila
    bool achou = false; //flag (não visitados)
    int corrente = inicio;
    struct str_no *ptr;
    int i;
    printf("=-=-=-= Busca em Largura =-=-=-= \n");
    //Marcando os nós como ‘não visitados’.
    for(i=0; i < MAXV; i++){
        visitado[i] = false;
    }
    //Partindo do primeiro vértice.
    printf("VISITANDO: %d. \n", corrente);
    visitado[corrente] = true;
    fila[indice] = corrente;
    indice++;
    while(true){
        //Visitar os nós adjacentes ao vértice corrente
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo){
        //Caso corrente ainda não tenha sido visitado:
        corrente = ptr->id;
        if(!visitado[corrente]){
            //Enfileira e marca como visitado.
            printf("VISITANDO: %d. \n", corrente);
            if(corrente == alvo){
                printf("Alvo encontrado!\n\n\n");
                return;
            }
            visitado[corrente] = true;
            fila[indice] = corrente;
            indice++;
        }
    }
    //Caso a fila não esteja vazia:
    if(indice!=0){
         //Atualizando vértice corrente.
        corrente = fila[0];
        //Desenfileirando o primeiro vértice.
        for(i=1;i<indice+1;i++)
            fila[i-1] = fila[i];
            indice--;
        }
        else{
            //Não há mais vértices para visitar.
            printf("Encerrando busca.\n");
            break;
        }
    }
    return;
}       
````

&nbsp;

## **Algoritmo de Dijkstra**

&nbsp;

Em 1956, o cientista da computação holandês, Edsger Dijkstra concebeu um algoritmo que tem como objetivo solucionar o problema do caminho mais curto entre dois vértices em Grafos conexos com arestas de pesos não negativos.

O algoritmo de Dijkstra assemelha-se ao de busca em largura, mas é considerado um ``algoritmo guloso``, ou seja, **toma decisão que parece ótima no momento**. A estratégia gulosa é muito interessante ao se tratar de problemas complexos ou para análises em grandes quantidades de dados.

O algoritmo de Dijkstra leva em consideração uma matriz de custos. Cada entrada na matriz tem armazenado o custo (peso) da aresta entre dois vértices.

Durante a visita aos vértices adjacentes, o programa inclui na fila apenas os vértice de menor custo.

&nbsp;

``Código do algoritmo de Dijkstra``:

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Variáveis
int destino, origem, vertices = 0;
int custo, *custos = NULL;

//Prototipação
void dijkstra(int vertices,int origem,int destino,int *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);

//Função principal
int main(int argc, char **argv) {
	int opt = -1;

//Laço principal do menu
	do {
		menu_mostrar(); //Desenha o menu na tela
		scanf("%d", &opt);
		switch (opt) {
			case 1:
				grafo_criar(); //cria um novo grafo
			break;
			case 2:
				//procura os caminhos
				if (vertices > 0) {
				grafo_procurar();
			}
			break;
		}
	} while (opt != 0);
	printf("\nAlgoritmo de Dijkstra finalizado...\n\n");
	system("pause");
	return 0;
}

//Implementação do algoritmo de Dijkstra
void dijkstra(int vertices,int origem,int destino,int *custos){
	int i, v, cont = 0;
	int *ant, *tmp;
	int *z; // vertices para os quais se conhece o caminho minimo 
	double min;
	double dist[vertices]; // vetor com os custos dos caminhos
	// aloca as linhas da matriz
	ant = (int*) calloc (vertices, sizeof(int *));
	if (ant == NULL) {
		system("color fc");
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}
	tmp = (int*) calloc (vertices, sizeof(int *));
	if (tmp == NULL) {
		system("color fc");
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}
	z = (int *) calloc (vertices, sizeof(int *));
	if (z == NULL) {
		system("color fc");
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}
	for (i = 0; i < vertices; i++) {
		if (custos[(origem - 1) * vertices + i] !=- 1) {
		ant[i] = origem - 1;
		dist[i] = custos[(origem-1)*vertices+i];
		}
		else {
			ant[i]= -1;
			dist[i] = HUGE_VAL;
		}
		z[i]=0;
	}
	z[origem-1] = 1;
	dist[origem-1] = 0;
	// Laco principal
	do {
	// Encontrando o vertice que deve entrar em z
		min = HUGE_VAL;
		for (i=0;i<vertices;i++){
			if (!z[i]){
				if (dist[i]>=0 && dist[i]<min) {
					min=dist[i];v=i;
				}
			}			
		}
		// Calculando as distancias dos novos vizinhos de z
		if (min != HUGE_VAL && v != destino - 1) {
		z[v] = 1;
			for (i = 0; i < vertices; i++){
				if (!z[i]) {
					if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
						dist[i] = dist[v] + custos[v*vertices+i];
					ant[i] =v;
					}	
				}	
			}
		}
	}while (v != destino - 1 && min != HUGE_VAL);
	// Mostra o Resultado da busca
	printf("\tDe %d para %d: \t", origem, destino);
	if (min == HUGE_VAL) {
		printf("Nao Existe\n");
		printf("\tCusto: \t- \n");
	}
	else {
	i = destino;
	i = ant[i-1];
	}
	while (i != -1) {
		tmp[cont] = i+1;
		cont++;
		i = ant[i];
	}
	for (i = cont; i > 0 ; i--) {
		printf("%d -> ", tmp[i-1]);
	}	
	printf("%d", destino);
	printf("\n\tCusto: %d\n",(int) dist[destino-1]);	
}

void grafo_criar(void){
	do {
		printf("\nInforme o numero de vertices (no minimo 3 ): ");
		scanf("%d", &vertices);
	} while (vertices < 3 );
	if (!custos) {
		free(custos);
	}
	custos = (int *) malloc(sizeof(int)*vertices*vertices);
	//Se o compilador falhou em alocar espaço na memória
	if (custos == NULL) {
		system("color fc");
		printf ("** Erro: Memoria Insuficiente **");
		exit(-1);
	}
	//Preenchendo a matriz com -1
	for (int i = 0; i <= vertices * vertices; i++){
		custos[i] = -1;
	}
	do {
		system("cls");
		printf("Entre com as Arestas:\n");
		do {
			printf("Origem (entre 1 e %d ou ‘0’ para sair): ", vertices);
			scanf("%d", &origem);
		} while (origem < 0 || origem > vertices);
		if (origem) {
			do {
				printf("Destino (entre 1 e %d, menos %d): ", vertices, origem);
				scanf("%d", &destino);
			} while (destino < 1 || destino > vertices || destino == origem);
			do {
				printf("Custo (positivo) do vertice %d para o vertice %d: ",
				origem, destino);
				scanf("%d",&custo);
			} while (custo < 0);
			custos[(origem-1) * vertices + destino - 1] = custo;
		}
	} while (origem);
}

//Busca os menores caminhos entre os vértices
void grafo_procurar(void){
	int i, j;
	system("cls");
	system("color 03");
	printf("Lista dos Menores Caminhos no Grafo Dado: \n");
	for (i = 1; i <= vertices; i++) {
		for (j = 1; j <= vertices; j++) {
			dijkstra(vertices, i,j, custos);
		}
		printf("\n");
	}
	system("pause");
	system("color 07");
}

//Desenha o menu na tela
void menu_mostrar(void){
	system("cls");
	printf("Implementacao do Algoritmo de Dijasktra\n");
	printf("Opcoes:\n");
	printf("\t 1 - Adicionar um Grafo\n");
	printf("\t 2 - Procura Os Menores Caminhos no Grafo\n");
	printf("\t 0 - Sair do programa\n");
	printf("? ");
}
````

``Parte importante do algoritmo de Dijkstra``: a variável **min** irá guardar o menor valor encontrato, ela é inicializada com um valor muito grande, a constante **HUGE_VAL** está presente na biblioteca **math.h** e foi criada para essa finalidade.

Em seguida, existe um laço de repetição em que é verificado se a distância entre o vértice atal e o vértice adjacente é menor do que o contido na variável **min**, se for, o valor da variável é atualizado e o processo se repete até que o vértice não tenha mais nós adjacentes.

````c
		min = HUGE_VAL;
		for (i=0;i<vertices;i++){
			if (!z[i]){
				if (dist[i]>=0 && dist[i]<min) {
					min=dist[i];v=i;
				}
			}			
		}
````

O algoritmo de Dijkstra é muito utilizado em situações em que é preciso minimizar custos ou otimizar recursos.

