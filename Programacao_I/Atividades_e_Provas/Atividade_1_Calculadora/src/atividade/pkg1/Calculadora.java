/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package atividade.pkg1;

import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class Calculadora {
    
    public void soma() throws IOException{

        Scanner scan = new Scanner(System.in);
        System.out.println("\n____________________________________________\nSoma\n\nInforme o primeiro numero: ");
        int n1 = scan.nextInt();
        System.out.println("Informe o segundo numero: ");
        int n2 = scan.nextInt();  
        System.out.printf("\nResultado: %d\n\nAperte Enter para voltar ao Menu\n", n1+n2);  
        System.in.read();
    }
    
    public void subtracao() throws IOException{

        Scanner scan = new Scanner(System.in);
        System.out.println("\n____________________________________________\nSubtracao\n\nInforme o primeiro numero: ");
        int n1 = scan.nextInt();
        System.out.println("Informe o segundo numero: ");
        int n2 = scan.nextInt();  
        System.out.printf("\nResultado: %d\n\nAperte Enter para voltar ao Menu\n", n1-n2);  
        System.in.read();
    }
     
    public void multiplicacao() throws IOException{

        Scanner scan = new Scanner(System.in);
        System.out.println("\n____________________________________________\nMultiplicacao\n\nInforme o primeiro numero: ");
        int n1 = scan.nextInt();
        System.out.println("Informe o segundo numero: ");
        int n2 = scan.nextInt();  
        System.out.printf("\nResultado: %d\n\nAperte Enter para voltar ao Menu\n", n1*n2);  
        System.in.read();
    }
    
    public void divisao() throws IOException{

        Scanner scan = new Scanner(System.in);
        System.out.println("\n____________________________________________\nDivisao\n\nInforme o primeiro numero: ");
        int n1 = scan.nextInt();
        System.out.println("Informe o segundo numero: ");
        int n2 = scan.nextInt();  
        System.out.printf("\nResultado: %d\n\nAperte Enter para voltar ao Menu\n", n1/n2);  
        System.in.read();
    }
    
    public void quadrado() throws IOException{

        Scanner scan = new Scanner(System.in);
        System.out.println("\n____________________________________________\nElevar ao quadrado\n\nInforme o numero: ");
        int n1 = scan.nextInt();
        //int n2 = (int) Math.pow(n1, 2);
        System.out.printf("\nResultado: %d\n\nAperte Enter para voltar ao Menu\n", (int) Math.pow(n1, 2));  
        System.in.read();
    }
}
