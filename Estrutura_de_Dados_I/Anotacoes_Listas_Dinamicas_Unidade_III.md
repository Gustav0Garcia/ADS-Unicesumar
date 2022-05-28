# **Anotações Estrutura de Dados I - Unidade III**

&nbsp;

## **Fundamentos de Listas Dinâmicas**

&nbsp;

A maneira mais simples de guardar um conjunto de informações na memória se dá pelo uso de ``vetores``. Devido o ``vetor`` manter os dados armazenados em uma estrutura sequencial, podendo acessar suas posições.

``Em C, um vetor começa na posição 0 e vai até n-1, em que n é a quantidade de elementos do vetor``.

Na criação de uma **Pilha**, o vetor se mostra muito eficaz, pois a entrada e a saída são feitas sempre no seu último elemento. Para a **Fila**, o vetor mostra algumas dificuldade de implementação, posto que o elemento que sai é sempre o mais antigo e uma das formas de manter os dados de forma sequencial é mover todo o resto dos dados para as posições precedentes, tornando grande dificuldade quando se trabalhga com muitos dados e várias posições na **Fila**

é necessário alterar a forma de organização dos dados para garantir que a ordenação seja independente do índice da variável. Suponhamos que os itens de uma **Pilha** ou **Fila** contivessem, além do seu valor, o endereço do próximo elemento, dessa forma, a partir do primeiro elemento da estrutura, seria possível percorrê-la toda na ordem corrreta, mesmo que fisicamente os dados não se encontrem ordenados na memória do computador. ``Segundo Tenenbaum (1995, p.224)``, tal ordenação explícita faz surgir uma estrutura de dados que é conhecida como ``lista ligada linear``. Na literatura, também pode-se encontrar referêncas à tal estrutura como ``lista encadeada``.

**Cada item na lista é chamado de nó** e contém pelo menos dois elementos: ``um de dados e um de endereço``. O campo de **dados** contém o real elemento da lista e o campo de **endereço** é um ponteiro para o próximo nó.

**Também é preciso uma variável extra que contenha o endereço do primeiro elemento da lista**
Para finalizar uma lista, o atributo endereço do último nó contém um valor especial conhecido como **null**.

Outro tipo de lista é a ``lista duplamente encadeada``, onde cada nó possui pelo menos três campos: ``um de dados e dois de endereço``. **Um dos endereços** é usado para apontar ao nó anterior e **o segundo endereço** aponta para o próximo nó, sendo possível percorrer a lista em ambas as direções.
O endereço anterior do primeiro nó também contém um valor **null** indicando o inínico da lista.
Outro tipo de lista, são as ``listas circulares`` que são estruturas de dados que "não têm fim". É como se fosse uma lista ligada linear simples, porém, ao invés de o último elemento apontar para **null**, ele aponta para o "primeiro" elemento da lista. ``Seria possível, ainda, combinar o concento de lista circular com lista duplamento encadeada``.

No caso do **vetor**, todo o espaço é reservado na memória pelo compilador, ``independendo se estamos usando uma, nenhuma ou todas as suas posições``. ``Já uma lista dinâmica isso não ocorre, pois vamos adicionando nós sempre que for necessário``. 

``Para inserir um novo elemento na lista``, basta encontrar a posição desejada, fazer com que o nó atual aponte para o nó que foi inserido e o novo nó aponte para o local onde apontava o nó imediatamente anterior.

``No processo de remoção``, basta que o nó anterior ao que for removido passe a apontar para o elemento que o nó removido apontava.

&nbsp;

## **Implementando uma Lista Dinâmica**

&nbsp;

A primeira coisa a ser feita, ``é a estrutura do nó``. **Ela terá dois elementos, um inteiro, que guardará a informação propriamente dita, e um  ponteiro, que apontará para o próximo nó**.

````c
struct no{
    int dado;
    struct no *proximo;
}
````

&nbsp;

Com a estrutura definida, tem que criar um **ponteiro do tipo nó, ele será necessário para fazer a alocação dinâmica na memória para cada novo elemento da lista**.

````c
typedef no *ptr_no;
````

&nbsp;

