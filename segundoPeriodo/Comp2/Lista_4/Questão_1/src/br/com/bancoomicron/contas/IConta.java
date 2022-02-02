package br.com.bancoomicron.contas;

public interface IConta {
    void depositar(double valor);
    boolean sacar(double valor);
    double getSaldo();
    int getNumero();
}
