/* Para esta Atividade 01, considere que você aluno de ADS, foi convidado para participar de uma seleção de desenvolvedores "Junior" de uma empresa da cidade de Maringá-PR.
Nesta seleção, você deverá cumprir alguns desafios na forma de desenvolvimento de programas.
Ao final do programa, você será analisado e, se obtiver sucesso, poderá ser contratado.

Como primeiro desafio, você deverá criar um programa que funcione como uma CALCULADORA na linguagem de programação Java. 
Para a construção desta CALCULADORA, você deverá utilizar a IDE de desenvolvimento NetBeans - a mesma que foi utilizado na disciplina.
O programa pode ser em uma única classe, ou caso prefira, utilize quantas classes achar necessário.

Requisitos do sistema:
1 - O programa deve possuir métodos para realizar as operações: soma, subtração, multiplicação, divisão e quadrado de um numero (número elevado ao quadrado).

Funcionamento do programa CALCULADORA
1 - A interface (em linha de comando) deve pedir para o usuário digitar a operação desejada e, em seguida, solicitar os números que serão utilizados na operação. Em seguida, calcula e exibe o resultado.
2 - O programa deve repetir esse passo até que o usuário digite um "0" como operação. */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package atividade.pkg1;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Atividade1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, InterruptedException{
        // TODO code application logic here
        int opc;
        do{

            Menu m = new Menu();
            m.menu();
            Scanner input = new Scanner(System.in);
            opc = input.nextInt();
            
            Calculadora c = new Calculadora();
            switch(opc){
            case 1:
                c.soma();
                break;
            case 2:    
                c.subtracao();
                break;
            case 3:    
                c.multiplicacao();
                break;
            case 4:    
                c.divisao();
                break;  
            case 5:    
                c.quadrado();
                break;       
            default:    
                System.out.println("\n\n____________________________________________\nCurso: Analise e Desenvolvimento de Sistemas\nMateria: Programacao I\nAluno: Gustavo Garcia\n\nSaindo do programa em 5 segundos\n1 segundo");
                Thread.sleep(1000); //pausa por 1s  para mostrar a contagem
                
               for(int i = 2; i < 6; i++){
                   System.out.println("" +i + " segundos");
                   Thread.sleep(1000); //pausa por 1s a cada repetição para mostrar a contagem
               }
               System.out.println("Programa Finalizado!\n");
            }    
        }while (opc != 0);
    }
}
