# **Anotações Programação I - Unidade III**

&nbsp;

## **Introdução**

---

&nbsp;

IDE é um ambiente de desenvolvimento integrado que possibilita o desenvolvimento de aplicações Java de forma mais rápida e mais simples.

A **Classe** é um modelo utilizado para criar o **Objeto**.

&nbsp;

## **Pacotes**

---

&nbsp;

**São agrupamentos de classes, que auxiliam a separá-las de acordo com uma determinada característica das classes**, esta organização se faz necessária, por por meio dela fica mais fácil para que outras pessoas que olhem o código, entendam o programa, além, de auxiliar no trabalho em equipe e manutenção do seu software.

&nbsp;

## **Conceitos Básicos de Classes**

---

&nbsp;

Com a Classe aberta, pode-se notar que primeiro no nome da Classe se encontra no final do comando "*public class NOME*", este *public class* indica que é uma classe que poderá ser utilizada por quem quiser usá-la.

Depois deste comandom abre e fecha colchetes ({}), tudo que se encontrará dentro destes colchetes, fará parte da Classe.

&nbsp;

### **Atributos**

&nbsp;

**São, basicamente, variáveis que se encontram dentro a Classe, e que a ela pertencem**.

``Exemplo``:

~~~~Java
public class Pessoa{
    String nome;
    String telefone;
    int idade;
}
~~~~

&nbsp;

### **Construtores**

&nbsp;

**Criados dentro da classe, eles auxiliam na hora de definir valores padrões para os atributos que serão criados ao se montar um objeto, os Construtores são métodos**.

``A principal diferente entre um Construtor e um método qualquer, é que o Construtor não pode conter nenhum tipo de retorno, deverá ter exatamente o mesmo nome da Classe e ele sempre será chamado primeiro quando um objeto for construído``.

``Exemplo``:

~~~~Java
public Pessoa(){

}
~~~~

&nbsp;

O **public** indica que ele será acessível de fora da classe.

O nome do Construtor será exatamente o nome da Classe (diferenciando letrsa maiúsculas e minúsculas).

Deve-se abrir e fechar parêntes,se houver necessidade de alguma variável para o Construtor funcionar, basta colocar entre estes parênteses.

Em seguida, ao cabeçalho, deve abrir e fechar as chaves, todos os códigos referentes ao Construtor devem estar dentro destas chaves.

&nbsp;

~~~~Java
public Pessoa(){
    idade = 0;
    nome = "";
    telefone = "";
}
~~~~

**É possível criar diversos Construtores para a mesma Classe, como todos têm que ter o mesmo nome da Classe, o que irpa diferenciar um Construtor do outro, são as variáveis criadas nos parênteses.

Para o exemplo abaixo, será criado um segundo Construtor, porém, os valores que irão para os atributos serão passados por parâmetro. **A passagem de parâmetro se dá quando recebemos estas variáveis de fora, ou seja, pelos parênteses**.

~~~~Java
public Pessoa(String nom, String tel, int id){
    nome = nom;
    telefone =  tel;
    idade = id;
}
~~~~

&nbsp;

A principal diferença entre o primeiro e o segundo Construtor se dá nos parênteses, sendo no segundo, tendo 3 variáveis sendo criadas como parâmetros.

**é muito importante notar que foi usado vírgula para separar uma variável da outra**.

Como neste caso temos as variáveis, em vez de atribuir valores fixos para os atributos, as variáveis foram atribuídas.

&nbsp;

## **Métodos**

---

&nbsp;

**Enquanto os atributos definem as características que um objeto terá quando criado, os métodos irão inficar quais funcionalidades que este objeto terá**. **Eles são pedaços de código que recebem um determinado nome, e podem ser chamados quando criamos um objeto**.

Um método possui 4 partes:

* É identificado se ele é acessível para outras classes;

* Deve inficar se ao fim do método, este terá que retornar algum valor ou não;

* Tem o nome;

* Se ele irá receber algum tipo de parâmetro ou não.

&nbsp;

``Exemplo``:

~~~~Java
public boolean testeIdade(int idade){
    if(idade >= 0){
        return true;
    }else{
        return false
    }
}
~~~~

**Para ter certeza de que a variável "idade" no if é a variável que está sendo passada por parâmetro, e não o atributo <<idade>> da classe, **existe uma regra que diz que uma vcariável criada dentro de um método (ou dentro das chaves, ou dentro dos parâmetros) sempre leva vantagem sobre um atributo, esta característica leva o nome de sombreamento, onde a variável criada para o método deixa o atributo em sua sombra**.

