# **Anotações Estrutura de Dados II - Unidade III**

&nbsp;

## **Preparando o Ambiente de Testes**

&nbsp;

O programa abaixo traz as ferramentas necessárias para verificar o conteúdo desta unidade:

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define tamanho 10

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt=-1;
int qtd;

//Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

//Função Principal
int main(void){
    srand(time(NULL));
    do {
        system("cls");
        lista_mostrar();
        lista_mostrar_ordenado();
        menu_mostrar();
        scanf("%d",&opt);
        switch (opt){
            case 1:
                lista_gerar();
            break;
            case 2:
                lista_ler();
            break;
        }
    }while(opt!=0);
    system("pause");
    return(0);
}           

//Mostra o conteúdo da lista
void lista_mostrar(void){
    printf("[ ");
    for (int i = 0; i < tamanho; i++ ){
        printf("%d ",lista[i]);
    }
    printf("]\n\n");
}

//Mostra o menu
void menu_mostrar(void){
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("0 - Sair...\n\n");
}

//Gera uma lista aleatória
void lista_gerar(void){
    for (int i = 0; i < tamanho; i++){
        lista[i] = rand()%50;
    }
}

//Permite que o usuário entre com os valores da lista
void lista_ler(void){
    for (int i = 0; i < tamanho; i++){
        system("cls");
        lista_mostrar();
        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%d", &lista[i]);
    }
}

//Preparar a lista para ordenação
void lista_limpar(void){
    for (int i = 0; i < tamanho; i++) {
        ordenado[i] = lista[i];
    }
}

//Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
    printf("[ ");
    for (int i = 0; i < tamanho; i++ ){
        printf("%d ",ordenado[i]);
    }
    printf("] Tempo = %d iteracoes\n\n", qtd);
}
````

&nbsp;

A biblioteca **time** foi incluída para fazer uso da máquina de geração de números aleatórios

A constante **tamanho** servirá de parâmetro em praticamente todas as funções de ordenação, ela define o tamanho máximo do vetor em que os dados estarão armazenados.

a variável **lista** guardará os dados na ordem original, e a variável **ordenado** conterá os valores após a aplicação das técnicas de ordenação. Com o vetor original intacto, iremos plicar diferentes técnicas, uma após a outra sem precisar "bagunçar" os dados no vetor antes de testar um novo algoritmo.

A variável **opt** é usada para fazer o controle do menu e a variável **qtd** é usada para calcular "o esforço computacionar" despendido pela técnica de ordenação

&nbsp; 

Na ``função principal`` o comando **srand** está incluído na biblioteca **time** e serve para inicializar a **máquina geradora de números aleatórios**.

O laço principal limpa a tela, desenha o vetor original, o vetor ordenado e mostra ao usuário quais são as opções disponíveis no programa. Por meio da entrada da variável **opt**, a estrutura **case** chama a função desejada.

&nbsp;

Existem três funções criadas para desenhar a tela do programa.

&nbsp;

a função **lista_gerar**, caso o usuário não queira digitar o conteúdo de um vetor para que possa ser ordenado, a função irá percorrer todo o vetor **lista** e para cada posição sorteia um número entre **0** e **50** por meio da função **rand()%50**.

&nbsp;

Por fim, existem mais duas funções, uma solicita que o usuário preencha uma lista com valores escolhidos por ele. A função **lista_limpar** prepara o vetor auxiliar para a aplicação da técnica de ordenação escolhida pelo usuário, essa função deve ser incluída no laço do menu principal, junto com a função de ordenação em cada uma das novas entradas na estrutura **case**.

&nbsp;

## **Ordenação por Bubblesorte (Método da Bolha)**

&nbsp;

A técnica de ordenação ``Bubblesorte``, também conhecida por ``ordenação por flutuação`` ou por ``método da bola``, **é de simples implementação e de alto custo computacional**.

Começando na primeira posição do vetor, compara-se o valor dela com todos os demais elementos, trocando caso o valor da posição atual seja maior que o valor verificado. Os valores mais altos vão **flutuando** para o final do vetor, criando a odenação da estrutura, esse processo se repete para cada uma das posições da tabela.

