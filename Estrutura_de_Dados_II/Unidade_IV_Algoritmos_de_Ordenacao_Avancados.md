# **Anotações Estrutura de Dados II - Unidade IV**

&nbsp;

## **Ordenação por Mergesort**

&nbsp;

Utiliza o conceito ``dividir para conquistar``, esse conceito sugere que um problema complexo possa ser dividido em dois problemas menores, e cada um desses sejam divididos novamente em partes menores ainda, até que se encontre uma parte pequena e simples suficiente para que seja resolvido.

O ``Mergesort`` faz isso de forma recursiva, assim que o vetor é dividido, cada uma das metades é passada como parâmetro a uma nova chamada de funão ``Mergesort``, essa recursividade desce até o ponto em que o vetor tem apenas um único valor, nesse momento, inicia-se o retorno da recursividade, e os vetores unitários são comparados e unidos já ordenados.

Essa abordagem é bem mais complexa que as duas anteriores, mas o seu esforço computacional é resudizdo, para cada divisão, é criado um novo vetor na memória e , no caso de ordenação de arquivos muito grandes, a utilização de memória poder ser excessiva.

Abaixo a implementação do ``Mergesort``, a primeira função mostra a recursividade da técnica, ela recebe como parâmetro o vetor **vec** a ser ordenado, o tamanho **tam** do vetor e uma variável **qtd** inteira usada para medir o esforço computacional do algoritmo.

Se o tamanho do vetor for maior do que um, o programa procura o meio do vetor e aplica a recursão duas vezes, uma para o início até a metade do vetor atual e outra da metade até o final do vetor.

logo após que o vetor for transformado em partes unitárias, a recursividade volta chamando a função junta, ela irá verificar o valor das partes antes de realizar a junção de forma ordenada.

````c
//Aplica o modo mergeSort
int mergeSort(int vec[], int tam, int qtd) {
    int meio;
    if (tam > 1) {
        meio = tam / 2;
        qtd = mergeSort(vec, meio, qtd);
        qtd = mergeSort(vec + meio, tam - meio, qtd);
        junta(vec, tam);
    }
    return (qtd+1);
}

