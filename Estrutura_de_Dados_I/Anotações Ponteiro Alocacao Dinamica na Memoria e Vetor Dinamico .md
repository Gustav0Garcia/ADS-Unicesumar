# **Anotações Estrutura de Dados I**

&nbsp;

## **Ponteiro**

&nbsp;

`É uma variável especial para armazenar endereços`

"Aponta" para o endereço dee uma outra variável

`Operadores:`

    Asterisco (*): declaração ou acesso a conteúdo
    Endereço (&): referência (endereço em memória)

Ao invés de obter o valor armazenado numa variável, podemos opcionamente obter o seu endereço na memoria. Por `exemplo`:

Criamos uma variável `x` do tipo `int`; para saber qual o seu endereço, usamos a notação `&x`. Isso significa que `&x` é um `ponteiro` que aponta para o endereço da variável `x` ma memória.

`Exemplo de criação de variáveis e ponteiros`
```c
#include <stdio.h>
#include <stdlib.h>

int xi;
int *ptr_xi;

float xf;
float *ptr_xf;

char xc;
char *ptr_xc;

int main(){

    system("Pause);
    return(0);
}

````

As variáveis **ptr_xi**, **ptr_xf** e **ptr_xc** são `ponteiros` que aponbtam para as variáveis, **xi**, **xf** e **xc**, respectivamente.

Segundo `Tenembaum (1995, p.29)`, "[...] um ponteiro é como qualquer outro tipo de dado em `C`. O valor de um ponteiro é uma posição na memória da mesma forma que o valor de um inteiro é um número".

Como **ptr_xi**, **ptr_xf** e **ptr_xc** são `ponteiros`, não podemos simplesmente atribuir a eles os valores de **xi**, **xf** e **xc**. Para isso devemos usar `&xi`, `&xf` e `&xc`, que significa "`o ponteiro que aponta para o endereço na memória da variável xi, xf e xc`"

```c
ptr_xi = &xi;
ptr_xf = &xf;
ptr_xc = &xc;
````

Assim, sabemos que os ponteiros **ptr_xi**, **ptr_xf** e **ptr_xc** contém o endereço de uma variável. E para saber o `o valor daquele objeto, utilizamos a notação *ptr_xi, *ptr_xf e *ptr_xc`

```c
xi = *ptr_xi;
xf = *ptr_xf;
xc = *ptr_xc;
```

`Exemplo:`

```c
#include <stdio.h>
#include <stdlib.h>

int xi;
int *ptr_xi;

void imprimir(){
    printf("Valor de xi = %d \n", xi);
    printf("Valor de &xi = %p \n", &xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi);
}

int main(){
    xi = 10;
    ptr_xi = &xi;
    imprimir();

    xi = 20;
    imprimir();

    *ptr_xi = 30;
    imprimir();

    system("Pause");
    return(0);
}
```

A saída esperada para o algoritimo:


    Valor de xi = 10
    Valor de &xi = 00405020
    Valor de ptr_xi = 00405020
    Valor de *ptr_xi = 10

    Valor de xi = 20
    Valor de &xi = 00405020
    Valor de ptr_xi = 00405020
    Valor de *ptr_xi = 20

    Valor de xi = 30
    Valor de &xi = 00405020
    Valor de ptr_xi = 00405020
    Valor de *ptr_xi = 30


``Ponteiro sempre deve ser do mesmo tipo de variável que irá apontar (exemplo: ambos int). Se não souber qual tipo de variável irá utilizar, deve criar o ponteiro do tipo void, que aceitar qualquer outro (tipo uma carta coringa).``

Porém é possível em C, fazer a conversão de ponteiros de tipos diferentes.

``Exemplo: converter o valor de ptr_xf para o tipo ponteiro para um inteiro por meio do comando (int *)``

```c
ptr_xi = (int *) ptr_xf;
```

E é possível aplcar diversos operadores aritméticos em variáveis. Se ``ptr_xi`` contém o endereço de um valor inteiro na memória, ``ptr_xi+1`` irá apontar para o endereço do número inteiro imediatamente posterior a ``*ptr_xi`` e ``ptr_xi-1`` irá apontar para o primeiro endereço de um número inteiro imediatamente anterior a ``*ptr_xi``. 

``Dessa forma, a partir de um ponteiro, é possível navegar pela memória investigando os valores de outros endereços sem precisar saber qual variável eles pertencem``

&nbsp;

## **Alocação Dinâmica na Memória**