````c
//Aplica o método do bubbleSort
int bubbleSort(int vec[]){
    int qtd, i, j, tmp;
    qtd = 0;
    for (i = 0; i < tamanho -1; i++){
        for (j = i+1; j < tamanho; j++){
            if (vec[i] > vec[j]){
                troca(&vec[i], &vec[j]);
            }
            qtd++;
        }
    }
    return(qtd);
}
//Função genérica de troca de valores
void troca(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

````

&nbsp;

O programa traz também uma função chamada **troca**, ela recebe como parâmetro dois ponteiro e tem como objetivo trocar os seus valores de lugar, essa função também será utilizada em outros algoritmos com base no vetor **vec[]** representado abaixo

<img src = "Imagens/Buble1.png">

&nbsp;

Vamos fixar na primeira posição **vec[0] = 3** e compará-lo com o próximo **vec[1] = 1**, como **3 > 1**, os valores são trocados no vetor

<img src = "Imagens/Buble2.png">

&nbsp;

Continuamos fixo no **vec[0]**, que possui valor **1** e comparamos com a próxima posição **vec[2] = 8**, como **1 < 8**, nada acontece.

O programa irá continuar comparando **vec[0]** com todas as demais posições do vetor de dados até encontrar **vec[9] = 0**, onde haverá nova troca.

<img src = "Imagens/Buble3.png">

&nbsp;

Depois será fixado **vec[2]** e, fazemos comparação com o restante do vetor e assim por diante, até que seja encontrado a última posição e os arquivos estejam ordenados, ao mesmo tempo em que os valores maiores são empurrados para a direita, os menores são puxados para a esquerda, no final de cada iteração do laço externo do algoritmo, a parte inicial da tabela fica mais e mais ordenada.

&nbsp;

## **Ordenação por Selectionsort**

&nbsp;

Também é uma **técnica de simples implementação e de alto consumo computacional**.

A partir da primeira posição, procura-se o menor valor em todo o vetor, chegando no final da estrutura, trocamos o menos valor encontrado com a primeira posição, em seguida, ele parte para a segunda posição e passa a procurar o segundo menor valor do vetor até o final da tabela, fazendo a troca de posição dos valores. O algoritmo repete até que a lógica seja aplicada a cada uma das posições da tabela.

````c
//Aplica o modo selectionSort
int selectionSort(int vec[], int tam){
    int i, j, min, qtd=0;
    for (i = 0; i < (tam-1); i++)
    {
        min = i;
        for (j = (i+1); j < tam; j++) {
            if(vec[j] < vec[min]) {
                min = j;
            }
            qtd++;
        }
        if (i != min) {
            troca(&vec[i], &vec[min]);
        }
    }
    return(qtd);
}
````

&nbsp;

Vamos simular a aplicação dessa técnica com base no vetor **vec[]** da figura abaixo. A partir da primeira posição, o algoritmo vai percorrer o vetor até o final armazenando em uma variável temporária o menor valor encontrado, que no nosso caso é o **vec[9] = 0**, iremos utilizar a função **troca** do programa visto anteriormente.
ira ser trocado os valores da primeira posição **vec[0] = 3** com **vec[9] = 0**.

<img src = "Imagens/Select1.png">

&nbsp;

Na segunda posição, o algoritmo percorrerá todo o vetor buscando o segundo menor valor, que é ele mesmo **vec[1] = 1**, nada acontecendo, o próximo passo é procurar a partir da terceira posição o terceiro menor valor, que é **vec[9] = 3**, sendo trocado com o de **vec[2] = 8**.

<img src = "Imagens/Select2.png">

&nbsp;

O algoritmo continua até que o processo seja repetido para cada uma das posições da tabela.

Enquanto o ``Bubblesorte`` **faz uma troca sempre que a posição atual fixa é maior que a posição visitada**, o ``selectionsorte`` **faz a troca apenas quando tem certeza que o menor valor foi encontrado para a atual posição**.

&nbsp;

## **Ordenação por Insertionsort**

&nbsp;

Também conhecida como **ordenação por inserção**, é de **implementação simples e traz bons resultados**.

A técnica consiste em remover o primeiro elemento da lista, e procurar sua posição ideal no vetor e reinseri-lo na tabela, sendo o processo repetido para todos os elementos.

Constam dois laços de repetição, o primeiro é executado inteiro e o segundo um número aleatório, dependendo da distância que o elemento está da sua posição ideal, esse algoritmo também utiliza a a função **troca**.

``Insertionsort`` é muito parecido com ``Bubblesorte`` e o ``Selectionsort``, já que os três trazem dois laços de repetição aninhados, porém, os dois últimos percorrem sempre os dois laços por inteiro, esse é o motivo do ``insertionsorte`` ser mais rápido do que os outros dois.

````c
//Aplicando o insertionSort
int insertionSort(int vec[], int tam)
{
    int i, j, qtd=0;
    for(i = 1; i < tam; i++){
        j = i;
        while((vec[j] < vec[j - 1]) && (j!=0)){
            troca(&vec[j], &vec[j-1]);
            j--;
            qtd++;
        }
    }
    return(qtd);
}
````

O primeiro elemento **vec[0] = 3**, vamos removê-lo do vetor e inseri-lo novamente do lado do primeiro número que encontrarmos que for menor do que ele.

<img src = "Imagens/Insert1.png">

&nbsp;

Os vatores de **vec[0] = 1** e **vec[1] = 3** se encontram corretamente posicionados no vetor, o próximo a ser analisado será **vec[2] = 8**, ele será removido e então reinserido assim que for encontrado um valor menor do que ele, que no caso será **vec[3] = 7**.

<img src = "Imagens/Insert2.png">

&nbsp;

O valor de **vec[4]** já se encontra ao lado de um número maior que ele, assim como **vec[5]** e **vec[6]**, não havendo nenhuma alteração, o próximo valor que será removido e reinserido no vetor é **vec[8] = 30**.

<img src = "Imagens/Insert3.png">

&nbsp;

Faltando apenas fazer o mesmo com o último elemento **vec[9]** e o vetor estará ordenado.

&nbsp;

## **Ordenação por Shellsort**

&nbsp;

Tem esse nome em homenagem ao seu criador ``Donald Shell``, publicado pela Universidade de Cincinnat em 1959.

Segundo ``Wirth (1989, p. 61 a 63)``, **ele é o mais eficiente dentro dos algoritmos classificados como de complexidade quadrática**, é uma técnica refinada do método do ``Insertionsort``.

Ao invés de tratar o arquivo como um todo, ele divide a tabela em segmentos menores e em cada um deles é aplicado o ``Insertionsort``, ele faz isso diversas vezes, dividindo grupos maiores em menores até que todo o vetor esteja ordenado.

Abaixo implementação do algoritmo de ``Shellsor``, ele possui uma variável chamada **gap**, o qual determina a distância entre os elementos que serão removidos do vetor original, ao subteror aplica-se o algoritmo de ``Insertionsort``, e o subvetor é novamente inserido no vetor original, o processo se repete até atingir todos os elementos.

O valor de **gap** sofre um decremento e uma nova quantidade de grupos é criada no vetor parcialmente ordenado, aplica-se o processo de ordenção por ``Insertionsort`` em cada um dos subvetores, o processo se repete até que **gap** seja igual a **1**, então uma nova sequência de ``Insertionsort`` é realizada e o vetor termina por estar odenado.

````c
//Aplica o shellSort
int shellSort(int vec[], int tam) {
    int i , j , valor, qtd=0;
    int gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < tam);
    do {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            valor = vec[i];
            j = i - gap;
            while (j >= 0 && valor < vec[j]) {
                vec[j + gap] = vec[j];
                j -= gap;
                qtd++;
            }
            vec[j + gap] = valor;
        }
    } while ( gap > 1);
    return (qtd);
}
````