Por último, será criado uma variável que irá apontar para o início da lista, onmde, a partir dela, poderemos navegar do primeiro ao último elemento, fazer remoções e inserções.

````c
ptr_no lista;
````

&nbsp;

A variável do tipo lista foi criada para apontar para a lista encadeada, como ela ainda não existe, tem que ser criado o primeiro nó com o **atributo dado valendo 0** e o **ponteiro proximo apontando para null**.

````c
lista = (ptr_no) malloc(sizeof(no));
lista->dadp = 0;
lista->proximo = NULL;
````

&nbsp;

A função **malloc** precisa, como parâmetro **sizeof**, o tipo de dado que será alocado (estrutura no), com isso o compilador saberá a quantidade exata de memória que precisará reservar.  **O retorno da função precisa ser esperado pela varável lista, que no caso é do tipo ptr_no**.

Com a listadefinida e inicializada, podemos criar agora a função **lista_mostrar()**, para desenhar na tela o conteúdo da lista dinâmica

````c
void lista_mostrar(ptr_no lista){
    system("cls");
    while(1){
        printf("%d, ", lista->dado)/
        if(lista->proximo == NULL){
            break;
        }
        lista = lista->proximo;
    }
}
````

&nbsp;

Será criado um laço infinito (*loop infinito*) que irá funcionar até que o atributo **proximo** do nó atual seja nulo, ``essa abordagem é perigosa, se houver um erro na implementação e o valor do último elemento não apontar para um endereço nulo, ficaremos presos nesse laço de forma indeterminada``.

Redesenhando a função **lista_mostrar()**, fazendo com que a verificação da nulidade do atributo **proximo** ``esteja definida como condicional do laço``.

````c
void lista_mostrar_2(ptr_no lista){
    system("cls");
    while(lista->proximo != NULL){
        printf("%d, ", lista->dado);
        lista = lista->proximo;
    }
    printf("%d, ", lista->dado);
}
````

&nbsp;

A repetição irá para quando chegar ao último elemento, mas sairá do laço antes de imprimir o valor de **dado** do último nó na tela, sendo necessário, para isso, o **printf** adicional no final da função.

Para a inserção dinâmica de um novo nó na lista, será criado a função **lista_inserir()**. A função possui um laço de repetição usado para percorrer a lista até o último nó. Alocamos memória no ponteiro que apontava para nulo, o que significa criar um novo elemento. Fazemos então com que ele aponte para **null** passando a ser o novo final da lista

