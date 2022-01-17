package br.com.bancoomicron.contas;

public class ContaPoupanca extends ContaCorrente {

    public ContaPoupanca(int numero, int matricula_cliente) {
        super(numero,matricula_cliente);
    }

    public void render(double juros) {
        this.saldo *= 1+juros;
    }

}
