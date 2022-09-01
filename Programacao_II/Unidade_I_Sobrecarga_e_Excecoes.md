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

pag 24....