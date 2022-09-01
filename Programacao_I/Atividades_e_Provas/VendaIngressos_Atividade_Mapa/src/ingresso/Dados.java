/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ingresso;

/**
 *
 * @author Gustavo
 */
public class Dados {
    
    private String evento;
    private String cpf;
    private String nome;
    private String data;
    private float valor;
    private int capacidade;
    private String tipoIngresso;
    
    public Dados(String evento, String nome, String cpf, String data, float valor, String tipoIngresso, int capacidade){
        this.evento = evento;
        this.nome = nome;
        this.cpf = cpf;
        this.data = data;
        this.capacidade = capacidade;
        this.valor = valor;
        this.tipoIngresso = tipoIngresso;
        
    }

    public String getEvento() {
        return evento;
    }

    public void setEvento(String evento) {
        this.evento = evento;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getData() {
        return data;
    }

    public void setData(String data) {
        this.data = data;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }

    public String getTipoIngresso() {
        return tipoIngresso;
    }

    public void setTipoIngresso(String tipoIngresso) {
        this.tipoIngresso = tipoIngresso;
    }
    
    

    public void Imprime(){
        System.out.println("____________________________________________\n\nEvento: " +getEvento()  + "\nData do evento: " +getData() + "\nNome: " +getNome() + "\nCPF: " +getCpf() + "\nTipo: " +getTipoIngresso() + "\nValor do ingresso: R$ " +getValor() + "0" + "\nCapacidade do evento: " +getCapacidade());
       
    }
}
