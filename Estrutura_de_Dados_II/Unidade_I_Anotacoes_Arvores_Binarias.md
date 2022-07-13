# **Anotações Estrutura de Dados II - Unidade I**

&nbsp;

## **Árvore Binária**

&nbsp;

Segundo Tenenbaum (1995, p. 303), ``Uma árvore binária é um conjunto finito de elementos que estão vazio ou é partcionado em três suconjuntos disjuntos. O primeiro subconjunto contém um único elemento, chamado raiz da árvore. Os outros dois subconjuntos são em si mesmos árvores binárias, chamadas subárvores esquerda e direita da árvore original. UMa subárvore esquerda ou direita pode estar vazia. Cada elemento de uma árvore binária é chamado nó da árvore``.

A figura abaixo representa uma árvore, possuindo 9 nós, sendo **A** o ``nó raiz da árvore``, sendo uma subárvore esquerda com raiz em **B** e uma direita com raiz em **C**. A subárvore com raiz em **B** possui uma subárvore esquerda com raiz em **D**, e a direita com raiz em **E**. A subárvore com raiz em **C** possui uma subárvore esquerda ``vazia`` e uma subárvore direita com raiz em **F**. As árvores binárias com raiz em **D**, **G**, **H** e **I** possuem subárvore direita e esquerda ``vazias``.

<img src = "Imagens/Arvore.png">

Se **A** é o nó raiz de uma árvore binária e tem uma subárvore com raiz em **B**, então se diz que **A** é ``pai`` de **B** e **B** é ``filho`` esquerda de **A**.
Um nó sem filhos é chamado de ``folha``. 
Os nós **D** e **E** são ambos filhos de **B**, dessa forma podemos considerá-los como nós ``irmãos``. 
Também podemos classificar os nós de acordo com a sua ``hereditariedade``. O nó **B** é ``ancestral`` dos nós **D**, **E** e **G**, da mesma forma que esses três nós são ``descendentes`` de **B**.

**Quando se percorre uma árvore a partir da raiz em direção às folhas, diz-se que se está caminhando para baixo, ou descendo na árvore**. De forma análoga, **quando se está percorrendo uma árvore a partir de uma de suas folhas em direção à raiz diz-se que se está caminhando para cima, ou subindo na árvore.**

&nbsp;

## **Árvore Estritamente Binária**

&nbsp;

``Uma árvore é considerada estritamente binária se todo nó que não for folha tiver sempre subárvores direita e esquerda não vazias.``

**A quantidade de nós presentes numa árvore estritamente binária se dá pela fórmula n = (2xf ) −1** em que f é o número de folhas na árvore.

&nbsp;

## **Árvore Binária Completa**

&nbsp;

O nó **raiz** de uma árvore binária é considerado como de nível ``0``. A partir dele, cada no possui um nível a mais do que o seu **pai**.

<img src = "Imagens/Arvore2.png">

Por exemplo, na árvore binária acima, o nó **C** está no ``nível 1``, **F** está no ``nível 2`` e o nó **M**, no ``nível 3``. 

**A profundidade ou altura de uma árvore binária é dada pelo maior nível de qualquer folha na árvore**. ``Isso equivale ao tamanho do percurso mais distante da raiz até uma folha qualquer``. Dessa forma, a profundidade da árvore da árvore acima é ``3``. **Quando uma árvore estritamente binária possui todas as folhas no último nível, ela é chamada de árvore binária completa**. A árvore acima demonstra uma árvore binária completa de profundidade 3.

&nbsp;

## **Implementando Árvore Binária em C**

&nbsp;

A forma mais simples de implementar uma árvore binária, é utilizando um ``vetor`` de **nós**

Cada nó possui pelo menos três valores: **pai**, **esquerda** e **direita**.

O atributo **pai** vai apontar para a posição da raiz da subárvore **esquerda**, e o atributo **direita** guarda a posição da raiz da subárvore **direita**.

Iremos adiiconar mais um atributo, **dado**, que irá armazenar o valor do **nó**.

&nbsp;

````c
//Estrutura
	struct str_no {
	char dado;
	int esquerda;
	int direita;
	int pai;
};
````

&nbsp;


Iremos criar a variável do tipo **vetor** de **str_no**, esse vetor terá tamanho definido por uma constante chamada **tamanho**, será preciso também uma variável do tipo **inteiro** que servirá de índice para o nosso vetor.

&nbsp;


````c
//Constantes
#define tamanho 100

//Variáveis
struct str_no arvore[tamanho];
int indice = 0;
````

&nbsp;

Para inserir um **nó** na árvore, precisamos saber o seu valor, quem é o seu **pai** e se ele é um filho **esquerda** ou **direita**. Mesmo sabendo quem é o pai, antes de fazer a inserção no vetor, precisamos encontrar a sua localização. Iremos criar uma função chamada **arvore_procura**, que retorna um valor **inteiro** (posição no vetor) e tem como parâmetro o nome do **pai**.

&nbsp;

````c
//Procura nó
	int arvore_procura(char dado){
	if (indice != 0){
		for (int i = 0; i<indice; i++){
			if (arvore[i].dado == dado) {
				return (i);
			}
		}
	}
	else {
		return (0);
	}
}
````

