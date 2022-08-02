# **Anotações Programação I - Unidade I**

&nbsp;

## **Histórico e Evolução da Linguagem Java**

---

&nbsp;

Criada por ``James Gosling em 1992``, a primeira versão estável da linguagem Java foi o JDK (*Java Development Kit*) 1.0.2, conhecido por Java 1, em janeiro de 1996, com o codinome Oak.

&nbsp;

**Fevereiro de 1997**, foram adicionadas algmas bibliotecas, como: eventos com base na biblioteca *Abstract Window Toolkit* (AWT), classes internas, conexão com banco de dados bia *Java Database Connectivity* (JDBC) e invocação remota de métodos.

&nbsp;

**Dezembro de 1998**, foi lançada a J2SE 1.2 (*Java Standard Edition*), codinome *playground* conhecida simplismente como Java 2, **essa foi a evolução mais significativa do Java**, ``já que a tecnologia foi dividida em três principais plataformas``: J2SE (*Java Standard Edition*), J2EE (*Java 2 Enterprise Edition*) e J2ME (*Java 2 Micro Edition*).
``Ao J2SE foram adicionadas as seguintes bibliotecas``: *Swing* para interface gráfica com o cliente, coleções (*List*, *Set* e *Map*), e a possibilidade de criação de pontos flutuantes de acordo com o padrão IEEE 754.

&nbsp;

**Maio de 2000**, foi lançada a versão 1.3, codinome Kestrel, **as mudanças mais notáveis foram**: invocação remota de método compatível com CORBA, introdução das bibliotecas JavaSound para tratamento de sons e JNDI (*Java Naming and Directory Interface*) para o compartilhamento de recursos.

&nbsp;

**Fevereiro de 2002**, foi lançada a versão 1.4 da J2SE, codinome Merlin, **que foi a primeira versão desenvolvida sob a tutela da Java Community Process (JCP)**, a ``JCP é uma comunidade extremante importante formada por um consórcio de empresas que regulamenta a tecnologia Java de forma geral``. ``Dentre as maiores melhorias, destacam-se``: a inclusão de expressões regulares, capacidade de lidar com protocolo iPv6, biblioteca para *Logging*, integração *parsers* XML, melhoria nas bibliotecas para criptogradia e segurança.

&nbsp;

**Setembro de 2004** foi lançada a versão J2SE 5.0, codinome Tiger, conhecida como Java 5, ``várias mudanças significativas foram incorporadas nesta nova versão, dentre elas``: biblioteca para *Generics*, eliminando a necessidade de conversões entre tipos similares, inclusão de uma biblioteca para metadados de uma aplicaão, *autoboxing/unboxing*, que são conversões automáticas entre tipos primitivos, *enumerations*, que permitem criar listas de valores ordenados, e a melhoria da estrutura de repetição *for* para coleções *arrays*.

&nbsp;

**Dezembro de 2006**, foi lançada a versão Java SE 6, conidnome Mustang, conhecida como Java 6, ``a partir dessa versão, as siglas J2SE, J2EE e J2ME foram substituídas pelas siglas Java SE, Java EE e Java ME``. ``Dentre as melhorias podemos citar``: aumento de desempenho da plataforma básica, suporte ao JDBC 4.0, uma biblioteca dedicada somente ao compilador Java e melhorias no desempenho e segurança da máquina virtual Java.

&nbsp;

**Julho de 2011**, foi lançada a versão Java SE 7, codinome Dolphin, conhecida como Java 7, ``algumas características adicionadas a esta versão``: estrutura de seleção *switch* aceitando *strings*, e não somente valores inteiros, nova biblioteca para tratar entrada e saída e melhorias nos *streams* para XML e Unicode.

&nbsp;

## **A Tecnologia Java**

---

&nbsp;

é composto por uma série de város produtos de software e especificações provenientes, originalmente, da *Sun Microsystems*, e hoje sobre responsabilidade da Oracle.

O Java é usado em uma ampla variedade de plataformas computacionais, desde sistemas embarcados e telefones celulares até servidores empresariais e supercomputadores, menos comum, porém ainda usados, estão os Java *applets* que de vez em quando são utilizados para melhorar a segunraça de navegadores Web e desktops.

Usando o Java é a principal forma de produzir código que será implantado na forma de *bytecodes* Java, existem aindam, os compiuladores de *bytecodes* disponíveis para gerar código para outras linguagem, como Ada, JavaScript, Phyton e Ruby, várias novas linguagens foram projhetadas para serem executadas de forma nativa na máquina vistual Java (*Java Virtual Machine - JVM*), como Scala, Clojure e Groovy, ``a sintaxer de Java é muito semelhante à C e C++, porém mais recursos orientados a objetos podem ser modelados``.