````c
void lista_inserir(ptr_no lista){
    while(lista->proximo != NULL){
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}
````

Para diferenciar os nós, toda vez que um novo elemento é adicionado à lista, atribuímos um valor aleatório ao seu atrivuto **dados**. Isso é possível utilizando a função **rand()** contida na biblioteca **<time.h>**.

&nbsp;

Para a remoção de um elemento em qualquer posição, será criada a função **lista_remover()**, que irá receber como parâmetro a variável que aponta para o começo da lista.

Irá ser necessário um laço que percorra a lista a partir do primeiro elemento até a posição que queremos remover. ``Se a estrutura nó possuísse dois ponteiros, um para o elemento anterior e um para o próximo, poderíamos ir e voltar livremente pela lista``.

````c
ptr_no atual;
atual = (ptr_no) malloc(sizeof(no));
while((lista->dado != dado)){
    atual = lista;
    lista = lista->proximo;
}
````

Pela lógica, a variável **lista** conterá o elemento que desejamos remover e o nó imediatamente anterior estará na variável **atual**. Para concretizar a remoção, fazemos com que o nó **atual** aponte para onde o nó **lista** estava apontando.

Para a implementação final da função **lista_remover()**. Ela está um pouco mais completa, pois irá perguntar ao usuário qual o nó irá ser removido e faz um controle dentro do laço para finalizar a função, caso chegue ao último nó sem encontrar o item a ser removido.

````c
void lista_remover(ptr_no lista){
    int dado;
    ptr_no atua;
    atual = (ptr_no) malloc(sizeof(no));
    printf("\n\nEscolha uma dos itens:\n");
    scanf("%d", &dado);
    while((lista->dado != dado)){
        if(lista->proximo == NULL){
            break;
        }
        atual = lista;
        lista = lista->proximo;
    }
    if(lista->dado == dado){
        atual->proximo = lista->proximo;
    }
}
````

&nbsp;

**Código completo**:

````c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo a estrutura da lista
struct no{
    int dado;
    struct no *proximo;
};
//Definindo variáveis
typedef struct no *ptr_no;
ptr_no lista;
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

//Função principal
int main(){
    //Inicializando máquina de números randômicos
    srand(time(NULL));
    op = 1;
    //Criando o primeiro nó da lista
    lista = (ptr_no) malloc(sizeof(struct no));
    lista->dado = 0;
    lista->proximo = NULL;
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

//Mostra o menu de opções
void menu_mostrar(){
    lista_mostrar(lista);
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da Lista\n");
    printf("2 - Remover um item da Lista\n");
    printf("0 - Sair\n\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            lista_inserir(lista);
        break;
        case 2:
            lista_remover(lista);
        break;
    }
}

//Insere um elemento no final da Lista
void lista_inserir(ptr_no lista){
    while(lista->proximo != NULL){
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(struct no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}

//Remover um elemento da Lista
void lista_remover(ptr_no lista){
    int dado;
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(struct no));
    printf("\nEscolha um dos itens:\n");
    scanf("%d", &dado);
    while((lista->dado != dado)){
        if(lista->proximo == NULL){
            break;
        }
        atual = lista;
        lista = lista->proximo;
    }
    if(lista->dado == dado){
        atual->proximo = lista->proximo;
    }
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar2(ptr_no lista){
    system("cls");
    while(1){
        printf("%d, ", lista->dado);
        if(lista->proximo == NULL){
            break;
        }
        lista = lista->proximo;
    }
}

//Desenha o conteúdo da Lista na tela
void lista_mostrar(ptr_no lista){
    system("cls");
    while(lista->proximo != NULL){
        printf("%d, ", lista->dado);
        lista = lista->proximo;
    }
    printf("%d, ", lista->dado);
}
````

&nbsp;

## **Lista Dinâmica com Forma de Pilha**

&nbsp;

A lista possui como característica a ordenção independe da forma de armazenamento. ``Para a Pilha, basta criar uma lista dinâmica e adicionar nela as regras LIFO (Último que entra é o primeiro que sai)``.

Vamos criar uma função **pilha_inserir()**. Ela vai percorrer a lista dinâmica até que o último nó aponte para uma posição **NULL**. Inserimos ali um novo nó, ou como diz a definição de pilha, só podemos adicionar valores no final da estrutura.

````c
//Insere um elemento no final da Pilha
void pilha_inserir(ptr_no pilha){
    while(pilha->proximo != NULL){
        pilha = pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha->dado = rand()%100;
    pilha->proximo = NULL;
}
````

&nbsp;

A remoção da pilha se dá da mesma maneira, pode-se remover sempre o último elemento. A função **pilha_remover()** vai percorrer toda a lista até encontrar o nó que aponta para um posição **NULL**. Isso signidica que chegou ao seu final, mas para removê-lo, precisamos ir guardando a posição atual antes de mover o ponteiro para a próxima posição. Quando o ponteiro **pilha** apontar para o último nó da pilha, o ponteiro **atual** estará apontando para a penúltima posição. Basta fazer o ponteiro **atual** apontar para **NULL** e o último elemento acaba de ser removido da estrutura.

````c
//Remove um elemento da pilha
void pilha_remover(ptr_no pilha){
    prt_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    while(pilha->proximo != NULL){
        atual = pilha;
        pilha = pilha->proximo;
    }
    atual->proximo = NULL;
}
````

&nbsp;

``Código de uma lista dinâmica com regras de entrada e saída na forma de pilha``:

````c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Definindo a estrutura da pilha
struct no{
    int dado;
    struct no *proximo;
};

//Definindo variáveis
typedef struct no *ptr_no;
ptr_no pilha;
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);

//Função principal
int main(){
    //Inicializando máquina de números randômicos
    srand(time(NULL));
    op = 1;
    //Criando o primeiro nó da pilha
    pilha = (ptr_no) malloc(sizeof(struct no));
    pilha->dado = 0;
    pilha->proximo = NULL;
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
    pilha_mostrar(pilha);
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover no final da pilha\n");
    printf("0 - Sair\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            pilha_inserir(pilha);
        break;
        case 2:
            pilha_remover(pilha);
        break;
    }
}

//Inserir um elemento no final da Pilha
void pilha_inserir(ptr_no pilha){
    while(pilha->proximo != NULL){
        pilha =  pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(struct no));
    pilha = pilha->proximo;
    pilha->dado = rand()%100;
    pilha->proximo = NULL;
}

//Remove um elemento da pilha
void pilha_remover(ptr_no pilha){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(struct no));
    while(pilha->proximo != NULL){
        atual = pilha;
        pilha = pilha->proximo;
    }
    atual->proximo = NULL;
}

//Desenha o conteúdo da pilha na tela
void pilha_mostrar(ptr_no pilha){
    system("cls");
    while(pilha->proximo != NULL){
        printf("%d, ", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("%d, ", pilha->dado);
}
````

&nbsp;

## **Lista Dinâmica com Forma de Fila**

&nbsp;

``Também pode ser implementado em uma lista dinâmica as regras da fila FIFO (Primeiro que entra, primeiro que sai)``.

A função **fila_inserir()** deve percorrer a lista até o final, encontrando o nó que aponta para uma posição **NULL** e inserir o novo elemento.

````c
//Insere um elemento no final da fila
void fila_inserir(ptr_no fila){
    while(fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = rand()%100;
    fila->proximo = NULL;
}
````

&nbsp;

A remoção é um pouco diferente, sabemos que na fila sempre se remove o elemento mais antigo, ou seja, o primeiro da fila.

Como na lista dinâmica, temos um ponteiro que aponta para o início da fila, basta guardar essa posição, andar na fila apenas uma vez e fazer com que o início da fila aponte para o segundo elemento. A função **fila_remover()** apresentada abaixo, também verifica se a fila não está vazia antes de fazer a remoção, o que pode ocasionar um erro e finzar repentinamente a execução do programa.

````c
//Remover um elemento do início da fila
void fila_remover(ptr_no fila){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo != NULL){
        fila = fila->proximo
        atual->proximo = fila->proximo;
    }
}
````

&nbsp;

``Código de uma lista dinâmica com regras de entrada e saída na forma de fila``:

````c
#include <stdio.lib>
#include <stdlib.h>
#include <time.h>

//Definindo a estrutura da fila
struct no{
    int dado;
    struct no *proximo;
};

//Definindo variáveis
typedef no *ptr_no;
ptr_no fila;
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);

//Função principal
int main(){
    //Inicializando máquina de números randômicos
    srand(time(NULL));
    op = 1;
    //Criando o primeiro nó da fila
    fila = (ptr_no) malloc(sizeof(no));
    fila->dado = 0;
    fila->proximo = NULL;
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
    fila mostrar(fila);
    printf("\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da fila\n");
    printf("2 - remover no início da fila\n");
    printf("0 - Sair\n\n");
}

//Executa a opção escolhida no menu
void menu_selecionar(int op){
    switch(op){
        case 1:
            fila_inserir(fila);
        break;
        case 2:
            fila_remover(fila);
        break;
    }
}

//Insere um elemento no final da fila
void fila_inserir(ptr_no fila){
    while(fila->proximo != NULL){
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(no));
    fila = fila->proxima;
    fila->dado = rand()%100;
    fila->proximo = NULL;
}

//Remove um elemento do inínicio da fila
void fila_remover(ptr_no fila){
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo != NULL){
        fila = fila->proximo;
        atual->proximo = fila->proximo;
    }
}

//Desenha o conteúdo da fila na tela
void fila_mostrar(ptr_no fila){
    system("cls");
    while(fila->proximo != NULL){
        printf("%d, ", fila->dado);
        fila = fila->proximo;
    }
    printf("%d, ", fila->dado);
}
````
