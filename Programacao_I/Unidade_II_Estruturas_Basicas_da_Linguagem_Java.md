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

Continuar da pag. 42...