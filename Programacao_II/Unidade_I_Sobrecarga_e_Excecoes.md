# **Anotações Programação I - Unidade II**

&nbsp;

## **Sobrecarga de Métodos**

---

&nbsp;

É necessário saber as diferenças entre sobreposição e sobrecarga.

``Sobreposição``, nada mais é do que escrever um método que já possui, sendo possível pelos recursos de herança.

``Sobrecarga`` consiste no recurso que a linguagem **Java** oferece, de escrever métodos com o mesmo nome, fazendo-se a distinção aénas pelos parâmetros de entrada que obrigatoriamente precisam ser diferenciados.

&nbsp;

## **Exemplos de Sobrecarga**

---

&nbsp;

Será criado uma classe chamada **ExemplosSobreCarga** e, nela, colocar um método chamado **calculaNumeroMaior()**, no primeiro momento, o método receberá apenas dois parâmetros de entrada, que serão duas variáveis do tipo **double**, depois será criado outro método com o mesmo nome, mas irá passar três números para serem verificados dentre os três quem é o maior.

Classe **ExemplosSobreCarga()**:

~~~~Java
public class ExemplosSobrecarga {
	//Criado aqui a variável maior que será usada na verificação do maior número digitado
	double maior;

	//Método que verifica o maior entre dois números digitados
	public double calculaNumeroMaior(double n1, double n2){
		if (n1 == n2){
			maior = 0;
		}else if(n1 > n2){
			maior = n1;
		}else if(n2 > n1){
			maior = n2;
		}
		return maior;
	}
	//Método que verifica o maior número entre números digitados
	public double calculaNumeroMaior(double n1, double n2, double n3){
		if ( (n1>n2) && (n1>n3) ){
			maior = n1;
		}else if ( (n2>n1) && (n2>n3) ){
			maior = n2;
		}else if ( (n3>n1) && (n3>n2) ){
			maior = n3;
		}else {
			maior = 0;
		}
		return maior;
	}
}
~~~~

&nbsp;

Classe **TestaSobreCarga**:

~~~~Java
import javax.swing.JOptionPane;
import main.ExemplosSobrecarga;

public class TestaSobreCarga {

	public static void main(String[] args) {

		double n1,n2,n3,maior;

		//Testando o primeiro metodo
		n1 = Double.parseDouble(JOptionPane.showInputDialog("Digite o primeiro numero:"));
		n2 = Double.parseDouble(JOptionPane.showInputDialog("Digite o segundo numero:"));
		ExemplosSobrecarga e1 = new ExemplosSobrecarga();
		maior = e1.calculaNumeroMaior(n1, n2);
		JOptionPane.showMessageDialog(null,"Maior numero digitado: " + maior);

		//Testando o primeiro segundo metodo
		n1 = Double.parseDouble(JOptionPane.showInputDialog("Digite o primeiro numero:"));
		n2 = Double.parseDouble(JOptionPane.showInputDialog("Digite o segundo numero:"));
		n3 = Double.parseDouble(JOptionPane.showInputDialog("Digite o terceiro numero:"));
		ExemplosSobrecarga e2 = new ExemplosSobrecarga();
		maior = e2.calculaNumeroMaior(n1, n2, n3);
		JOptionPane.showMessageDialog(null,"Maior numero digitado: " + maior);
	}
}
~~~~

&nbsp;

Executando o código, **pode-se ver claramente que tem a utilização de um método que verifica o maior número, só que de duas formas diferentes**: no ``primeiro``, passa-se dois números para serem verificados; no ``segundo``, passa-se três números para serem verificados.

Os dois métodos contêm o mesmo nome, mas com parâmetros de entrada diferente.

Os parâmetros de entrada podem diferenciar-se somente pelo tipo de dados que estamos passando para o método, como por exemplo, criando uma classe chamada **SegundoExemplo**, essa classe contém dois métodos chamados **retornaDddMascara()**; nesse método, será passado primeiro um DDD do tipo **int** e depois um DDD do tipo **String** e o método vai retornar somente uma **String** com o DDD formatado com máscara.

Classe **SegundoExemplo**:

~~~~Java
public class SegundoExemplo {
	//Criado aqui uma string que sera o ddd formatado
	String dddComMascara;

	//Criado aqui um metodo que retorna o ddd formatado recebendo um DDD to dipo int

	String retornaDddMascara(int ddd){
		dddComMascara = "(" +ddd+ ")";
		return dddComMascara;
	}

	//Criado aqui um método que retorna o ddd formatado recebendo um DDD to dipo string
	String retornaDddMascara(String ddd){
		dddComMascara = "(" +ddd+ ")";
		return dddComMascara;
	}
}
~~~~

&nbsp;

Classe **TestaDdd**:

~~~~Java
import javax.swing.JOptionPane;

public class TestaDdd {

