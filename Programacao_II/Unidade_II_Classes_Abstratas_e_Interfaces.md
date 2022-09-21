# **Anotações Programação I - Unidade II**

&nbsp;

## **O que é Classe Abstrata?**

---

&nbsp;

É desenvolvida para representar classes e conceitos abstratos, ``é sempre uma superclasse que não permite que nenhum objeto seja criado a partir dela, ou seja, não pode ser estanciada``.

O uso das classes abstratas é dirigido para a construção de classes que constituirão um modelo, ou seja, **classes abstratas servirão como especificações básicas de novas classes, que serão implementadas por meio do mecanismo de herança**. **Assim, uma classe abstrata devce ser estendida, ou seja, deve ser a classe-base de outra, mais específico, que contenha os detalhes que não puderam ser incluídos na superclasse (abstrata)**.

~~~~Java
public abstract class ClasseAbstrata{

}
~~~~

&nbsp;

Métodos abstratados são declarados com o modificador **abstract**, se uma classe tiver algum método abstrato, a classe também deverá obrigatóriamente ser declarada com o modificador **abstract**, os métodos de uma classe abstrata classificados como abstratos devem sempre terminar com ; (ponto e vírgula) e a classe que a estender deverá implementá-los.

~~~~Java
public abstract class ClasseAbstrata{

    public abstract void metodoAbstrato(String parametros);

}
~~~~

&nbsp;

Os métodos acima não têm uma implementação, isto é, não possuem um corpo delimitado por chaves contendo qualquer código.

Uma classe também pode ser declaradas abstrata mesmo que tenha um método não abstrato, ou a combinação de método abstratos e não abstratos.

~~~~Java
public abstract class ClasseAbstrata{

    public abstract void metodoAbstrato(String parametros);

    public void metodoConcreto(){

    }
}
~~~~

&nbsp;

**Como geralmente as classes abstratas pertencem ao nível superior de uma hierarquia de classes, recomenda-se que contenham tanto código quanto for possível, deixando para suas subclasses apenas as implementações específicas dos métodos abstratos**.

``Uma classe abstrata que herda de outra classe abstrata não precisará fornecer implementação de todos os métodos abstratos herdados``.

&nbsp;

## **Modelando um Projeto com Classes Abstratas**

---

&nbsp;

Será implementado um sistema de locadora de DVDs e CDs utilizadnos os mais variados recursos que as classes abstratas oferecem.

``É importante observar que o uso do conceito de classes abstratas precisa ser modelado nas atividades de análise e design do projeto, caso contrário, se for usado a técnica de codificação direta, talvez nunca apareça a necessidade de usar esse conceito``.

<img src = "Imagens/Abs.png">

A figura acima demonstra a modelagem, uma árvore de herança com uma classe abstrata (**ItemAbstrato**) e duas concretas (**Dvd** e **Cd**).

&nbsp;

## **Implementando um Projeto com Classes Abstratas**

---

&nbsp;

### **Criando a Classe Abstrata ItemAbstrato**

&nbsp;

Será criado um projeto chamado locadora-Abstrata, sendo desmarcado o campo **Criar Classe principal** e criando uma classe nova com o nome **ItemAbstrato** e colocando como nome do pacote **locadora**

Agorantendo a classe, deve ser inserido a palavra **abstract** antes de **class ItemAbstrato** e também os seguintes atributos e método abstratos abaixo

~~~~Java
public aabstract class ItemAbstrato{

    private int codigo;
    private String titulo;
    private String dataEmprestimo;
    private String dataDevolucao;
    private String situacaoItem; //L - Livre ; E - Emprestado

    public abstract void cadastrar();
    public abstract void emprestar();
    public abstract void devolver();

}
~~~~

A classe **ItemAbstrato** apresenta a definição de uma classe abstrata que representa um item de uma locadora, nessa classe é definido atributos e métodos comuns a um DVD, CD, como a intenção é analisar o comportamento de classes abstratas não será implementado todos os atributos e objetos que poderiam existir em uma locadora real, mas sim o elementar para compreender quanto deve usar classes abstratas.

&nbsp;

### **Criando a Classe Dvd que Herdará a Classe ItemAbstrato**

&nbsp;

Agora será criado uma classe chamada **Dvd** que irá herdar a classe **ItemAbstrato**, para isso basta acrescentar a palavra-chave **extends** e logo após o nome da classe que deseja herdar os métodos e atributos, no caso, **ItemAbstrato**.

