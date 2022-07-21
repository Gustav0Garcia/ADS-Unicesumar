# **Anotações Estrutura de Dados II - Unidade II**

&nbsp;

## **Caminhamento em Árvores Binárias**

&nbsp;

Dependendo dos requisitos de uma aplicação, pode ser preciso percorrer todos os elementos de uma árvore para, por exemplo, exibir todo o seu conteúdo ao usuário. 

&nbsp;

## **Percurso Pré-Ordem**

&nbsp;

Também conhecido por ``caminhamento pré-fixado``, **marca primeiramente a raiz como visitada, e só depois visitamos as subárvores esquerda e direita, respectivamente**.

Abaixo um código-fonte no qual a função **preOrdem()** implementa a lógica semântica necessária para fazer com que, a partir do parâmetro raiz, o programa realize o respectivo caminhamento em uma árvore binária

&nbsp;


````c
void preOrdem(struct NO* raiz){
	if(raiz){
		printf("%d \t", raiz->dado); //visita o nó atual
		preOrdem(raiz->esq);
		preOrdem(raiz->dir);
	}
}
````

Considerando a figura abaixo, a ordem de visitação produzida pela função **preOrdem()**, levando em conta o nó inicial **F**, segia a seguinte: **F**, **B**, **A**, **D**, **C**, **E**, **G**, **I**, **H**.

&nbsp;

<img src = "Imagens/PreOrdem.png">

&nbsp;

## **Percurso Em-Ordem**

&nbsp;

Também conhecido por ``caminhamento interfixado``, **primeiramente visitamos toda a subárvore esquerda e, só então, a raiz é marcada como visitada. Em seguida, o método Em-Ordem faz a visitação de toda a subárvore direita**.

Abaixo um código-fonte no qual a função **emOrdem()** implementa a lógica para fazer com que, a partir da raiz, o programa execute o caminhamento Em-Ordem em uma árvore binária.

&nbsp;

````c
void emOrdem(NO* raiz){
	if(raiz){
		emOrdem(raiz->esq);
		printf("%d \t", raiz->dado); //visita o nó atual
		emOrdem(raiz->dir);
	}
}
````

Considerando a figura abaixo, a ordem de visitação produzida pela função **emOrdem()**, levando em conta o nó inicial **F**, segia a seguinte: **A**, **B**, **C**, **D**, **E**, **F**, **G**, **H**, **I**.

&nbsp;

<img src = "Imagens/PreOrdem.png">

&nbsp;

## **Percurso Pós-Ordem**

&nbsp;

Também conhecido por ``caminhamento pós-fixado, **nesse caso, primeiramente visitamos toda a subárvore esquerda, depois, toda a subárvore direita. Só após ter vistiado as duas subárvores, é que marcamos o nó corrente como visitado**.

Abaixo um código-fonte no qual a função **posOrdem()** implementa a lógica para fazer com que, a partir da raiz, o programa execute o caminhamento Pós-Ordem em uma árvore binária.

&nbsp;

````c
void posOrdem(NO* raiz){
	if(raiz){
		posOrdem(raiz->esq);
		posOrdem(raiz->dir);
		printf("%d \t", raiz->dado); //visita o nó atual
	}
}
````

Considerando a figura abaixo, a ordem de visitação produzida pela função **posOrdem()**, levando em conta o nó inicial **F**, segia a seguinte: **A**, **C**, **E**, **D**, **B**, **H**, **I**, **G**, **F**.

&nbsp;

<img src = "Imagens/PreOrdem.png">

&nbsp;

## **Busca em Árvores Binárias**

&nbsp;

A partir de um vetor vamos construir uma árvore binária com regras específicas para que ela se torne uma árvore binária de busca.

Uma árvore binária ou é vazia ou tem pelo menos um nó **raiz**. Todo nó tem um **pai** (menos a raiz) e no máximo foi filhos, um **esquerdo** e um **direito**. Tanto o filho esquerdo como direto podem ser **subárvores** vazias.

Iremos adiiconar uma nova regra para a construção da árvore, o nó raiz será o valor que estiver na posição do meio de um vetor (ordenado ou não), ``ao adicionar um novo nó na árvore, verificamos se ele é menor do que a raiz, caso seja verdade, ele será adicionado na subárvore esquerda, caso contrário, na subárvore direita``

A posição central do vetor é encontrada pela fóruma

&nbsp;

meio = (menor + maior) / 2

&nbsp;

Dado um argumento qualquer, se ele for menor que a **raiz**, ou ele não existe, ou ele se encontra na sua subárvore **esquerda**, se o valor for maior que a **raiz**, ou ele não existe ou está na sua subárvore **direita**. A partir da **raiz** vamos descendo pela árvore binária de busca até que o valor seja encontrado ou que encontremos uma **folha** ou uma **subárvore vazia**.

``A árvore binária de busca pode ser implementada dinamicamente na memória, pois não precisa descobrir onde fica a metade da tabela, ao invés de dividir o vetor pela metade, é ignorado uma das subárvores para continuar a pesquisa. Esse método é muito rápido e eficiente em arquivos com grandes quantidades e registros.``

Abaixo demonstra um algoritmo em linguagem C, que encontra um valor por meio de uma árvore binária de busca em um vetor de dados, a função **buscaArvoreBinaria()** recebe três parâmetros:  vetor **vec** a ser pesquisado, o argumento **arg** a ser encontrado e o tamanho **tam** do vetor.

