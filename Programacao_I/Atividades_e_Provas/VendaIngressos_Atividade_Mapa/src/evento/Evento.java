/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package evento;

import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class Evento {
    
    private String nomeEvento = "Mamonas Assassinas Cover";
    private String dataEvento = "10/06/2023";
    private float valorUnico = 100f;
    private int capacidade = 200;

    public String getNomeEvento() {
        return nomeEvento;
    }

    public void setNomeEvento(String nomeEvento) {
        this.nomeEvento = nomeEvento;
    }

    public String getDataEvento() {
        return dataEvento;
    }

    public void setDataEvento(String dataEvento) {
        this.dataEvento = dataEvento;
    }

    public float getValorUnico() {
        return valorUnico;
    }

    public void setValorUnico(float valorUnico) {
        this.valorUnico = valorUnico;
    }

    public int getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(int capacidade) {
        this.capacidade = capacidade;
    }
    
    public void mostraEvento() {
        JOptionPane.showMessageDialog(null, "Nome do evento: " +getNomeEvento() + "\nData do evento: " + getDataEvento() + "\nValor único do ingresso: R$ "  +getValorUnico() + "\nCapacidade do evento: " +getCapacidade());
    }
    
}
