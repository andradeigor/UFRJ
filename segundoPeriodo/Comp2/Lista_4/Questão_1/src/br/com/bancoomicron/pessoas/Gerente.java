package br.com.bancoomicron.pessoas;

import br.com.bancoomicron.carteiras.CarteiraClientes;
import br.com.bancoomicron.carteiras.IAuditoria;

public class Gerente extends Pessoa implements IAuditoria  {

    private CarteiraClientes clientes;

    public Gerente(String cpf, String nome) {
        super(cpf,nome);
        this.clientes = new CarteiraClientes();
    }

    @Override
    public int quantidadeContas() {
        return this.clientes.quantidadeContas();
    }

    @Override
    public double somaSaldo() {
        return this.clientes.somaSaldo();
    }
}
