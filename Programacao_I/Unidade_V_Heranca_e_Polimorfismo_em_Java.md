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

Em Orientação a Objetos, polimorfismo **é a capacidade pela qual duas ou mais classes derivadas de uma mesma superclasse podem invocar métodos que têm a mesma identificação, assinatura (o mesmo nome de método), mas que possuem comportamentos distintos (de acordo com a forma de implementação em cada subclasse)**.

``Em Java, o conceito de Polimorfismo se manifesta apenas nas chamadas dos métodos``.

A possibilidade de Polimorfismo se dá pelo fato de que métodos podem ser sobrescritos pelas subclasses (métodos com o mesmo nome e números de argumentos), ou seja, se o método da superclasse não é suficiente, ou não se aplica à classe filha, ele pode ser escrito novamente tendo um comportamento completamente diferente do da superclasse.

**O interpretador Java se encarrega de chamar corretamente o método a ser executado em tempo de execução**, existe ainda, um mecanismo de sobrecarga, onde dois métodos de uma classe podem ter o mesmo no,e porém, com asinaturas diferentes (tipos de retornos ou tipos de argumentos diferentes), entretanto, esta sobrecarga não recebe o nome de polimorfismo.

``Em Java, todas as determinações de métodos a executar ocorrem por meio de ligação tardia (ocorrência em tempo de execução) exceto em dois casos``: métodos **final**, que não podem ser redefinidos, e métodos **private**, que também não podem ser redefinidos e , portanto, possuem as mesmas características de métodos **final**.

Para que o polimorfismo seja implementado da maneira correta, é necessário que os métodos tenham exatamente a mesma identificação, sendo utilizado o mecanismo de redefinição de métodos, que é o mesmo que sobrescrita (***Override***) de métodos em classes derivadas, a redefinição ocorre quando um método cuja asssinatura já tenha sido especificada recebe uma nova definição, ou seja, um novo corpo em umc classe derivada.

``É importante observar que, quando o polimorfismo está sendo utilizado, o comportamento que será adotado por um método só será definido durante a execução``, embora em geral, esse seja um mecanismo que facilite o desenvolvimento e a compreensão do código orientado a objetos, há algumas situações onde o resultado da execução pode ser não intuitivo.

Utilizando o método **cadastra**, que está presente nas três classes do exemplo do caixa eletrônico (**Pessoa**, **Fisica** e **Juridica**) e acrescentar a implementação do método **imprime** nestas classes, o código abaixo, inficará a classe **abstract Pessoa**, que possui atributos **protected** (podem ser visualizados por seus herdeiros) e métodos de **cadastrar()** e **imprime()** implementados.

~~~~Java
public abstract class Pessoa{
    protected String telefone;
    protected String nomePessoa;
    protected Endereco e = new Endereco();
    public void cadastra(){
        Scanner tec = new Scanner(System.in);
        System.out.println("Digite o nome");
        nomePessoa = tec.nextLine();
        System.ou.println("Digite o telefone");
        telefone = tec.nextLine();
        e.cadastra();
    }
    public void imprime(){
        System.out.println("Nome: " + getNomePessoa());
    }
    //Getters e Setters
    public Endereco getE() {...}
    public void setE(Endereco e) {...}
    public String getNomePessoa() {...}
    public void setNomePessoa(String nomePessoa) {...}
    public String getTelefone() {...}
    public void setTelefone(String telefone) {...}
}
~~~~

Temos no código abaixo, a implementação da subclasse **Fisica**, que conta com a implementação do método c**adastra()** e **imprime()**, pode-se notar que antes da assinatura dos métodos, existe uma anotação indicando que o método está sobrescrevendo outro, caso haja necessidade de utilização do método da superclasse, é necessário incolá-lo como acontece na linha "**super.cadastra()**", desta forma, o método da classe Pai também será executado.

~~~~Java
package cliente;

importa java.util.Scanner;

public class Fisica extends Pessoa{

    private String cpf;

    //Sobrescrita do método cadastra
    @Override
    public void cadastra(){
        System.out.println("----Cadastro de Pessoa Física");
        super.cadastra();
        Scanner tec = new Scanner(System.in);
        System.out.println("Digite o cpf");
        cpf = tec.nextLine();
    }
    @Override
    public void imprime(){
        System.out.println("Pessoa Física!");
        super.imprime();
        Sustem.ou.println("CPF: " + cpf);
    }
}
~~~~

