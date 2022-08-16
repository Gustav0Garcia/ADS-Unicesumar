# **Anotações Programação I - Unidade IV**

&nbsp;

## **Encapsulamento**

---

&nbsp;

**A ideia principal do encapsulamento envolve omitir os membros de uma classe, além, de esconder como funcionam as rotinas ou regras de negócio**.

Realizar o encapsulamento de um projeto é fundalmental para que seja possível minimizar o impacto de problemas referentes a alterações do projeto, uma vez que não é preciso alterar uma regra de negócio em vários lugares, mas sim, em apenas um único lugar, já que tal regra está encapsulada.

Para exemplificar, será usado umproblema de realização de operações bancárias de um caixa eletrônico, no caixa é possível: sacar dinheiro, depositar, verificar saldo, verificar extrato, pagar contas e fazer trasnferências.

Para utilizar o caixa eletrônico, não é necessário conhecer como as operações foram implementadas em nível de programação, mas sim, o que cada operação afeta sua conta.

Na figura abaixo, consta classe **Conta**, com atributos e métodos para uma Conta Corrente, o método trasnferir recebe como parâmetro o número da conta (**numContaDistino**) e um valor a ser transferido (**valor**), para utilizar este método, o programador não precisa saber como o criador desta classe implementou o método trasnferir, basta  saber que este métrodo é responsável por enviar um valor a outra conta corrente e que esta transferência implica em subtração do saldo da conta remetente.

<img src = "Imagens/Encap.png">

&nbsp;

A figura acima está ilustrada em um diagrama de Clase UML, e o símbolo de coma (**+**) infica que tanto os atributos quanto os métodos são públicos, isso significa que eles podem ser acessados e modificados de qualquer outra classe do projeito (não é uma boa prática, de programação, uma vez que seus atributos estão expostos e qualquer outro objeto pode alterar os valores dos elementos das classes, o qe pode comprometer a coesão de seu projeto).

``Exemplo``:

~~~~Java
//Criação da referência a Conta
conta c = new Conta();
//Modificação do atributo saldo de forma direta
c.saldo = 0;
~~~~

Faz-se necessário, para solucionar este problema, a utilização de modificadores de acesso, sendo que estes farão o papel de restringir ou autorizar o acesso a determinados atributos ou método das classes.

&nbsp;

### **Modificadores de Acesso: *default*, *public*, *private* e *protected***

&nbsp;

É a aprtir dos modificadores de acesso que pode-se restringir ou não o acesso aos atributos e métodos de uma classe, **na programação Orientada a Objetos, os modificadores de acesso mais utilizados são o *public* e o *private***.

**É importante frisar alguns conceitos básicos sobre a programação em Java: Projetos e Pacotes do projeto**.

Um **Projeto** é a base para o desenvolvimento em Java, é nele que estarão todos os pacotes e classes da sua aplicação.

Um **Projeto** envolve **Pacotes e Bibliotecas** que, porventura, sua aplicação necessite utilizar.

Voltando sobre **Modificadores de Acesso, exitem quadro**: *public*, *private*, *protected* e *default*.

O modificador **default** não precisa ser declarado, ou seja, atributos ou métodos que não têm a declaração de um modificador de acesso são considerados **default** .

No exemplo abaixo, no pacote em que está localizada a classe criada, o atributo com modificador **default** pode ser acessado de forma direta por qualquer classe, agora, se a classe que instanciar a classe estiver em outro pacote, este não será acessível de forma direta:

~~~~Java
//Exemplo de atributo default
String exemploDefault;
~~~~

&nbsp;

Atributos e métodos **public** podem ser acessados e modificados de qualquer classe do projeto a partir da instância do objeto, ou seja, até de outros pacotes é possível ter acesso a atributos/métodos do tipo **public** de forma direta, para declarar este tipo de modificador, é necessário utilizar a palavra reservada **public** antes de inficar o tipo de variável, isto pode ser vericicado no exemplo abaixo:

~~~~Java
//Exemplo de atributo public
public int inteiroPublic;
//Exemplo de método public
public int soma(int a, int b){
    return a+b;
}
~~~~

