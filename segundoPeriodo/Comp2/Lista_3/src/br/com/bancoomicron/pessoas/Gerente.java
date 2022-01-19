package br.com.bancoomicron.pessoas;

import java.util.ArrayList;

import br.com.bancoomicron.carteiras.CarteiraClientes;
import br.com.bancoomicron.carteiras.CarteiraContas;
import br.com.bancoomicron.carteiras.IAuditoria;

public class Gerente extends Pessoa implements IAuditoria {
    public CarteiraClientes carteira_clientes;
    public Gerente(String cpf, String nome){
        super(cpf,nome);
        this.carteira_clientes = new CarteiraClientes();
    }

    public int quantidadeContas(){
        CarteiraContas Contas = carteira_clientes.geraCarteiraContas();
        return Contas.quantidadeContas();
    }
    public double somaSaldo(){
        CarteiraContas Contas = carteira_clientes.geraCarteiraContas();
        return Contas.somaSaldo();
    }
}
