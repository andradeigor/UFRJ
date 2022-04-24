package br.com.bancoomicron.contas;
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class ContaPoupanca extends ContaCorrente {

    public ContaPoupanca(int numero, int matricula_cliente) {
        super(numero,matricula_cliente);
    }

    public void render(double juros) {
        this.saldo *= 1+juros;
    }

}