&nbsp;

Outro método de se criar, é uma mensagem padrão para mostrar os atributos da classe de forma ordenada, para isso deve ser criado um método onde não precisa receber nenhum valor, mas ele retorna uma String preparada para usar.

~~~~Java

public String mostrarDados(){
    String retorno = "Nome: " + nome + " Idade: " + idade + " Telefone: " + telefone;
    return retorno;
}
~~~~

&nbsp;

Algumas regras são adotadas para manter um padrão, primeiro, **é importante ressaltar que nomes de métodos não podem conter espaços, caracteres especiais ou iniciar com números, além disso, adota-se a seguinte regra: o nome do método inicia-se com minúsculo, e a cada palavra nova, não se dá espaço e nem unferline, mas deixa a primeira letra maiúscula (é um padrão que não precisa necessariamente seguir)**.

&nbsp;

Para se utilizar as Classes, deve-se criar uma classe principal, nela se encontrará o método **main**

**Um método não é identificado pelo seu nome, e sim pela sua assinatura, a principal diferença é que na assinatura, além do nome, os parâmetros também ajudam a identificar**.

Vamos criar um método chamado teste:

~~~~Java
public void teste(){
    ...
}
~~~~

&nbsp;

**A assinatura deste método é o teste()**, se quiser criar outro método com o mesmo nome, deve mudar a forma como os parâmetros estão chegando:

~~~~Java
public void teste(String var1){
    ...
}
~~~~

**Porém, a assinatura de um método não leva em consideração o nome das variáveis, ou seja, não é possível criar outro método chamado teste, que receba uma variável do tipo String, mesmo que esta variável tenha outro nome, o que é levado em conta é o número de parâmetros e a ordem deles**.

``Exemplos``:

~~~~Java
public void teste(String var1, String var2, int var3){
    ...
}
~~~~

e

~~~~Java
public void teste (String var1, int var2, String var3){
    ...
}
~~~~

&nbsp;

### **O Método Main**

&nbsp;

Serve de ponto de partida para que o sistema comece a rodar, todo programa em Java começade um método **main**.

Enquanto as outras classes trazem os códigos necessários para resolver o problema, o **main** irá efetivamente resolver o problema com o auxílio das classes previamente criadas.

``Exemplo``:

~~~~Java
public static void main (String args []){

}
~~~~

O **public** indica que ele será aberto para as outras classes, o **static**, indica que não precisará criar um objeto desta classe para usar o **main**, desta forma, o próprio Java chama este método, o **void** indica que o método não retorna nada e **main** é o seu nome.

Como parâmetro, ele recebe um vetor de **Strings**, qe pode ser passado ou não, quando se chama o **main**.

&nbsp;

~~~~Java
public static void main (String args []){
    System.out.prinln("Olá Mundo!");
}
~~~~

**System.out** infica a saída padrão do computador, neste comando, utilizando o método **println**, que imprime o que for passado por parâmetro e pula uma linha, também pode ser ussado os métodos **print** e **printf**.

**É possível mudar a classe principal na IDE, variando a localização dependendo de qual IDE está utilizando**.

&nbsp;

## **Objetos Java**

---

&nbsp;

Agora será criado um código dentro do método **main**, primeiro será criado um objeto da classe **Pessoa**, que se encontra em outro pacote.

Depois, será adicionada uma linha de comando antes da classe **Início**, porém, depois do comando que indica o pacote daquela classe.

~~~~Java
import Dados. Pessoa;
~~~~

**Este comando importa para a classe uma outra classe, podendo esta ser uma biblioteca ou de outra classe disponível na máquina**.

Para esse caso, será importado a classe **Pessoa**, que se encontra dentro do pacote **Dados**.

A partir de agora, será criado e usado a classe **Pessoa**, será usada para criar um objeto, dentro do método **main**, será inserido o comando:

~~~~Java
Pessoa pes = new Pessoa();
~~~~

**Este comando cria um objeto do tipo Pessoa, chamado pes**, este comando possui 2 etapas distintas, o **Pessoa pes** cria uma variável do tipo Pessoa, sendo equivalente a um "**int pes**", que seria uma variável do tipo inteiro, porém, o objeto ainda não existe só nessa declaração, neste momento, apenas a referência ao objeto foi criada, ficando a cargo do **new Pessoa()** a função de instanciar o objeto, ou seja, criar o objeto na memória.

