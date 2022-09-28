# **Anotações Programação I - Unidade III**

&nbsp;

## **Entendendo um Array**

---

&nbsp;

**Deve pensar em um Array como um grupo de posições na memória, um imediatamente após o outro, que possuem o mesmo nome e o mesmo tipod e dado**.

Quando é preciso localizar algum elemento deste **Array**, é utilizado o nome declarado para o mesmo, assim como o número, ou índice, ou ainda, subscrito da posição que queremos acessar.

Abaixo, mostra uma imagem de um **Array** de 06 elementos, com números inteiros para o qual é dado o nome de **meuArray**. Para ser feita referência a uma posição específica deste **Array**, deve ser fornecido o nome do **Array** seguido pelo índice da posição entre colchetes ([ ]).

<img src = "Imagens/Array.png">

&nbsp;

**O primeiro elemento do Array possui o número de posição zero (meuArray [0]), as vezes chamado de zero-ézimo elemento, ou seja, não deve ser relacionado primeira posição de um Array com a posição 1**.

Para fixar melhor: o i-ésimo elemento do **Array** **meuArray** é **meuArray[ i - 1]**.

O Array **meuArray** possui 6 elementos, todos com valores, onde todos são do mesmo tipo, isso significa **que todos os Arrays em Java conhecem seu p´roprio tamanho, essa informação pode ser acessada por meio da variável *length*, e para recuperar o tamanho do Array meuArray, deve-se usar a expressão meuArray.length**

&nbsp;

## **Declarando Arrays de Objetos e de Tipos Primitivos**

---

&nbsp;

Os **Arrays** em Java são declarados mediante a descrição do tipo de dado armazenado seguido de colchetes à direita ou à esquerda do identificador.

``Abaixo declarações válidas e inválidas de Arrays de tipo primitivo``:

~~~~Java
long[] id; //Neste exemplo os colchetes foram definidos antes do nome (válido e recomendado)

int sequencia[]; //Neste exemplo os colchetes foram definidos depois do nome (válido, mas menos legível)

[] double valor; //Neste exemplo os colchetes foram definidos no início da declaração do Array (inválido)
~~~~

&nbsp;

``Abaixo declarações válidas e inválidas de Arrays de referências a objetos``:

~~~~Java
String[] nomes; //Neste exemplo os colchetes foram definidos antes do nome (válido e recomendado)

Thread threads[]; //Neste exemplo os colchetes foram definidos depois do nome (válido, mas menos legível)

[] Thread threads; //Neste exemplo os conchetes foram definidos no início da declaração do array (inválido)
~~~~

&nbsp;

Foram vistos apenas declarações de **Arrays Unidimensionais**, mas pode-se ser criado **Arrays Multidimensionais**, ``que é um Arrays com outros Arrays armazenados``.

~~~~Java
String[][][] ocupantePoltronas; //Válido e recomendado

String[] aniversariantesMes[]; //Deselegante, porém válido

[][] String cardapioSemana; //Inválido
~~~~

&nbsp;

O primeiro exemplo trata-se de um Array com três dimensões (**Tridimensionar - um Arrays com outros Arrays também armazenando Arrays**), já o segundo, é um Arrays com duas dimensões (**Bidimensional**).

&nbsp;

## **Construindo Arrays Unidimensionais**

---

&nbsp;

Para que seja possível trabalhar com Arrays, é preciso criar um objeto de Array e a manseira mais simples para isso, é por meio do operador **new**, todo e qualquer Array se trata de um objeto que ocupa espaço na memória e para o compilador saber quanto espaço alocar, é preciso especificar o tamanho do Array na hora da sua construção.

~~~~Java
//Declarando e construindo o array com apenas uma instrução
int[] meuArray = new int[6];

//Executando a declaração e construção em etapas separadas
int[] meuArray;
meuArray = new int[6];
~~~~

&nbsp;

Quando o compilador executar a instrução **new int[6]**, será criado um novo objeto na memória contendo 6 elementos, com um tipo **int** de valor **default** igual a 0.

``Todo e qualquer Arrays alocado na memória possui um valor default para cada elemento do Arary de acordo com o tipo do elemento. Para variáveis numéricas do tipo primitivo, será atribuído o valor 0, alse para variáveis boolen ou null para qualquer tipo não primitivo``.

<img src = "Imagens/Array2.png">

&nbsp;

## **Construindo Arrays Multidimensionais**

