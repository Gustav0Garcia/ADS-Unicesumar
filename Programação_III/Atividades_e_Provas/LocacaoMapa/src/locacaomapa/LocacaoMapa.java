/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package locacaomapa;

import Classes.Locatario;
import Classes.Quadra;
import javax.swing.JOptionPane;


/**
 *
 * @author Gustavo
 */
public class LocacaoMapa {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        
        Locatario l  = new Locatario();
        l.cadastrarLocatario();
        
        if(l.verificarIdade() == true){
            Quadra q = new Quadra();
            q.cadastrarQuadra();
            q.calcularValorLocacao();
            

            JOptionPane.showMessageDialog(null, "Resumo da locação\n\nLocatário\n\nNome: " + l.getNome() + "\nCPF: " + l.getCpf() + "\nTelefone: " + l.getTelefone() + "\nAno de Nascimento: " + l.getAnoNascimento() + "\n\nQuadra\n\nNome da quadra: " + q.getNome() + "\nTipo: " + q.getTipo() + "\nValor do minuto: R$" + q.getValorMinuto() + "\n\nLocação\n\nTempo em minutos: " + q.getMinuto() + "\nNecessita Equipamento: " + q.getEquip() + "\nValor calculado: R$" + q.getValorCalculado());  
        }      
    }    
}
