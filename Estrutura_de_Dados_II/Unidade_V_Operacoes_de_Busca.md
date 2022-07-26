# **Anotações Estrutura de Dados II - Unidade V**

&nbsp;

## **Conceitos Básicos**

&nbsp;

Uma **tabela** ou **arquivo** é um conjunto de **registros**, e um **registro** é um conjunto de **dados**.

Existe uma **chave** associada a cada registro, se ela estiver dentro do próprio registro ela é chamada de **chave interna**, **chave embutida** ou **incorporada**, no caso da chave ficar fora do registro ela é chamada de **chave externa**.

Para todos os registros dentro de uma tabela, pelo menos um dos campos precisa ter um valor único para diferenciar cada um dos registros, esse campo é chamado de **chave primária**.

Se nenhum dos campos de um registro for potencial para servir de chave primária (**como por exemplo, utilizar o CPF como chave primária**) deve ser criado um novo campo, chamado de **codigo** ou **id**, e atribuir um número único para cada um dos registros.

Quando um atributo com informações não únicas é utilizado em uma pesquisa, ele é chamado de **chave secundária**.

As grandes massas de dados ficam armazenados em dispositivos de memória secundária, como disco rígido, disco óptico, fita magnética, memória flash, dentre outros, entretanto, todo dado para ser manipulado, precisa necessariamente estar na memória principal. Como a relação entre as duas memórias é desproporcional, ou seja, um computador tem GB de memória RAM enquanto possui TB de memória de armazenamento, somente uma pequena parcela dos dados pode ser analisada por vez, dessa forma, é mais inteligente carregar apenas uma tabela de chaves do que todos os registros de um arquivo.

&nbsp;

## **Operação de Busca Sequencial**

&nbsp;

É a forma mais simples de pesquisa, ela pode ser utilizada tanto para o caso em que a tabela está armazenada em um vetor como em uma lista ligada.

A partir da primeira posição no vetor (ou do primeiro nó da lista), compara-se o valor atual da estrutura com o argumento **x** passado, repete-se esse procecimento com cada um dos valores até que seja encontrado o valor desejado ou o final da tabela.

Abaixo algoritmo apresentando a busca sequencial em C, a função **buscaSequencial** recebe três parâmetros: o vetor **vec** a ser pesquisado, o argumento **arg** a ser procurado e o tamanho **tam** do vetor.

São criadas duas variáveis locais, a variável **i** serve de índice para percorrer o vetor, enquanto a variável **achou** é usada para identificar se a busca foi concluída antes do final do vetor.

``Como os vetores em C começam pela posição 0, a variável i também foi iniciada com esse valor, para que a pesquisa realmente dê início pelo começo do vetor, a variável achou foi incializada com -1``.

Durante o laço de repetição, é verificado se a variável de controle **i** atingiu o tamanho máximo **tam** recebido como parâmetro, o valor de **i** é incrementando sempre no final do laço, garantindo que a busca percorra o vetor até o final.

Acionalmente o laço possui outra regra de parada que verifica o valor da variável **achou**, ela foi iniciada com **-1**, porém, se o valor for encontrado, a sua posição no vetor serpa atribuída ao valor de **achou**

Ao final, a função retorna o valor da variável **achou**, ele serpa **-1** se a busca falhar, ou, no caso contrário, a posição do registro no vetor.

````c
//Função de Busca Sequencial
int buscaSequencial(int vec[], int arg, int tam){
    int i = 0, achou = -1;
    while ((i < tam) && (achou == -1)){
        if (vec[i]==arg){
            achou = i;
        }
        i++;
    }
    return(achou);
}
````

&nbsp;

## **Busca Sequencial Indexada**

&nbsp;

Se for observado que alguns argumentos específicos sejam procurados com mais frequência, esses registros podem ser movidos para uma região mais próxima do início da tabela, fazendo com que futuras buscas sejam cada vez mais rápidas.

**Tenenbaum (1995)** fala de um método em particular, muito simples e que traz bons resultados, chamado método da **transposição**, no qual o registro recuperado com sucesso é trocado pelo registro imediatamente anterior.

A ``Busca Sequencia`` procuraria o valor desejado em cada uma das posições até encontrá-lo ou até chegar ao final do arquivo, o que ocorrer primeiro, mesmo se o registro não existir na tabela, todo o arquivo seria percorrido.

A técnica de ``Busca Sequencial Indexada`` consiste em criar uma tabela auxiliar ao arquivo de dados, nessa tabela, deve constar pelo menos dois campos: a **chave de busca** e o **endereço do registro na tabela original**.

