# **Anotações Programação I - Unidade II**

&nbsp;

## **O que são Tipos Primitivos**

---

&nbsp;

Há oito tipos de dados primitivos em Java:

&nbsp;

### **Tipos Inteiros**

&nbsp;

São para números sem partes fracionárias, valores negativos são permitidos

&nbsp;

**Quatro tipos de números inteiros**:

 * ***byte*** - números inteiros de 8 bits (1 byte). Podem assumir valores entre -128 a 127.

 * ***short*** - números inteiros de 16 bits (2 bytes). Podem assumir valores entre -32.768 até 32.767.

 * ***int*** - números inteiros de 32 bits (4 bytes). Podem assumir valores entre -2.147.483.648 até 2.147.483.647.

 * ***long*** - números inteiros de 64 bits (8 bytes). Podem assumir valores entre -9.223.372.036.854.775.808 até 9.223.372.036.854.775.807.

&nbsp;

O tipo *long* deve ser identificado com a letra "L" para não ser "compactado" pela linguagem em um tipo inteiro, a compactação ocorre como uma maneira de reduzir o uso de memória.

&nbsp;

### **Tipos de Ponto Flutuantes**

&nbsp;

Sãopara os números com partes fracionárias.

&nbsp;

**Dois tipos de pontos flutuantes**:

* ***float*** - números reais de 32 bits com precisão simples. Podem assumir valores de ponto flutuante com formato definido pela especificação IEEE 754.

* ***double*** - números reais de 64 bits com precisão dupla. Assim como o float, podem assumir valores de ponto flutuante com formato definido pela especificação IEEE 754.

&nbsp;

Números do tipo float têm sufixo “F” (Exemplo: 3.454F). Números de ponto flutuante sem um sufixo F sempre são considerados como o tipo double. Opcionalmente, você pode fornecer o sufixo “D” (Exemplo: 3.22D).

&nbsp;

### **Tipo Char**

&nbsp;

Utilizado para descrever caracteres individuais.

**Um tipo de char**:

* ***char*** - Representam notação de caracteres de 16 bits (2 bytes) para formato Unicode UTF-16. Podem assumir caracteres entre ‘\u0000’ a ‘\uffff’ e valores numéricos entre 0 a 65535.

&nbsp;

### **Tipo Boolean**

&nbsp;

Consta com dois valores: *true* e *false*. É utilizado para avalizar condições lógicas.

**Um tipo de boolean**:

* ***boolean*** - Representam apenas 1 bit de informação (0 ou 1). Podem assumir apenas os valores true e false.

&nbsp;

## **Declaração e Inicialização de variáveis**

---

&nbsp;

### **Declaração de variáveis**

&nbsp;

Java é uma lingiagem de programação fortemente tipada.

O nome de uma variável pode começar com uma letra, um sublinhado "_", ou cifrão "$", se o nome da variável começar com um sublinhado, o segundo caractere deve ser uma letra alfabética.

**Exemplos**:

~~~~Java
public class TiposPrimitivos{

    float pi;
    double tamanho;
    char estadoCivil;
    boolean aprovado;
    short s;
    byte b;
    int _variavel1;
    long $variavel2;
}
~~~~

&nbsp;

O nome não pode começar com um dígito (0, 1, 2, 3, 4, 5, 6, 7, 8 ou 9).

Depois do primeiro caractere, o nome da variável pode incluir letras, dígitos ou sublinhados, em qualquer combinação.

O nome de uma variável não pode ser nenhuma palavras-chaves da linguagem Java, as quais são palavras especiais, reservadas em Java.

**Abaixo as 49 palavras-chaves reservadas**:

> byte - short - int - long - char - Boolean - double - float - public - private - protected - static - abstract - final - strictfp - transient - synchronized - native - void - class - interface -implements - extends - if - else - do - default - switch - case - break - continue - assert const - goto - throws - throw - new - catch - try - finally - return - this - package - import - instaceof - while - for - volatile - super

&nbsp;

