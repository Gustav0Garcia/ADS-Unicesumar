# **Anotações Programação I - Unidade V**

&nbsp;

## **Introdução**

---

&nbsp;

O **JPA** é uma **API** que define um **framework** de persistência, na qual fornece um modelo de mapeamento objeto relacional para  persistência em bancos de dados relacionais.

Quando se fala de persistência em Java com **JPA**, é sobre mapear objvetos Jav normais de forma automática para um banco de dados **SQL**.

&nbsp;

## **JDBC - *Java Database Connectivity***

---

&nbsp;

``Trata-se de uma API para acesso ao banco de dados relacionais por meio de comndos SQL em que a programação do sistema é a mesma para qualquer SGBD`` (**Sistema Gerenciador de Banco de Dados**)``, ou seja, não há necessidade de desenvolver aplicações amarradas com um banco específico``.

Com JDBC é possível:

* Estabelecer uma conexão com um banco de dados ou com qualquer fonte de dados tabular;

* Executar instruções SQL;

* Processar os resultados obtidos.

&nbsp;

## **Drivers JDBC**

---

&nbsp;

Para que seja possível estabelecer uma conexão com um banco de dados permitindo que uma aplicação java interaja com esse banco, o JDBC utiliza **drivers** específicos de acordo com cada **SGDB**.

Normalmente, os drivers JDBC são fornecidos pelos seus fabircantes ou por comunidades de usuários.

Atualmente, existem 4 tipos de drivers:

1. Ponte JDBC-ODBC - é o mais simples, porém restrito a plataforma Windows, geralmente, utilizado quando não existe para o SGDB um driver nativo (tipo 4), sendo necessário um ODBC para se conectar ao banco de dados;

2. Driver API-Nativo - converte as chamadas JDBC para as chamadas da API cluiente do SGDB;

3. Driver de Protocolo de Rede - trata-se do tipo mais flexível, pois possibilita criar aplicações Java independe de banco de dados, ou seja, a mesma aplicação pode se conectar a vários SGDBs diferentes;

4. Driver Nativo - é o mais recomendado, pois as chamadas JDBC são traduzidas no protocolo do SGDB.

&nbsp;

## **Conectando a um SGDB com *Connection***

---

&nbsp;

A primeira interface  ser estudada é a ***java.sql.Connection***, um objeto **Connection** representa uma sessão de conexão com um determinado banco de dados na qual as instruções SQL são executadas e os resultados obtidos dentro do contexto desta sessão, ``ela permite que seja criada uma ou mais conexões com um mesmo banco de dados ou várias conexões com diferentes banco de dados``.

Ela também permite obter informações do banco de dados a qual ela se conectou, por exemplo:

* Qual o fabricante e a versão do banco de dados.

* O nome e a versão do driver JBDC utilizado.

* O nome do usuário utilizado na conexão.

* A URL de conexão.

* As estruturas das tabelas do banco de dados.

* Qual a gramática SQL suportada.

* Procedimentos.

&nbsp;

Estas e outras informações podem ser obtidas por meio de um objeto ***DatabaseMetaDta*** retornado pelo método **getMetaData()** acessado em uma instância de **Connection**.

A maneira mais comum de estabelecer uma conexão com um banco de dados é por meio de uma chamada para o método **DriverManager.getConnection()**, esse método recebe como argumento 3 **Strings** contendo a URL JDBC de conexão com o banco de dados, o usuário e a senha, respectivamente.

~~~~Java
//URL JDBC de conexão
String urlConexao = "jdbc:derby://localhost:1527/ead-bd";

//Obtendo um objeto Connection (uma conexão) com getConnection
Connection con = DriverManager.getConnection(urlConexao, usuario, senha);
~~~~

&nbsp;

Quando é utilizado o **DriverManager** em uma aplição para criar um objeto, deve fornecer para o método **getConnection** uma URL JDBC, que tem a finalidade de fornecer uma maneira de identificar com qual banco de dados determinado driver irá estabelecer uma conexão

~~~~Java
jdbc: <subprotocol>: <subname>
~~~~

&nbsp;

A primeira parte **jdbc** indica que a URL em questão é uma URL JDBC, a segunda, **subprotocol**, representa o nome do driver de conexão utilizado para um determinado SGBD, o terceiro, **subname**, representa a fonte de dados a qual será realizada a conexão.

Abaixo uma relação com os principais fabricantes de banco de dados e o formato de URL JDBC de conexão de cada um:

* SGDB - Url de Conexão

* Oracle - jdbc:oracle:thin:@host:porta:nomeBanco (Porta padrão 1521)

* PostgreSQL - jdbc:postgresql://host:porta/nomeBanco (Porta padrão 5432)

* DB2 - jdbc:db2://host:porta/nomeBanco (Porta padrão 446, 6789, ou 50000)

* SQL Server - jdbc:sqlserver://host:porta;databaseName=nomeBanco (Porta padrão 1433)

* MySQL - jdbc:mysql://host:porta/nomeBanco (Porta padrão 3306)
Firebird - jdbc:irebirdsql:host/porta:caminhoArquivo.fdb (Porta padrão 3050)

&nbsp;

O exemplo abaixo cria uma conexão com um banco de dados **derby**, o qual obtém informações da conexão e do banco de dados utilizando os métodos estudados até então.

~~~~Java
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class ExemploConnection{

    private Connection con = null;
    private String usuario = null;
    private String senha = null;
    private String urlConexao = null;

    public ExemploConnection(){

        urlConexao = "jdbc:derby://localhost:1527/ead-bd";
        usuario = "ead";
        senha = "ead";

        this.conectarBanco();

        this.desconectarBanco();
    }

    public static void main(String[] args){
        new ExemploConnection();
    }

    private void conectarBanco(){
        String saida = "";
        try{
            con = DriverManager.getConnection(urlConexao, usuario, senha);

            saida += "Informações de Conexão";
            saida += "\nFabricante SGDB: " + con.getMetaData().getDatabaseProductName();
            saida += "\nVersão SGDB: " + con.getMetaData().getDatabaseProductVersion();
            saida += "\nDriver SGDB: " + con.getMetaData().getDriverName();
            saida += "\nVersão Driver SGDB: " + con.getMetaData().getDriverVersion();
            saida += "\nUrl de Conexão: " + con.getMetaData().getURL();
            saida += "\nUsuário: " + con.getMetaData().getUserName();

            JTextArea saidaArea = new JTextArea();
            saidaArea.setText(saida);

            JOptionPane.showMessageDialog(null, saidaArea, "Conexão realizada com Sucesso", JOptionPane.INFORMATION_MESSAGE);
        }catch(SQLException ex){
            JOptionPane.showMessageDialog(null, ex.getMessage(), "Erro ao conectar no banco", JOptionPane.ERROR_MESSAGE);    
        }
    }

    private void desconectarBanco(){
        try{
            if(!con.isClosed()){
                con.close();
            }
        }catch(SQLException ex){
            JOptionPane.showMessageDialog(null, ex.getMessage(), "Erro ao desconectar", JOptionPane.ERROR_MESSAGE);    
        }
    }
}
~~~~

&nbsp;

## **Executando Instruções SQL com *Statement****

---

&nbsp;

Pag 148...