---

&nbsp;

Um Array multidimensional consistem em um Array onde cada elemento possui outro Array armazenado, o tipo mais comum de Array multidimensional é o Array bidimensional que consiste em dois sobscritos.

São utilizados frequentemente para representar tabelas de valores que consistem em informações organizadas em linhas e colunas, para ident9ificar um elemento específico da tabela, deve-se utilizar os dois subscritos, no qual o primeiro representa uma linha do elemento e o segundo representa a coluna.

Portanto, um Array bidimencional do tipo **int** é um objeto com o tipo de Array **int** (**int[]**), onde cada elemento fará referência a outro Array do tipo **int**.

~~~~Java
int[][] a = new int[3][4];
~~~~

<img src = "Imagens/Array3.png">

&nbsp;

<img src = "Imagens/Array4.png">

&nbsp;

É possível também, definir para cada linha um número de colunas diferentes:

~~~~Java
int[][] a;

a = new int[2][]; //Aloca linhas

a[0] = new int[5]; //Aloca 5 colunas para a linha 0

a[1] = new int[3]; //Aloca 3 colunas para a linha 1
~~~~

<img src = "Imagens/Array5.png">

&nbsp;

## **Inicializando Arrays**

---

&nbsp;

``É importante ressaltar, quando é dito que um Array foi inicializado com um objeto, não significa que o objeto propriamente dito está armazenado em um determinado elemento do Array, e sim a referência deste objeto na memmória``.

**Quandp é construído um Array de referência a objetos, por padrão, o valor de cada elemento deste Array é null, portanto, se o Array não for inicializado adequadamente e tentar acessar a referência null aplicando o operador ponto, irá receber a exceção *java.lang.NullPointerException***.

Será criado um Array com 4 carros:

~~~~Java
Carro[] carros = new Carro[4];
~~~~

&nbsp;

Acima, quando o programa for executado, será criado na memória um Array com nome carros contendo 4 referências a objetos do tipo **Carro**. O Array ainda não foi inicializado, não havendo nenhum objeto **Carro** criado, portanto, essas referências são **null**

~~~~Java
carros[0] = new Carro();
carros[1] = new Carro();
carros[2] = new Carro();
carros[3] = new Carro();
~~~~

&nbsp;

A partir desse momento existem 45 objetos do **tipo Carro** criados, onde a referência de cada objeto na memória foi armazenado em um elemento do **Array carros**.

Para inicializar os elementos foram utilizados os índices de cada elemento, desta maneira, consegue-se acessar elementos específicos e armazenar a referência de cada novo **objeto Carro**.

Agora, se tentar armazenar um novo **objeto Carro** ao elemento [4] do **Array carros**, a partir do momento que foi usado o operador **new** para construir um Array, esse Array passa a conhecer o seu tamanho, portanto, se tentar acessar um elemento com um índice que não existe, será lançado em tempo de execução a exceção **java.lang.ArrayIndexOutOfBoundsException**, a mesma exceção será lançada ao tentar utilizar um índice com número negativo, exemplo: -1

~~~~Java
int[] y = new int[3];

y[2] = 7; //Correto, o último elemento está no índice 2

y[3] = 4; //Errado, será gerado uma exceçao em tempo de execução. Não há nenhum elemento no índice 3.(Apenas constam o y 0, 1 e 2)

int[] w = new int[7];
int k = -1;
w[k] = 3; //Exceção, pois k é um número negativo.
~~~~

&nbsp;

Para declarar, construir e inicializar um Array em apenas uma linha:

~~~~Java
long x = 2;
long[] id;
id = new long[3];
id[0] = 1;
id[1] = x;
id[2] = 3;
~~~~

Agora o código abaixo:

~~~~Java
long x = 2;
long[] id = {1,x,3};
~~~~

&nbsp;

SOs dois códigos são equivalentemente funcionais, no entanto, o segundo é mais curto. Analisando a segunda linha do código acima, pode-se notar quatro operações:

* Declarado uma variável de referência ao **Array de long** chamado id.

* Criado um **Array de long** com tamanho igual a três, ou seja, três elementos.

* Atribuído a estes elementos os valores 1, 2 e 3;

* Atribuído um novo **objeto de Array** à variável de referência id.

&nbsp;

Da mesma maneira que pode inicialiar em apenas uma linha um **Array de tipos primitivos**, também pode fazer referência a objetos, como mostra abaixo:

~~~~Java
Carro fiat = new Carro("fiat");

Carro[] carros = {fiat, new Carro("audi"), new Carro("chevrolet"), new Carro("ford")};
~~~~

&nbsp;

A inicialização do **Array Carro** referenciada pela **variável carros** é muito semelhante ao exemplo dado anteriormente com tipos primitivos, note também, que este Array possui um tamanho de 4 elementos, onde ao primeiro elemento foi atribuído uma referência para o **objeto fiat** do **tipo Carro** criado anteriormente.

Foram criados também, 4 novos **objetos do tipo Carro** (**audi**, **chevrolet** e **ford**) atribuindo, respectivamente, a referência destes objetos aos 3 últimos elementos.

Abaixo exemplo utilizando o lenght para recuperar o tamanho de um Array.

~~~~Java
Carro[] carros = new Carro[6]; //Cria um Array de 6 referências a Carro

for (int i = 0; i < carros.length; i++) {
    carros[i] = new Carro(); //Atribui um novo elemento Carro a posiçao de índice i
}
~~~~

&nbsp;

## **Passando Arrays para Métodos**

---

&nbsp;

``Java difere das outras linguagens, quando é preciso passar argumentos po valor ou referência, o Java não permite que escolha entre passar cada argumento por valor ou referência. Quando é trabalhado com variáveis de tipos primitivos, estas sempre serão passadas por valor. Quando é pbjeto, estes não são passados para o método e sim a referência desse objeto``.

``Nesse caso, a referência é passada por valor, ou seja, é feita uma cópia da referência do objeto e passado esta cópia para o método chamado, permitindo assim, por meio da referência, acessar o objeto e manipulá-lo se necessário``.

``No caso de retornar informações de um método mediante a instrução return, a regra é praticamente a mesma, Variáveis do tipo de dado primitivo são retornadas por valor, ou seja, devolvida uma cópia cujos objetos são retornados por referência``.

**Arrays** em Java são tratados como objetos, sendo assim, os **Arrays** também são passados para os métodos como referência, significando que pode manipular elementos dos **Arrays** originais do **chamador**. Para isso, basta passar para o método chamado o nome do **Array** sem colchetes, que na verdade é uma referência para um objeto que contém os elementos do **Array**.

~~~~Java
int[] temperaturaHora = new int[24];
modificadorArrays(temperaturaHora);
~~~~

&nbsp;

O método **modificarArray** recebe como argumento a variável **temperaturaHora**, sem colchetes, que contém uma referência para um **Array** de int de 24 elementos, para que isso seja possível, o método que recebe o **Array** deve contem em sua lista de argumentos um argumento que seja um **Array** ou vários, se mais de um **Array** for recebido pelo método.

~~~~Java
void modificadorArray(int[] a)
~~~~

&nbsp;

No código acima, pode perceber que o método **modificarArray** espera receber no argumento **a** um **Array** do tipo int, nesse caso, quando o método chamado utilizar o **Array a**, na verdade ele estará se referindo ao **Array real** no chamador que é **temperaturaHora**.

&nbsp;

## **Exemplos com Arrays**

---

&nbsp;

Será criado uma classe que declara e aloca um **Array** de 10 elementos na memória, em seguida, irá recuperar o valor contido nos elementos desse **Array** e imprimir em uma janela o índice e o valor respectivo.

~~~~Java
importa javax.swing.*;

public class Exemplo1{