**O Java elimina algumas construções de baixo nível, como ponteiros, além de possuir um modelo de memória muito simples, em que cada objeto é alocado em uma pilha e todas as variáveis de tipos de objeto são referências, o seu gerenciamento de memória é feito por meio da coleta de lixo (*Garbage Collector*) automática realizada pela JVM**.

Uma edição da "plataforma Java" é o nome de um pacote de programas relacionados que permite o desenvolvimento e a execução de programas escritos em Java, a plataforma não é específica para qualquer processador  ou SO, porém, a sua execução requer uma JVM e um compilador com um conjunto de bibliotecas que são implementadas para diversos hardwares e SO para que os programas em Java possam ser executados de forma idêntica em qualquer ambiente.

&nbsp;

``Plataformas Java mais comuns``:

* **Java Card** - permite pequenas aplicações baseadas em Java (applets) para serem executadas em cartões inteligentes com segurança e similares de memória em pequenos dispositivos.

* **Java ME (Micro Edition)** - especifica vários conjuntos diferentes de bibliotecas (conhecidos como perfins) para dispositivos com armazenamento, exibição e capacidade de energia limitados, muitas vezes usado para desenvolver aplicativos para dispositivos móveis, PDAs, set-top bozes de TV e impressoras;

* **Java SE (Standard Edition)** - para uso geral em aplicações, desktops. servidores e dispositivos similares.

* **Java EE (Enterprise Edition)** - é a soma da plataforma Java SE com as mais diversas APIs úteis para aplicações multicamadas e cliente-servidos.

&nbsp;

O Java consiste de vários programas, como por exemplo, o compilador Java, que converte o código-fonte Java em *bytecode* Java (Linguagem intermediária JVM) e é ujma parte do *Java Development Kit* (JDK) , O *Java Runtime Environment* (JRE) complementa a JVM com o compilador *just-in-time* (JIT), que converte bytecodes intermediários no código de máquina nativo da plataforma alvo.

&nbsp;

``Principais componentes do Java``: compilador Java, bibliotecas e o ambiente de tempo de execução em que o *bytecode* Java intermediário "executa" de acordo com as regras estabelecidas na especificação da máquina virtual.

&nbsp;

``A máquina virtual é o coração do Java, que executa programas de bytecode Java, sendo o mesmo código não importando em que SO ou hardware o programa está sendo executado``. **O compilador JIT traduz o bytecode Java em instruções do processador nativo em tempo de execução e armazena o código nativo em memória durante a execução**.

**O uso do bytecode como linguagem intermediária permite que os programas Java possam rodas em qualquer plataforma que tenha uma máquina virtual, o JIT permite que aplicações Java, depois de um pequeno atraso durante o caregamento e uma vez "prontas" tendam a ser executadas tão rápido como os programas nativos** (desde a versão 1.2 da JRE foi implementado o compilador JIT).

``Cada SO possui a sua própria JVM, mesmo que os programas Java sejam multiplataformas``.

Como o Java não é dependente de qualquer SO específico, os aplicativos não podem confiar em qualquer biblioteca de SO pré-existente, em vez disso, a plataforma Java fornece um conjunto amplo de suas próprias bibliotecas-padrão contendo, as mesmas funções reutilizáveis comumente encontradas em SO modernos.

&nbsp;

``As bibliotecas Java servem dois propósitos``:

* **Primeiro** - assim como outras bibliotecas de código-padrão, as bibliotecas Java fornecem ao programador um conjunto bem conhecido de funções para realizar tarefas comuns, como a manutenção de listas de itens ou análise de uma *String* complexa.

* **Segundo** - as bibliotecas de classe fornecem uma interface abstrata para tarefas que normalmente dependem fortemente dos sistemas de hardware e operacional, tarefas como acessoà rede e acesso a arquivos estão muitas vezes entrelaçadas com as implementações distintas de cada plataforma, as bibliotecas java.net e java.io implementam uma camada de abstração em código nativo do SO, então fornecido para a interface padrão das aplicações Java.

&nbsp;

## **O Processo de Compilação e Interpretação de Programas Java**

---

&nbsp;

``O JDK inclui muitos utlitários para compilação, depuração e execução de aplicações Java.``

&nbsp;

### **O Compilador Java**

&nbsp;

Uma aplicação jave deve ter pelo menos uma classe que contenha um método chamado **main()**, que conterá o primeiro código a ser executado para iniciar a aplicação.

````Java
public class OlaMundo {
	public static void main(String[ ] args) {
	System.out.println(“Olá, Mundo!”);
	}
}
````

