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

Continuar da pág. 125....