### **Inicializando variáveis**

&nbsp;

Antes da variável ser utilizada, ea deve receber um valor inicial, sendo isso chamado de inicialização de variável.

Para iniciar uma variável, deve ser usada uma instrução de atribuição, essa instrução segue o mesmo padrão de uma equação matemática, ``para dar um valor à variável, o lado esquerdo tem de ser o nome da variável e o lado direito o valor atribuído``.

Exemplo:

~~~~Java
int numero; //iniciando a variável
numero = 0;
~~~~

&nbsp;

O número foi declarado com um tipo de dados **int** e foi inicializado com 0, sendo assim, pode-se agora, adicionar 5 para a variável número, pois a mesma já foi inicializada.

~~~~Java
int numero; //iniciando a variável
numero = 0;
numero = numero +5;
~~~~

&nbsp;

Tipicamente, a inicialização de uma variável é feita ao mesmo tempo que a sua declaração

~~~~Java
int numero = 0;
numero = numero +5;
~~~~

&nbsp;

## **Escopo de variável**

---

&nbsp;

``O conceito escopo de variável descreve a vida de uma variável, ou seja, refere-se à acessibilidade de uma variável, é a parte do programa em que o nome da variável pode ser referenciada``.

Pode-se declarar a variável em vários diferentes lugares do mesmo código.

&nbsp;

### **Variável de Instância (Atributos)**

&nbsp;

**São definidas dentro da classe, mas fora de qualquer método,e  só são inicializdas quando a classe é instanciada**.

``Elas são os campos que pertencem a cada objeto, por exemplo, código abaixo define campos para a classe Livro:

~~~~Java
public class Livro {

    long preco;
    int quantidade;
    char tipo;

}
~~~~

A classe Livro informa que cada intância sua terá seu próprio preço, quantidade e tipo, ou seja, cada instância poderá ter seus próprios valores exclusivos para esses três campos.

&nbsp;

#### **Variáveis Locais**

&nbsp;

``São as declaradas dentro de um método, ela é eliminada quando a execução do método é concluída``.

Elas são só visíveis para os métodos em que são declaradas, não são acessíveis a partir do resto da classe, por isso elas não utilizam a maioria dos modificadores e acessos como *public*, *abstract*, *static* etc., porém ela pode fazer uso do modificador final.

**A variável local precisa ser inicializada para ser usada** e sua sintaxe para iniciar é semelhante ao declarar um campo.

~~~~Java
public class Livro{

    public void metodoContar(){
        int contador = 20;
        contador = contador +1;
    }
}
~~~~

&nbsp;

A variável contador foi declarada dentro do método **metodoContador()**, e ela foi inicializada na mesma linha onde foi declarada. **O compilador rejeitará qualquer tentativa de utilização de uma variável a qual não tenha sido atribuído um valor, pois, diferente das variáveis de instância, as variáveis locais não recebem valores padrãp**.

A variável **contador** não pode ser referenciada em nenhum código externo ao método onde foi declarada

~~~~Java
public class Livro{

    public void metodoContar(){
        int contador = 20;
        contador = contador +1;
    }

    //O codigo abaixo não será compilado
    //O compilador não tem acesso a variável contador
    public void imprimir(){
        System.out.println(contador);
    }
}
~~~~

O "System.out.println(contador);" a variável contador seria destacada, acusando um erro de acesso.

&nbsp;

#### **Variáveis de Classe (Estáticas)**

&nbsp;

Também conhecidas como ``variáveis estáticas``, **são declaradas com a palavra-chave *static* em uma classe, mas fora de um método construtor ou um bloco**

O modificador *static* diz ao compilador que há apenas uma cópia de cada variável de classe por classe, independentemente de quantos objetos são criados a aprtir dele.

``A ideia é que objetos de uma mesma classe podem e , em algumas situações, devem compartilhar valores em comum, caso contrário, teríamos de criar atributos que precisariam ser atualizados todos ao mesmo tempo, e em cada objeto criado``.

