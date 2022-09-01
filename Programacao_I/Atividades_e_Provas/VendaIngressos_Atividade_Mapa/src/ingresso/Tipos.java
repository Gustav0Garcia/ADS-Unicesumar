/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ingresso;

/**
 *
 * @author Gustavo
 */
public class Tipos {
    
    public float valor;
    public String nome;
    
    public float pista(){
        valor = (float) 100;
        return valor;
    } 
    
    public float vip(){
        valor = (float) (100 + (100*0.3));
        return valor;
    } 
    
    public float camarote(){
        valor = (float) (100 + (100*0.6));
        return valor;
    } 
    
    public String pistaNome(){
        nome = "Pista";
        return nome;
    } 
    
    public String vipNome(){
        nome = "VIP";
        return nome;
    } 
    
    public String camaroteNome(){
        nome = "Camarote";
        return nome;
    } 
}
