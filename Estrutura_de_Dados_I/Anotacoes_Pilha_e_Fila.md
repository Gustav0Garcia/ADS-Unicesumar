# **Anotações Estrutura de Dados I - Unidade II**

&nbsp;

## **Pilha**

&nbsp;

É uma das estruturas mais imples e mais versáteis dentre as itulizadas na computação.

``Na informática, a pilha é uma etrutura em que os fados são inseridos e removidos no seu topo``

São estruturas conhecidas como  ***Last In, First Out (LIFO)***

``Exemplo``

Temos um vetor de 10 posições no qual serão inseridos os seguintes valores nessa ordem: 1, 5, 12 e 3:

[ 1 ][ 5 ][ 12 ][ 3 ][  ][  ][  ][  ][  ][  ]

Agora serão inseridos 14 e 2:

[ 1 ][ 5 ][ 12 ][ 3 ][ 14 ][ 2 ][  ][  ][  ][  ]

O valor mais a esquerda é o começo da pilha, o lado oposto é o final e todos os valores vão entrando na primeira casa livre à direita. ``Esse é o processo de empilhamento, em que cada novo valor é inserido "em cima" dos valores previamente inseridos (empilhados)``.

``Quando houver remoção de valor, o valor removido será o último valord a pilha``:

[ 1 ][ 5 ][ 12 ][ 3 ][ 14 ][  ][ ][ ][ ][ ]

&nbsp;

``Para se construir uma pilha, são necessários pelo menos 3 elementos``: **um vetor para armazenar os dados e dois números inteiro, um para marcar o início e o outro o final da pilha**

``Exemplo de pilha``:
 
````c
//Constantes
#define tamanho 10

//Estrutura da Pilha
struct tpilha{
    int dados [tamanhoo];
    int ini;
    int fim;
}

//Variávveis globais
struct tpilha pilha;
````

Constante **tamanho** guarda a capacidade máxima da fila, podendo facilmente ser alterada, caso necessário.

O vetor **dados** guardará os valores que forem empilhados.

O atributo **ini** marca o início da pilha.

O atributo **fim**, marca o final da pilha.

As variáveis **ini** e **fim** são inicializadas com valor zero para indicar que a fila está vazia.

&nbsp;

Em seguida, vamos ``criar 3 funções, uma para mostrar o conteúdo da pilha``, que ajuda no entendimento e visualização do processo, ``uma para a entrada (empilhamento)`` e ``outra para a saída (desempilhamento)``.

A função **pilha_mostra()** é um laço de repetição para percorrer todas as posições do vetor e ir imprimindo seus valores na tela, usaremos a constante **tamanho** para saber quantos valores cabem na pilha:

````c
//Mostrar o conteúdo da Pilha
void pilha_mostrar(){
    int i;
    
    printf("[   ");

    for(i = 0; i < tamanho; i++){
        printf("%d  ", pilha.dados[i]);
    }
    printf("]\n\n");
}
````
&nbsp;

A função **pilha_entrar()** foi criada para a entrada de dados. Para o empilhamento, é necessário ler o dado diretamente na primeira posição disponível, que representa o topo da pilha, sendo possível utilizando o atributo **fim** criado na estrutura da pilha, depois da leitura, o valor de **fim** é atualizado para que ele aponte sempre para a primeira posição diponível.

````c
//Adiconar um elemento no final da Pilha
void pilha_entrar(){
    printf("\nDigite o valor a ser empilhado: ");
    scanf("%d", &pilha.dados[pilha.fim]);
    pilha.fim++;
}
````

&nbsp;

Os valores estão sendo empilhados infinitamente, porém sabemos que a pilha tem tamanho finito. é necessário criar mecanismos que evitam o estouro da pilha.

Para isso iremos utilizar a estrutura **pilha_entrar**, adicionando um desvio condicional para verificar se existe espaço disponível para o novo empilhamento.