O comando **new** reserva o espaço na memória, que tem seu valor calculado quando é informado qual tipo de objeto será criado, inficado no **Pessoa()**.

É possível reescrever o código em 2 linhas separadas de tão distintas que elas são:

~~~~Java
Pessoa pes;
pes = new Pessoa();
~~~~

Existe uma regra de  que não pode utilizar o objeto enquanto ele não for criado na memória, ou seja, não for dado comando **new** nele.

Ao se dar esse comando, logo em seguida é determinado qual construtor irá chamar, acima foi chamado o construtor que não recebe parâmetro algum, logo, os atributos destes objetos estão zerados ou com **Strings** vazias.

&nbsp;

~~~~Java
Pessoa pes2 = new Pessoa("João", "(11)0980-0980", 13);
~~~~

No comando acima estamos criando um segundo objeto chamado **pes2**, onde, ao instanciar o objeto, os valores que estão sendo passados serão passados para os atributos

No objeto **pes** pode-se acessar os atributos e métodos colocando o nome do objeto, um ponto e o atributo ou método desejado:

~~~~Java
pes.nome = "Fulano";
pes.idade = 22;
pes.telefone = "(00) 7654-3210";
~~~~

Ao inserir o código acima, irpa acusar erro, irá ser indicado que os atributos não são acessíveis de fora do pacote por não serem públicos, para resolver este problema, deve adotar duas medidas. **A primeiroa** e mais imples é inserir o modificador **public** para cada atributo na classe:

~~~~Java
public class Pessoa{
    public String nome;
    public String telefone;
    public int idade;
}
~~~~

**A segunda** medida será discutida na próxima seção.

Para confirmar que o objeto **pes** possui seus atributos com valores determinados, pode-se utilizar o método **mostrar-Dados()** (método criado para exibir os dados), o comando ficará:

~~~~Java
System.out.println(pes.mostrarDados());
~~~~

ou

~~~~Java
System.out.println(pes2.mostrarDados());
~~~~

Código e o resultado:

~~~~Java
package Principal;

import Dados.Pessoa;

public class Inicio{

    public static void main(String args[]){
        Pessoa pes;
        pes = new Pessoa();
        Pessoa pes2 = new Pessoa("João", "(11) 0980-0980", 13);
        pes.nome = "Fulano";
        pes.idade = 22;
        pes.telefone = "(00) 7654-3210";
        System.out.println(pes.mostrarDados());
        System.out.println(pes2.mostrarDados());
    }
}
~~~~

&nbsp;

Um erro muito comum que ocorre no momento que está trabalhando com mais de um objeto dentro de um método:

~~~~Java
pes = pes2;
~~~~

Em primeiro momento, parece que os atributos goram replicados e agora existem dois objetos contendo os mesmo valores, porém, pode-se perceber algo estranho quando mudar o atributo de algum dos objetos, caso seja alterado algum atributo de um objeto, o outro também será alterado, isso porque os objetos não foram replicados, e sim apenas a variável que aponta para o objeto, na verdade, existem um único objeto e 2 caminhos diferentes para chegar nele.

**Existe um objeto especial, que pode ser usado como desejar e que ajuda ao criar os métodos de algumas classes, esse objeto especial é o *this***.

**Não há necessidade de criálo para utilizá-lo, porém ele tem um uso muito restrito, ele representa o próprio objeto**.

Estando dentro da própria classe, póde-se utilizar o **this** para acessar o próprio atributo:

~~~~Java
this.nome;
~~~~

Assim, o Java saberá que é para pegar o atributo do p´roprio objeto, portanto, quando um objeto chamar uma função que contenha este código, ele vai pegar o próprio atributo e utilizá-lo.

Utilizando **this** com **if**:

~~~~Java
if(this.idade > 0);
~~~~

&nbsp;

Com o uso do **this**, pode-se até mesmo chamar construtores.

Pode-se criar construtores que recebem um objeto como parâmetro, devendo ter um certo cuidado na hora de trabalhar com ele.

Este tipo de construtor é muito útil quando possui objetos que deseja replicar e evitar o erro de 2 variáveis apontarem para o mesmo objeto, basicamente, recebe o objeto como parâmetro, mas dentro do construtor, cada atributo é tratado separadamente:

~~~~Java
public Pessoa(Pessoa nova){
    this.nome = nova.nome;
    this.idade = nova.idade;
    this.telefone = nova.telefone;
}
~~~~