A tabela de índice pode ser ordenada de forma ascendente, descendente ou de qualquer outra forma que seja mais compatível com as principais buscas que utilizarão a chave contida na tabela auxiliar.

&nbsp;

## **A Busca Binária**

&nbsp;

**É a forma mais eficiente de efetuar pesquisa em um arquivo ordenado sem a necessidade de tabelas auxiliares**, a estratégia consiste emn comparar o argumento chave ao elemento do meio da tabela, se forem iguais, a busca terá terminado com sucesso, caso contrário, o vetor serpa dividido em duas metades, e a pesquisa será repetida na metade inferior, se o argumento for menor do que o valor do meio da tabela, ou na parte superior, se o argumento for maior.

A cada iteração, a ``Busca Binária`` reduz a quantidade de possíveis candidatos pela metade, **vale ressaltar que essa estratégia funciona apenas em estruturas cujos dados se encontram ordenados**.

``esse algoritmo não pode ser utilizado com listas dinâmicas devido às características da sua estrutura``, mesmo criando um ponteiro especial que aponte para o meio da lista, toda vez que o problema for dividido, a lista precisará ser percorrida novamente para achar o meio da nova metade da lista, o que torna o tempo de execução do algoritmo muito extenso. Abaixo algoritmo em C apresentando essa busca:

````C
//Função de Busca Binária
int buscaBinaria(int vec[], int arg, int tam){
    int menor, maior, meio;
    menor = 0;
    maior = tam-1;
    while (menor <= maior){
        meio = (menor + maior)/2;
        if (arg == vec[meio]){
            return(meio);
        }
        if(arg < vec[meio]){
            maior = meio - 1;
        }
        else {
            menor = meio + 1;
        }
    }
    return(-1);
}
````

&nbsp;

A função **buscaBinaria** recebe três parâmetros: o vetor **vec** que será pesquisado, o argumento **arg** que será procurado e o tamanho **tam** do vetor, são criadas três variáveis internas, uma para marcar a posição de início (**menor**) da pesquisa, o limite a ser pesquisado (**maior**) e o **meio** do vetor.

A variável **menor** é inicializada com o valor **0**, que na linguagem C representa o início do vetor, a variável **maio** é inicializada com o valor **tam - 1**, posto que um vetor de tamanho **n** vai de **0** até **n - 1**.

O laço será repetido enquanto a variável **menor** for menor ou igual a variável **maior**, nele será calculada a posição do **meio** entre **menor** e **maior**, se o argumento **arg** estiver na posição **meio** do vetor **vec**, a função retorna o valor de **meio** e o algoritmo conclui a **recuperação**, se a **recuperação** não foi concluída, é preciso atualizar o valor da variável **meio**, como o vetor se encontra ordenado, se o argumento **arg** for menor do que o conteúdo no vetor **vec** na posição **meio**, então a busca deverá ser feita entre a posição **menor** e a metade, caso contrário, a busca deve continuar entre a metade e o final do vetor.

Simulação de uma busca binária: vetor ordenado de 10 posições, o valor do argumento a ser encontrato é **5**.

    a) A variável menor será inicializada em 0 e maior com 9 (tamanho -1)
    b) Para o cálculo do meio do vetor fazemos:

    meio = (menor + maior) / 2

    meio = (0 + 9) / 2

    meio = (9) / 2

    meio = 4,5

&nbsp;

Como a variável **meio** é do tipo inteiro, a posição que indica a metade do vetor é **4**, o valor contido no vetor na posição **meio** é **16**, que é maior do que o argumento pesquisado **5**.

    c) Como o valor não foi encontrado, o laço é repetido e a busca se dá entre as posições 0 a 3.

    meio = (menor + maior) / 2

    meio = (0 + 3) / 2

    meio = (3) / 2

    meio = 1,5

&nbsp;

Como a variável **meio** é do tipo inteira, a posição que indica a metade do vetor é **1**, o valor contido no vetor na posição **meio** é 7, que é maior do que o argumento pesquisado **5**.

    d) Como o valor não foi encontrado, o laço é repetido e a busca se dá na parte restante do vetor, que é a posição 0.

O vetor na posição **0** contém o valor procurado **5**, o algoritmo finaliza com sucesso recuperando a posição no vetor onde o argumento está armazenado.


<img src = "Imagens/Bina1.png">

&nbsp;

## **Busca por Interpolação**

&nbsp;