    public static void main(String[] args){
        int[] array; //Declara referência para um array
        array = new int[10]; //Cria um array com 10 elementos
        Strin saida = "Índice\tValor\n";

        ///Adicionando o valor de cada elemento do Array na variável saida
        for(int i = 0; i < array.length; i++){
            saida += i + "\t" + array[i] + "\n";
        }

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.ShowMessageDialog(null, saidaArea, "Criando um Array de inteiros", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }
}
~~~~

&nbsp;

Foi declarado a variável **array** capaz de referir-se a uma **Array** de elementos **int**, depois foi utilizado o perador **new** para construir o **Array** e alocar os 10 elementos na memória.

Foi declarado uma variável do tipo **String** chamada **saida**, na qual é responsável por armazenar os índices e os valores dos elementos para, posteriormente, serem exibidos em um diálogo de mensagem.

A estrutura **for** foi utilizada para adicionar o índice e o valor de cada elemento do **Array saida**, o uso da contagem na variável **i** se inicia com o, desse modo, o laço irá acessar cada elemento do **Array** iniciando por 0.

O uso do **array.length** para recuperar o comprimento do **Array**.

Para o segundo exemplo, é semelhante ao anterior, mas a diferença é que agora será inicializado os elementos do **Array**, apresentar o **Array** incializado e, em seguida, somar os elementos deste **Array** e será apresentado essa soma em um diálogo de mensagem.

~~~~Java
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo2{

    public static void main(String[] args){
        //Cria um Array com 6 elementos
        int[] array = {10, 15, 25, 3, 8, 7};
        int total = 0;
        String saida = "Índice\tValor\n";

        //Adicionando o valor de cada elemento do Array na variável saida
        for(int i = 0; i < array.length; i++){
            total += array[i];
            saida += i + "\t" + array[i] + "\n";
        }
        saida += "\n\nA soma dos elementos do array é: " + total;
        
        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Criando um Array de Inteiros", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }
}
~~~~

&nbsp;

A diferença para o exemplo anterior, é qe foi declarada a variável **array** que faz referência a um **Array** do tipo **int**, com os valores (10, 15, 25, 3, 8, 7), quando o programa executar, automaticamente um **Array** com 6 elementos será alocado na memória e já inicializado.

Foi declarada uma variável **total** do tipo **int**, para poder armazenar a soma dos valores dos elementos do **Array**, e a qual, posteriormente a soma será feita com base no valor do elemento.

O laço **for** foi utilizado para recuperar o valor do **Array** por meio da expressão **array[i]**.

Por fim, é atribuído à variável **saida** um texto apresentando o total da soma.

&nbsp;

Agora um exemplo utilizando **Arrays multidimensionais** e passagem de **Array** por referência, será demonstrado a inicialização de dois **Arrays** bidimencionais e o uso de laços de repetição aninhados **for** para percorrer os **Arrays**.

~~~~Java
import java.awt.Container;
import javax.swing.JApplet;
import javax.swing.JTextArea;

public class Exemplo3 extends JApplet{
    JTextArea saida Area;

    @Override
    public void init(){
        super.init();

        saidaArea = new JTextArea();
        Container container = getContestPane();
        container.add(saidaArea);

        int[][] array1 = {{1,2,3}, {4,5,6}};
        int[][] array2 = {{1,2}, {3}, {4,5,6}};

        saidaArea.setText("Os valores do array1 são\n");
        buildSaida(array1);

        saidaArea.apprend("Os valores do array2 são\n");
        buildSaida(array2);
    }

    public void buildSaida(int[][] array){
        //Percorre as linhas do array com um for
        for(int linha = 0; linha < array.length; linha++){
            //Percorre as colunas da linha corrente com outro for
            for(int coluna = 0; coluna < array[linha].length; coluna++){
                saidaArea.apprend(array[linha][coluna] + " ");
            }
            saidaArea.append("\n");
        }
        saidaArea.append("\n");
    }
}
~~~~

&nbsp;

O primeiro **Array** é referenciado pela varável **array1**, criado com seis elementos em duas subllistas, se trata de um **Array** com duas linhas e 3 colunas em que a primeira sublista é inicializada com os valor (1, 2, 3) e a segunda sublista com os valores (4, 5, 6).

O segundo **Array** é referenciado pela variável **array2**, também fornece seis elementos, porém, inicializados em 3 sublistas com os valor (1, 2), (3) e (4, 5, 6).

O método **buildSaida**, é responsável por percorrer os elementos do **Array** passado como parâmetro para e apresentar em um diálogo de mensagem os valores de cada elemento.

No exemplo foi passado na primeira chamada do método **buildSaida** a variável **array1** e **array2** na segunda, desta maneira, o método tem a capacidade de percorrer os elementos dos dois **Arrays** e apresentar no diálogo de mensagem os valores de cada elemento do **Array**.

O uso dos laços **for** para percorrer o **Array** bidimensional, no laço externo **for**, foi utilizdo a expressão **array.length** para determinar o número de linhas do **Array**. Para determinar o número de colunas do **Array**, foi utilizado a expressão **array[linha].length** para determinas o número de colunas na linha corrente do **Array**, permitindo, assim, determinar o número exato de colunas em cada linha.

&nbsp;

## **Visão Geral das Coleções**

---

&nbsp;

Pag 92...