A implementação da classe **Juridica** é análoga à implementação da classe **Fisica**, o que difere são as mensagens que serão apresentadas ao usuário do aplicativo, e atributo CNPJ existente somente na classe **Juridico**

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
    @Override
    public void imprime(){
        System.out.println("Pessoa Jurídica!");
        super.imprime();
        Sustem.ou.println("CNPJ: " + cnpj);
    }
}
~~~~

Implementando as classes filhas e os métodos sobrescritos, criou-se um método principal para manipular os objetos do tipo **Pessoa**, dando a opção para que o usuário do aplicativo seleciona qual o tipo de **Pessoa** que deseja cadastrar.

O método **cadastra** no código abaixo é chamado apenas uma vez, isto é possível pois como as subclasses sobrescrevem um método da superclasse, este método pode ter comportamento diferente de acordo com o objeto de origem, e isto é polimorfismo.


~~~~Java
public class CaixaEletronico{
    static Pessoa p[] = new Pessoa[10];
    public static int ultimo = 0;
    public static void main(String[] args){
        Scanner tec = new Scanner)System.in);
        int opcao = 0;
        while(opcao != 4)`+
        System.out.println("Digite: ");
        System.out.println("1 - Cadastrar Pessoa Física");
        System.out.println("2 - Cadastrar Pessoa Jurídica");
        System.out.println("3 - Imprimir clientes");
        System.out.println("4 - Sair");
        opcao = tec.nextInt();
        tec.nextLine();
        switch(opcao){
            case 1: 
                p[ultimo] = new Fisica();
                break;
            case 2: 
                p[ultimo] = new Juridica();
                break;
            case 3: 
                imprime();
                break;
            case 1: 
                System.ou.println("Sair...");
                break;
            default: 
                System.ou.println("Valor invaálido");
                break;                
        }
        if(opcao == 1 || opcao == 2){
            p[ultimo].cadastra();
            ultimo++;
        }
    }
}
~~~~

Outro exemplo de polimorfismo no exemplo em questão, é com o método de **impressão**, como todas as classes filhas também sobrescrevem o método **imprime** da Superclasse, ele pode ser chamado, que se comportará de acordo com o objeto de origem.

**Caso não houver sobrescrita do método, o compilador invoca o método de classe Pai e executa-o**.

&nbsp;

## **Estudo de Caso - Animais**

---

&nbsp;

Os animais do zoológico da cidade de São Paulo precisam ser catalogados pela idade e nome e o zoológico precisa que, além disso, fossem catalogadas as formas de se locomover do animal, assim como o som que eles emitem, pois a ideia do zoológico é transformar este software em algo que possa mostrar para os visitantes algumas curiosidades sobre os animais que ali vivem.

A utilizaçãode técnicas de polimorfismo e herança são imprescindíveis para que o projeto possa ser expandido futuramente, além de auxiliar no processo de manutenção.

Consta classe **abstract** chamada **Animal**, e nela constam as informações principais solicitadas pelo zoológico para a catalogação.

As classes **Cachorro**, **Cavalo** e **Preguiça**, que herdam as propriedades de Animal e implementam os métodos abstratos.

No código abaixo, a classe **Animal** foi criada como uma classe **abstract**, pois “**Animal**” é uma abordagem geral e precisa ser especificada, esta classe possui dois atributos, **nome** e **idade** do animal, além dos métodos **abstracts** **seLocomove()** e **emiteSom()**, que deverão, obrigatoriamente, serem implementados nas classes que herdarem a classe **Animal**.

~~~~Java
package animal;
    abstract public class Animal {
    private String nome;
    private int idade;
    abstract public void seLocomove();
    abstract public void emiteSom();
    public int getIdade() {
    return idade;
    }
    public void setIdade(int idade) {
    this.idade = idade;
    }
    public String getNome() {
    return nome;
    }
    public void setNome(String nome) {
    this.nome = nome;
    }
}
~~~~

&nbsp;

A Classe **Cachorro** herda todos os atributos e métodos da classe **Animal**, e é obrigada a implementar os métodos **seLocomove()** e **emiteSom()**, ainda na classe classe **Cachorro** possui um **Construtor** que recebe como parâmetro o **nome** e a **idade** do Animal.

~~~~Java
package animal;
public class Cachorro extends Animal{
    public Cachorro(String nome, int id ){
    super.setNome(nome);
    super.setIdade(id);
    }
    @Override
    public void seLocomove() {
    System.out.println(“Cachorro: “+super.getNome());
    System.out.println(“Idade: “+super.getIdade());
    System.out.println(“Cachorro correndo, com suas 4 patas”);
    }
    //
    @Override
    public void emiteSom() {
    System.out.println(“Au Au !”);
}
~~~~

&nbsp;

A Classe **Cavalo**, assim como a Classe **Cachorro**, herda todos os atributos e métodos da classe **Animal** e é obrigada a implementar os métodos **seLocomove()** e **emiteSom()**, porém, a implementação difere da classe **Cachorro**, o que resulta em um comportamento diferente, isto é o polimorfismo dos métodos **seLocomove()** e **emiteSom()**.

~~~~Java
package animal;
public class Cavalo extends Animal {
    public Cavalo(String nome, int id ){
    super.setNome(nome);
    super.setIdade(id);
    }
    @Override
    public void seLocomove() {
    System.out.println(“Cavalo: “+super.getNome());
    System.out.println(“Idade: “+super.getIdade());
    System.out.println(“Cavalga, Marcha, Trota”);
    }
    //
    @Override
    public void emiteSom() {
    System.out.println(“Nhiiiiiiiiiiii ri ri rin !”);
    }
}
~~~~

&nbsp;

Abaixo a implementação da classe **Preguica**, seguindo os padrões de implementação dos outros animais. 

~~~~Java
package animal;
public class Preguica extends Animal{
    public Preguica(String nome, int id ){
    super.setNome(nome);
    super.setIdade(id);
    }
    @Override
    public void seLocomove() {
    System.out.println(“Preguiça: “+super.getNome());
    System.out.println(“Idade: “+super.getIdade());
    System.out.println(“Subindo na Árvore”);
    }
    @Override
    public void emiteSom() {
    System.out.println(“GRRRRRRRrrrrrr”);
    }
}
~~~~

&nbsp;

Abaixo a implementação da classe principal, que cria e manipula o vetor **animais**, no código de criação do vetor criam-se ponteiros para cada **Animal**, mas ainda não se sabe qual animal será colocado em cada posição, quem vai determinar o tipo do animal é o usuário, de acordo com a ordem de inserção por meio do método **cadastraAnimal()**.

Este método questiona ao usuário qual o tipo de animal será armazenado, sendo que, o método fica encarregado de criar o objeto do animal desejado, depois de cadastrado, é possível verificar que animal ocupa cada posição do vetor por meio do método **imprimeAnimais()**.

~~~~Java
import java.util.Scanner;
public class AnimalPrincipal {
    Animal vetAni[] = new Animal[30];
    static int tam=0;
    public static void main(String[] args) {
        // TODO code application logic here
        int opcao=0;
        Scanner scan = new Scanner(System.in);
        AnimalPrincipal ap = new AnimalPrincipal();
        while(opcao!=3){
            System.out.println(“Digite a opcao desejada:”);
            System.out.println(“1 - Cadastrar”);
            System.out.println(“2 - Listar”);
            System.out.println(“3 - Sair”);
            opcao = scan.nextInt();
            scan.nextLine();
            switch(opcao){
                case 1: 
                    ap.cadastraAnimal();
                    break;
                case 2: 
                    ap.imprimeAnimais();
                    break;
                case 3: 
                    System.out.println(“Saindo...”);
                    break;
                default:
                    System.out.println(“Opção inválida”);
                    break;
            }
        }
}
public void cadastraAnimal(){
    Scanner scan = new Scanner(System.in);
    System.out.println(“Digite o tipo de animal:”);
    System.out.println(“1 - Cachorro”);
    System.out.println(“2 - Cavalo”);
    System.out.println(“3 - Preguica”);
    int i = scan.nextInt();
    scan.nextLine();
    if (i==1 || i==3 || i==2){
        System.out.println("Digite o nome do animal");
        String n = scan.nextLine();
        System.out.println("Digite a idade do animal");
        int id = scan.nextInt();
        scan.nextLine();
        if (i==1){
            vetAni[tam]= new Cachorro(n,id);
        }else if(i==2){
            vetAni[tam]= new Cavalo(n,id);
        }else if(i==3){
            vetAni[tam]= new Preguica(n,id);
            tam++;
        }    
    }
    public void imprimeAnimais(){
    Scanner scan = new Scanner(System.in);
    for (int i=0;i<tam;i++){
        System.out.println("Codigo do Animal: "+i);
        vetAni[i].seLocomove();
    }
    System.out.println("Digite o codigo do animal que deseja
    ver");
    int cod = scan.nextInt();
    vetAni[cod].seLocomove();
    vetAni[cod].emiteSom();
    }
}
~~~~

&nbsp;

## **Sobreposição ou Reescrita de Métodos**

---

&nbsp;

Continuar da pag. 150...