package ingresso;

import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */


/**
 *
 * @author Gustavo 
 */
public class Ingresso extends Dados{
    
    private int cod;
    
    public Ingresso(String evento, String nome, String cpf, String data, float valor, String tipoIngresso, int capacidade, int cod){
        super(evento, nome, cpf, data, valor, tipoIngresso, capacidade);
        this.cod = cod;
    }

    public int getCod() {
        return cod;
    }

    public void setCod(int cod) {
        this.cod = cod;
    }

    
    
    public void resumo() {
        super.Imprime();
        System.out.println("Código do ingresso: " +cod + "\n____________________________________________\n");
    }

}
