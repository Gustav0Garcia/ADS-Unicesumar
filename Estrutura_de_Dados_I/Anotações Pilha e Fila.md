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

Para o desempilhamento...
