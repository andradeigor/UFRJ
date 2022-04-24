package br.com.bancoomicron.contas;
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public interface IConta {
    void depositar(double valor);
    boolean sacar(double valor);
    double getSaldo();
    int getNumero();
}