Imagina um vetor **vec** de **12** posições e a variável **gap** com valor **3, o primeiro subgrupo terá os valores:

    vec[0], vec[3], vec[6], vec[9], vec[12]

&nbsp;

Nesse subvetor de quatro elementos, é aplicado o ``Insertionsort`` e seus dados serão inseridos de volta no vetor original, depois é a vez dos valores:

    vec[1], vec[4], vec[7], vec[10]

&nbsp;

Aplica-se o ``Insertionsort`` e devolve os valores ao vetor, o processo continua agora para os valores:

    vec[2], vec[5], vec[8], vec[11]

&nbsp;

O novo subvetor é ordenado por ``Insertionsort``, seu resultado é inserido de volta ao vetor original, nesse momento, finaliza a primeira passagem e o **gap** sofre um decremewnto. Vamos supor para o nosso caso que o decremento é de **1**, então **gap** agora será **2**.

Com o novo valor de **gap**, um novo subvetor é criado com os seguintes valores:

    vec[0], vec[2], vec[4], vec[6], vec[8], vec[10], vec[12]

&nbsp;

Esse subvetor é ordenado por ``Insertionsort``, o processo continua até que todos os valores tenham sido escolhidos e o **gap** sofre um novo incremento, quando o valor de **gap** for **1**, será aplicado o algoritmo de ``Insertionsorte`` no vetor original parcialmente ordenado e o processo é finalizado.