````c
//Adicionar um elemento no final da Pilha
void pilha_entrar(){
    if(pilha.fim == tamanho){
        printf("\nA pilha está cheia, impossível empilhar um novo elemento\n\n");
        system("Pause");
    }
    else{
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d", &pilha.dados[pilha.fim]);   
        pilha.fim++;
    }
}
````
&nbsp;

Para o desempilhamento, usaremos a função **pilha_sair()**. A remoção se da pelo elemento **fim - 1** do vetor **dados**, o atributo **fim** aponta para a p´rimeira posição livre e queremos o valor diretamente anterior.

``Após a remoção do item, o valor de fim deve ser atualizado para apontar corretamente para o final da pilha que acabou de diminuir``.

````c
//Retirar o último elemento da Pilha
void pilha_sair(){
    pilha.dados[pilha.fim-1] = 0;
    pilha.fim--;
}
````

&nbsp;

``Os vetores não trabalham com índice negativo, e se muitos elementos forem removidos, além da capacidade do vetor, o valor de fim iria diminuir até passar a ser um valor negativo, havendo nova inclusão de valor, iria ser colocado em posição inválida e seria perdido``

É necessário fazer um controle antes da remoção para verificar se a pilha está vazia.

Deve ser feito a comparação do valor **ini** com **fim**.`` Se forem iguais, significa que a pilha está vazia e que nenhum valor pode ser removido``.

````c
//Retirar o último elemento da Pilha
void pilha_sair(){
    if(pilha.ini == pilha.fim){
        printf("\nA Pilha está vazia, não há nada para desempilhar!\n\n");
        system("Pause");
    }
    else{
        pilha.dados[pilha.fim-1] = 0
        pilha.fim--;
    }
}
````

&nbsp;

``Código-fonte completo da pilha``:

````c
#include <stdio.h>
#include <stdlib.h >
#include <locale.h>

//Contante parao tamanho da pilha
#define tamanho 5

//Registro de estrutura para criar o "tipo pilha" constando com um vetor para armazenar os dados e dois números inteiros para controlar o inínico e o fim da pilha
struct tpilha{
    int dados[tamanho];
    int ini;
    int fim;
};

//Variáveis globais
struct tpilha pilha;
int op;

//Prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

//Função principal
int main(){

    setlocale(LC_ALL, "Portuguese"); //Configurar idioma em português e permitir acentuação

    op = 1;
    pilha.ini = 0;
    pilha.fim = 0;

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
        }
    }
    return(0);
}

