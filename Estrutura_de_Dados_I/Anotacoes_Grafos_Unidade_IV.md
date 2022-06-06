# **Anotações Estrutura de Dados I - Unidade IV**

&nbsp;

## **Sete pontes de Königsberg**

&nbsp;

A Teoria dos Grafos surgiu informalmente em 1736, quando o matemático e físico suíço Leonhard Paul Euler (1707 - 1783), por meio do seu artigo ***Solutio problematus ad feometriam situs pertinentes***, propôs uma solução para o famoso problema matemático conhecido como **Sete pontes de Königsberg**.

    A  região de Königsberg é cortada pelo Rio Prególia, que divide o território em duas grandes ilhas e duas faixas continentais, na época, havia 7 pontes que interligavam todo o complexo geográfico que formava a cidade. Uma lenda popular dizia ser possível atravessar todas as sete pontes sem repetir nenhuma delas no trajeto.

Euler provou matematicamente que não havia uma solução possível de satisfazer tais restrições, modelando o problema de forma abstrata.

Considerou **cada porção de terra como um ponto (vértice)** e **cada ponte como uma reta (aresta)** que ligava dois pontos (duas porções de terra).

``Ele percebeu que só seria possível caminhar todo o percurso atravessando cada uma das pontes uma única vez se houvesse exatamente zero ou dois vértices de onde saísse um número ímpar de arestas.``

**Se um vértice possuir um número par de arestas, eu posso chegar áquele ponto pela primeira aresta e sair pela segunda. Não havendo vértices com número ímpar de arestas, o percurso pode ser iniciado a partir de qualquer vértice, porém deverá iniciar e terminar no mesmo ponto no grado.**

``Deve haver exatamente zero vértice com número ímpar de arestas.``

**No caso de haver vértices com número ímpar de arestas, precisa haver exatamente dois deles. No caso de haver vértices com número ímpar de arestas eu posso entrar e sair usando duas delas, sobrando uma terceira. Quando temos exatamente dois pontos com número ímpares de caminhos, um desses vértices será obrigatóriamente o início e outro o final do trajeto.**

&nbsp;

## **Teoria dos Grafos**

&nbsp;

**É um ramo da matemática que estuda as relações entre os objetos de um determinado conjunto. Para isso são empregadas estruturas chamadas de grafos.**

Grafo é uma estrutura ***G = (V,E)***, em que ***V*** é um conjunto finito não nulo de vertices (ou nós), e ***E*** é um conjunto de arestas (ou arcos). Uma aresta é um par de vértices ***a = {v,w}***, em que ***v*** e ***w*** **∈** ***V*** e ***a*** **∈** ***E***

**Grafo é formado por dois conjuntos: um de vértices (V, que não pode ser nulo) e um de arestas (E)**

Conjunto ***V*** é formado por:

    V = {a,b,c,d}

``As arestas são formadas sempre por dois vértices que existam no conjunto ***V*** e não há nenhuma obrigatoriedade da existência de arestas no grafo.``

Conjunto ***E*** é formado por:

    E = {(a.b), (b,c), (c,d), (d,a)}

Para indicar que os elementos do conjunto ***E*** são pares ordenados, usamos a notação de chaves angulares ao invés de parênteses. A representação do conjuntps anterior é a seguinte:

    E = {(a.b), (c,b), (a,d), (d,a)}

Em um ``grafo simple``s, dois vértices ***v*** e ***w*** são adjacentes (ou vizinhos) se há uma aresta ***a = {v,w}*** em ***G***. Esta aresta é dita ser incidente a ambos, ***v*** e ***w***. No caso de ``grafos orientado``s, diz-se que cada aresta ***a = (v,w)*** possui uma única direção de ***v*** para ***w*** onde a aresta ***a = (v,w)*** é dita divergente de ***v*** e convergente a ***w***. O grau de um vértice é definido pela sua quantidade de arestas. O seu grau de saída é a quantidade de arestas divergentes e o grau de entrada o de arestas convergentes. No exemplo de grafo orientado, podemos afirmar que o vértice a possui grau 3, sendo grau de saída 2 ***{(a, b), (a, d)}*** e grau 1 de entrada ***{(d, a)}***. Um grafo é dito ``grafo conexo`` quando é possível partir de um vértice ***v*** até um vértice ***w*** por meio de suas arestas incidentes. ``Caso contrário, o grafo é dito desconexo``.

&nbsp;

## **Grafos como representação de problemas**

&nbsp;

Podemos modelar de forma matemáetica diversos problemas reais, como por exemplo, no desenvolvimento de um site, pode ser considerado cada página como um vértice e o link entre duas delas como uma aresta. Uma empresa de logística pode considerar cada cliente como um nó e o caminho entre dois deles um arco. Por meio de um algoritmo de busca de caminho, como o algoritmo de busca em largura ***(BFS - Breadh First Search)***, um sistema informatizado poderia traçar a tora de entrega para o dia seguinte de forma automática a partir de uma lista de pedidos, etc.