&nbsp;

Atributos e métodos **private** são acessados somente pela própria classem independente do pacote em que a classe esteja, o código-fonte abaixo mostra como se pode criar um atributo **private**, métodos **private** só podem ser acessados pela própria calsse, ou seja, eles não são visíveis e nem acessados po outros objetos

~~~~Java
//Exemplo de atributo private
private String nomePrivate;
//Exemplo de método private
private String[] splitNome(String n){
    return n.split (" ");
}
~~~~

&nbsp;

Um modificador de acesso não tão comumente utilizado é o modificador **protected**, este tipo de modificador funciona como um modificador **public** para elementos que estão no mesmo pacote, e em outros pacotes ele só é visível para classes que herdam a classe que possui o atributo **protected**

~~~~Java
//Exemplo de atributo protected
protected String nomeCliente;
//Exemplo de método protected
protected String[] splitNome(String n){
    return n.split(" ");
}
~~~~

&nbsp;

``Tabela demonstrando resumo dos modificadores de acesso``:

<img src = "Imagens/Acess.png">

&nbsp;

## **Utilizando Modificadores de Acesso**

---

&nbsp;

Utilizando o exemplo doCaixa Eletrônico, vamos elucidar a utilização dos modificadores de acesso, além disso, trazer o conceito dos *getters* e *setters*.

<img src = "Imagens/Acess2.png">

Cada pacote tem suas classes que possuem suas particularidades, o pacote **caixaeletronico** possui a classe **CaixaEletronico** e esta é a classe inicial doprojeto, é nesta classe que se inicia a execução da aplicação, pois nela contêm o método **main**.

O pacote **cliente** possui classes quee struturam os objetos **Clientes** que poderão ser pessoa física (**Fisica**), ou jurídica (**Juridica**), além, de estruturar como será o formato do endereço de cada pessoa (**Endereco**).

No pacote **conta**, possui a classe **Conta** que armazena as informações de uma conta, abaixo diagrama geral do exemplo:

<img src = "Imagens/Acess3.png">

Em UML, o sinal de "**-**" significa que trata-se de um atributo/método que utiliza modificador de acesso **private**, o sinal "**+**" infica o modificador **public** e o sinal "**#**" indica o sinal de modificador **protected**.

As classes **Fisica** e **Juridica** se ligam à classe **Pessoa** com uma seta grande e vazia, esta ligação significa que **Fisica** e **Juridica** são "filas" de **Pessoa**, ou seja, herdam todas as propriedades da classe **Pessoa**.

Se houver restrições do acesso a alguns atributos das classes, basta criar métodos públicos que controlarão os acessos a estas variávei, ou seja, será criada uma interface de acesso para cada atributo **private** da classe em questão, é aí que entra o conceito de **getters** e **setters** na programação Orientada a Objetos e este é um mecanismo de acesso a dados encapsulados.

Para criar o método **setter**, primeiro faz-se necessário analisar o tipo do atributo, por exemplo, o atributo saldo da classe **Conta**; por se tratar de um atributo do tipo **float**, o método para setar este atributo deverá receber como parâmetro um elemento também **float**, como é um método que não terá retorno, então, utiliza-se o tipo de retorno como **void**, além disso, o padrão para métodos **setters** é sempre utilizar a palavra **set** e, em seguida, concatenar o nome da variável, no caso em exemplo, seria denominado **setSaldo**:

~~~~Java
//Método setSaldo – setter para o atributo saldo
public void setSaldo(float s){
this.saldo = s;
}
//Método setNumConta – setter para o atributo numConta
public void setNumConta(int n){
this.numConta = n;
}
~~~~

Agora é preciso utilizar o método para "resgatar" o valor deste atributo, a estes métodos chamamos de **getters** e a característica deste tipo de método é que ele retorna o valor do atributo para o elemento que o chamada, os métodos **get** são precedidos pela palavra **get** e o nome do atributo, e eles devem retornar elementos do mesmo tipo de atributo em questão.

