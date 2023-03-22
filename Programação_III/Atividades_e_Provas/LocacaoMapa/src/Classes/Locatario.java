/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Classes;

import java.util.Calendar;
import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class Locatario {

    private String nome;
    private String cpf;
    private String telefone;
    private int anoNascimento;
    
    public void cadastrarLocatario(){
        this.setNome(JOptionPane.showInputDialog("Cadastro do locatário\nNome: \n"));
        this.setCpf(JOptionPane.showInputDialog("Cadastro do locatário\nCPF: \n"));
        this.setTelefone(JOptionPane.showInputDialog("Cadastro do locatário\nTelefone: \n"));
        try{
            this.setAnoNascimento(Integer.parseInt(JOptionPane.showInputDialog("Cadastro do locatário\nAno de nascimento: \n")));
        }catch(NumberFormatException a){
            JOptionPane.showMessageDialog(null, "Não foi possível converter o valor, será atribuído 0!\n\n");
            this.setAnoNascimento(0);
        }          
    }
    
    public void mostrarLocatario(){
        JOptionPane.showMessageDialog(null, "Resumo da locação\n\nLocatário\n\nNome: " + this.getNome() + "\nCPF: " + this.getCpf() + "\nTelefone: " + this.getTelefone() + "\nAno de Nascimento: " + this.getAnoNascimento() + "\n\n");
    }
    
    public boolean verificarIdade() {
        int idade = Calendar.getInstance().get(Calendar.YEAR) - getAnoNascimento();
        if (idade < 18){
            JOptionPane.showMessageDialog(null, "Locatário é menor de idade!\n\nEncerrando aplicativo!\n\n");
            return false;
        }else{
            JOptionPane.showMessageDialog(null, "Locatário é maior de idade!\n\n");
            return true;
        }
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public int getAnoNascimento() {
        return anoNascimento;
    }

    public void setAnoNascimento(int anoNascimento) {
        this.anoNascimento = anoNascimento;
    }
}