&nbsp;

## **Representação computacional de Grafos**

&nbsp;

A maneira mais simples e prática para representar um conjunto finito de informações é um **vetor**. Para a representação de pares ordenados, podemos utilizar uma **matriz bidimensional**.

Dada uma matriz ***Mij*** em que ***i*** é a quantidade de linhas e ***j*** a quantidade de colunas, podemos dizer que, se houver uma aresta a ligando os vértices ***v*** e ***w***, então o valor contido em ***Mvw*** será 1. Essa matriz é chamada de **Matriz de Adjacência**, ``lembrando que dois vértices são adjacentes num grafo se houver uma aresta entre eles``.

Como um Grafo possui quatro vértices, a sua matriz de adjacência terá quatro linhas e quatro colunas. Cada intersecção entre linha e coluna representa um par ordenado (aresta) no Grafo.

&nbsp;

## **Implementando Grafos em C**

&nbsp;

Para representar os vértices, vamos utilizar um **vetor**; para as arestas, uma **matriz** (vetor bidimensional). Como não sabemos a quantidade de vértices no Grafo, iremos criar um vetor grande para que acomode uma grande quantidade de informações, utilizando uma constante chamada ***maximo*** de valor 10

````c
//Constantes
#define maximo 10
````

&nbsp;

Como variáveis, criaremos um **vetor** chamado ***grafo***, com tamanho definido na constante ***maximo***. Para as arestas, utilizaremos um **vetor bidimensional** chamado ***ma***, para representar a matriz de adjacências. Iremos permitir que o usuário defina o tamanho do grafo a´te o limite estabelecido em ***maximo***, utilizaremos para isso uma variável chamada ***tamanho*** do tipo inteira.

````c
//Constantes
#define maximo 10

//Variáveis
int tamanho = 0;
int grafo[maximo];
int ma[maximo][maximo];
````

&nbsp;

O vetor foi criado com um tamanho muito grande, mas o usuário poderá usar apenas uma parte dele. N afunção **grafo_tamanho()** que irá ler a quantidade de vértices e retorna esssa informação para a chamada da função.

````c
//Define o número de vértices do Grafo
in grafo_tamanho(){
    int tamanho;
    printf("Escolha a quantidade de vértices do Grafo: ");
    scanf("%d", &tamanho);
    return tamanho;
}
````
&nbsp;

Para deixar o o usuário escolher a quantidade de nós, precisa verificar se esse valor é válido, se é maior do que zero e menor ou igual ao tamanho definido no vetor.
Próximo passo é inserir as arestas. ``Numa matriz de adjacências, a representação de uma aresta entre um vértice x qualquer com um vértice y se dá pelo valor 1 na posição xy da matriz``.
Como não se trata de um Grafo orientado, podemos considerar que se existe uma aresta xy, também é verdadeiro considerar que existe uma aresta yx. Na função **grafo_inserir()** irá perguntar para o usuário os dois vértices e irá adicionar o valor 1 nas respectivas posições dentro da matriz de adjacências.

````c
//Inserir aresta
void grafo_inserir(){
    int num1, num2;
    system("cls");
    prinft("Ecolha o vértice de origem entre 0 a %d: ", tamanho-1)/
    scanf("%d", &num1);
    prinft("Ecolha o vértice de destino entre 0 a %d: ", tamanho-1)/
    scanf("%d", &num2);
    if(num1 > tamanho-1 || num 2 > tamanho-1 || num1 < 0 || num2 < 0){
        printf("\nOs valores precisam estar entre 0 e %d\n\n", tamanho);
        system("pause");
    }
    else{
        ma[num1][num2] = 1;
        ma[num2][num1] = 1;
    }
}
````

&nbsp;

Também precisamos remover uma aresta do grafo, para que o usuário tenha que começar tudo do zero caso tenha inserido uma aresta por engano. A função **grafo_remover()** irá cumprir essa função e também caso seja necessário transformar o Grafo a partir da remoção de arestas. O`` procedimento será o mesmo, só que ao invés de colocar o valor 1 na posição xy da matriz de adjacências, o valor será definido como 0``.

````c
void grafo_remover(){
    int num1, num2;
    system("cls");
    prinft("Ecolha o vértice de origem entre 0 a %d: ", tamanho-1)/
    scanf("%d", &num1);
    prinft("Ecolha o vértice de destino entre 0 a %d: ", tamanho-1)/
    scanf("%d", &num2);
    if(num1 > tamanho-1 || num 2 > tamanho-1 || num1 < 0 || num2 < 0){
        printf("\nOs valores precisam estar entre 0 e %d\n\n", tamanho);
        system("pause");
    }
    else{
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
    }
}
````

