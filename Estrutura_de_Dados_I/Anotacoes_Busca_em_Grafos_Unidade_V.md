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

