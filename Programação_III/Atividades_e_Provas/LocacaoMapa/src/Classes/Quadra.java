/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class Quadra {
    
    private String nome;
    private String tipo;
    private int minuto;
    private double valorMinuto;
    private double valorCalculado; //Variável que será utilizada para calcular o valor, com ou sem desconto de horas e com ou sem acrescimo de equipamento
    private String equipamento; //String para captura da resposta da necessidade de equipamento
    private char equip; //Char que irá receber por charAt a resposta da variável equipamento
    
    //Método que realiza cadastro apenas da quadra
    public void cadastrarQuadra(){
        this.setNome(JOptionPane.showInputDialog("               Cadastro da quadra\n________________________________\n\nQuadra: "));
        this.setTipo(JOptionPane.showInputDialog("               Cadastro da quadra\n________________________________\n\nTipo: "));
        //Tratativa para caso for inserido letras em vez de números
        try{
            this.setValorMinuto(Integer.parseInt(JOptionPane.showInputDialog("               Cadastro da quadra\n________________________________\n\nValor do minuto: ")));
        }catch(Exception a){
            JOptionPane.showMessageDialog(null, "Não foi possível converter o valor, será atribuído 5 ao valor do Minuto!\n\n");
            this.setValorMinuto(5);
        }finally{
            //Tratativa para caso for inserido letras em vez de números
            try{
                this.setMinuto(Integer.parseInt(JOptionPane.showInputDialog("               Cadastro da quadra\n________________________________\n\nTempo em minutos: ")));
            }catch(Exception b){
                JOptionPane.showMessageDialog(null, "Não foi possível converter o valor, será atribuído o tempo de 60 minutos!\n\n");
                this.setMinuto(60);               
            }finally{
                //Variável equipamento recebendo a resposta
                this.setEquipamento(JOptionPane.showInputDialog("                    Cadastro da quadra\n____________________________________\n\nNecessita de Equipamento (S - Sim | N - Não): "));
                //Variável equipe recebendo a resposta da variável equipamento através da utilização de charAt
                this.equip = this.equipamento.charAt(0);
                calcularValorLocacao();
            }    
        }    
    }
    
    //Método para calcular valor da locação, utilizando estrutura condicional, para aplicar desconto e o valor do equipamento
    public void calcularValorLocacao(){
        this.valorCalculado = this.minuto * this.valorMinuto;
        
        if(this.minuto >= 120){
            JOptionPane.showMessageDialog(null, "Desconto de 10% para 2h ou mais aplicado!\n\n");
            this.valorCalculado *= 0.9;
        }
        
        if("S".equals(this.equipamento) || "s".equals(this.equipamento)){
            JOptionPane.showMessageDialog(null, "Adicionado valor de R$50,00 pelo equipamento!\n\n");
            this.valorCalculado += 50.0;
        }else{
            this.valorCalculado += 0;
        }

    }
    
    public double getValorCalculado() {
        return valorCalculado;
    }

    public void setValorCalculado(double valorCalculado) {
        this.valorCalculado = valorCalculado;
    }
    
    public int getMinuto() {
        return minuto;
    }

    public void setMinuto(int minuto) {
        this.minuto = minuto;
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public double getValorMinuto() {
        return valorMinuto;
    }

    public void setValorMinuto(double valorMinuto) {
        this.valorMinuto = valorMinuto;
    }

    public String getEquipamento() {
        return equipamento;
    }

    public void setEquipamento(String equipamento) {
        this.equipamento = equipamento;
    }

    public char getEquip() {
        return equip;
    }

    public void setEquip(char equip) {
        this.equip = equip;
    }
    
    
}
