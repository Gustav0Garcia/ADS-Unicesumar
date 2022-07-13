# **Anotações Estrutura de Dados II - Unidade II**

&nbsp;

## **Caminhamento em Árvores Binárias**

&nbsp;

<img src = "">

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


continuar da pag 44...