É outra forma de pesquisar entre vetores com dados ordenados, se o valores estiverem distribuídos de forma uniforme entre **vec[menor]** e **vec[maior]**, esse método pode ser ainda mais eficiente do que a ``Busca Binária``.

Sua implementação é muito parecida com a ``Busca Binária``, a variável **menor** é definida com **0** e a **maior** é definida com **tamanho - 1**, sabendo que os valores estão distribuídos de forma uniforme e tomando por verdade que em toda a execução do algoritmo o argumento **arg** estará contido entre os valore **vec[menor]** e **vec[maior]**, pode-se esperar que **arg** esteja aproximadamente na posição:

<img src = "Imagens/Inter1.png">

&nbsp;

A busca deve continuar até que o valor seja encontrado ou que **menor > maior**, se **arg** for menor que **vec[meio]**, o valor da variável **maior** será atualizada com **meio - 1**, fazendo com que a busca aconteça na parte inferior do vetor, caso contrário, a variável **menor** será atualizada com **meio + 1**, para que a busca prossiga na parte superior da estrutura.

````C
//Função de busca por interpolação
int buscaInterpol(int vec[], int arg, int tam){
    int menor, maior, meio, achou;
    menor = 0;
    maior = tam-1;
    achou = -1;
    while((menor <= maior) && (achou == -1)){
        meio = menor + (maior - menor) * ((arg - vec[menor]) /vec[maior] - vec[menor]);
        if (arg == vec[meio]){
            achou = meio;
        }
        if(arg < vec[meio]){
            maior = meio - 1;
        }
        else {
            menor = meio + 1;
        }
    }
    return(achou);
}
````

&nbsp;

A ``Busca por Interpolação`` pode ser mais rápida do que a ``Busca Binária`` se os valores no vetor estiverem distribuídos de forma uniforme, caso contrário, ela pode ser tão lenta como uma ``Busca Sequencial``.

&nbsp;

## **Tabela de Dispersão**

&nbsp;

Existe uma estrutura de dados pensada para eliminar a necessidade de realizar comparações durante as buscas por dados, existe uma maneira de realizar um cálculo que indica examente (ou quase) a posição do elemento chave dentro do arranjo de dados, sem realizar comparações. como se, a aprtir da chave de busca, fosse possível aferir o índice da posição no qual o elemento igual àquela chave se encontra em um vetor, por exemplo.

**Drozdek (2008)**, comenta que é preciso desenvolver uma função **h()** que processe uma chave particular **k** em um índice que possa ser utilizado para armazenar itens em um vetor que seja do mesmo tipo de **k** (int, float, char, etc).

Chama-se **h()**, a **função de dispersão**, **função de escrutínio**, ou **função hash**, em suma, a **função hash** deve ser capaz de converter um dado, ou um conjunto de dados, em um índice, que é a posição na qual tais dados serão armazenados **(DROZDEK, 2008)**.

Em outras ocasiões, uma **função hash** pode gerar um código utilizado em aplicações que envolvam criptografia.

Por exemplo, um vetor com dez posições, que vão de 0 a 9. Suponha que queiramos armazenar dados do tipo inteiro em nossa tabela de busca, assim, poderíamos pensar em uma **função h()** tal que, realizando cálculos matemáticos sob o elemento a ser armazenado (ou buscado), cheguemos a um valor inteiro que varie entre 0 e 9, assim como o índice do vetor.

A título de ilustração, consideraremos que a **função h()** recebe um parâmetro de entrada **x**, do tipo *int*, e retorna o cálculo da expressão "**(x * x) % 10**", ou seja, a **função hash** retorna o resto de divisão do quadrado do parâmetro de entrada, assim, para inserir o número 72 no vetor, devve realizar o cálculo "**72 x 72 % 10**", de acordo com a expressão de retorno da **função hash**, assim sendo, ao realizar a conta, iremos descobrir que **h(72)** é igual a **4**, por isso, o elemento 72 deve ser armazenado na posição 4 do vetor, matematicamente, pode-se dizer que **h(x) = x² mod 10**.

Abaixo a figura de como ficou o vetor após a inserção dos elementos 11, 23, 26 e 72, o vetor na porção direita funciona como uma tabela, na qual os dados são armazenados de acordo com o resultado do processamento de uma chave pela **função hash**, ``dados o nome a esse tipo de estrutura de dados de Tabela Hash, Tabela de Dispersão ou Tabela de Escrutínio``.

<img src = "Imagens/Disper1.png">

&nbsp;