~~~~Java
//Método  getSaldo – getter para o atributo saldo
public float getSaldo(){
return this.saldo;
}
//Método  getNumConta – getter para o atributo numConta
public int getNumConta(int n){
return this.numConta;
}
~~~~

Código para as outras variáveis:

~~~~Java
MODIFICADORES JAVA E ENCAPSULAMENTO
Reprodução proibida. Art. 184 do Código Penal e Lei 9.610 de 19 de fevereiro de 1998.
IV
package conta;
import cliente.Pessoa;
public class Conta {
    private float saldo;
    private Pessoa titular;
    private int numConta;
    private int tipoConta;

    public int getNumConta() {
    return numConta;
    }
    public void setNumConta(int numConta) {
    this.numConta = numConta;
    }
    public int getTipoConta() {
    return tipoConta;
    }
    public void setTipoConta(int tipoConta) {
    this.tipoConta = tipoConta;
    }
    public Pessoa getTitular() {
    return titular;
    }
    public void setTitular(Pessoa titular) {
    this.titular = titular;
    }
}
~~~~

&nbsp;

O Javap também permite a utilização de outros modificadores: ***static***, ***final*** e ***abstract***.

&nbsp;

## **O Modificador *Static***

---

&nbsp;

Pode ser aplicado av ariáveis e métodos,e a **principal característica dele é que se tratando de atributos, todo os objetos compartilham do mesmo espaço de memória, e se tratando de método, este pode ser acessado sem a necessidade de instância do objeto**.

Quando é criado uma aplicação Java, é criado p método "**public static void main(String[] args)**", o modificador de acesso **public** indica que este método pode ser visualizado de qualquer classe do projeto, o modificador **static** infica que para acessar o método da classe não é necessário instanciá-lo, e o que acontece é que métodos e variáveis **static** são alocadas em memória antes de qualquer objeto seja criado, por essa razão, um atributo não **static** da classe que não esteja no método **static** não pode ser acessado de forma direta, pois ele só existirá a partir da instância do objeto, por exemplo, no código a segui da classe Exemplo, tem duas variáveis, **int valor** e **static int valor2**, no do método **static**, ao tentar atribuir um inteiro à variável **valor**, a IDE irá acusar erro com os seguinte dizeres: **non-static variable valor cannot be referenced form a static context** - significa que a variável **não static valor** não pode ser referenciada em um contexto **static**.

~~~~Java
public class Exemplo{
    int valor;
    static int valor2;
    public static void main(String[] args){
        valor = 30;
        valor2 = 10;
    }
}
~~~~

Para resolver este erro, existem duas saídas: uma é transformar o atributo **valor** em **static**, a outra é criar um objeto (instância) do tipo **Exemploe  então acessar e modificar a vartiável **valor.

``Solução 1``:

~~~~Java
public class Exemplo{
    static int valor;
    static int valor2;
    public static void main(String[] args){
        valor = 30;
        valor2 = 10;
    }
}
~~~~

``Solução 2``:

~~~~Java
public class Exemplo{
    int valor;
    static int valor2;
    public static void main(String[] args){
        Exemplo e = new Exemplo();
        e.valor = 30;
        valor2 = 10;
    }
}
~~~~

Uma variável **static** é compartilhada em todas as instâncias de uma classe, ou seja, em vez de cada instância da classe ter uma cópia dessa variável, ela é uma única variável compartilhada por todas as instâncias.

Para a existência de uma variável **static** não é necessário a criação de uma instância da classe que contenha a variável, apenas é necessário que a classe seja carregada na **JVM** (Java Virtual Machine - Máquina Virtual Java), já que esta é criada e inicializada no momento de carga da clase.

``Exemplo``:

Imagine que haja um limite para realizar transferências entre contas e que este liimte seja igual para todas as contas, para resolver este problema, basta declarar o atributro **limiteTransferencia** como **static**, assim, o limite é alterado para todas as referências de conta.

<img src = "Imagens/Static.png">

&nbsp;

## **O Modificador *Final***

---

&nbsp;

