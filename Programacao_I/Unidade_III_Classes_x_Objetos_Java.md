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

Continuar da pag 81....
