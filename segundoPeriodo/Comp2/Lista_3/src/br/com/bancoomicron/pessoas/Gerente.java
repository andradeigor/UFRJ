/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/

package br.com.bancoomicron.pessoas;


import br.com.bancoomicron.carteiras.CarteiraClientes;
import br.com.bancoomicron.carteiras.CarteiraContas;
import br.com.bancoomicron.carteiras.IAuditoria;

public class Gerente extends Pessoa implements IAuditoria {
    private CarteiraClientes carteiraClientes;
    public Gerente(String cpf, String nome){
        super(cpf,nome);
        this.carteiraClientes = new CarteiraClientes();
    }
    public void adicionarClienteGerente(Cliente C){
        carteiraClientes.adicionarCliente(C);
    }

    public int quantidadeContas(){
        CarteiraContas Contas = carteiraClientes.geraCarteiraContas();
        return Contas.quantidadeContas();
    }
    public double somaSaldo(){
        CarteiraContas Contas = carteiraClientes.geraCarteiraContas();
        return Contas.somaSaldo();
    }
    public void removeClienteGerente(String cpf){
        carteiraClientes.removerCliente(cpf);
    }
}
