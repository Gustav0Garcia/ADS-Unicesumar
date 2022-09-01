/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package vendaingressos;

import evento.Evento;
import ingresso.Ingresso;
import ingresso.Tipos;
import ingresso.Vendidos;
import java.util.Random;
import java.util.Scanner;
import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class VendaIngressos {

    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    public static void main(String[] args) throws InterruptedException {
        // TODO code application logic here
        //Aqui inseri ingressos para poder contabilizar certa quantidade
        Random random = new Random(); //gerar números aleatórios para utilizar como código no ingresso            
        Tipos t = new Tipos();
        Evento e = new Evento();
        Ingresso i1 = new Ingresso(e.getNomeEvento(), "Gustavo", "000.000.000-00", e.getDataEvento(), t.pista(), t.pistaNome(), e.getCapacidade(), random.nextInt(1000));
        Ingresso i2 = new Ingresso(e.getNomeEvento(), "Ana Paula", "111.111.111-11", e.getDataEvento(), t.vip(), t.vipNome(), e.getCapacidade(), random.nextInt(1000));
        Ingresso i3 = new Ingresso(e.getNomeEvento(), "João", "222.222.222-22", e.getDataEvento(), t.camarote(), t.camaroteNome(), e.getCapacidade(), random.nextInt(1000));
        int i = 00; //variável criada para ajudar no controle da capacidade do evento
        Vendidos v = new Vendidos(e.getNomeEvento(), "Gustavo", "000.000.000-00", e.getDataEvento(), t.pista(), t.pistaNome(), e.getCapacidade(), random.nextInt(1000));
        v.cadastrarVenda(i1);
        i++;
        v.setContador(i);
        v.cadastrarVenda(i2);
        i++;
        v.setContador(i);
        v.cadastrarVenda(i3);
        i++;
        v.setContador(i);
        
        int aux;
        
        
        do{
            
            Menu m = new Menu();
            m.menu();
            Scanner input = new Scanner(System.in);
            aux = input.nextInt();
            
            switch(aux){
                case 1:
                    if(v.getContador() <= 200){
                        String leituraNome = JOptionPane.showInputDialog("Informe o nome: ");  
                        String leituraCpf = JOptionPane.showInputDialog("Informe o CPF: ");  
                        Ingresso i4 = new Ingresso(e.getNomeEvento(), leituraNome, leituraCpf, e.getDataEvento(), t.pista(), t.pistaNome(), e.getCapacidade(), random.nextInt(1000)); 
                        v.cadastrarVenda(i4);
                        i++;
                        v.setContador(i);
                        JOptionPane.showMessageDialog(null, "Ingresso " +i + "/200 cadastrado\nPressione Enter para ver o resumo do cadastro");
                        System.out.println("\n");
                        i4.resumo();
                        Thread.sleep(2000);
                    }else
                        JOptionPane.showMessageDialog(null, "Capacidade máxima do Evento atingida: " +i + "/200");
                    break;
                case 2:
                    v.resumoVenda();
                    break;
                default:
                    System.out.println("\n\n____________________________________________\nCurso: Analise e Desenvolvimento de Sistemas\nMateria: Programacao I\nAluno: Gustavo Garcia\n\nSaindo do programa em 5 segundos\n1 segundo");
                    Thread.sleep(1000); //pausa por 1s  para mostrar a contagem
                
                    for(int j = 2; j < 6; j++){
                        System.out.println("" +j + " segundos");
                        Thread.sleep(1000); //pausa por 1s a cada repetição para mostrar a contagem
                    }
                    System.out.println("Programa Finalizado!\n");
            }
        }while(aux != 0);         
    }
}