package br.com.bancoomicron.carteiras;
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
import br.com.bancoomicron.contas.IConta;
import br.com.bancoomicron.pessoas.Cliente;

import java.security.InvalidParameterException;
import java.util.HashSet;
import java.util.Set;


public class CarteiraClientes implements IAuditoria {

    private Set<Cliente> clientes;
    public CarteiraClientes() {
        this.clientes = new HashSet<Cliente>();
    }

    public int quantidadeContas() {
        int cnt = 0;
        for (Cliente c: clientes) {
            cnt += c.numContas();
        }
        return cnt;
    }

    public double somaSaldo() {
        double soma = 0;
        for (Cliente c: clientes) {
            soma += c.somaSaldos();
        }
        return soma;
    }

    public void adicionarCliente(Cliente c) throws InvalidParameterException {
        if(this.getClientePorCPF(c.getCpf())!=null){
            throw new InvalidParameterException("O cliente já pertence a essa carteira!");
        }
        clientes.add(c);
    }

    private Cliente getClientePorCPF(String cpf) {
        for(Cliente c: clientes){
            if(c.getCpf().equals(cpf)){
                return c;   
            }
        }
        return null;
    }

    public boolean removerCliente(String cpf) {
        Cliente i = this.getClientePorCPF(cpf);
        return i!=null? this.clientes.remove(i): false;
    }

    public int removerCliente(String[] cpfs) {
        int cnt = 0;
        for (int i=0;i<cpfs.length;++i) {
            if (removerCliente(cpfs[i])) {
                cnt += 1;
            }
        }
        return cnt;
    }

    public Cliente buscaCPF(String cpf) {
       return this.getClientePorCPF(cpf);
    }

    public CarteiraContas getContasClientes() {
        CarteiraContas contas = new CarteiraContas();
        for (Cliente c: clientes) {
            Set<IConta> contas_cliente = c.getCarteiraContas().getContas();
            for (IConta conta_cliente:contas_cliente) {
                contas.adicionarConta(conta_cliente);
            }
        }
        return contas;
    }

}