~~~~Java
public class Livro{

    //Variável estática representando 20& de desconto
    public static int DESCONTO = 20;

    public void vender(double valor){
        double novoValor = valor - (valor * DESCONTO) / 100;
    }
}
~~~~

&nbsp;

A variável quando é estática funciona mais ou menos como uma variável do tipo global em linguagens como Pascal ou Delphi, **embora no Java não exista conceito de variável global**.

&nbsp;

### **Comparando os Escopos de Variável**

&nbsp;

``Comparação resumida entre os escopos de variáveis e principais pontos a serem lembrados``:

<img src = "Imagens/Escopo1.png">

&nbsp;

## **Estruturas de Controle**

---

&nbsp;

São instruções que permitem que blocos específicos de código sejam escolhidos para sereme xecutados, redirecionando determinadas partes do fluxo do programa.

``O Java contém três tipos de estruturas de controle``: instruções de sequência; instrução de seleção (*if, if else, switch*) e instruções de repetição (*while, do-while, for*).

&nbsp;

### **Instruções de Sequência**

&nbsp;

Diagrama de atividades UML que modela um fluxo de sequência em Java com 2 instruções:

<img src = "Imagens/Sequencia.png">

&nbsp;

O circulo na parte superior representa o estado inicial do programa, os retângulos são as diretrizes (instruções), as setas representam as transições e o circulo na parte inferior representa o estado final do programa.

&nbsp;

## **Estruturas de Seleção**

---

&nbsp;

### **Instruções *If* e *Else***

&nbsp;

O java disponibiliza os comandos *if* e *else* que, de forma seletiva, definem qual bloco de comandos deverá ser executado. Se a condição do comando *if* for avaliada como verdadeira, será executado o bloco de comando dentro do *if*

~~~~Java
    if(expressao){
        diretiva
    }
~~~~

&nbsp;

Abaixo fluxograma de como funciona o comando *if*

<img src = "Imagens/If1.png">

&nbsp;

``Diretivas`` são as instruções que o Java fornece para a construção de programas, elas são separadas por ";".

**Exemplo If**:

~~~~Java
public class EstruturaControle{
    
    public static void main (String args[]){

        int valor1 = 5;
        int valor2 = 10;

        if (valor1 > valor2){
            System.out.println("Valor 1 é maior que valor 2");
        }

        System.out.println("Soma dos valores: " + (valor1 + valor2));
    }
}
~~~~

&nbsp;

Acima temos uma expressão comparando o **valor1** com o **valor2**, no caso, a expressão retornou um valor verdadeiro, o que fez com que a diretiva fosse executada

Agora utilizando a estrutura de condição *if else*

~~~~Java
    if (expressao){
        Diretiva 1
    }else{
        Diretiva 2
    }
~~~~

Abaixo fluxograma de como funciona o comando *if else*

<img src = "Imagens/IfElse.png">

&nbsp;

**Exemplo If Else**:

~~~~Java
public class EstruturaControle{

    public static void main(String args[]){
        int valor1 = 5;
        int valor2 = 10;
        if(valor1 > valor2){
            System.out.println("Valor 1 é maior que valor 2");
        }else{
            System.out.println("Valor 2 é maior que valor 1");
        }
    }
}
~~~~

A expressão (valor1 > valor 2) sempre irá retornar um valor lógico, sendo verdadeiro ou falso.

&nbsp;

### **Argumentos Válidos para Instruções *If***

&nbsp;

As instruções *if* só podem avaliar valores booleanos, pode fazer uso de operadores lógicos "&&" (E) e "||" (OU).

Utilizando o operador "&&", caso a primeira condição avaliada em um comando *if* seja falsa, automaticamente a segunda expressão não será avaliada.

Utilizando o operador "||", caso a primeira condição avaliada em um comando *if* seja verdadeira, automaticamente a segunda expressão não será avaliada.

~~~~Java
public class EstruturaControle{

