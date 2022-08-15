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

Continuar pag 115...

