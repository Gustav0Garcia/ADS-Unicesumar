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

continuar da pág. 98...