**Ele restringe ainda mais o acesso aos elementos de uma classe, para atributos, ele faz com que o atributo não possa ser modificado em tempo de execução, ou seja, cria-se uma variável que terá um valor constante do inínio ao término da execução da aplicação, para classes, indica que esta não poderá ser herdada (não poderá ter filhos) e para métodos, infica que o mesmo não poderá ser sobrescrito (usar técnicas de polimorfismo)**.

As variáveis de instância do tipo **final** podem ser declaradas em conjunto com o modificador **static**, neste caso, se ele for declarado na inicialização da variável, o valor atribuído a ele será o mesmo para todos os objetos e não poderá ser modificado durante a execução do projeto, se uma variável **static final** não for inicializada, ocorrerá um erro de compilação.

``Exemplo``:

~~~~Java
public class Conta{
    ...
    private final static float LIMITETRANSFERENCIA = 3000;
    ...
}
~~~~

Métodos **final** não podem ser sobrescritos, ou seja, um método final em uma superclasse (classe pai) não pode ser reimplementado na subclasse (classe filha)

Os métodos **final** são implicitamente 88final88, porque não é possível sobrescrever em uma subclasse.

Uma classe **final** não pode ser superclasse, ou seja, não pode ter classes que herdam suas propriedades, portanto, quando uma classe é **Final**, implicitamente todos os métodos são **final**.

&nbsp;

## **O Modificador *Abstract***

---

&nbsp;

**Ele é aplicado somente a métodos e a classes, métodos abstract não fornecem implementações e em classes abstracts não é possível a criação de objetos da classe, e normalmente possuem um ou mais métodos abstracts**.

``Seu objetivo é fornecer uma superclasse apropriada a aprtir da qual outas classes podem herdar e assim poder compartilhar um design comum``.

``Exemplo``: criação da classe **Pessoa** como sendo uma classe **abstract** baseada no projeto do caixa eletr^nico, esta classe possui também um método **abstract** para cadastro, a declaração do método **abstract** "força" a programação do método nas subclasses.

~~~~Java
public abstract class Pessoa{
    protected String telefone;
    protected String nomePessoa;
    protected Endereco e =  new Endereco();
    //Método abstract para cadastro de pessoa
    public abstract void cadastra().
    public Endereco getE() {...}
    public void setE(Endereco e) {...}
    public String getNomePessoa() {...}
    public void setNomePessoa(String nomePessoa) {...}
    public String getTelefone() {...}
    public void setTelefone(String telefone) {...}
}
~~~~

O código acima, mostra a "tentativa" de criação de um objeto de uma classe **abstract**, no caso, apareceria uma mensagem do IDE de que uma classe **abastract** não pode ser instanciada:

~~~~Java
import cliente.Pessoa;

public class CaixaEletronico{
    public static void main(String[] args){
        Pessoa p = new Pessoa(); //Iria aparecer o detalhe do erro aqui em Pessoa()
    }
}
~~~~


Abaixo a criação de uma sibclasse para a classe Pessoa, o método cadastra precisou ser implementado na classe Fisica:

~~~~Java
public class Fisica extends Pessoa{

    private String cpf;

    //Implementação do método abstract é imprescindível
    @override
    public void cadastra(){
        //Leitura via teclado
        Scanner tec = new Scanner(System.in);
        System.out.println("Digite o nome");
        nomePessoa = tec.nextLine();
        System.out.println("Digite o telefone");
        telefonea = tec.nextLine();
        System.out.println("Digite o cpf");
        cpf = tec.nextLine();
        e.cadastra();
    }
}
~~~~

&nbsp;

## **Construtores Java**

---

&nbsp;

Um **Construtor não é um método, pois este não possui a declaração de retorno, mas toda classe em Java tem pelo menos um construtor, exceto interfaces.

**Um Construtor é o primeiro "método" que é executado sempre que uma classe é instanciada, quando se utiliza a palavra chave new, o construtor será executado e inicializará o objeto**, existem classes que quando inicializadas requerem algum tipo de parâmetro, por exemplo, objetos do tipo **Scanner** (para realizar a leitura de informações para o projeto):

~~~~Java
Scanner tec = new Scanner(System.in);
~~~~

&nbsp;

