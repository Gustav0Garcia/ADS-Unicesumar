# **Anotações Programação I - Unidade IV**

&nbsp;

## **O que é a Bibliotéca Swing**

---

&nbsp;

É uma **toolkit** que inclui um conjunto de componentes para fornecer uma oncstrução gráfica para usuário (**GUI**) de programas Java.

Aplicações desktop são aquelas que rodam diretamente na máquina do usuário, sendo necessária a instação prévia do programa para que possa ser executadas.

O **Swing** foi desenvolvido para fornecer um conjunto mais sofisticado de componentes GUI comparado com o **Abstract Window Toolkit** (**AWT**), **Swing** fornece um visual nativo que simula a aparência de várias plataformas, além de componentes familiares, tais como botões, caixas de seleçõ e rótulos, há ainda, uma seção especialmente sobre gerenciamento de **layout**, os chamados "**Lyout Managers**", item muito importante quando se trta de programação de Interfaces Gráficas.

&nbsp;

## **Criando um Contêiner JFrame**

---

&nbsp;

Com o projeto já criado, devesse, geralmente, dependendo do IDE, clicar com o botão direito na classe e selecionar Novo > Form JFrame.

Será criada uma tela com uma caixa de edição, onde poderá construir toda a interface gráfica, é possível redimensionar a tela.

Ao lado direito (depende da IDE) haver´2 seções, **Paleta** e **Propriedades**, em **Paleta** se encontra todos com componentes para criar a interface gráfica e na seção **Propriedades** é possível definir vários atributos a cada componente.

&nbsp;

## **Adicionando Componentes Swing**

---

&nbsp;

Como foi adicionado um **JFrame** como container principal, será separado os itens do formulário com um **JPanel**

Na janela **Paleta**, pode-se delecionar o componente Painel na categoria Contêiners do **Swing** e deve movê-lo até o canto esquerdo superior do form no **GUI Buiilder**.

Outros componentes também podem ser encontrado na janela **paleta**

&nbsp;

## **Construindo a Interface**

---

&nbsp;

Para um sistema simples de cadastro, será utilizado os seguintes componentes:

* ``JLabel``: permite inserir textos e imagens.

* ``JTextField``: caixa de texto para que o usuário insira os dados no programa.Lembrando que todos os dados inseridos em um JTextField são tratados como String.

* ``JRadioButton``: botão que permite apenas seleção de uma opção quando relacionado a um ButtonGroup.

* ``JComboBox``: componente semelhante a um vetor, que permite ao usuário escolher apenas uma opção.

* ``JButton``: botão onde serão implementados os eventos.

* ``JTextArea``: campo semelhante ao JTextField, normalmente usado para entrada de textos maiores. Como críticas, sugestões etc.

* ``JCheckBox``: caixas de múltiplas seleções, permite o usuário marcar várias opções ao mesmo tempo.

&nbsp;

## **Escrevendo o Código**

---

&nbsp;

Para iniciar a implementação do código, deve-se alterar o nome das variáveis de todos os componentes que serão utilizados para que o código fique limpo e organizado.

Para alterar o nome da variável de um componente, clique sobre ele, com o botão direito do mouse escolha "alterar o nome d variável...".

No caso será colocado:

* Para os JTextField os nomes a seguir: nomeCampo; telefoneCampo; enderecoCampo; cidadeCampo; emailCampo.

* Para o JComboBox: estadoCampo.

* Para os JRadioButton: masculinoCampo; femininoCampo.

* Para JCheckBox: alemaoCampo; espanholCampo; francesCampo; ingles-Campo; italianoCampo; japonesCampo.

* Para JTextArea: motivoCampo.

* Para JButton: salvar.

&nbsp;

Não há necessidade de lterar os JPanels nem os JLabels.

Agora deve-se criar uma classe com todas as variáveis utilizadas no formulário **Swing**, a qual será criada apenas uma classe que terá o objeto para manipular e armazenar os dados contidos em todos os componentes do formulário.

Será criado a classe **Cadastro** e será inserido todos os atributos que serão utilizados no projeto e gerar todos os gets e sets.

~~~~Java
public class Cadastro{
    private String nome;
    private String telefone;
    private String endereco;
    private String cidade;
    private String estado;
    private String email;
    private String sexo;
    private boolean alemao;
    rivate boolean espanhol;
    rivate boolean ingles;
    rivate boolean frances;
    rivate boolean italiano;
    rivate boolean japones;
}
~~~~

&nbsp;

Os nomes dos atributos são semelhantes aos campos no formulário, é importante manter os nomes dos atributos condizentes com as variáveis utilizads no form do **Swing** para facilitar a implementação.

Para criar um evento no Botão Salvar:

* Clique com o botão direito do mouse sobre o botão Salvar.

* Navegue até a propriedade evento>action>actionPerformed.

* A IDE irá apresentar o método salvarActionPerformed criado automaticamente.

~~~~Java
private void salvarActionPerformed(java.awt.event.ActionEvento evt){

}
~~~~

&nbsp;

Agora, será implementar o código dos dados recebidos nos campos do form, primeiro, é necessário instanciar o objeto criado:

~~~~Java
private void salvarActionPerformed(java.awt.event.ActionEvento evt){
    Cadastro objCadastro = new Cadastro();

}
~~~~

&nbsp;

É necessário utilizar o método **getText()** para receber os dados inseridos em um **JTextField**:

~~~~Java
private void salvarActionPerformed(java.awt.event.ActionEvento evt){
    Cadastro objCadastro = new Cadastro();

    objCadastro setNome(nomeCampo.getText());
}
~~~~

&nbsp;

A nomenclatura dos atributos e dos campos facilita a visualizaçõ do código, ``nesse caso, o atributo nome do objeto está recebendo os dados do campo nome do formulário``.

Agora implementando o mesmo método para os outros atributos de texto conforme abaixo incluído o campo **JTextArea**:

~~~~Java
private void salvarActionPerformed(java.awt.event.ActionEvento evt){
    Cadastro objCadastro = new Cadastro();

    objCadastro setNome(nomeCampo.getText());
    objCadastro setCidade(cidadeCampo.getText());
    objCadastro setEmail(emailCampo.getText());
    objCadastro setTelefone(telefoneCampo.getText());
    objCadastro setEndereco(enderecoCampo.getText());
    objCadastro setMotivo(motivoCampo.getText());
}
~~~~

&nbsp;

Agora a implementaçõ do código dos campos de seleção **JCheckBox**, a defirença é que terá que fzer algumas validações pra descobrir se estõ selecionados ou não:

~~~~Java
if(alemaoCampo.isSelected()){
    objCadastro.setAlemao(true);
}

if(italianooCampo.isSelected()){
    objCadastro.setItalianoo(true);
}

if(francesCampo.isSelected()){
    objCadastro.setFrances(true);
}

if(inglesCampo.isSelected()){
    objCadastro.setIngles(true);
}

if(espnholCampo.isSelected()){
    objCadastro.setEspnhol(true);
}

if(japonesCampo.isSelected()){
    objCadastro.setJapones(true);
}
~~~~

&nbsp;

A mesma ideia será utilizada no campo sexo do formulário, mas como ele é uim **buttonGroup**, deve ser feito uma condição para atribuir uma **String** ao Objeto quando um deles estiverem selecionados:

~~~~Java
if(masculinoCampo.isSelected()){
    objCadastro.setSexo("M");
}else{
    objCadastro.setSexo("F");
}
~~~~

&nbsp;

Agora, o **JComboBox**, que se refere ao atributo Estado, o método a ser implementado é o **getSelectedItem()**, mas é necessário observar que o tipo do atributo Estado é **String** e, por isso, terá de realizar um **casting** ou moldagem para converter um objeto ou primitiva de um tipo para outro:

~~~~Java
objCadastro.setEstado((String) estadoCmpo.getSelectedItem());
~~~~

&nbsp;

Para concluir o método salvar, deve inserir uma informação apresentando ao usuário que o formulário foi salvo, para isso, será feito uso da classe **JOptionPane**

Para utilizar o **JOptionPane**, deve importar o pacote **jaavax.swing.JOptionPane**.

O método **showMessageDialog** é responsável por trazer a caixa de mensagem, o qual pode ter muitos argumentos:

~~~~Java
JOptionPane.showMessageDialog(null, "O Cadstro foi salvo");
~~~~

&nbsp;

Outro método que deve ser implementado no projeto é o método **limpar()**, o qual tem o objetivo de eliminar d tela todas as informações que foram digitadas no formulário após clicar no botão Salvar, e nele, será definido novos valores para limpar cada cmpo do formulário, para os campos de texto, **JTextField** e **JTextArea**, basta atribuir "" por meio do método **setText("")**, para os **JCheckBox** deve fazer uso do método **setSelected(false)**:

Para alterar o estado dos **JRadioButton** definidos para representar Masculino e Feminino, deve-se modificar os componentes **buttonGroup1** por meio do método **clearSelection()**

E para alterar o estado do **JComboBox** deve fazer uso da propriedade índex definindo -1 para a sua posição.

&nbsp;

~~~~Java
public void limpar(){
    nomeCampo.setText("");
    enderecoCampo.setText("");
    telefoneCampo.setText("");
    emailCampo.setText("");
    cidadeCampo.setText("");
    motivoCampo.setText("");
    espanholCampo.setSelected(false);
    alemaoCampo.setSelected(false);
    inglesCampo.setSelected(false);
    italianoCampo.setSelected(false);
    francesCampo.setSelected(false);
    japonesCampo.setSelected(false);
    buttonGroup1.clearSelection();
    estadoCampo.setSelectedIndex(-1);
}
~~~~

&nbsp;

Para o método **limpar()** seja executado, deve fazer a chamada no método Salvar antes da mensagem de confirmação de cadastro salvo.

~~~~Java
.
.
.
limpar()

JOptionPane.showMessageDilog(null, "O Cadastro foi salvo");

}

public void limpar(){
    nomeCampo.setText("");
    enderecoCampo.setText("");
    telefoneCampo.setText("");
.
.
.
~~~~