    public static void main(String args[]){
        int valor1 = 5;
        int valor2 = 10;
        if(valor1 > 10 && valor2 > 10){
            System.out.println("1) Os dois valores são maiores que 10");
        }else{
            System.out.println("1) O primeiro ou o segundo valor não é maior que 10");
        }
        if(valor1 > 10 || valor2 > 10){
            System.out.println("2) Um dos números é maior que 10");
        }else{
            System.out.println("2) Nenhum dos números é maior que 10");
    }
}
~~~~

&nbsp;

### **Instruções *Switch***

&nbsp;

Ela verifica uma variável e trabalha de acordo com seus *cases*, os *cases* são as possibilidades de resultados que são obtidos por *switch*.

El serve para controlar diversas ações diferentes de acordo com o *case* definido dentro dele.

Utilizando a estrutura de condição *switch*:

~~~~Java
    switch (expressao ordinal) {
    case valor ordinal 1:
        diretiva 1;
    break;
    case valor ordinal 2:
        diretiva 2;
    break;
        ...
    default:
        diretiva N;
    }
~~~~

A ``expressão ordenal`` é a expressão que retorna um valor de algum tipo discreto (*inteiro, char* etc.).

Abaixo fluxograma de como funciona o comando *switch*

<img src = "Imagens/Switch.png">

&nbsp;

É possível construir um programa com *if* equivalente ao *switch*, porém é mais trabalhoso se no caso for possível utilizar o *switch*.

**Deve-se usar o *switch* quanhdo usar uma mesma variável, igualando-a com vários valores diferentes, a estrutura do comando *switch* vem acompanhada com o comando *case*, que com base no valor da variável do comando *switch* define qual opção será executada**. 

``Para que somente um entre vários comandos seja executado, deve-se executar o comando break logo após a execução dos comandos contidos no bloco de comando case selecionados``.

**Exemplo de *switch***

~~~~Java
public class Menu{
    public static void main(String[] args) throws IOException{
        System.out.println("Digite um dos comandos abaixo do menu: ");
        System.out.println("1: Comprar; 2: Vender; 3: Listar; 4: Sair");
        //Lê do teclado um caracter
        Scanner scan = new Scanner(System.in);
        int opcao = scan.nextInt();
        switch(opcao){
            case 1:
                System.out.println("Você acessou COMPRAR");
                break;
            case 2:    
                System.out.println("Você acessou VENDER");
                break;
            case 3:    
                System.out.println("Você acessou LISTAR");
                break;       
            default:    
                System.out.println("Saindo do sistema");                        
        }   
    }
}
~~~~

&nbsp;

Iremos ler do teclado um caractere numérico utilizando a classe **Scanner** do Java, a classe **Scanner** permite a leitura de dados vindos do teclado, a utilização do método **nextin()** da classe **Scanner** deixa no *buffer* a instrução da tecla pressionada.

No programa acima, foi lido um caractere numérico do teclado, e caso for igual a uma das opções do menu, ele então apresentará a informação personalizada para cada opção escolhida.

**A palavra break interrompe a execução do case, se a palavra-chave break for omitida, o programa simplesmente continuará a executar os outros blocos case até que uma palavra break seja encontrada na instrução switch, ou até que a instrução termine**.

``O comando default representa uma excessão a todas as opções listadas nos comandos case, também é importante observar que nos comandos case da instrução switch, só são aceitas variáveis do tipo: int, char, byte e short``.

&nbsp;

## **Estruturas de Repetição**

---

&nbsp;

Os **loops** no Java permitem que faça repetição na execução de um bloco de código até que uma determinada condição seja verdadeira ou durante uma quantidade específica de iterações.

&nbsp;

### **Usando *Loop For***

&nbsp;

é aprticularmente útil para o controle de fluxo quando já souber quantas vezes terá de executar as instruções do bloco **loop**

Utilizando a estrutura do comando *for*:

~~~~Java
    for ([inicio]; [condicao]; [incremento/decremento]){
        diretiva;
    }
~~~~

O **inicio** é a diretiva executada antes do laço começar; em seguida, temos a condição que é a expressão de condição de parada do laço (geralmente, comparação com o valor final); o incremento/decremento representa diretiva executada antes de começar cada iteração do laço (geralmente usada para incrementar ou decrementar o contador).

Abaixo fluxograma de como funciona o comando *for*:

<img src = "Imagens/For.png">

&nbsp;

``O loop for é uma construção geral para suportar a interação que é encontrada por uma variável de contador ou semelhante, que é atualizada depois de cada iteração``.

**Exemplo de *loop for***

~~~~Java
public class ComandoFor{