O laço principal tem duas regras de parada, o laço continua até o valor ser encontrado, que se dá no momento em que a variável **achou** for diferente de **-1** ou quando chegar ao final do vetor. 

Simplificando, estamos utilizando um vetor que guarda os nós de forma ordenada de acordo com o nível de cada nó, assim, a busca começa na raiz e segue para **2 x p + 1** na direção da árvore esquerda ou **2 x p + 2** na árvore direita, onde **p** é a posição do nó no vetor.

&nbsp;

````c
//Função de árvore binária de busca
	int buscaArvoreBinaria(int vec[], int arg, int tam){
	int no, achou, fim;
	fim = 0;
	no = 0;
	achou = -1;
	while((achou == -1) && (fim <= tam)){
		if (arg == vec[no]){
			achou = no;
		}
		if (arg < vec[no]){
			no = (2 * no) + 1;
		}
		else {
			no = (2 * no) + 2;
		}
		fim++;
	}
	return(achou);
}
````

&nbsp;

## **Árvores AVL**

&nbsp;

Se inserirmos dados, do primeiro até o último, em uma árvore de busca binária, teremos uma árvore estruturada da seguinte fgorma:

<img src = "Imagens/ArvDesbalanc.png">

A estrutura de dados se assemelha muito mais a uma lista linear encadeada do que uma árvore binária. Em consequência, operações de busca nessa estrutura de dados serão feitas de maneira sequencial, ao invés de aproveirarem-se da capacidade de ignorar subárvores, cortando caminho na busca, com isso, dizemos que a árvore encontra-se **desbalanceada**.

&nbsp;

Surge o conceito de **balanceamento**, uma árvore **balanceada** tende a manter sua altura tão pequena quanto possível, à medida em que são realizadas novas inserções ou remoções de dados, árvore binária de busca balanceada seria algo como a de baixo:

<img src = "Imagens/ArvBalanc.png">

&nbsp;

O concento de balanceamento está relacionado à altura das subárvores que compõem uma árvore binária, é ``importante lembrar que a altura (ou profundidade) de uma subárvore é igual ao número de nós visitados desde a raiz até o nó folha mais ditante (uma subárvore vazia possui altura -1, por definição)``.

**Dizemos que um nó está balanceado caso o valor absoluto da diferença entre as alturas das subárvores esquerda e direita seja menor ou igual a 1**. Chamaremos de fator de balanceamento (**Fb**)o resultado da diferença entre a altura da subárvore esquerda (**He**) de um nó pela altura da subárvore direita (**Hd**) do mesmo nó, de acordo com a seguinte fórmula:

Fb = He - Hd

&nbsp;

``Para resolver o problema do desbalanceamento de árvores binárias de busca``, os pesquisadores **Adelson-Velskii** e **Landis**, em 1962, **criaram um algoritmo que leva as iniciais de seus nomes**. ``As árvores AVL são, nesse sentido, árvores nas quais todos os nós encontram-se balanceados. Para cada nó, a diferença entre as alturas de suas subárvores não pode ser igual ou superior a 2, em valor absoluto``.

**Como vimos, uma árvore balanceada pode perder essa característica quando um novo elemento é inserido**. Isso também pode ocorrer quando um elemento é removido da árvore binária. Assim, quando ocorrem operações de inserção ou remoção em árvores AVL, recalcula-se os fatores de balanceamento de cada nó para, assim, poder executar rotações nos nós problemáticos, na tentativa de restabelecer seu balanceamento. ``Existem, basicamente, quatro tipos de rotações: dois tipos de rotações simples e dois tipos de rotações duplas``.

``De acordo com Adam Drozdek (2008), quando uma árvore AVL se desbalanceia inserindo-se um nó na subárvore que se encontra à direita do filho direito, é necessário realizar uma rotação simples para esquerda e o mesmo vale para o caso oposto, quando inserindo-se um nó na subárvore que se encontra à esquerda do filho esquerdo, é necessário realizar uma rotação simples para direita``. Simetricamente, se inserimos um nó na subárvore esquerda do filho esquerdo, é preciso realizar uma rotação simples no sentido oposto ao anterior.

**Para casos em que a rotação simples não funciona, devemos utilizar a rotação dupla, sendo elas rotação dupla direita-esquerda e rotação dupla esquerda-direita.**

&nbsp;

``Em suma, são quatro situações nas quais precisamos balancear nossa árvore AVL, a saber: duas rotações simples e duas rotações duplas. Podemos resumir as quatro situações que exigem as respectivas rotações como o descrito a seguir.``


1. Inserção na subárvore direita do filho à direita: solução com rotação simples à esquerda.


2. Inserção na subárvore esquerda do filho à esquerda: solução com rotação simples à direita.


3. Inserção na subárvore esquerda do filho à direita: solução com rotação dupla direita-esquerda.


4. Inserção na subárvore direita do filho à esquerda: solução com rotação dupla esquerda-direita.

&nbsp;

**Uma árvore AVL é uma árvore binária de busca na qual o fator de balanceamento de cada um de seus nós não pode ser maior que 1 ou menor que -1. Caso o fator de balanceamento de um ou mais nós seja maior ou igual a 2, em valores absolutos, é preciso analisar a ordem das inserções para aplicar a rotação mais adequada para corrigir o balanceamento de cada um dos nós**. Isso faz com que buscas em uma árvore AVL sejam mais eficientes.