	public static void main(String[] args) {

		//Criado aqui duas variaveis para ddd uma int outra string
		int ddd;
		String strDdd;

		//Irá ler qui a variavel ddd que é integer
		ddd = Integer.parseInt(JOptionPane.showInputDialog("Digite o ddd de sua cidade:"));

		//Irá ler aqui a variavel ddd que é string
		strDdd = JOptionPane.showInputDialog("Digite o ddd de sua cidade:");
		SegundoExemplo se = new SegundoExemplo();

		//Irá imprimir primeiro o ddd int com mascara
		JOptionPane.showMessageDialog(null,"DDD int com mascara:" + se.retornaDddMascara(ddd));

		//Irá imprimir agora o ddd string com mascara
		JOptionPane.showMessageDialog(null,"DDD string com mascara: " + se.retornaDddMascara(strDdd));
	}
}
~~~~

&nbsp;

Executando o código, pode-se concluir que pode criar métodos com o mesmo nome e até os nomes dos parâmetros de entrada iguais, nomes e quantidades, tendo apenas o tipo de dados diferentes.

&nbsp;

## **Conversões Implícitas**

---

&nbsp;

Também é possível usar **conversões implícitas** nos métodos utilizados na sobrecarga, embora, dependendo da situação, os valores podem ficar incorretos.

Exemplo: criar uma classe chamada **ConversaoImplicita** e depois criar outra classe chamada **TesteConversapimplicita**, se o valor passado no argumento for válido pela conversão implícita, o método poderá ser utilizado sem erros de execução, mas seus valores poderão sofrer alterações, como pode-se ver no exemplo a seguir:

~~~~Java
public class ConversaoImplicita {

	int retornaQuadradoNumero(int numero){
		numero = numero * numero;
		return numero;
	}
}
~~~~

&nbsp;

Classe **TestaConversaoImplicita**:

~~~~Java
public class TestaConversaoImplicita {

	public static void main(String[] args) {

		ConversaoImplicita c1 = new ConversaoImplicita();
		JOptionPane.showMessageDialog(null,"Quadrado de 3= " + c1.retornaQuadradoNumero(3) );
		JOptionPane.showMessageDialog(null,"Quadrado de 3= " + c1.retornaQuadradoNumero(‘3’));
	}
}
~~~~

&nbsp;

## **Construtores com Sobrecarga**

---

&nbsp;

Um recurso muito utilizado é usar **sobrecarga** com construtores da classe.

O construtor é o primeiro método a ser executad quando instanciamos um objeto, ou seja, quando instanciamos, é executado o da classe.

Exemplo: criar uma classe chamada **Cliente** com um construtor vazio.

~~~~Java
public class Cliente {
	//Craido aqui um constructor vazio para a classe
	public Cliente() {
	}
	//Criado aqui atributos normais de uma classe Cliente
	int codigo;
	String nome;
	String cpf;
	String endereco;
}
~~~~

&nbsp;

Agora, como ficaria a classe que instancia a classe **Cliente**, dando o nome para ela de **TestaCliente**

~~~~Java
public class TestaCliente {
	public static void main(String[] args) {
		//Instanciado um objeto do tipo cliente, neste momento está executando o construtor definido como vazio
		Cliente c1 = new Cliente();
	}
}
~~~~

&nbsp;

Quando é feito isso, os atributos do objetvo **c1** estão nulos, ou seja, ainda sem valor; agora, a seguinte situação: já no momento de instanciar o objetvo **c1**, precisar passsar valores para os atributos, poderia ser feito por sobrecarga com os construtores, pois pode já criar um objeto e iniciar os atributos com valores já no momento de instanciar, se utilizar a sobrecarga, pode-se instanciar o objeto das duas formas diferentes, passando valores iniciais ou não passando valores iniciais.

Como ficará a classe **Cliente**:

~~~~Java
public class Cliente {
	//Criado aqui atributos normais de uma classe Cliente
	int codigo;
	String nome;
	String cpf;
	String endereco;

	//Criado aqui um constructor vazio para a classe
	public Cliente() {
	}

	//Criado aqui outro constructor passando valores de entrada para inicializar os atributos
	public Cliente(int codigo, String nome, String cpf, String endereco) {
		this.codigo = codigo;
		this.nome = nome;
		this.cpf = cpf;
		this.endereco = endereco;
	}
}
~~~~

&nbsp;

Classe **TestaCliente**:

~~~~Java
import javax.swing.JOptionPane;
public class TestaCliente {
	public static void main(String[] args) {

		//Criado aqui os atributos a serem lidos referente ao cliente 1 e cliente 2
		int codigo;
		String nome;
		String cpf;
		String endereco;

		//aqui é lido os valores dos atributos pelo usuário referente ao primeiro cliente
		codigo = Integer.parseInt(JOptionPane.showInputDialog("Digite o codigo do primeiro cliente:"));
		nome = JOptionPane.showInputDialog("Digite o nome do primeiro cliente");
		cpf = JOptionPane.showInputDialog("Digite o cpf do primeiro cliente");
		endereco = JOptionPane.showInputDialog("Digite o endereço do primeiro cliente");

		//Criado um objeto do tipo cliente e usado um construtor vazio, passa os valores para os atributos depois dele instanciado
		Cliente c1 = new Cliente();
		c1.codigo = codigo;
		c1.nome = nome;
		c1.cpf = cpf;
		c1.endereco = endereco;

		//aqui é lido os valores dos atributos pelo usuário referente ao segundo cliente
		codigo = Integer.parseInt(JOptionPane.showInputDialog("Digite o codigo do segundo cliente:"));
		nome = JOptionPane.showInputDialog("Digite o nome do segundo cliente");
		cpf = JOptionPane.showInputDialog("Digite o cpf do segundo cliente");
		endereco = JOptionPane.showInputDialog("Digite o endereço do segundo cliente");

		//Aqui é instanciado o objeto passando para o construtor os valores dos atributos já neste momento
		Cliente c2 = new Cliente(codigo,nome,cpf,endereco);
	}
}
~~~~

&nbsp;

Pode-se ver que a **Sobrecarga** em construtores é muito útil e que pode oferecer uma facilidade muito grande para a flexibilidade na utilização de passagem de valores dos atributos.

&nbsp;

## **Tratamento de Exceções**

---

&nbsp;

``Quando um evento excepcional ocorre em Java, diz-se que uma exceção será lançada``.

O código que é responsável por fazer algo com a exceção é chamado de manipulador de exceções; ele captura a exceção lançada.

**Uma exceção é uma ocorrência que altera o fluxo normal do programa, ela pode ocorre por diversos motivos, incluindo os seguintes**:

* Um usuário encontrou dados inválidos.
  
* Um arquivo que precisa ser aberto não pode ser encontrado.
  
* A conexão de rede foi perdida no meio de comunicação, ou a JVM está sem memória.
  
* Falhas no Hardware.
  
* Exautão de recursos.

&nbsp;

Com o tratamento de exceções, um programa pode continuar executando (em vez de encerrar) depois de lidar com um problema, isso ajuda a assegurar a robustez dos aplicativos.

&nbsp;

## **Captura de Exceções**

---

&nbsp;

**A manipulação de exceção funciona pela transferência da execução de um programa para um manipulador de exceções apropriado quando uma exceção ocorrer**.

Por exemplo, s``e for chamado um método qe abra um arquivo, mas o arquivo não puder ser aberto, a execução desse método será encerrada e o código que foi escrito para lidar com essa situação sera processado``.

Portanto, é utilizado o ***try*** e ***catch*** para informar a **JVM** (***Java Virtual Machine***) que o código executar quando uma determinada eceção ocorrer.


&nbsp;

### ***Try / Catch***

&nbsp;

É a forma mais utilizada, o código dentro de um bloco ***try/catch*** é chamado de código protegidos, quando uma exceção é capturada, temos de dar tratamento à exceção, ou seja, tem que haver um plano de contingência para resolver o problema que ela significa. 

Pode declarar mais de um bloco ***catch***, isso é importante,porque pode ter vários tipos diferentes de exceção sento lançados e necessitar de um traatamento específico para cada um.

~~~~Java
public static void main(String[] args){
	try{
		//Aqui é executado um ou mais métodos que podem lançar exceções
	}catch(Exception e){
		//Aqui a exceção ocorreu e é tentado evitar o problema fazendo a operação de modo diferente
	}
}
~~~~

No exemplo anterior, dentro do ***Try***, constituem a região protegida que será controlada pela cláusula, dentro do ***Catch*** é o manipulador para uma exceção do tipo ***Exception***

O bloco ***Catch*** aparece logo após o bloco ***Try***, isso é um requisito, se tiver um ou mais blocos ***catch***, eles devem aparecer imediatamente após o bloco ***Try***. além disso, todos os blocos ***catch*** precisam ficar um após o outro, sem nenhuma outra instrução ou bloco entre eles.

A ordem na qual os blocos ***catch*** forem inseridos também importa.

Se a execução dentro do ***Try*** for lançada sem nenhuma exceção, a execução irá pular o ***catch**, caso houver exceção, será executado os comandos dentro do ***catch***.

&nbsp;

### **Usando *Finally***

&nbsp;

O bloco ***Finally*** é usado quando é preciso executar um código mesmo se houver uma exceção, por exemplo, se está escrevendo em um arquivo e acontece um erro, o arquivo tem que ser fechado mesmo assim, ou se está usando uma conexão a banco de dados e acontece algum problema, a conexão tem que ser fechada.

~~~~Java
public static void main(String[] args){
	try{
		//Usando o Resource
	}catch(Exception e){
		//Problema com o resource
	}finally{
		try{
			resource.close()/
		}catch(Exception e){
			//Não foi possível fechar o resource?
		}
	}
}
~~~~

&nbsp;

## **Definindo Exceções**

---

&nbsp;

Pag 30...