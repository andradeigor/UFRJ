/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/


package br.com.bancoomicron.contas;

public interface IConta {
    
    public void depositar(double valor);

    public boolean sacar(double valor);

    public double getSaldo();

    public int getNumero();
}
