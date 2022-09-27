/* Um professor de matemática pede a você que ajude a criar um programa que auxilie na resolução das operações em equação do segundo grau completas. 
Para isso ele pede que você crie um programa em que os alunos informem os 3 valores e o programa calcule a equação de segundo grau. 
O professor espera que o aluno tenha um entendimento claro do que está sendo solicitado e para isso ele quer que o programa solicite as variáveis da seguinte forma:

Etapa 1 
Informe o valor de ‘a’
Informe o valor de ‘b’
Informe o valor de ‘c’

Etapa 2
E como resposta, após o cálculo ele espera que o programa responda:
O valor de delta é: ??????
O valor de x1 é: ??????
O valor de x2 é: ??????

Agora se o delta for negativo ele espera a seguinte resposta:
O valor de delta é: ??????
Não existem raízes reais.
 
Para esta atividade mapa você pode utilizar a função Math.pow(x,2) para elevar a variável ‘x’ ao quadrado, e a função Math.sqrt(x) para calcular a raiz quadrada de ‘x’. 
Se utilizar outras variáveis é só substituir a variável x pela sua correspondente. 
Importante é que você deve utilizar exceção para quando não existir uma raiz real usando o seguinte método estático para cálculo do delta

    private static double calcularDelta(int a, int b, int c) throws IllegalArgumentException{
        double delta = Math.pow(b,2) - 4*a*c;
        if (delta<0) {
            throw new IllegalArgumentException("Delta é: "+delta+"\nNão existem raízes reais.");
        }
        return delta;
    }

​Lembrando que o cálculo do x1 e x2 pode ser realizado pelas fórmulas:
double x1 = (-b + Math.sqrt(delta)) / (2 * a);
double x2 = (-b - Math.sqrt(delta)) / (2 * a); */

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package equacaosegundograu;

import java.util.Scanner;

/**
 *
 * @author Gustavo
 */
public class EquacaoSegundoGrau {
    
    //Aqui seria outra classe a ser criada
    private static double calcularDelta(double a, double b, double c) throws IllegalArgumentException{
        double delta = Math.pow(b,2) - 4*a*c;
        
        if (delta<0) {
            throw new IllegalArgumentException("\n\nDelta é: " + delta + "\nNão existem raízes reais.\n\n");
        }
        return delta;
    }


    /**
     * @param args the command line arguments
     * @throws java.lang.InterruptedException
     */
    