//Adiciohnar um elemento no final da Pilha
void pilha_entrar(){
    if(pilha.fim == tamanho){
        printf("\nA pilha está cheia, impossível empilhar!\n\n");
    }
    else{
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d", &pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}

//Retirar o último elemendo da Pilha
void pilha_sair(){
    if(pilha.ini == pilha.fim){
        printf("\nA pilha está vazia, impossível desempilhar\n\n");
        system("Pause");
    }
    else{
        pilha.dados[pilha.fim-1] = 0;
        pilha.fim--;
    }
}

//Mostrar o conteúdo da Pilha
void pilha_mostrar(){
    int i;
    printf("[ ");
    for(i = 0; i < tamanho; i++){
        printf("%d", pilha.dados[i]);
    }
    printf("]\n\n");
}

//Mostrar o menu de opções
void menu_mostrar(){
    printf("\nEscolha uma opção:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("3 - Sair\n\n");
}
````

&nbsp;

## **Fila**

&nbsp;

Conceito básico da Fila é o ``FIFO`` (``First In, First Out``), traduzindo, Primeiro que Entra é o Primeiro que sai.

Na programação, a primeira coisa que precisamos é definir a sua estrutura. Usaremos um **vetor** para armazenar os valores que serão enfileirados e dois números inteiros para fazer o controle de início e fim da fila. Usaremos também uma constante para definir a capacidade de armazenamento.

````c
//Contante
#define tamanho 5

//Estrutura da Fila
struct tfila{
    int dados [tamanho];
    int ini;
    int fim;
};

// Variáveis globais
struct tfila fila;
````

&nbsp;

Vamos criar uma função chamada **fila_entrar()**, para acompanhar a entrada de novos valores na fila

A primeira coisa a fazer, é verificar se há espaço, podendo ser feito comparando o atributo **fim** com a constante **tamanho**. Caso haja uma posição livre, o valor será inserido no vetor **dados** na posição **fim** e finalmente o valor de **fim** é incrementado em um.

````c
//Adicionar um elemento no final da Fila
void fila_entrar(){
    if (fila.fim == tamanho){
        printf("A fila está cheia, impossível adicionar um novo valor!\n\n");
        system("Pause");
    }
    else{
        printf("\n Digite o valor a ser inserido: "");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}
````

&nbsp;

A diferença entre a Pilha e a Fila está em sua forma de saída. Na Pilha sai sempre o elemento mais recente, na Fila sai sempre o mais antigo. ``Assim como na Pilha, é necessário fazer uma verificação na Fila para saber se ainda existe algum elemento a sere removido``.

````c
//Retirar o primeiro elemento da Fila
void fila_sair(){
    if(fila.ini == fila.fim){
        printf("\nA fila está vazia, não há nada para remover!\n\n");
        system("Pause");
    }
}
````

&nbsp;

``Como o primeiro elemento da fila será removido, os demais precisam andar em direção ao início. Em seguida. atualizamos o valor do atributo fim para apontar corretamente para o final da fila``.

````c
int i;

for(i = 0; i < tamanho; i++){
    fila.dados[i] = fila.dados[i+1];
}
fila.dados[fila.fim] = 0;
fila.fim--;
````

&nbsp;

A função **fila_sair()** completa:

````c
//Retirar o primeiro elemento da Fila
void fila_sair(){
    if(fila.ini == fila.fim){
        printf("\nA fila está vazia, não há nada para remover!\n\n");
        system("Pause");
    }
    else{
        int i;
        for(i = 0; i < tamanho; i++){
            fila.dados[i] = fila.dados[i+1];
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}
````

&nbsp;

Finalizando, a função **fila_mostrar()**, que possui um laço de repetição que percorre todo o vetor de **dados** e imprime os valores na tela.

````c
//Mostrar o conteúdo da Fila
void fila_mostrar(){
    int i;
    printf("[");
    for(i = 0; i < tamanho; i++){
        printf("%d", fila.dados[i]);
    }
}
````

&nbsp;

Existem outras aformas de Filas, como por exemplo, a Fila Cíclica, que ao invés de mover os dados para a esquerda sempre que a posição fica livre, move-se o atributo que marca o início da fila para a direita.

&nbsp;

``Código completo da Fila``:

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Constantes
#define tamanho 5

//Estrutura da Fila
struct tfila{
    int dados[tamanho];
    int ini;
    int fim;
};

//Variáveis globais
struct tfila fila;
int op;

//Prototipação
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

//Função principal
int main(){
    setlocale(LC_ALL, "Portuguese");

    op = 1;
    fila.ini = 0;
    fila.fim = 0;

    while(op != 0){
        system("Cls");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch(op){
            case 1:
                fila_entrar();
            break;
            case 2:
                fila_sair();
            break;
        }
    }
    return(0);
}

//Adiocnar um elemento no final da Fila
void fila_entrar(){
    if(fila.fim == tamanho){
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("Pause");
    }
    else{
        printf("\nDigite o valor a ser inserido: ");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}

//Retirar o primeiro elemento da Fila
void fila_sair(){
    if(fila.ini == fila.fim){
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("Pause");
    }
    else{
        int i;
        for(i = 0; i < tamanho; i++){
            fila.dados[i] = fila.dados[i+1];
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
}

//Mostrar o conteúdo da Fila
void fila_mostrar(){
    int i;
    printf("[");
    for(i = 0; i < tamanho; i++){
        printf("%d", fila.dados[i]);
    }
    printf("]\n\n");
}

//Mostrar o menu de opções
void menu_mostrar(){
    printf("\nEscolha uma opção:\n");
    printf("1 - Incluir na Fila\n");
    printf("2 - Excluir da Fila\n");
    printf("0 - Sair\n\n");
}