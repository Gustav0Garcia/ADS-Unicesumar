# **Anotações Programação I - Unidade V**

&nbsp;

## **Herança**

---

&nbsp;

A **Herança** permite a criação de novas classes (subclasses) a partir de classes já existentes (superclasses), "herdando" características existentes na classe a ser estendida, essa técnica implica em grande reaproveitamento de código existente, uma vez que não há necessidade de reimplementação de métodos que já foram criadaos nas superclasses.

Referente a Superclasses e Subclasses, pode-se dizer que Subclasses são especializações de Superclasses que, por sua vez, são generalizações de Subclasses, em outras palavras, Subclasses são mais especializadas do que as suas Superclasses, mais genéricas.

As Subclasses herdam todas as características de suas Superclasses, como suas variáveis e métodos.

O Java permite o uso de herança simples, mas não permite a implementação de herança múltipla, que significa que uma classe pode herdar métodos atributos de mais de uma classe, para superar essa limitação, o Joava faz uso de interfaces.

No Java, a palavra reservada que define que uma classe herda as caracterísicas de outra e **extends**, e deve ser utilizada assim que a classe for criada

``Exemplo``:

~~~~Java
public class Peixe {
    //Atributos
    private String tipoPele;
    private int numDentes;
    //Métodos
    public void nadar(){
    System.out.println(“Mecher as barbatanas”);
    }
    public void comer(){
    System.out.println(“Procurar comida e comer”);
    }
}
~~~~

&nbsp;

~~~~Java
public class PeixePalhaco extends Peixe{
    //Implementação da classe peixe palhaco
    private int numeroListras;
}
~~~~

A classe **PeixePalhaco** herda todos os atributos e métodos da classe **Peixe**, mas com a diferença de possuir um atributo a mais, "**numeroListras**", que é uma especialidade do peixe-palhaço em relação a outros tipos de peixe.

Agora, será criado uma classe principal que cria uma instância de peixe-palhaço e chama um de seus métodos:

~~~~Java
public class Principal
    public static void main(String[] args){
    PeixePalhaco pp = new PeixePalhaco();
    pp.nadar();
    PP.comer();
    }
}
~~~~

O código acima irá reproduzir:

    Mexer basbatanas
    Procurar comida e comer

Os métodos **nadar** e **comer** não foram implementados na classe **PeixePalaco**, somente na classe **Peixe**, como **PeixeiPalhaco** é uma subclasse de **Peixe**, então os métodos da classe **Peixe** serão herdados automcaticamente a objetos do tipo **PeixePalhaco**.

Retornando ao exemplo do Caixa eletrônico, abaixo um diagrama ilustrando o projeto como um todo:

<img src = "Imagens/Heranca.png">

Existem dois tipos de pessoas: pessoa **Fisica** e **Juridica**, pode-se projetar os objetos como a classe *Pessoa** sendo a superclasse e as classes **Fisica** e **Juridica** como sendo subclasses, além disso, pode-se criar a classe **Pessoa** como sendo abstrata, já que "**Pessoa**" não se refere a ninguém especificamente, spo de forma genérica, teremos o seguinte código para cada classe:

~~~~Java
package cliente;

importa java.util.Scanner;

public abstract class Pessoa{
    protected String telefone;
    protected String nomePessoa;
    protected Endereco e =  new Endereco();
    //Métodos
    public abstract void cadastra().
    //Getters e Setters
    public Endereco getE() {...}
    public void setE(Endereco e) {...}
    public String getNomePessoa() {...}
    public void setNomePessoa(String nomePessoa) {...}
    public String getTelefone() {...}
    public void setTelefone(String telefone) {...}
}
~~~~

&nbsp;

~~~~Java
package cliente;

importa java.util.Scanner;

public class Fisica extends Pessoa{

    private String cpf;

    //Sobrescrita do método cadastra
    @override
    public void cadastra(){
        System.out.println("----Cadastro de Pessoa Física");
        super.cadastra();
        Scanner tec = new Scanner(System.in);
        System.out.println("Digite o cpf");
        cpf = tec.nextLine();
    }
}
~~~~

&nbsp;

~~~~Java
package cliente;

importa java.util.Scanner;

public class Juridica extends Pessoa{

    private String cnpj;

    @override
    public void cadastra(){
        System.out.println("----Cadastro de Pessoa Jurídica");
        super.cadastra();
        Scanner tec = new Scanner(System.in);
        System.out.println("Digite o cnpj");
        cnpj = tec.nextLine();
    }
}
~~~~

No momento de declarações das classes **Fisica** e **Juridica** existe a palavra reservada **extends**, e é esta palavra que infica se uma classe é ou não subclasse de outra, neste momento, todos os atributos e métodos implementados na classe **Pessoa** vão automaticamente fazer parte das classes **Filhas**, os atributos da classe **Pessoa**, estão inficados com o modificador de acesso **protected**,isto quer dizer, que as classes filhas de **Pessoa** terão acesso a estes atributos de forma direta.

Além dos atributos, as classes também possuem os métodos implementados na classe **Pessoa**.

Quando precisar "chamar" algum método que faz parte da superclasse **Pessoa**, é necessário utilizar a palavra reservada **super**, que irá dar acesso aos métodos e atributos da classe pai, além disso, quando for criado uma instância de **Fisica**, poderá também ter acesso a todos os métodos da classe **Pessoa**.

O mecanismo de **Herança** fornece um benefício notável no desenvolvimento de aplicações, ao concentrar caracterísicas comuns em uma classe e derivar as classes mais específicas a partir desta, estará preparado para a adição de novas funcionalidades ao sistema, se mais adiante uma nova propriedade comum tiver que ser adicionada, não será preciso efetuar alterações em todas as classes, basta alterar a superclasse e todas as outras classes derivadas serão automaticamente atualizadas.

&nbsp;

## **Polimorfismo**

---

&nbsp;

Continuar da pag 138