~~~~Java
public class Dvd extends ItemAbstrato{

}
~~~~

Possivelmente poderá haver uma marcação no nome da classe Dvd, indicando que deve implementar os métodos da classe pai, **IntemAbstrato**, para isso deve posicionar o ponteiro do moise sobre o nome da classe e precionar as teclas **alt + enter** para abrir o menu que implementará todos os métodos automaticamente ou pode utilizar **alt + insert** e selecionar quais métodos deseja implementar, lembrando que uma classe não é obrigada a implementar todos os métodos abstratos da classe pai.

Após gerar os métodos da classe **Dvd**, ficará da seguinte forma:

~~~~Java
public class Dvd extends ItemAbstrato{

    @override
    public void cadastrar(){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @override
    public void emprestar(){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @override
    public void devolver(){
        throw new UnsupportedOperationException("Not supported yet.");
    }   

}
~~~~

Foi gerado todos os métodos abstratos da classe **ItemAbstrato**, caso a IDE gere automaticamente um código para cada método, basta ignorá-los deletando ou apenas comentando. Foram também gerados uma anotação acima dos métodos: @Override. Embora não seja necessário usar esta anotação, é recomendado que use, pois terá a vantagem do compilador verificar algum erro de ortografia e/ou erro na combinação dos parâmetros no método da classe pai e também tornará seu código mais fácil de ser compreendido.

Agora é necessário implementar o código de cadas método, como o objetivo é o estudo das classes abstratas, será simplificado o código.

~~~~Java
public class Dvd extends ItemAbstrato{
    SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    //Construtor padrão
    public Dvd(){

    }

    @Override
    public void cadastrar(){
        setCodigo(1);
        setTitulo("Senhor dos Aneis");
        setSituacaoItem("L");

        System.out.println("DVD Cadastrado: " + " - Cod: " + getCodigo()+ " - Titulo: " + getTitulo() + " - Situação: " + getSituacaoItem());
        System.out.println("DVD Cadastrado utilizadno método abstrato " + "Herdado da classe abstrata ItemAbstrato");
    }

    @Override
    public void emprestar(){
        setSituacaoItem("E");
        setDataEmprestimo(sdf.format(new Date()));

        System.out.println("DVD Emprestado: " + " - Situação: " + getSituacaoItem() + " - Data Emprestimo: " + thisgetDataEmprestimo());
        System.out.println("DVD Emprestado utilizadno método abstrato " + "Herdado da classe abstrata ItemAbstrato");
    }

    @Override
    public void devolver(){
        setSituacaoItem("E");
        setDataEmprestimo(sdf.format(new Date()));

        System.out.println("DVD Devolvido: " + " - Situação: " + getSituacaoItem() + " - Data Devolução: " + thisgetDataDevolucao());
        System.out.println("DVD Devolvido utilizadno método abstrato " + "Herdado da classe abstrata ItemAbstrato");
    }

    public void imprimir(){
        System.out.println("Imprimir Lista de DVDs utilizando método" + "concreto da classe Dvd");
    }

    public static Dvd getInstance(){
        return new Dvd();
    }

}
~~~~

&nbsp;

Acima foi utilizado todos os atributos da classe **ItemAbstrato** e também implementado mais dois novos métodos concretos na classe **Dvd**: (**imprimir()** e **getInstance()**).

O método estático **getInstance()** retorna uma instância da classe **Dvd** que será utilizada na classe principal.

&nbsp;

### **Criando a Classe Cd que Herdará a classe Dvd**

&nbsp;

Criando a classe Cds, será estendida a classe Dvd.

~~~~Java
public class Cds extends Dvd{

}
~~~~

Provavelmente a IDE não destacou o nome da classe, forçando a implementação dos métodos da classe herdada, pois a classe herdada não é uma classe abstrata, porém, como a classe **Dvd** herda diretamente da classe abstrata, a classe **Cds** passa a poder reutilizar todos os atributos e métodos da classe **ItemAbstrato** e **Dvd**, como também definir suas particularidades e usá-las.

~~~~Java
public class Cds extends Dvd{

    @Override
    public void cadastrar(){
        setCodigo(1);
        setTitulo("The Best of Joy Division");
        setSituacaoItem("L");

        System.out.println("CD Cadastrado: " + " - Cod: " + getCodigo()+ " - Titulo: " + getTitulo() + " - Situação: " + getSituacaoItem());
        System.out.println("CD Cadastrado utilizadno método abstrato " + "Herdado da classe abstrata ItemAbstrato");
    }

    @Override
    public void imprimir(){
        System.out.println("Imprimir Lista de CDs utilizando método" + "concreto da classe Dvds");
    }

    public void vender(){
        System.out.println("CD Vendido utilizando método " + "concreto da classe Cds");
    }

    public static Cds getInstance(){
        return new Cds();
    }
}
~~~~

Está sendo utilizado métodos da classe **ItemAbstrato** e também da classe **Dvd**, além, de escrever método exclusivos da classe **Cds**, como, método **vender()** e **getInstance()**, a classe **Cds** herda esses métodos, pois eles são públicos e concretos.

&nbsp;

## **Regras Sobre Classes e Métodos Abstratos**

---

&nbsp;

Regras de classe e métodos abstratos:

* Os métodos construtores não podem ser declarados como abstratos. Mesmo que a classe abstrata não possa ser instanciada, seus construtores podem inicializar os campos da classe que serão usados por subclasses, sendo imprescindível em praticamente todos os casos.

* Métodos declarados como abstratos não pode sem privados (**private**).

* Classes abstratas não podem contem métodos estáticos (**static**).

* Os campos de uma classe abstrata serão herdados pelas classes descendentes e poderão ser usados por intâncias destas a não ser que sejam declarados como **private**.

&nbsp;

### **Criando a Classe Programa para Executar o Sistema**

&nbsp;

Para finalizar o sistema, será criado uma classe com o método **main** chamada **Programa, e nela será criado um menu e um método de escolha para que possa ser chamado todos os métodos implementados.

~~~~Java
public class Programa{
    
    public static void main (String[] args){
        int opcao;
        Dvd dvd;
        Cds cds;

        while(true){
            System.out.println(" ");
            System.out.println(" ----------------------------- ");
            System.out.println("Digite 0 para SAIR ou a opcao abaixo:");
            System.out.println("1 - Cadastrar DVD    " + " 2 - Emprestar DVD    " + " 3 - Devolver DVD    ");
            System.out.println("4 - Cadastrar CDs    " + " 5 - Vender CD    " + " 6 - Imprimir CDs");
            System.out.println("Opcao: ");

            Scanner scan = new Scanner(System.in);
            opcao = scan.nextInt();
            System.out.println(" ----------------------------- ");
            System.out.println(" ");

            if(opcao == 0){
                System.exit(0);
            }
            switch(opcao){
                case 1:
                    dvd = DVD.getInstance();
                    dvd.cadastrar();
                    break;
                case 2:
                    dvd = Dvd.getInstance();
                    dvd.emprestar();
                    break;
                case 3:
                    dvd = Dvd.getInstance();
                    dvd.devolver();
                    break;
                case 4:
                    cds = Cds.getInstance();
                    cds.cadastrar();
                    break;
                case 5:
                    cds = Cds.getInstance();
                    cds.vender();
                    break;
                case 6:
                    cds = Cds.getInstance();
                    cds.imprimir();
                    break;
            }
        }
    }
}
~~~~

&nbsp;

## **O que são Interfaces?**

---

&nbsp;

Interface é um recurso da orientação a objeto utilizado em Java que define ações que devem ser obrigatoriamente executadas, mas que cada classe pode executar de forma diferente.

Em Java, uma interface é um tipo de referência, semelhante a uma classe, que pode conter apenas constantes, assinaturas de métodos e tipos aninhados, não há corpo de método.

Interfaces não podem ser instanciadas, elas só podem ser implementadas por classes ou prorrogado por outras interfaces.

&nbsp;

## **Caracterísicas das Interfaces**

---

&nbsp;

Interface tem a seguinte característica:

* Uma interface não pode ser instanciada, mas podem ser definidos referências do seu tipo.

Exemplo:

~~~~Java
MinhaInterface minhaInterface;
~~~~

Nessa situação não é utilizado o operador **new**.

&nbsp;

* Todos os métodos definidos são implicitamente do tipo **public** ou **abstract**, por essa razão, ao declarar um método em uma interface, não é necessário fornecer a palavra-chave **public**, os métodos não podem ter corpo definido, somente é definido sua assinatura.

Exemplo:

~~~~Java
public interface minhaInterface{

    void conectarBanco();
}
~~~~

&nbsp;

* Uma interface pode estender mais de uma interface, é importante lembrar que uma classe pode estender somente de uma outra classe.

Exemplo:

~~~~Java
public interface MinhaInterface extends InterfaceA, InterfaceB{

}
~~~~

&nbsp;

* A classe que implementa uma interface deve obrigatoriamente implementar todos os métodos definidos na interface.

* ``Uma interface é formalmente uma classe abstrata, somente com atributos constantes`` (**final**) ``e estáticos`` (**static**) ``e métodos sem corpo``. Estes deverão ser implementados pelas classes que irão implementar a interface, é importante observar que os atributos na interface precisam ser inicializados.

Exemplo:

~~~~Java
public interface MinhaInterface{

    static final int val01 = 10;
    static final float val02 = (float) 2.8;
}
~~~~

&nbsp;

## **Modelando um Projeto com Interfaces**

---

&nbsp;

Será implementado um sistema de cadastro de Blu-Rays, utilizadno a interface como principal recurso.

As interfaces são um conjunto de operações que definem os serviços de uma classe ou de um componente, nesse caso, as interfaces existirão apenas na classe.

<img src = "Imagens/Inter.png">

&nbsp;

Na figura acima a linha tracejada e com uma ponta de flecha vazada demonstra que a classe **Bluray** implementa a interface, outra forma de mostrar que uma classe implementa uma interface é desenhar uma linha com um círculo em uma das extremidades com o nome dessa interface.

**As interfaces e seus métodos sempre são abstratos em Java**.

&nbsp;

## **Implementando um Projeto com Interfaces**

---

&nbsp;

### **Criando a Classe ItemBluRay**

&nbsp;

Primeiramente será criado um projeto chamado **blurayInterface**, com uma classe chamava **ItemBluRay** e o nome do pacote **blurayInterface**

Será criado fois atributos e implementado os métodos gets e sets.

~~~~Java
public class ItemBluRay{
    private double preco;
    private String nomeCliente;

    public double getPreco(){
        return preco/
    }

    public void setPreco(double preco){
        this.preco = preco;
    }

    public String getNomeCliente(){
        return nomeCliente;
    }

    public void setNomeCliente(String nomeCliente){
        this.nomeCliente = nomeCliente;
    }
}
~~~~

&nbsp;

### **Criando a Interface InterfaceBluRay**

&nbsp;

Na IDE, deve clicar com o botão direito do mouse sobre o pacote do prjeto e no menu escolher **Novo -> Interface Java... e adicionar InterfaceBluRay** como nome da Interface e clicar em finalizar

~~~~Java
public interface InterfaceBluRay{

}
~~~~

&nbsp;

Na interface deve ser criado um atributo estático e fois métodos:

~~~~Java
public interface InterfaceBluRay{
    final static double PROMOCAO = 20; //20% de desconto
    
    void adicionarLista(ItemBluRay obj);
    void imprimirLista();
}
~~~~

&nbsp;

Está sendo utilizado um atributo do tipo **final** e **static**, a ``instrução final`` insica que a classe, método ou variável assim declarada tem uma única atribuição que se mantém constante, ou seja, não pode ser alterada no decorrer do processamento. A ``instrução static`` é utilizada para se criar uma variável que poderá ser acessada por todas as instâncias de objetos desta classe como uma variável comum.

**A vantagem de ter um atributo estático e final é que ao alterar a variável estática, todo o sistema receberá o novo valor atualizado**.

``Não constam nos métodos os modificadores de acesso public, pois, todos os métodos e atributos de uma interface são públicos``.

&nbsp;

### **Criando a Classe Bluray e Estendendo a Interface**

&nbsp;

Agora será criado a classe **Bluray** acrescentando a palavra resertvada **implements** e a Interface **InterfaceBluRay**.

~~~~Java
public class Bluray implements InterfaceBluRay{

}
~~~~

&nbsp;

Provavelmente na IDE haverá um destaque no nome para que seja criado todos os métodos exigidos pela interface, a interface obriga o uso de todos os métodos declarados, mas pode ser decidido como implementá-los.

~~~~Java
public class Bluray implements InterfaceBluRay{

    @Override
    public void adicionarLista(ItemBluRay obj){
        throw new UnsupportedOperationException("Not supported yet.");
    }

    @Override
    public void imprimirLista(){
        throw new UnsupportedOperationException("Not supported yet.");        
    }
}
~~~~

``Como demonstrado acima, Provavelmente na IDE será gerado os pmétodos automaticamente e adciionado a anotação @Override, pois estára sobrescrevendo os métodos da Interface``

Abaixo a reescrita com as informações e instruções corretas:

~~~~Java
public class Bluray implements InterfaceBluRay{~

    private Vector<ItemBluRay>listaBluray = new Vector<ItemBluRay>();

    @Override
    public void adicionarLista(ItemBluRay obj){
        this.listaBluray.add(obj);
    }

    @Override
    public void imprimirLista(){
        System.out.println("Lista de Blu-Rays");

        for(int i = 0; i < this.listaBluray.size(); i++){
            System.out.println();
            System.out.println("Nome do Cliente: ")/
            System.out.println(this.listaBluray.get(i).getNomeCliente());
            System.out.println("Preco do Blu-Ray: ");
            System.out.println(this.listaBluray.get(i).getPreco());
        }
        System.out.println("..........");
        System.out.println();       
    }
}
~~~~

&nbsp;

Nessa classe será criado um **vetor de ItemBluray** para armazenar os objetos **ItemBluRay** e assim obter uma lista.

O método **adicionarLista()** recebe por parâmetro o objeto salvo na classe( Programa que será implementado a seguir). O método **imprimirLista()** apresenta a relação de Blu-Ray salvos no programa.

Abaixo o método para realizar cadastro de todos os Blu-Rays ( como ele não foi implementado na Interface, será criado diretamente na classe):

~~~~Java
public void cadastrarBluRay(ItemBluRay obj){
    Scanner scan = new Scanner(System.in);
    System.out.println("Nome do cliente: ");
    obj.setNomeCliente(scan.nextLine());
    System.out.println("Valor do Blu-Ray: ");
    obj.setPreco(scan.nextDouble());
}
~~~~

&nbsp;

O métpdp **cadastrarBluRay()** recebe por parâmetro o objeto **ItemBluRay** da classe **Programa** que será implementada a seguir.

&nbsp;

### **Criando a Classe Programa**

&nbsp;

Abaixo o código para a classe **Programa**

~~~~Java
public class Programa{

    public static void main(String[] args){
        Bluray objBluray = new Bluray()/
        ItemBluRay objItem;

        while(true){
            objItem = new ItemBluRay();

            System.out.println("1 - Cadastrar Blu-Ray");
            System.out.println("2 - Imprimir lista de Blu-Ray");
            System.out.println("3 - Cadastrar Blu-Ray com Descontos");
            System.out.println("4 - Fim");
            System.out.println("Entre com a opcao desejada: ");

            Scanner scan = new Scanner(System.in);
            int opcao = scan.nestInt();
            if(opcao == 4){
                break;
            }
            switch(opcao){
                case 1:
                    objBluray.cadastrarBluRay(obkItem);
                    objBluray.adicionarLista(objItem);
                    break;
                case 2:
                    objBluray.imprimirLista();
                    break;
                case 3:
                    objBluray.cadastrarBluRay(objItem);
                    System.out.println("Valor do Blu-Ray com promocao de: ");;
                    System.out.println(InterfaceBluRay.PROMOCAO);
                    double valorDesconto = objItem.getPreco() - (objItem.getPreco() * InterfaceBluRay.PROMOCAO) / 100;
                    objItem.setPreco(valorDesconto);
                    objBluray.adicionarLista(objItem);
                    System.out.println();
                    System.out.println();
                    break;
                default:
                System.out.println("Opcao invalida");
            }
        }
    }
}
~~~~

&nbsp;

## **Comparando Interfaces e Classes Abstratas**

---

&nbsp;

Uma classe dó pode estender uma única classe, iremos supor que a classe **Bluray** já estenda uma classe diferente, digamos **Midia**, ela então não poderá estender uma segunda classe, mas cada classe pode implementar quantas interfaces quiser.

Os projetistas do Java optaram por não dar suporte à heranã múltipla, porque ela torna a linguagem muito complexa.

Ao invés disso, as interfaces suportam a maioria dos benefícios da herança múltipla e, ao mesmo tempo, evitam as complexidades e ineficiências.

Abaixo quadro comparativo entre diferenças e similaridades entre Classes Abstratas e Interfaces:

<img src = "Imagens/Inter2.png">