Existe uma forma de alocar variáveis dinamicamente, criando mais e mais espaço de acordo com a necessidade do programador, sem haver necessidade de prevê-las durante o desenvolvimento do programa:

```c
int *ptr;
printf("Endereco: %p\n\n", ptr);
ptr = (int *) malloc(sizeof (int));
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
```

A função ``malloc`` reserva um espaço na memória do tamanho ``sizeof``

A saída esperada para o algoritimo:


    Endereco: 00000008

    Endereco: 00380CA0
    Valor: 3673280


Após a alocação na memória pela função ``malloc``, o ponteiro **ptr** passa a apontar um endereço válido disponibilizado pelo compilador.

Quando o espaço na memória é reservado de forma dinâmica, seu valor não é inicializado tal qual na declaração estática.

O compilador busca na memória um bloco de 4 byts (por ter usado int no exemplo) disponível e passou esse endereço para ``ptr``, porém aqueles bytes já possuiam valores. ``A memória só é zerada, quando o computador é desligado e sua fonte de alimentação de energia interrompida, ou por comando específico do SO``

``Exemplos``

```c
int *ptr;
printf("Endereco: %p\n\n", ptr);
ptr = (int *) malloc(sizeof (int));
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
*ptr = 10;
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
```

Agora que ``ptr`` está apontando para um endereço válido na mem´roa, podemos armazenar valor em ``*ptr``

A saída esperada para o algoritimo:

    Endereco: 00000008

    Endereco: 00380CA0
    Valor: 3673280

    Endereco: 00380CA0
    Valor: 10

A atribuição de ``*ptr = 10`` o endereço do ponteiro continua inalterado

Agora, criando uma variável ``x`` do tipo inteira, inicializando com valor 20 e atribuindo o endereço ``&x`` para ``ptr``:

```c
int x;
x = 20;
ptr = &x;
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
```

A saída esperada para o algoritimo:

    Endereco: 0028FF08
    Valor: 20

O endereço original de ptr se perde, já que não era de nenhuma variável, mas alocado dinâmicamente para o ponteiro

Realizando novo ``malloc``:

```c
int x;
x = 20;
ptr = &x;
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

ptr = (int *) malloc(sizeof (int));
printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
```

A saída esperada para o algoritimo:

    Endereco: 0028FF08
    Valor: 20

    Endereco: 00380CC0
    Valor: 3683664

O ``*ptr`` traz o "lixo" de bits existentes no endereço que acabou de ser alocado a ele pela função ``malloc``

``Função completa:``

````c
#include <stdio.h>
#include <stdlib.h>

main(){
    int *ptr;
    
    printf("Endereco: %p\n\n", ptr);
    ptr = (int *) malloc(sizeof (int));
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);
    *ptr = 10;
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    int x;
    x = 20;
    ptr = &x;
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    ptr = (int *) malloc(sizeof (int));
    printf("Endereco: %p \nValor: %d\n\n", ptr, *ptr);

    system("Pause");
    return(0);
}
````

A saída esperada para o algoritimo:

    Endereco: 00000008

    Endereco: 00380CA0
    Valor: 3673280

    Endereco: 00380CA0
    Valor: 10

    Endereco: 0028FF08
    Valor: 20

    Endereco: 00380CC0
    Valor: 3683664

&nbsp;

## **Criando Vetores Dinâmicos**

&nbsp;

Para evitar o problma de reservar mais espa~p do que realmentye precisamos e não ficarmos limitados a quantidade previamente estipulada de posições do vetor, ``utilizamos vetores dinâmmicos``

``Exemplo``

Na função **main()**, vamos criar uma variável **tam** do tipo inteiro para ler o tamanho do vetor e uma variável do tipo pontyeiro chamado **vetor**, que será criada de forma dinâmica de acordo com o valor lido na variável **tam**

````c
int tam;
int *vetor;

printf("Escolha o tamanho do vetor: ");
scanf("%d", &tam);

vetor = (int *) malloc(sizeof (int) *tam);
````

O processo de alocação de um vetor usando ``malloc`` é muito parecido com o de uma variável simples, basta multiplicar o tipo definido em ``sizeof`` pela quantidade de posições que deseja para o vetor.

``Código completo do exemplo:``

````c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

main(){

int tam;
int *vetor;

printf("Escolha o tamanho do vetor: ");
scanf("%d", &tam);

vetor = (int *) malloc(sizeof (int) * tam);

for (int i = 0; i < tam; i++){
    vetor[i] = pow(2, i);
    printf("Posicao %d: %d\n", i, vetor[i]);
}
system("Pause");
return(0);
}
````