Para melhor compreensão, tommemos o caso da inserção do elemento 23, durante o processamenteo, a **função h()** encontra o quadrado de 23 que é igual a 529, em seguida, a **função hash** divide 529 po 10, encontrando um quociente igual a 52 (para o caso, não nos interessa), e um resto de divisão igual a 9, sendo assim, o resultado da execução da **função h()**, passando o argumento 23, é 9, por isso, o elemento 23 se encontra armazenado na posição 9 da tabela, esse mesmo processo é repetido para todo elemento que é inserido.

Após os elemento terem sido inseridos no vetor, para realizar uma busca, basta utilizar a **função hash**, novamente, de maneira similar ao que foi feito no momento da inserção, ou seja, se quiser realizar uma busca pelo elemento 11, por exemplo, deve-se invocar a **função hash** para que, nesse caso, saiba-se que o elemento 11 se encontra na posição 1 da tabela.

Por outro lado, se tentar buscar um elemento ausente, como por exemplo, o 35, ao processar o elemento 35 de acordo com a **função hash**, irá descobrir que o 35 dveria estar armazenado na posição 5, todavia, conforme imagem abaixo, o 35 não se encontra armazenado nessa posição, assim o algortimo de busca conclui que o elemento está ausente. 

Na tabela abaixo, o elemento 88 não foi armazenado no vetor propositalmente, ao tentar inserir o elemento 88, verificaríamos que o resultado de **h(88)** é igual a 4, com isso teriamos de sobrescrever o dado que se encontra armazenado na posição 4, ``damos o nome de colisão a fatos como esse``. **Sempre que duas ou mais chaves, depois de processadas pela função hash, apresentam um resultado igual, temos uma colisão**.

Existem diversas técnicas para resolver colisões em tabelas hash, por exemplo, quando houver uma colisão, podemos decidir procurar pela próxima posição livre no vetor, para armazenar o dado conflitante, dessa forma, quando for fazer a busca, ao calcular o **hash** da chave, não nastaria apenas verificar a posição inficada pela **função hash**, mas também as posições subsequentes.

<img src = "Imagens/Disper2.png">

&nbsp;

Quando tentamos inserir 88 na posição 4 por meio da **função hash**, tevesse uma colisão, nesse instante, o algoritmo pode tentar procurar pela próxima posição livre dentro do arranjo, após a colisão, para armazenar o elemento em questão. dessa forma, ao tentar realizar a busca pelo elemento 88, a **função hash** retornaria à posição 4, ao verificar que a posição 4, notamos que quem se encontra lá é o 72, todavia, o algoritmo sabe que pode ter havido alguma colisão, por isso, a busca continua sequencialmente, verificando se existe algum elemento posterior ao 72 que seja igual ao 88, nesse caso, o 88 está armazenado exatamente na posição seguinte, encerrando a busca com sucesso, na posição 5, por outro lado, o algoritmo pode interromper a busca sequencial caso atinja alguma posição na qual não haja elemento armazenado.

Podemos considerar que os elementos em uma ``Tabela Hash`` podem ser removidos, além de inserido, por exemplo, se inserirmos o 88 na posição 5 para solucionar a colisão, o elemento 72 seria removido, após isso, ao tentar buscar pelo elemento 88, tentaremos acessa a posição 4 devido à **função hash** e iriamos perceber que é uma posição vazia, a busca não pode ser interrompida quando um elemento está ausente por causa de uma remoção, pois o elemento alvo pode ter sido inserido em um momento que ocasionava uma colisão, por isso, nesse tipo de solução de colisões, é interessante que todo o vetor possua **flags** que sinalizam se uma posição vazia é resultado de uma remoção ou não;

Outro método de solução de colisões consiste em combinar o caráter estático de vetores com o potencial de alocação dinâmico dos ponteiro, assim, caso haja uma colisão, pode-se "pendurar" mais elementos naquela posição do vetor de maneira dinâmica, ou seja, o vetor passa a ser uma tabela na qual cada posição do vetor pode dar origem a uma lista encadeada distinda,  abaixo imagem do problema da colisão do número 88 solucionada por meio de ponteiros:

<img src = "Imagens/Disper3.png">

&nbsp;

Antes de tudo, cada elemento deve ser um registro que contém ao menos um campo de "dados" e outro campo ponteiro para aponar para o próximo elemento (em caso de colisões), assim a ``Tabela Hash`` passa a ser um vetor de **struc** que pode ser flexível em seu tamanho, fazendo com que colisões resultem na criação de listas encadeadas.