//Junta os pedaços num novo vetor ordenado
void junta(int vec[], int tam) {
    int i, j, k;
    int meio;
    int* tmp;
    tmp = (int*) malloc(tam * sizeof(int));
    if (tmp == NULL) {
        exit(1);
    }
    meio = tam / 2;
    i = 0;
    j = meio;
    k = 0;
    while (i < meio && j < tam) {
        if (vec[i] < vec[j]) {
            tmp[k] = vec[i];
            ++i;
        }
        else {
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    if (i == meio) {
        while (j < tam) {
            tmp[k] = vec[j];
            ++j;
            ++k;
        }
    }
    else {
        while (i < meio) {
            tmp[k] = vec[i];
            ++i;
            ++k;
        }
    }
    for (i = 0; i < tam; ++i) {
        vec[i] = tmp[i];
    }
    free(tmp);
}
````

&nbsp;

A primeira coisa que o algoritimo faz é dividir o vetor em dois a aplicar recursividade em cada uma das metades.

<img src = "Imagens/Merge1.png">

&nbsp;

Cada uma das chamadas ao ``Mergesort`` irá dividir onovamente o vetor, recursivamente, e o processo se repete até que cada vetor contenha apenas um valor

<img src = "Imagens/Merge2.png">

<img src = "Imagens/Merge3.png">

&nbsp;

Nesse momento não há mais chamadas recursivas e começa o retorno para a chamada origina, aplicando a função **junta** nos pares de vetores já ordenados.

<img src = "Imagens/Merge4.png">

&nbsp;

O procedimento se repete até que tenha apenas um vetor, e o mesmo se encontrará totalmente ordenado.

<img src = "Imagens/Merge5.png">

&nbsp;

## **Ordenação por Quicksort**

&nbsp;

Segundo **Cormen (2012)**, esse método também é conhecido como ``classificação por troca de partição**

Criado em 1960 pelo cientista da computação britânico Sir Charles Antony Richard Hoare, é considerado o algoritmo de ordenação mais utilizado no mundo.

``Também utiliza a estratégia de dividir para conquistar``, o primeiro passo é escolher um elemento qualquer que será denominado de pivô, a partir desse elemento, a lista será dividida em três sublistas, uma para o pivô, uma para os valores menores e outra para os valores maiores do que o próprio pivô, isso garante que as chaves menores precedam as chaves maiores e que o pivô esteja na sua correta posição dentro do vetor.

**Essa técnica é muito parecida com a árvore de busca binária**

As duas sublistas (partições) ainda não ordenadas são chamadas de forma recursiva até que cada uma das inúmeras sublistas criadas tenha apenas um elemento e o vetor se encontre ordenado.

A implementação abaixo apresenta duas funções, a primeira é o ``Quicksort`` propriamente dito a sua chamada recursiva, a cada iteração ele incova a função **particiona**, que irá escolher o pivô e criar duas novas listas a serem ordenadas.

````c
//Aplica o modo do quickSort
int quickSort(int vec[], int left, int right, int qtd) {
    int r;
    if (right > left) {
        r = particiona(vec, left, right);
        qtd = quickSort(vec, left, r - 1, qtd);
        qtd = quickSort(vec, r + 1, right, qtd);
    }
    return (qtd +1);
}

//Divide o vetor em pedaços menores
int particiona(int vec[], int left, int right) {
    int i, j;
    i = left;
    for (j = left + 1; j <= right; ++j) {
        if (vec[j] < vec[left]) {
            ++i;
            troca(&vec[i], &vec[j]);
        }
    }
    troca(&vec[left], &vec[i]);
    return i;
}
````

&nbsp;

Esse algoritmo também se assemelha ao ``Mergesort``, a principal diferença é que o ``Quicksort`` trabalha com um pivô em uma posição aleatória e, durante o processo de partição, o pivô já estará na sua posição final do vetor. O ``Mergesort`` divide a estrutura sempre pela metade e inicia o processo de ordenação apenas no final do processo durante o retorno da recursividade.

Abaixo a representação do ``Quicksort``.

<img src = "Imagens/Quick1.png">

&nbsp;

Qualquer elemento pode ser escolhido como pivô, iremos escolher para a simulação o **vec[0] = 3**, iremos separar a lista em três partes, uma com o **pivô**, uma com os elementos menores que **3** e outra com elementos maiores que **3**.

<img src = "Imagens/Quick2.png">

&nbsp;

O valore scolhido para o pivô (**3**), já se encontra na sua devida posição na lista, e à sua esquerda está a sublista com valores menores que **3**, e à direita outra sublista com valores maiores que **3**m irá ser aplicado a recursividade em cada uma dessas sublistas.

Iremos tratar as duas chamadas recursivas separadamente para melhor entendimento, primeiro a da sublista com valores menores que o pivô, escolheremos nela um elemento qualquer para ser o novo pivô na recursão, iremos pegar o **vec [0] = 1**, os valores da sublista serão divididos novamente, ficando os valotes menores à esquerda e os maiores à direita.

<img src = "Imagens/Quick3.png">

&nbsp;

O valor do pivô (**1**) já se encontra na sua devida posição na lista, como apenas sobrou um elemento na sublista (**0**), o mesmo já se encontra ordenado, agora iremos tratar da recursão do outro lado do primeiro pivô.

Iremos nesse caso escolher o **vec[9] = 30** como novo pivô, dividiremos a lista em duas sublistas e aplicaremos novamente a recursão, uma lista terá apenas valores menores do que **30** e a outra apenas valores maiores.


<img src = "Imagens/Quick4.png">

&nbsp;

O algoritmo não sabe, mas a aprte superior da lista já se encontra ordenada, mesmo assim aquela parte também sofrerá recursão e em mais uma interação estará pronta.

A sublista com valores menores também está quase ordenada, e a quantidade de passos necessários para a finalização depende da escolha do pivô, se for escolhido **7** ou **8**, o vetor já ficará ordenado, se for escolhido **20** ou **21**, será necessário ainda mais uma iteração para encontrar o vetor original devidamente ordenado.

<img src = "Imagens/Quick5.png">

&nbsp;

## **Ordenação por Heapsort**

&nbsp;

Para entender o ``Heapsort`` devemos remeter a outra estrutura de dados: **as filas de prioridade**. Uma fila de prioridade agrupa elementos de forma que cada um dos elementos pode ter maior ou menor importância para a aplicação, em suma, nesse tipo de fila é possível inserir elementos a qualquer instante e em qualquer posição do arranjo, de acordo com sua priodade, e sua remoção é sempre feita no elemento de maior prioridade.

A implementação de uma fila de prioridades eficiente, advém da estrutura de dados **heap**, uma **heap** permite a inserção e remoção de elementos em filas de prioridade em tempo logarítimo, tamanha eficiência é alcançada a partir da transformação de um vetor linear em uma estrutura similar a uma árvore binária, todavia, o algoritmo ``Heapsort`` não implementa uma fila de prioridades.

Podemos definir a estrutura de dados **heap** como uma árvore binária com algumas priopriedades adicionais, considere uma árvore binária com N níveis, que vão de **0** até **N-1**:

* A heap deve ser uma árvore binária eficiente, por isso é preciso que ela seja uma árvore completa até o nível N-2. Isto é, a heap é, obrigatoriamente, uma árvore binária completa até o penúltimo nível;

* Por convenção a heap deve fazer com que os nós do nível N-1 (último nível) estejam tão à esquerda quanto possível;

* A chave de cada nó deve ser comparada ao seu nó pai. Ou seja, o conteúdo de nós x e y, cujas subárvores são enraizadas em z, devem respeitar a seguinte regra:

    * No caso de uma max-heap, o nó raiz deve ser maior ou igual aos nós filhos x e y.
    * Já em uma min-heap, o nó raiz deve ser menor ou igual aos  nós filhos x e y.

&nbsp;

Abaixo uma representação de uma **heap**

<img src = "Imagens/Heap1.png">

&nbsp;

Tais propriedades auziliam a armazenar a **heap** em um vetor, ao invés de trabalhar com alocação dinâmica de memória.

Se um nó pai esatá na posição **p** do vetor, então seu filho esquerdo estará na posição **2 x p + 1** e seu filho direito na posição **2 x p + 2**, dessa forma, observe como a **heap** representa visualmente abaixo pode ser armazenada em um vetor **v**.

<img src = "Imagens/Heap2.png">

&nbsp;

As propriedades da **heap** garantem um fato importante: **o maior elemento entre todos sempre estará armazenado na raiz, isto é, na posição inicial do vetor** (**v[0]**), dessa forma, aproveitando essa característica, utilizamos no algoritmo ``Heapsort``.

Primeiro, deve garantir que o vetor esteja formatado como uma **heap**, de acordo com as fórmulas de posicionamento apresentadas anteriormente, damos o nome de **constroiHeap** ao método que realiza essa façanha (e inglês, **Build-Max-Heap**). Além de construir uma árvore binária quase completa dentro do vetor, o método **constroiHeap** é responsável por garantir que cada nó pai seja maior ou igual aos nós filhos.

Em seguida, deve focar nas extremidades do vetor de forma a considerar que, conforme o ``Heapsort`` vai sendo executado, nas partes iniciais do vetor, temos os dados da **heap**, e nas partes finais do vetor, temos o arranjo ordenado, resumindo, durante o processo de ordenação, dividimos o vetor logicamente em duas poções: a **heap** e a porção ordenada do vetor.

Uma vez que o vetor desordenado foi transformado em **heap**, damos sequência, se a intenção for ordenar o vetor em ordem não-crescente (de modo geral, crescente), pode-se simplesmente trocar o maior elemento da raiz pelo elemento que se encontra ao final da **heap**.

Ao trocar o elemento da raiz da **heap** com o elemento do final do vetor, estará posicionamento o maior elemento em sua posição ordenada final, nesse instante, deve desconsiderar tal elemento como um nó da **heap** de forma que, agora ele passe a pertencer à porção ordenada do vetor

Abaixo, o nó 80, raiz do vetor **v** da figura anterior, foi trocada com o nó de chave igual a 13

<img src = "Imagens/Heap3.png">

&nbsp;

O elemento 80, de fato, é o maior de todos e, após a troca, foi posicionado no último índice de **v**, assim, o 80 já se encontra ordenado em sua posição final, todavia, após a troca, a árvore perdeu a propriedade de **heap**, pois a raiz 13 não é maior que seus filhos, quebrando as regras. É necessário consertar a **heap**, fazendo com que a nova raiz "escorrregue" até uma posição que restaure a árvore binária para ser enquadrada enquanto uma **heap**, isso é feito através do método chamado de **heapifica** (em inglês, **heapify**)

<img src = "Imagens/Heap4.png">

&nbsp;

O método **heapifica**, quando invocado, vai comparando um nó pai aos respectivos nós filhos, caso algum filho seja maior que o nó pai, é realizado a troca entre o maior filho e o pai, dessa forma, após essa operação, o nó pai seja, de fato, maior o igual aos nós filhos para manter a propriedade da **heap**.

Essa troca pode fazer com que o novo nó filho quebre as propriedades de **heap**, isto é, o nó filho, recém trocado, pode ter novos filhos que não se categorizam enquanto **heap**, por isso, é preciso invocar o método **heapifica** recursivamente, até que todos os nós necessários sejam corrigidos.

<img src = "Imagens/Heap5.png">

<img src = "Imagens/Heap6.png">

&nbsp;

Pode-se notar como o método **hipifica** troca a raiz de uma subárvore com seu maior filho, à medida em que é  executado, para cada nó trocado, invoca-se o método recursivamente, até que a propriedade de **heap** seja garantida a todos os nós envolvidos no processo, além disso, podemos observar que, ao final, temos novamente uma **heap** na qual o maior entre todos os elementos se encontra na raiz.

Agora, o nó, cuja chave é igual a 75, econtra=se na raiz, assim, repete-se o processo realizado anteriormente, no qual a raiz da **heap** era trocada com o "último" elemento do vetor, por último elemento, seria a última posição da porção desordenada do vetor, ou seja, a última posição da **heap**.

<img src = "Imagens/Heap7.png">

&nbsp;

Pode-se perceber que, repetindo todo o processo descrito, o ``heapsort`` posiciona os maiores elementos ao final do arranjo, de maneira ordenada.

````c
//Garante as propriedades de heap a um nó
int heapifica(int vec[], int tam, int i){
    int e, d, maior, qtd;
    qtd = 1;
    e = 2*i+1;
    d = 2*i+2;
    if(e<tam && vec[e] > vec[i]){
        maior = e;
    }
    else {
        maior = i;
    }
    if(d<tam && vec[d] > vec[maior]){
        maior = d;
    }
    if(maior != i){
        troca(&vec[i], &vec[maior]);
        qtd += heapifica(vec, tam, maior);
    }
    return qtd;
}

//Transforma o vetor em uma heap
int constroiHeap(int vec[], int tam){
    int i, qtd;
    qtd = 0;
    for(i=tam/2;i>=0;i--){
        qtd += heapifica(vec, tam, i);
    }
    return qtd;
}

//Ordena com base na estrutura heap
int heapSort(int vec[], int tam){
    int n, i, qtd;
    qtd = 0;
    qtd += constroiHeap(vec, tam);
    n = tam;
    for(i=tam-1;i>0;i--){
        troca(&vec[0], &vec[i]);
        n--;
        qtd += heapifica(vec, n, 0);
    }
    return qtd;
}
````