&nbsp;

O compilador Java converte arquivos-fonte Java em bytecodes, o uso do compitador Java:

	javac[opções][arquivofonte]

A forma mais direta:

	javacOlaMundo.java


Isso resultará em arquivo *bytecode* com o mesmo nome do arquivo . java, mas com a extensão .class: OlaMundo.class.

É possívelinformar a pasta de destino do *bytecode* com a opção -d.

&nbsp;

### **O Classpath**

---

&nbsp;

O *Path* é uma variável de ambiente de um SO que fornece a uma aplicação uma lista de pastas onde procurar por algum recurso específico.

**A variável de ambiente Classpath de Java é uma lista de locais que são visitados na procura por arquivos de classes, o interpretador Java e o compilador Javam usam a Classpath quando procuram por pacotes e classes Java**.

Um elemento de **classpath** pode ser uma pasta, um arquivo . jar ou um arquivo .zip a configuração da classpath varia de SO para SO.

&nbsp;

``Pra Unix (incluindo Mac OS X)``:

	% CLASSPATH=/home/ze/Java/classes:/home/maria/lib/foo.jar:.
	% export CLASSPATH

``Pra Windows``:

	C:\> set CLASSPATH=D:\users\joao\Java\classes;E:\apps;

&nbsp;

**O inicializador Java e outras ferramentas de linha de comando sabem como encontrar as classes essenciais, as quais são incluídas na instalação Java**. Para encontrar outras classes, o compilador e o interpretador Java procuram os elementos da **classpath** na ordem em que foram inseridos, combinando os locais e os nomes dos pacotes das classes.

Caso queira compilar sua aplicação com pacotes e classes definidos por você mesmo, teverá dizer à JVM onde procurar os pacotes e classes na **classpath**, essa inclusão da informação de localização da classe na **classpath** é feita dizendo ao compilador onde a classe ou pacote desejado estão com as opções de linha de comando -cp ou -classpath.

**Exemplo**:

	javac –cp terceiros\classes;\home\maria\classesuteis.jar;.AloMundo.java

&nbsp;

Essa linha de comando diz que além das classes **core**, qualquer classe ou pacote que esteja nos locais citados na lista separada por ponto e vírcula pode ser utilizado na compialçao de AloMundo.java.

``Não é necessário incluir na classpath da compilação o local das classes core e também locais já definidos na variável de ambiente classpath``.

**Comando -help ou javac mostram opções do compitador javac**.

&nbsp;

### **O Interpretador Java**

&nbsp;

Forma de utilizar o aplicativo java.exe para interpretar arquivos de bytecodes (.class):

	java [-opções] nome_da_classe [argumentos]

&nbsp;

#### **Interpretação do Bytecode**


&nbsp;

Interpretador Java é chamado com o aplicativo java.exe (Windows), é usado para interpretar o bytecode (arquivo .class) e executar o programa, o nome da classe deve ser específicado de forma completa.

``Exemplo``:

	% java animais.passaros.Galinha
	% java AloMundo

&nbsp;

Pode-se encontrar pacotes ou classes em tempo de execução incluindo a opção -cp ou -classpath com o interpretador, utlização é a mesma que no comando javac.

O interpretador Java pode ser utilizado com a opção -jar para executar um arquivo containe .jar.

``Exemmplo``:

	% java -jar batalhanaval.jar

&nbsp;

No exemplo assim, o arquivo .jar se torna o classpath e a classe que contém o método main() dentro dela é considerada o programa a ser executado.

&nbsp;

### **A Assinatura do método Main()**

---

&nbsp;

**Deve possuir a assinatura de método correta, a qual é um conjunto de informações que define o método, ela inclui o nome do método, seus argumentos e o tipo de retorno, assim como o modificador de visibilidade e tipo**.

O **main()** deve ser público e estático, significando que ele é acessível globalmente e que ele pode ser chamado diretamente pelo nome, quem o chama é o inicializados quando interpreta o bytecode.

O único argumento no **main()** é um **array** de objetos **Strings**, que serve para armazenar em cada entrada do **array** os parâmetros digitados pelo usuário após o nome da classe a ser interpretada, o nome do parâmetro pode ser escolhida pelo usuário, mas o tipo deve ser sempre **String[]**, que significa **array** de objetos **String**.

Exemplo de interpretação de classe:

	java ClasseExemplo arroz feijão macarrão

&nbsp;

Tremos a primeira posição do **array**, argumentos [0] igual a "arroz", a segunda posição, argumento [1] igual a "feijão" e a terceira posição do **array**, argumento [2] igual a "macarrão", sendo que o **array** têm sua indexação comecada em zero.




 