    //Main
    public static void main(String[] args) throws InterruptedException {
        // TODO code application logic here
        
        int aux = 0; //Variável para utilizar no loop
        int aux2 = 1; //Variável para utilizar no Switch Case       
        double a = 0; //A da equação.
	double b = 0; //B da equação.
	double c = 0; //C da equação. 
        double delta = 0; //Delta da equação
	double x1 = 0; //Primeira raiz da equação. 
	double x2 = 0; //Segunda raiz da equação. 
        
        Scanner dado = new Scanner(System.in);
        System.out.printf("______________________________________________________________\n\nSelecione:\n\n1 - Para realizar o Cálculo da Equação de Segundo Grau\n0 - Sair\n\nOpção: ");
        aux = dado.nextInt();        
        
        do{
            switch(aux){
                case 1:
                    try{
                        while(aux == 1){
                            //Inserir valores de A, B e C
                            System.out.printf("\n______________________________________________________________\n\nInsira o valor de A: ");
                            a = dado.nextDouble();
                            System.out.printf("Insira o valor de B: ");
                            b = dado.nextDouble();
                            System.out.printf("Insira o valor de C: ");
                            c = dado.nextDouble();

                            //Imprime os valores inseridos para conferir
                            System.out.println("\n______________________________________________________________\n\nValores inseridos:\n\nValor de A: " + a + "\nValor de B: " + b + "\nValor de C: " + c + "\n______________________________________________________________");
                            Thread.sleep(2000);

                            //Cálculo do Delta
                            delta = calcularDelta(a, b, c);

                            //Cálculo do x1 e x2
                            x1 = (-b + Math.sqrt(delta)) / (2 * a);
                            x2 = (-b - Math.sqrt(delta)) / (2 * a);

                            System.out.println("\nValores calculados:\n\nValor de Delta: " + delta + "\nValor de x1: " + x1 + "\nValor de x2: " + x2 + "\n______________________________________________________________");
                            Thread.sleep(2000);
                            
                            //Reseta as variáveis para caso for necessário nova consulta
                            a = 0;
                            b = 0;
                            c = 0;
                            delta = 0;
                            x1 = 0;
                            x2 = 0;

                            System.out.printf("\nSelecione:\n\n1 - Para realizar o Cálculo da Equação de Segundo Grau\n0 - Sair\n\nOpção: ");
                            aux = dado.nextInt();   
                        }
                    }catch(IllegalArgumentException e){ //Aqui é tratada a Exception que foi utilizada com Throw anteriormente

                        delta = Math.pow(b,2) - 4*a*c;
                        System.out.println("\nDelta é: " + delta + "\nNão existem raízes reais.\n______________________________________________________________");

                        while(aux == 1){

                            System.out.printf("\nSelecione:\n\n1 - Para realizar o Cálculo da Equação de Segundo Grau\n0 - Sair\n\nOpção: ");
                            aux = dado.nextInt();  
                            
                            if(aux != 0 && aux != 1 || aux == 0){ //If para caso for inserido opção diversa 
                                break;    
                            }
                            
                            //Inserir valores de A, B e C
                            System.out.printf("\n______________________________________________________________\n\nInsira o valor de A: ");
                            a = dado.nextDouble();
                            System.out.printf("Insira o valor de B: ");
                            b = dado.nextDouble();
                            System.out.printf("Insira o valor de C: ");
                            c = dado.nextDouble();

                            //Imprime os valores inseridos para conferir
                            System.out.println("\n______________________________________________________________\n\nValores inseridos:\n\nValor de A: " + a + "\nValor de B: " + b + "\nValor de C: " + c + "\n______________________________________________________________");
                            Thread.sleep(2000);

                            //Cálculo do Delta
                            delta = calcularDelta(a, b, c);

                            //Cálculo do x1 e x2
                            x1 = (-b + Math.sqrt(delta)) / (2 * a);
                            x2 = (-b - Math.sqrt(delta)) / (2 * a);

                            System.out.println("\nValores calculados:\n\nValor de Delta: " + delta + "\nValor de x1: " + x1 + "\nValor de x2: " + x2 + "\n______________________________________________________________");
                            Thread.sleep(2000);
                            
                            //Reseta as variáveis para caso for necessário nova consulta
                            a = 0;
                            b = 0;
                            c = 0;
                            delta = 0;
                            x1 = 0;
                            x2 = 0;

                            System.out.printf("\nSelecione:\n\n1 - Para realizar o Cálculo da Equação de Segundo Grau\n0 - Sair\n\nOpção: ");
                            aux = dado.nextInt();   
                        }
                    }
                    break;
                default:

                    if(aux == 0){
                        
                        aux2 = 0;
                        System.out.println("\n______________________________________________________________\n\nCurso: Análise e Desenvolvimento de Sistemas\nMatéria: Programacao II\nAluno: Gustavo Garcia\nRA: 21025427-5\n\nSaindo do programa em 5 segundos\n1 segundo");
                        Thread.sleep(1000);

                        for(int i = 2; i < 6; i++){
                            System.out.println("" +i + " segundos");
                            Thread.sleep(1000);
                        }
                        System.out.println("Programa Finalizado!\n");

                    }else if(aux != 0 && aux != 1){
                        
                        System.out.println("______________________________________________________________\n\nOpção inválida" );
                        Thread.sleep(1000);
                        aux2 = 1;
                        System.out.printf("______________________________________________________________\n\nSelecione:\n\n1 - Para realizar o Cálculo da Equação de Segundo Grau\n0 - Sair\n\nOpção: ");
                        aux = dado.nextInt();       
                    }
            }
        }while(aux2 == 1);    
    }
}
