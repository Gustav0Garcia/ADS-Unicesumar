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

página 48...