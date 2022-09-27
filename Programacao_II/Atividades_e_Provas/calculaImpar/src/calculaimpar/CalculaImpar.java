/*Você pode verificar que estudar programação possibilita criar operações simples e complexas utilizando as estruturas de controle, seleção e repetição. 
No qual estas estruturas permitem que os programas produzam o melhor resultado: escalabilidade. 
Para esta atividade você deverá criar um programa em java para calcular e mostrar a média da soma dos números impares entre 1 e 1000 (inclusive) usando while. */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package calculaimpar;

import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class CalculaImpar {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        // TODO code application logic here
        
        int num = 1; //Variável para ser inserido o valor a ser calculado
        int impar = 0; //Variável para calcular a soma dos números ímpares 
        int cont = 0; //Variável para contar quantos números ímpares e utilizar para calcular a média
        
        Scanner dado = new Scanner(System.in);
        
        
            try{
                System.out.printf("______________________________________________________________\n\nInforme o número para calcular os ímpares ou 0 para sair: ");
                num = dado.nextInt();

                while(num != 0){                

                    for(int i = 1; i <= num; i++)
                        if(i % 2 == 1){ //Para descobrir quando o número é impar
                            impar = impar + i;
                            cont++;
                        }
                    System.out.println("\n______________________________________________________________\n\nSoma dos números ímpares de 1 até " + num + " é igual à: " + impar + "\n" + "Média da soma dos números ímpares de 1 até " + num + " é igual à: " + impar/cont + "\n");
                    impar = 0;
                    cont = 0;
                    System.out.printf("______________________________________________________________\n\nInforme o número para calcular os ímpares ou 0 para sair: ");
                    num = dado.nextInt();
                }
            }catch(ArithmeticException negativo){ //Exception para caso for informado valor negativo
                System.out.printf("______________________________________________________________\n\nErro\n\nApenas número positivos\n\n______________________________________________________________\n\nInforme o número para calcular os ímpares ou 0 para sair: ");
                num = dado.nextInt();

                while(num != 0){                

                    for(int i = 1; i <= num; i++)
                        if(i % 2 == 1){ //Para descobrir quando o número é impar
                            impar = impar + i;
                            cont++;
                        }
                    System.out.println("\n______________________________________________________________\n\nSoma dos números ímpares de 1 até " + num + " é igual à: " + impar + "\n" + "Média da soma dos números ímpares de 1 até " + num + " é igual à: " + impar/cont + "\n");
                    impar = 0;
                    cont = 0;
                    System.out.printf("______________________________________________________________\n\nInforme o número para calcular os ímpares ou 0 para sair: ");
                    num = dado.nextInt();
                }            
            }catch(InputMismatchException letra){ //Exception para caso for informado letra de vez número e finaliza o código
                System.out.printf("______________________________________________________________\n\nErro\n\nNão é possível letras\n\n");
                  
            }           
    }         
}   

