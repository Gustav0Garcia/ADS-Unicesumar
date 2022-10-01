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

Quando é trabalhado com estruturas de **Coleções**, o desenvolvedor não precisa se preocupar como estas estruturas foram criadas e sim qual a **Coleção** que ela irá utilizar e em que determinada situação se encontra isso, graças às **interfaces** que a estrutura de **coleções** fornece.

As **interfaces** definem várias operações a serem realizadas genericamente sobre vários tipos de **Coleções** minimizando a quantidade de código que um programador precisa escrever para criar e manipular **Coleções**.

``O conjunto de interfaces e classes de coleções contidos na API Java constitui o chamado Framework Collections que tem por raíz duas intefaces básicas: Collection, utilizada para manipular coleções onde os elementos são objetos individuais, e Map, onde se mapeia uma chave única para um valor específico, por meio de uma estrutura de pares de objetos, no qual um é utilizado como chave de acesso``.

**Algumas das principais interfaces fornecidas pelo pacote java.util.*:**

* ColLection - interface raiz da hierarquia de Coleções a partir da qual se derivam as interfaces Set e List

* Set - dá relevância à exclusividade, ou seja, contém elementos únicos

* List - interface onde o índice tem relevância. Esta interface possui divcersas operações relacionadas ao índice que outras interfaces não list não têm.

* Map - diz respeito a identificadores únicos, onde se mapeia uma única chave para um determinado valor. Para os Maps são associados chaves e valores onde estas não podem ser duplicadas, ou seja, cada chave pode mapear somente um valor.

* Queue - o mesmo que fila, geralmente utilizada para se manter uma lista de execuções a serem processadas. A ela se atribui o conceito de FIFO (First In, First Out).

**Representação da hierarquia de interfaces e classes para coleções**:

<img src = "Imagens/InterCole.png">

&nbsp;

## **A Inteface List**

---

&nbsp;

É uma **Collection** que permite elementos duplicados de maneira ordenada, onde o programador tem controle preciso sobre onde o elemento está inserido na lista.

Assim como os **Arrays**, essa interface também é baseada em índice, onde o primeiro elemento da lista é **zero**.

``Uma vantagem que uma coleção lista possui sobre as coleções não list é a grande variedade de métodos relacionados com índices, como o get(int index), indexOf(Object o), add(int index, Object obj), entre outros``.

**A interface List possui 3 classes que a implementa**: **ArrayList**, **LinkedList** e **Vector**.

No **ArrayList**, deve ser considerado esse conjunto como um **Array** redimensionável, isto é, que pode crescer. Pois, além de implementar a interface **List**, essa classe fornece métodos que permitem manipular o tamanho da matriz que é usada internamente para armazenar a lista.

Cada instância de uma **ArrayList** possui uma capacidade que define o tamanho da matriz usada para armazenar os elementos da lista, quando é adicionado um elemento a uma **ArrayList**, sua capacidade aumenta automaticamente.

**Exemplo**:

~~~~Java
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo4{

    public static void main(String[] args){

        List<String> listaFrutas = new ArrayList<String>();
        String s = "uva";
        listaFrutas.add("melancia");
        listaFrutas.add(s);
        listaFrutas.add("caju");

        String saida = "";
        saida += "Frutas da Lista: " + listaFrutas.toString();
        saida += "\nTotal de Frutas na lista: " + listaFrutas.size();
        saida += "\nA lista possui caju? " + listaFrutas.contains("caju");
        listaFrutas.remove("uva");

        saida += "\nTotal de Frutas na lista " + "após remover uva: " + listaFrutas.size();
        saida += "\nFrutas da Lista: " + "após remover uva: " + listaFrutas.toString();
        saida += "\nÍndice da Fruta " + "caju na lista: " + listaFrutas.indexOf("caju");

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com ArrayList", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }
}
~~~~

&nbsp;

Quando é declarado o **ArrayList**, não houve necessidade de declarar o tamanho, pois, é graças a capacidade que o **ArrayList** tem de definir o seu tamanho automaticamente quando adicionado ou removido um objeto da lista.

Foi utilizado a sintaxe **<String>** no **ArrayList**, pois, esse tipo de programação segue o princípio da **POO** (**Programação Orientada a Objetos**) de "programas para uma interface" fazendo o uso de genéricos para declarar o tipo de uma coleção.

Outro ponto interessante foi a possibilidade de perguntar ao **ArrayList** se ele possuí determinadas frutas na lista por meio do método **listaFrutas.contains()**.

De vez utilizar algum laço de repetição para percorrer os elementos, pode apenas ser utilizado o método **listaFrutas.indexOf()**

&nbsp;

**Exemplo utilizando classificação por ordem alfabética**:

~~~~Java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo5{

    public static void main(String[] args){
        List<String> listaNomes = nre ArrayList<String>();
        listaNomes.add("Maria");
        listaNomes.add("João");
        listaNomes.add("José");
        listaNomes.add("Adriano");
        listaNomes.add("Willian");
        listaNomes.add("Patrícia");

        String saida = "";
        saida += "Lista desordenada: " + listaNomes;

        Collections.sort(ListaNomes);

        saida += "\nLista ordenada: " + listaNomes;

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com ArrayList", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }
}
~~~~

&nbsp;

Foi declarado o **ArrayList** de **String**, posteriormente utilizado o método **listaNomes.add()** para adicionar a lista, nomes de pessoas de forma desordenada.

A variável **saida** foi adicionado os nomes contidos na lista antes de ser realizado a ordenação.

Foi utilizado os métodos **sort()** da classe **Collections** para realizar a classificação, ou melhor, ordenação da lista, em seguida foi recuperado novamente os nomes contidos na lista e demonstrar a ordenação.

&nbsp;

## **A Inteface Set**

---

&nbsp;

``A interface Set é uma Collection que não permite elementos duplicados``.

O que determinará que dois objetos seja idênticos é o método **equals()**, situação onde só um objeto poderá ficar no **set**, ou seja, se tentar adicionar um elemento que já existe nele, o método **add()** retornará **false** e o elemento não será adicionado.

As três classes que implementam **Set** são: **HashSet**, **LinkedHashSet** e **TreeSet**.

Exemplo abaixo será codificado e analisando utilizando **HashSet**, esta classe trata-se de um conjunto **Set** não ordenado e não classificado, pode utilizar essa classe quando quiser obter um conjunto sem elementos duplicados sem precisar de ordem na sua iteração.

**HashSet** remove qualquer duplicidade existente na Collection.

~~~~Java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo6{

    String saida = "";
    private String[] cores = {"vermelho", "branco", "azul", "verde", "cinza", "laranja", "bronzeado", "branco", "ciano", "pêssego", "cinza", "laranja"};

    public static void main(String[] args){
        new Exemplo6();
    }

    public Exemplo6(){
        List lista;

        lista = new ArrayList(Arrays.asList(cores));
        saida += "Lista com elementos duplicados: ";
        saida += "zn" + lista;

        this.gerarListaNaoDuplicada(lista);

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com Sets", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }

    public void GerarListaNaoDuplicada(Collection collection){
        Set set = new HashSet(collection);
        Iterator iterator = set.iterator();

        saida += "\n\nLista com elementos não duplicados\n";

        while(iterator.hasNext()){
            saida += iterator.next() + " ";
        }
    }
}
~~~~

&nbsp;

É utilizado um **HasSet** para remover **Strings** duplicadas de uma **ArrayList**. 

O método **gerarListaNaoDuplicada** recebe como argumento uma **collection** onde é construído um **HasSet** desta Collection, quando esta construção é realizada, quaisquer elemento duplicado na Collection, nesse caso, o **ArrayList** declarado e criado é removido.

Foi declarado um **Array cores** com nomes duplicados (branco, cinza e laranha), na construção do **ArrayList** é utilizado o **Array** de cores para criar a lista de cores duplicadas, depois de construir o **HashSet** com base na lista de cores duplicadas, foi utilizado um **Iterator** para poder acessar os elementos do **HashSet**.

Foi obtido posterior, um **Iterator** de **HashSet** e utilizado os métodos **hasNext** e **next** de **Iterator** para acessar os elementos de **HashSet**

No exemplo abaixo, caso precise ordenar os elementos, é utilizado a classe **TreeSet** da interface **SortedSet** que estende **Set**.

A interface **SortedSet** mantém seus elementos em ordem natural ou uma ordem especificada por um **Comparator**.

A classe **TreeSet** implementa **SortedSet** e cria uma estrutura de árvore garantindo que os elementos estejam ordenados de forma ascendente, de acordo com a ordem natural.

~~~~Java
import java.util.Arrays;
import java.util.Iterator;
import java.util.SortedSet;
import java.util.TreeSet;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo7{

    String saida = "";
    private String[] cores = {"vermelho", "branco", "azul", "verde", "cinza", "laranja", "bronzeado", "branco", "ciano",  "pêssego", "cinza", "laranja"};

    public static void main(String[] args){
        new Exemplo7();
    }

    public Exemplo7(){
        TreeSet tree = new TreeSet(Arrays.asList(cores));

        saida += "\nSet de elementos não " + "duplicados e ordenados:\n";
        this.mostrarSet(tree);

        saida += "\n\nSubconjunto de TreeSet " + "menor que 'laranja':\n";
        this.mostrarSet(tree.headSet("laranja"));

        saida += "\n\nSubconjunto de TreeSet " + "maior que 'laranja':\n";    
        this.mostrarSet(tree.tailSet("laranja"));    

        saida += "\n\nPrimeiro elemento de set: " + tree.first();
        saida += "\nÚltimo elemento de set: " + tree.last();

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com Sets", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }

    private void mostrarSet(SortedSet ss){
        Iterator iterator = ss.iterator();

        while(iterator.hasNext()){
            saida += iterator.next() + " ";
        }
    }
}    
~~~~

&nbsp;

Criou-se um objeto **TreeSet** com base no **Array cores** e atribui uma referência para esse objeto a **tree**.

Depois, é realizado uma chamada para o método **headSet** no qual retorna um subconjunto de **TreeSet** com elementos menores que "**laranja**", para retornar os elementos maiores que ou igual a "**laranja**", é realizado uma chamada para o método **tailSet**, quaisquer alterações realizadas por meios destas duas visões, **headSet** e **tailSet**, serão refletidas em **TreeSet**.

Foi chamado os método **first** e **last**, estes são responsáveis por obter o menor e o maior elemento, respectivamente.

O método **mostrarSet** recebe como argumento um **sortedSet** e o imprime quando é realizado a chamada deste método.

E o método **set** ordenado, para os elementos menores que "**laranja**" e os elementos maiores que ou igual a "**laranja**", respectivamente

&nbsp;

## **A Inteface Map**

---

&nbsp;

Embora as classes **SortedMap**, **Hashtable**, **HashMap**, **TreeMap** e **LinkedHashMap** sejam consideradas coleções, nenhuma destas estendem de Collection como as classes que implementam as interfaces Set e List.

Deve ser considerado um objeto **Map** como um objeto que mapeia chaves para valores não permitindo que existam chaves duplicadas (assim como **Sets**, **Maps** conta apenas com o método **equals ()**) para determinar se as chaves são iguais ou diferentes) e que cada chave pode ser mapeada para no máximo um valor.

Este tipo de mapeamento é chamado de mapeamento um para um, um objeto **Map** difere de um **Set** no fato de que o **Map** possui chave e valor, enquanto **Set** possui somente chave.

A interface que estende **Map** responsável por manter suas chaves ordenadas é o **SortedMap**.

Implementações realizadas com **Maps** permitem buscar um valor com base em uma determinada chave, recuperar uma coleção apenas dos valores ou apenas das chaves.

Abaixo exemplo utilizadno **HasMap** para contar o número de **Strings** que iniciam com uma determinada letra.

~~~~Java
import java.util.HashMap;
import java.util.Map;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public classe Exemplo8{

    private static String[] nomes = {"João", "José", "Pedro", "Carlos", "Jaqueline", "Matheus", "Marcelo"};

    public Exemplo8(){
        HashMap map = new HashMap();
        Integer i;

        for(int j = 0; j < nomes.length; j++){
            i = (Integer) map.get(new Character(nomes[j].charAt(0)));

            if(i == null){
                map.put(new Character(nomes[j].charAt(0)), new Integer(1));
            }else{
                map.put(new Character(nomes[j].charAt(0)), new Integer(i.intValue() + 1));
            }
        }

        this.geraSaidaMap(map);
    }

    private void geraSaidaMap(Map mapRef){
        String saida = "";
        saida += "Número de palavras iniciadas com letra: ";
        saida += "\n" + mapRef.toString();
        saida += "\nQuantidade de valores do Map: " + mapRef.size();
        saida += "\né vazio?: " +mapRef.isEmpty();

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com Maps", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }

    public Static void main(Stroing[] args){
        new Exemplo8();
    }
}
~~~~

&nbsp;

Foi construído um **HashMap** para armazenar a quantidade de palavras **nomes** que inicial por uma determinada letra em **map**, sendo exxe armazenamento feito no laço **for**.

Posterior, foi realizado uma chamada para o método **get** de **map** para recuperar do **HashMap** a primeira letra de uma **String** em nomes utilizando **Character**, se não for encontrato um objeto mapeado em **HashMap**, o método **get** irá devolver **null**, caso contrário, o valor do mapeamento é devolvido como um objeto, convertido para **Integer** e atribuído em **i**

No **if** é verificado se **i** é **nul**, caso seja, é realizado chamada para o método **put** de **map** para armazenar um **Integer** com valor 1 no **HashMap**, esse valor é o número de palavras que inicial com **Character**, se **i** não for **null**, significa que **Caracter** está no **HashMap**, por isso, é feito o incremento do valor de **Integer** em 1, atualizando o valor no **HashMap**.

O método **geraSaidaMap** recebe como argumento um **Map** e atribui o seu conteúdo na variável **saida** utilizando o método **toString**.

Posterior, é recuperado o número de valores no **Map** por meio do método **size** e depois é recuperado um **boolean** por meio do método **isEmpty** indicando se o **Map** está vazio.

&nbsp;

## **A Inteface Queue**

---

&nbsp;

A **Queue** (Fila) segue o conceito **FIFO** (**First In, First Out**), mas é possível o uso de outras, tem como objetivo manter uma lista de tarefas a serem processadas de alguma maneira, além, de suportar todos os métodos padrões de uma Collection, ela também possui métodos adicionais para adicionar, extrair e revisar os elementos da fila.

A classe responsável por implementar uma **Queue** é a **PriorityQueue**, seus elementos são ordenados pela ordem natural e seu objetivo é criar uma fila onde o elemento que tem prioridade para entrar, tem prioridade para sair (**Priority In, Priority Out**), ou seja, os elementos ordenados primeiro serão acessados primeiro, o que difere de uma fila do tipo **FIFO** (**Primeiro a entrar é o primeiro a sair**).

Abaixo exemplo utilizando a classe **LinkedList**:

~~~~Java
import java.util.LinkedList;
import java.util.Queue;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class Exemplo9{

    String saida = "";

    public Exemplo9(){
        Queue<Integer> queue = new LinkedList<Integer>();
        this.adicionarElemento(queue);
        saida += "\n";
        this.removerElemento(Queue);

        JTextArea saidaArea = new JTextArea();
        saidaArea.setText(saida);

        JOptionPane.showMessageDialog(null, saidaArea, "Trabalhando com Queues", JOptionPane.INFORMATION_MESSAGE);

        System.exit(0);
    }

    public static void main(String[] args){
        new Exemplo9();
    }

    private void adicionarElemento(Queue qe){
        int elemento = 10;
        for(int i = elemento; i >= 0; i--){
            saida += "Adicionando o elemento: " + i + " na fila\n";
            qe.add(i);
        }
    }

    private void removerElemento(Queue qe){
        while(!qe.isEmpty()){
            saida += "Removendo o elemento: " + qe.remove() + " da fila\n";
        }
    }
}
~~~~

&nbsp;

É declarado uma **Queue** que recebe uma instância de uma **LinkedList**, assim como um **ArrayList**, **LinkedList** é uma classe onde seus elementos são ordenados pela posição no índice exceto pelos elementos serem duplamente encadeados.

Além dos métodos obtidos da interface **List**, esse encadeamento fornece métodos para ionserção ou remoção do início ou final tornando-se a melhor opção para implementações de pilha ou fila.

O método **adicionarElemento()**, recebe como argumento uma **Queue** na qual são adicionados 6 elementos.

Foi declarado uma variável **elemento** do tipo **int** e inicializada com o valor 5.

Foi feito um laço **for** decrementando esse valor até 0 e adicionando o valor decrementado na fila, ou seja, o primeiro elemento a entrar na fila é o 5, o próximo é o 4, 3 e seguinte e assim sucessivamente decrementando e adicionando até 0.

O método **removerElemento** também recebe como argumento uma **Queue** da qual serão removidos os elementos contidos nela.

O laço **while** que enquanto a fila não for vazia (verificação realizada com o método **isEmpty()**) será removido um elemento ao utilizar o método **remove()**, esse método tem a finalidade de recuperar e remover um objeto da fila.