&nbsp;

## **Javabeans ou Pojos**

---

&nbsp;

Existem convenções adotadas para se criar classes, estas convenções forame scolhidas pela sociedade de desenvolvedores para estabelecer um padrão entre as diferentes classes que são criadas ao redor do mundo, e assim, desta forma, facilitar o uso de objetos criados a partir desta classe.

A **Primeira Convenção é que um construtor que não receba parâmetros seja feito para que valores vazios sejam atribuídos**.

Um **próximo item, seria tratar todos os atributos como private, ao invés de public, isso implica que não podemos acessar o atributo diretamente de outra classe**.


Ao colocar um atributo como private, faz-se necessário criar 2 métodos específicos para aquele atributo, para receber valor e recuperar o valor que possui.

~~~~Java
public void setNome(String Nome){
    this.nome = nome;
}
~~~~

Foi adotada a nomenclatura **setNome** para seguir um padrão, o nome do método que irá **iserir valores noa atributos** sempre será **set + Nome do Atributo**.

**Normalmente este método não possui retorno, pois é uma operação de inserção de conteúdo**, por isso temos um parâmetro do mesmo tipo do atributo, e este parâmetro está sendo atribuído para o atributo, neste momento, pode-se notar como o **this** consegue diferenciar o atributo variável.

O método que **retorna o conteúdo do atributo**:

~~~~Java
public String getNome(){
    return this.nome;
}
~~~~

Aqui faz a união do nome do atributo com a palavra **get**, e possui um retorno do mesmo tipo do atributo e não recebe nenhum parâmetro.

~~~~Java
private String nome;
private String telefone;
private int idade;

public int getIdade(){
    return idade;
}

public void setIdade(int idade){
    this.idade = idade;
}

public String getNome(){
    return nome;
}

public void setNome(String nome){
    this.nome = nome;
}

public String getTelefone(){
    return telefone;
}

public void setTelefone(String telefone){
    this.telefone = telefone;
}
~~~~

&nbsp;

Na classe principal, para que se utilize estes métodos de acesso:

~~~~Java
pes.setNome("Fulano");
pes.setIdade(22);
pes.setTelefone("(00) 7654-3210");
~~~~

**O código fica maior e mais complexo, porém agora, tem mais controle em como os objetos criados a partir daquela classe trabalham com seus atributos**.

Como por exemplo, não pode haver idade negativa no código, antes ficaria a cargo de quem utiliza o objeto de cuidar que isto não ocorra, mas agora, isso pode ser controlado.

Basta lembrar que dentro dos métodos pod-se adicionar qualquer comando de programação, e que estes **sets** e **gets** são métodos.

Para resolver o problema de idade negativa, pode adicionar um controle dentro do **setIdade**, assim, o objeto pode tentar inserir uma idade negativa, mas não conseguirá, desta forma, os atributos ficam mais protegidos e sua classe menos propensa a cometer erros.

``Exemplo``:

~~~~Java
public void setIdade(int idade){
    if(testeIdade(idade)){
        this.idade = idade;
    }else{
        this.idade = 0;
    }
}
~~~~

Como o método está na mesma classe que o método **setIdade**, não há necessidade de se criar um objeto para chamá-lo, assim o parâmetro que está chegando é passadi para o método **testaIdade** que, por sua vez, retorna verdadeiro ou falso.

**Com os métodos *get* e *set* criados, o ideal é que mesmo dentro da classe, eles sejam utilizados, assim, não há qualquer meio de um atributo não passar pelo teste imposto no método**.

~~~~Java
public Pessoa(){
    this.setIdade(0);
    this.setNome("");
    this.setTelefone("");
}

public Pessoa(String nom, String tel, int id){
    this.setIdade(id);
    this.setNome(tel);
    this.setTelefone(nom);    
}

public Pessoa(Pessoa nova){
    this.setIdade(nova.getIdade());
    this.setNome(nova.getNome());
    this.setTelefone(nova.getTelefone());
}

public String mostrarDados(){
    String retorno = "Nome: " + this.getNome() + " Idade: " + this.getIdade() + " Telefone: " + this.getTelefone();
    return retorno;
}
~~~~

Um código mostrado acima que vale a pena comentar é a atribuição de um objeto para o outro. Vamos pegar a atribuição do atributo nome:

~~~~Java
this.setNome(nova.getNome());
~~~~