``Quando é feito isso, estará inicializando a classe com os dados parâmetros, o Construtor inicializa as variaveis de instância da classe, como também executa códigos necessários para a inicialização de uma classe, em outras palavras, no Construtor pode-se determinar o que será realizado assim que seu objeto for instanciado``.

``Exemplo``:

~~~~Java
public abstract class Pessoa {
    protected String telefone;
    protected String nomePessoa;
    protected Endereco e = new Endereco();

    public Pessoa(){
    super();
    System.out.println(“Executando o construtor de Pessoa”);
    }
    ...//Outros métodos da classe
}
~~~~


**O Construtor é similar a um método, mas ele não tem um tipo de retorno, nem void, outro fato importante, um Construtor sempre terá o mesmo nome da classe**.

Modificadores de acesso pdoem ser atribuídos aos Construtores, inclusive o **private**, ``se o Construtor não for criado junto ao código-fonte da classe, o compilador criará automaticamente um coinstrutor para a Classe``.

Quando uma classe é instanciada, o método **super()** dela é chamado, mesmo que não seja declarado, pois em algum momento a classe terá que ser inicializada.

Todas as classes em Java são filas da classe **Object**, ou seja, **Object** é a mãe de todas as classes (ela fornece métodos como **equal** e **toString**, por exemplo).

Ainda utilizando o exemplo do Caixa Eletrônico, onde objetos do tipo **Fisica** são filhos da classe **Pessoa**, quando criar uma instância de **Fisica** os Construtores são executados em forma de pilha: **Fisica** chama **Pessoa**,, que chama **Object**, ou seja, o Construtor de **Fisica** só será executado por último:

~~~~Java
public class Fisica extends Pessoa{
    private String cpf;
    public Fisica(){
    System.out.println(“Pessoa Fisica”);
    }
}
~~~~

&nbsp;

~~~~Java
public class CaixaEletronico {
    public static void main(String[] args) {
    Fisica f = new Fisica();
    }
}
~~~~

Ao realizar a instância da classe **Fisica**, o construtor da classe **Pessoa também foi acionado.

**Uma classe pode possuir mais de um Construtor, para isso, é preciso criar Construtores com argumentos diferentes, desta forma, criam-se diversas formas de inicializar um objeto**.

``Exemplo``: na classe **Fisica**, passando como parâmetro no momento da inicialização da classe o nome do titular da conta:

~~~~Java
public class Fisica extends Pessoa{
    private String cpf;
    public Fisica(){
    System.out.println(“Pessoa Fisica”);
    }
    public Fisica(String nome){
    nomePessoa = nome;
    }
}
~~~~

~~~~Java
public class CaixaEletronico {
    public static void main(String[] args) {
    Fisica f = new Fisica();
    Fisica f2 = new Fisica(“Joaquim”);
    System.out.println(f2.getNomePessoa());
    }
}
~~~~

**Não há limits para a criação de Construtores, apenas deve haver diferenciação nos parâmetros, por exemplo, se um Construtor requer uma única String, então não se pode criar outro Construtor solicitando uma String, por mais que sejam variáveis diferentes, porém, se for um Construtor solicitando uma String e outro solicitando duas Strings, é possível, ou seja, o tipo do parâmetro e o número de parâmetros serão os determinantes para que o compilador saiba qual Construtor deva ser chamado**.

``Um ponto importante, é que enquanto o Construtor não for executado, nenhuma acesso à variável de instância ou método será possível, isto quer dizer que um objeto não pode ser utilizado até ser inicializado, o que é obvio, mas também significa que você não pode tentar sabotar o Construtor do objeto antes de chamar super()``:

~~~~Java
public class Fisica extends Pessoa{
    private String cpf;
    public Fisica(){
    System.out.println(“Pessoa Fisica”);
    }
    public Fisica(String nome){
    nomePessoa = nome;
    super();
    }
}
~~~~

A chamada de **super()** no Construtor da classe **Fisica** retorna um erro de compilação, onde será mostrado ao programador uma mensagem de que a chamada ao COnstrutor de super() deve ser a primeira sentença no Construtor.


