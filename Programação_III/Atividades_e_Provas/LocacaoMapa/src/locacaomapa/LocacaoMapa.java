/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package locacaomapa;

import Classes.Locatario;
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
        l.mostrarLocatario();
        
        JOptionPane.showMessageDialog(null, "                   Programa Finalizado!\n\nCurso: Análise e Desenvolvimento de Sistemas\nMatéria: Programação III\nAluno: Gustavo Garcia\n\n");
    }    
}