Dois métodos diferentes são chamados neste comando, primeiro é chamado o método **getNome()** do objeto **nova**, por ser um **get**, ele não recebe parâmetros e retorna uma **String**, este retorno está sendo utilizado como forma de parâmetro para o **setNome** do objeto **this**, ou seja, ele próprio.

Outra forma que podemos fazer com os construtores é direcionar os outros construtores para um punico construtor, nesta classe tem 3 construtores, que basicamente fazem a mesma coisa, porém com atributos em quantidade e formatos diferentes, e o código dentro deles é muito parecido. para isso pode eleger um único construto que terá estas chamadas dos métodos **set** e direcionar os outros para o construtor eleito utilizando o **this**.

Normalmente o construtor eleito é aquele que recebe os atributos separadamente por parâmetro:

~~~~Java
this("", "", 0);
~~~~

O comando **this** é usado de uma forma diferente neste caso, não havendo necessidade do uso de pontos apra chamada de método, apenas o **this** e os parâmetros.

Como o construtor eleito recebe nome, telefone e idade, nesta ordem, pode passar por parâmetro os valores que ele deverá colocar em cada atributo, já no construto que recebe o objeto como parâmetro, o comando ficará assim:

~~~~Java
this(nova.getNome(), nova.getTelefone(), nova.getIdade());
~~~~

Simplismente estará pegando cada atributo separadamente e mandando em forma de parâmetro para o construtor eleito, ficcando os 3 construtores desta forma:

~~~~Java
public Pessoa(){
    this("", "", 0);
}

public Pessoa(String nom, String tel, int id){
    this.setIdade(id);
    this.setTelefone(tel);
    this.setNome(nom);
}

public Pessoa(Pessoa nova){
    this(nova.getNome(), nova.getTelefone(), nova.getIdade());
}
~~~~

&nbsp;

## **Estado e Comportamento**

---

&nbsp;

As classes são compostas por um conjunto de atributos e métodos, cada objeto criado possui seus p´roprios atributos, mesmo que for da mesma classe, cada um possui o mesmo número e tipo de variáveis, mas cada um com o seu valor, neste caso, a classe só informa o modelo do que cada objeto irá conter, mas o valor é gerenciado pelo objeto.

Este conjunto de atributos de um objeto define o estado em que ele se encontra, cada objeto, por ter seus próprios atributos, pode estar em estados diferentes, por exemplo, dois objetos criados a partir da classe **File**, que gerencia arquivos do sistema, um objeto pode estar com umdocumento em aberto e ponto para alterar, enquanto que o outro pode já estar fechado, não podendo mais alterar o arquivo.

O comportamento que o objeto tem é algo descrito e compartilhado entre todos os objetos por meio dos métodos, estes possuem um código criado pelo desenvolvedor, que não se altera de objeto para objeto, logo, todos possuem as mesmas funções, seus atributos podem acabar influenciando em um método, mas todos os objetos têm acesso a todas as funções que os outros objetos têm.

&nbsp;

### **Comparando Objetos**

&nbsp;

Utilizando os exemplos anteriores "**pes**" e "**pes2**", podemos pensar neles como um ponteiro que aponta para o objeto quando criado, ou seja, quando executamos o comando:

~~~~Java
Pessoa pes;
~~~~

Está criando um ponteiro que não aponta para lugar algum, a partir do momento que faz:

~~~~Java
pes = new Pessoa();
~~~~

O ponteiro **pes** recebe o endereço de onde o comando **new** criou o objeto, para ter certeza disso, pode-se usar o comando:

~~~~Java
System.out.println(pes);
~~~~

Irá aparecer um valor numérico precedido de um arroba e algumas letras, isso é na verade o valor que **pes** possui, o endereço de seu objeto, por isso não se trabalha normalmente com a variável, no caso o **pes**, diretamente, sempre colocando um ponto para acessar o conteúdo do objeto apontado, como um método ou atributo.

Abaixo exemplo de um erro utilizando a variável diretamente:

~~~~Java
if (pes > pes2){
    System.out.println(pes.getNome());
}else{
    System.our.println(pes2.getNome());
}
~~~~

Apenasr que a IDE poderá não apresentar erro na sintaxe, o código contém um erro grave. ao comparar os objetos por meio de seus ponteiros, na verdade estará comparando qual endereço de memória possui o maior valor, logo, vai mostrar o nome de "**pes**" se o endereço apontado for maior, para que seja efetuada a comparação correta, deve utilizar:

~~~~Java
if(pes.getIdade() > pes2.getIdade())
~~~~