    public static void main(String args[]){

        for(int i = 1; i <= 5; i++){
            System.out.println(i);
        }
    }
}
~~~~

&nbsp;

No Java é possível utilizar o **loop for** para fazer repetição condicional:

~~~~Java
    boolean achou = false;
    for(int i = 0; (!achou); i++){ //!achou é negativa, tornando-o true
        /*...*/
    }
~~~~

&nbsp;

Pode efetuar múltiplas diretivas na inicialização e no incremento, se necessário, separando com vírgulas

~~~~Java
    for(int i = 1, j = i + 10; i < 5; i++, j = 1 * 2){
        System.out.println("i = " + i + "j = " + j);
    }
~~~~

&nbsp;

### **Usando *Loop While***

&nbsp;

É adequado para quando não souber quantas vezes o bloco ou instrução terá que ser repetido.

Utilizando a estrutura do comando *while*:

~~~~Java
    while(condicao){
        Diretiva;
    }
~~~~

&nbsp;

A condição é a expressão de condição de parada do laço (expressão lógica).

Abaixo fluxograma de como funciona o comando *while*:

<img src = "Imagens/While.png">

&nbsp;

O problema com estruturas de repetição, é que pode ocorrer o *looping* infinito, sendo imprescindível que uma determinada variável seja modificada de acordo com cada *loop*.

**Exemplo de *While***

~~~~Java
    int contador = 0;
    while(contador < 5){
        System.out.println("Repetição Nro: " + contador);
        contador++;
    }
~~~~

&nbsp;

A variável **contador** é iniciada com 0, a cada *loop* executado é somado 1 ao contador, fazendo o **while** manter a repetição enquanto a variável **contador** for menor que 5.

``Outro ponto importante é que a variável **contador** é inicializada antes de chgar ao while, assim, o while comparará a sentença e só depois permitirá a execução do bloco``, **se quizer fazer todo o bloco primeiro e só depois fazer a comparação, devemos utilizar o comando do while**.

&nbsp;

### **Usando *Loop Do-While***

&nbsp;

**Ele permite que pelo menos uma execução do bloco de comandos seja executada antes de testar a condição**.

O bloco de comandos será executado enquanto a condição for verdadeira.

Utilizando a estrutura do comando *do-while*:

~~~~Java
    do{
        Diretiva;
    }while(condicao);
~~~~

&nbsp;

Abaixo fluxograma de como funciona o comando *do-while*:

<img src = "Imagens/DoWhile.png">

&nbsp;

O **do while** só avalia depois, certamente executando a diretiva ao menos uma vez, não sendo possível comparar a variável de controle antes do bloco de código como acontece com o **while**, pois a comparação só será feita após todo código ter sido executado.

**Exemplo de *Do While***

~~~~Java
    int valor = 1;
    do{
        System.out.println("O numero é: " + valor);
        valor++;
    }while(valor < 5>);
~~~~

&nbsp;

## **Desvios Incondicionais**

---

&nbsp;

Constam dois casos específicos no Java de desvios incondicionais: **break** e **continue**.

**Break** e **continue** são dois comandos de controle de estruturas largamente utilizados em loops (repetições), como **for** e **while**.

&nbsp;

### **Break**

&nbsp;

**Esse comando tem a função de interromper a execução de um loop**.

Abaixo exemplo, tem a repetição que se inicia em 1 e deve terminar em mim (500), mas dentro desta estrutura há uma condição: se a variável foir igual a 6, saia da estrutura de repetição:

~~~~Java
    public static void main (String args[]){
        for(int cont = 1; cont <= 500; cont++){
            System.out.println("nr: " + cont);
            if(cont == 6){
                break;
            }
        }
    }
~~~~

&nbsp;

Mesmo que a condição **for** instruísse para o programa imprimir números até 500, a condição **if** se tornou válida quando o **cont** chegou ao número 6, e sendo verdadeiro, executou seu bloco de instruções interrompendo o programa.

&nbsp;

### **Continue**

&nbsp;

**Tem a função de fazer com que a condição do comando de loop seja novamente testada, mesmo antes de alcançar o fim do comando**.

Exemplo:

~~~~Java
    public static void main(String args[]){

        for(int i = 0; i < 12; i++){
            if ((i > 4) && (i < 8)){
                continue;
            }
            //Apresenta na tela quando o i não estiver entre 4 e 8
            System.out.println("i = " + i);
        }
    }
~~~~

&nbsp;

O programa não irá imprimir os números 5, 6 e 7 devido à execução do comando **continue**.

&nbsp;

### **Break e Continue Rotulados**

&nbsp;

Tando **break** quanto **continue** podem ser ou não rotulados ou rotulados, **as rotuladas serão necessárias somente nas situações em que tiver um loop aninhado e precisar indicar qual quer encerrar ou a partir de qual deseja continuar a próxima interação**.

Uma instrução **break** sairá do **loop** rotulado e não do **loop** atual se a palavra-chave **break** for combinada com um rótulo.

&nbsp;

**Exemplo de rótulo com break**:

~~~~Java
    public static void main(String[] args){

        int y = 7;
        externo:
        for(int i = 0; i < 15; i++){
            while (y > 3){
                y++;
                System.out.println("Dentro do Loop");
                break externo;
            }
            System.out.println("Fora do loop");
        }
        System.out.println("Fora do Programa");
    }
~~~~

&nbsp;

A sentença "Dentro do Loop" será exibida uma vez, em seguida a instrução **break** rotulada será executada e o fluxo sairá do **loop** rotulado com o rótulo que foi declarado como "externo", então, a próxima linha de código exibirá "Fora do Programa.

&nbsp;

**Exemplo de rótulo com continue**:

~~~~Java
    public static void main(String[] args){

        int y = 1;
        externo:
        for(int i = 0; i < 15; i++){
            while (y > 3){
                y++;
                System.out.println("Dentro do Loop");
                break externo;
            }
            System.out.println("Fora do loop");
        }
        System.out.println("Fora do Programa");
    }
~~~~

&nbsp;

A sentença "Dentro do Loop" foi executada 2 vezes, atendendo a condição de y < 3, depois de concluída essa instrução, o programa imprimiu 13 vezes a sentença "Fora do Loop", para concluir, quando a condição do **loop** externo for avaliada como falsa, o **loop i** será encerrado e a sentença "Fora do programa" será exibida.

&nbsp;

### **Break e Continue Não Rotulados**

&nbsp;

AS instruções não rotuladas saíram da estrutura do **loop** atual e prosseguirão na linha de código posterior ao bloco do **loop**.

&nbsp;

**Exemplo de não rótulada com break**:

~~~~Java
    public static void main(String [] args){

        boolean pausa = true;
        while(true){
            if(pausa)`
            System.out.println("Programa Pausado")/
            break
        }
    }
~~~~

&nbsp;

**Exemplo de não rótulada com continue**:

~~~~Java
    public static void main(String [] args){

        for(int cont = 1; cont <= 8; cont++){
            if(cont == 3){
                continue;
            }
        }
        System.out.println("nr: " + cont);
    }
~~~~

&nbsp;

No código acima, não foi impresso o número 3, pois ao chegar na condição, o programa encontrou um **continue** que mandou continuar a execução do programa.