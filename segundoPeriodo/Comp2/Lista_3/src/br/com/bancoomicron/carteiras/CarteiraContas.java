/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/

package br.com.bancoomicron.carteiras;

import br.com.bancoomicron.contas.IConta;
import java.util.ArrayList;

public class CarteiraContas implements IAuditoria {

    private ArrayList<IConta> contas;

    public CarteiraContas() {
        this.contas = new ArrayList<>();
    }

    public int tamanho() {
        return this.contas.size();
    }

    public int quantidadeContas() {
        return this.tamanho();
    }
    public ArrayList<IConta> getContasList(){
        return this.contas;
    }
    public double somaSaldo() {
        double soma = 0;
        for (int i=0;i<this.contas.size();++i) {
            IConta c = this.contas.get(i);
            soma += c.getSaldo();
        }
        return soma;
    }

    public void adicionarConta(IConta c) {
        this.contas.add(c);
    }

    public boolean removerConta(int numero) {
        for (int i=0;i<this.contas.size();++i) {
            IConta c = this.contas.get(i);
            if (c.getNumero() == numero) {
                this.contas.remove(i);
                return true;
            }
        }
        return false;
    }

}
