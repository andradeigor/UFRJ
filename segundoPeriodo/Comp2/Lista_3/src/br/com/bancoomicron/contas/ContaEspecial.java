
package br.com.bancoomicron.contas;
public class ContaEspecial extends ContaCorrente {

    private double cheque_especial;
    private final double taxa_iof = 0.03;

    public ContaEspecial(int numero, int matricula_cliente, double cheque_especial) {
        super(numero,matricula_cliente);
        this.cheque_especial = cheque_especial;
    }

    @Override
    public boolean sacar(double valor) {

        boolean tem_fundos = super.sacar(valor);
        if (tem_fundos) {
            return true;
        } else {
            double valor_emprestado = valor - Math.max(0,this.saldo);
            double imposto_iof = valor_emprestado * this.taxa_iof;
            double novo_saldo = this.saldo - valor - imposto_iof;
            if (novo_saldo <= cheque_especial) {
                this.saldo = novo_saldo;
                return true;
            } else {
                return false;
            }
        }
    }
}
