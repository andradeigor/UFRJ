package br.com.bancoomicron.contas;

import java.io.FileNotFoundException;

public class ContaCorrente implements IConta {
    protected double saldo;
    protected int numero;
    protected int matricula_cliente;
    public ContaCorrente(int numero, int matricula_cliente) {
        this.numero = numero;
        this.matricula_cliente = matricula_cliente;
        this.saldo = 0;
    }

    public void depositar(double valor){
        this.saldo +=valor;
    }

    public double getSaldo() {
        return saldo;
    }

    public int getNumero() {
        return numero;
    }

    @Override
    public boolean sacar(double valor) {
        if (valor <= this.saldo) {
            this.saldo -= valor;
            return true;
        } else {
            return false;
        }
    }
}
