package br.com.bancoomicron.carteiras;

import br.com.bancoomicron.contas.IConta;
import java.util.HashSet;
import java.util.Set;


public class CarteiraContas implements IAuditoria {

    private Set<IConta> contas;

    public CarteiraContas() {
        this.contas = new HashSet<>();
    }

    public int tamanho() {
        return this.contas.size();
    }

    public int quantidadeContas() {
        return this.tamanho();
    }

    public double somaSaldo() {
        double soma = 0;
        for (IConta c: contas) {
            soma += c.getSaldo();
        }
        return soma;
    }

    public void adicionarConta(IConta c) {
        this.contas.add(c);
    }

    public boolean removerConta(int numero) {
        for (IConta c : contas) {
            if (c.getNumero() == numero) {
                this.contas.remove(c);
                return true;
            }
        }
        return false;
    }

    public IConta getConta(int numero) {
        for(IConta c: contas){
            if(c.getNumero() == numero){
                return c;
            }
        }
        return null;
    }
    public Set<IConta> getContas(){
        return this.contas;
    }
}
