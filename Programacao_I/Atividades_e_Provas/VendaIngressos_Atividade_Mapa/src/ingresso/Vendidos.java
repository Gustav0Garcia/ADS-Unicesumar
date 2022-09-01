/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ingresso;

import evento.Evento;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class Vendidos extends Ingresso{
    
    private List<Ingresso> vendas;
    private int contador;

   
    
    public Vendidos(String evento, String nome, String cpf, String data, float valor, String tipoIngresso, int capacidade, int cod){
        super(evento, nome, cpf, data, valor, tipoIngresso, capacidade, cod);
        this.vendas = new ArrayList<Ingresso>();
    }
    
    public void cadastrarVenda(Ingresso venda){
        vendas.add(venda);
    }
    
    Evento e = new Evento();
    
    public void resumoVenda() {
        String msg = "Evento " + e.getNomeEvento() + "\n";
        msg += "Data: " + e.getDataEvento() + "\n____________________________________________\n";
        
        for(int i = 0; i < vendas.size(); i++){
            String nomeCliente = vendas.get(i).getNome();
            String cpfCliente = vendas.get(i).getCpf();
            String tipoIng = vendas.get(i).getTipoIngresso();
            float valorIng = vendas.get(i).getValor();
            int codigo = vendas.get(i).getCod();
            int cont = getContador();
            msg += "\nNome: " + nomeCliente + "\nCPF: " + cpfCliente + "\nTipo: " + tipoIng + "\nValor do ingresso: R$ " + valorIng + "0" + "\nCódigo do ingresso:  " + codigo + "\nQuantidade: " + cont + "/200" + "\n____________________________________________\n";
        }
        JOptionPane.showMessageDialog(null, msg);
    }

    public List<Ingresso> getVendas() {
        return vendas;
    }

    public void setVendas(List<Ingresso> vendas) {
        this.vendas = vendas;
    }

    public int getContador() {
        return contador;
    }

    public void setContador(int contador) {
        this.contador = contador;
    }
  
    
}
