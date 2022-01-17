package br.com.bancoominicron.contas;

public class ContaCorrente extends Conta{
    public ContaCorrente(int numero, int matricula_cliente){
        super(numero, matricula_cliente);
    }

    public boolean sacar(double valor){
        return valor<=this.saldo && sacarHelper(valor);
    }
    public boolean sacarHelper(double valor){
        this.saldo -= valor;
        return true;
    }
}