&nbsp;

O código acima irá fazer uma verificação no valor da variável **indice**. ``Se o valor for 0, significa que a árvore está vazia e o valor a ser inserido será a raiz da árvore``.

A função leva em conta que o **pai** está presente na árvore, já posto que não foi previsto nenhum tipo de retorno de erro para o caso do **pai** não ser encontrado.

Fizemos a leitura do valor a ser inserido e sabemos quem e o seu pai e qual a sua descendência. Por meio da função acima, passamos o valor do pai como parâmetro e obtivemos como retorno a sua posição no vetor, agora estamos prontos para a inserção do novo nó na árvore;

Iremos criar a função nova, chamada **arvore_insere**, ela terá como parâmetro um valor inteiro que representa a posição do **pai** no vetor, o valor **dado** digitado pelo usuário e a sua posição de descendência (se é filho do **lado** esquerdo ou direito).

&nbsp;

````c
//Inserir nó
void arvore_insere(int pai, char dado, int lado){
	switch (lado){
		case E:
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
		case D:
			arvore[pai].direita = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
	}
}
````

&nbsp;

Anteriormente criamos uma variável chamada **indice**, que giarda a primeira posição livre da **arvore**. O parâmetro **pai** recebido na função infica qual a posição do nó pai. Se o novo nó for filho esquerdo, atribuiremos o valor de **indice** ao atributo **esquerdo** na **arvore**, na posição **pai**.
O próximo passo é guardar o nome do nó no atributo **dado** e a referência do **pai**. ``Vamos marcar com -1 o valores de esquerda e direita para identificar que ambos os ponteiros não apontam para uma subárvore``.

O código abaixo traz uma implementação completa de uma Árvore Binária em linguagem C:

&nbsp;

````c
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define tamanho 100
#define E 0
#define D 1
#define R -1

//Estrutura
struct str_no {
	char dado;
	int esquerda;
	int direita;
	int pai;
};

//Variáveis
struct str_no arvore[tamanho];
int lado,indice=0;
int opt=-1;
char pai, no;

//Prototipação
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
void menu_mostrar(void);

//Função principal
int main(void){
	int temp;
	do {
		menu_mostrar();
		scanf("%d", &opt);
		switch (opt){
			case 1:
				printf("\nDigite o valor do PAI: ");
				scanf("%c",&pai);
				scanf("%c",&pai);
				printf("Digite o valor do NO: ");
				scanf("%c",&no);
				scanf("%c",&no);
				printf("Digite o lado da subarvore (E=%d/D=%d R=%d): ", E,D,R);
				scanf("%d",&lado);
				temp = arvore_procura(pai);
				arvore_insere(temp,no,lado);
			break;
			case 2:
				printf("Digite o valor do NO: ");
				scanf("%c",&no);
				scanf("%c",&no);
				temp = arvore_procura(no);
				printf("No %c\nFilho Esquerda: %c \nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].esquerda].dado, arvore[arvore[temp].direita].dado);
				system("pause");
			break;
		}
	}while (opt!=0);
	system("pause");
	return(0);
}

//Inserir nó
void arvore_insere(int pai, char dado, int lado){
	switch (lado){
		case E:
			arvore[pai].esquerda = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
		case D:
			arvore[pai].direita = indice;
			arvore[indice].dado = dado;
			arvore[indice].pai = pai;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
		case R:
			arvore[indice].dado = dado;
			arvore[indice].pai = -1;
			arvore[indice].esquerda = -1;
			arvore[indice].direita = -1;
			indice++;
		break;
	}
}

//Procura nó
int arvore_procura(char dado){
	if (indice != 0){
		for (int i = 0; i<indice; i++){
			if (arvore[i].dado == dado) {
				return (i);
			}
		}
	}
	else {
		return (0);
	}
}

//Desenha o menu na tela
void menu_mostrar(void){
	system("cls");
	for (int i = 0; i < indice; i++){
		printf("| %c ",arvore[i].dado);
	}
	printf("\n1 - Inserir um NO na arvore");
	printf("\n2 - Pesquisar um NO na arvore");
	printf("\n0 - Sair...\n\n");
}
		
````

&nbsp;

Acabamos de ver uma forma de armazenar uma árvore binária em um vetor. Essa implementação é bem simples e rápida, mas longe do ideal.

&nbsp;

## **Árvore Binária Diferente**

&nbsp;

Uma outra forma de armazenar uma árvore binária em um vetor é reservar as posições de acordo com o nível e descendência de cada nó. O primeiro nó a ser armazenado é a raiz da árvore e ele ficará na primeira posição do vetor, ``lembrando que os vetores em C começan na posição 0``.

Se a árvore não for binária completa, existirão vários espaços vazios no vetor, lembrando uma memória fragmentada. Por outro lado, estaremos ocupando exatamente a mesma quantidade de memória que a implementação anterior.

A principal diferença é que nesse modelo os nós da árvore estarão indexados, assim é possível obter as informações de forma rápida e precisa, utilizando-se do índice ao invés de percorrer toda a estrutura.

&nbsp;

Uma árvore binária também pode ser criada dinamicamente, basta um ponteiro **esquerdo** e **direito** que apontará para os filhos e um ponteiro para o  **pai**.