Agora com os dados na memória, só falta mostrar o resultado para o usuários. Serão criadas duas funções, uma chamada **grafo_desenhar()**, que apresentará na tela a lista de vértices, e outra chamada **grafo_desenhar_ma()**, para desenhar a matriz de adjacências.
Para o vetor de vértives, basta um laço de repetição que comece em zero e vá até o valor contido na variável ***tamanho***.

````c
//Função para desenhar o vetor de vértices
void grafo_desenhar(){
    //Desenhando lista de vértives
    printf("Listas de vértices\n[ ");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", grafo[i]);
    }
    prinf("]\n\n");
}
````
Para desenhar a matriz, precisaremos de dois laços de repetição, um para percorrer linhas e o segundo para percorrer as colunas.

````c
//Função para desenhar a matriz de arestas
void grafo_desenhar_ma(){
    //Desenhando matriz de adjacências
    printf("Matriz de adjacencias\n[\n");
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf(" %d", ma[i][j]);
        }
        printf("\n");
    }
    printf("]\n\n");
}
````

``Código completo``:

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //adicionei para funcionar acentuação etc

//Constantes
#define maximo 10

//Variáveis
int tamanho=0;
int grafo[maximo];
int ma[maximo][maximo];
int op=1;

//Prototipação
int grafo_tamanho();
void grafo_desenhar();
void grafo_desenhar_ma();
void grafo_inserir();
void grafo_remover();
void menu_mostrar();

//Função Principal
int main(){
	
	setlocale(LC_ALL, "Portuguese"); //Selecionando a linguagem
    while (tamanho <= 0 || tamanho > maximo){
        tamanho = grafo_tamanho();
        if(tamanho <= 0 || tamanho > maximo) {
            system("cls");
            printf("Escolha um valor entre 1 e %d!\n\n", maximo);
        }
        else {
            for(int i=0; i<tamanho;i++){
                grafo[i] = i;
            }
        }
    }
    while (op != 0) {
    system("cls");
    grafo_desenhar();
    grafo_desenhar_ma();
    menu_mostrar();
    scanf("%d", &op);
    switch (op){
        case 1:
            grafo_inserir();
        break;
        case 2:
            grafo_remover();
        break;
        }
    }
    system("Pause");
    return(0);
}            

//Define o número de vértices do Grafo
int grafo_tamanho(){
int tamanho;
    printf("Escolha a quantidade de vértices do grafo: ");
    scanf("%d", &tamanho);
    return tamanho;
}

//Função para desenhar o vetor de vértices
void grafo_desenhar(){
    //Desenhando lista de vértices
    printf("Listas de vértices\n[ ");
    for (int i = 0; i < tamanho; i++){
        printf("%d ", grafo[i]);
    }
    printf("]\n\n");
}

//Função para desenhar a matriz de arestas
void grafo_desenhar_ma(){
    //Desenhando matriz de adjacências
    printf("Matriz de adjacencias\n[\n");
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            printf(" %d", ma[i][j]);
        }
        printf("\n");
    }
    printf("]\n\n");
}

//Inserir aresta
void grafo_inserir(){
    int num1, num2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ",tamanho-1);
    scanf("%d",&num1);
    printf("Escolha o vértice de destino entre 0 a %d: ",tamanho-1);
    scanf("%d",&num2);
    if (num1 > tamanho-1 || num2 > tamanho-1 || num1 <0 || num2 <0){
        printf("\nOs valores precisam estar entre 0 e %d\n\n",tamanho);
        system("pause");
    }
    else {
        ma[num1][num2]=1;
        ma[num2][num1]=1;
    }
}    

//Remover aresta
void grafo_remover(){
int num1, num2;
    system("cls");
    printf("Escolha o vértice de origem entre 0 a %d: ",tamanho);
    scanf("%d", &num1);
    printf("Escolha o vértice de destino entre 0 a %d: ",tamanho);
    scanf("%d", &num2);
    if (num1 > tamanho-1 || num2 > tamanho-1 || num1 <0 || num2 <0){
        printf("\nOs valores precisam estar entre 0 e %d\n\n",tamanho);
        system("pause");
    }
    else {
        ma[num1][num2]=0;
        ma[num2][num1]=0;
    }
}

//Mostrar o menu de opções
void menu_mostrar() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("0 - Sair\n\n");
}
````

&nbsp;

## **Grafo Conexo, Desconexo, Orientado (ou Dígrafo), Não Orientado e Trivial**

&nbsp;

Um grafo é dito ``grafo conexo`` quando é possível partir de um vértice ***v*** até um vértice ***w*** através de suas arestas incidentes. Caso contrário, o ``grafo é dito desconexo``. 

No caso dos pares de vértices serem ordenados, ou seja, uma aresta ***a = <v,w>*** é considerada diferente da aresta ***a = <w,v>***, o ``grafo é dito orientado (ou dígrafo)``.Caso contrário, o ``grafo é não orientado``.

``Grafo trivial`` é quando possui apenas um vértice e nenhuma aresta.