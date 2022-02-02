package br.com.bancoomicron.carteiras;

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
        boolean TemCliente = clientes.add(c);
        if(!TemCliente){
            throw new InvalidParameterException("O cliente já pertence a essa carteira!");
        }
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
        if (i==null) {
            return false;
        } else {
            this.clientes.remove(i);
            return true;
        }
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
        Cliente i = this.getClientePorCPF(cpf);
        if (i!=null) {
            return i;
        } else {
            return null;
        }
    }

    public CarteiraContas getContasClientes() {
        CarteiraContas contas = new CarteiraContas();
        for (Cliente c: clientes) {
            CarteiraContas contas_cliente = c.getCarteiraContas();
            for (int j=0;j<contas_cliente.tamanho();++j) {
                contas.adicionarConta(contas_cliente.getConta(j));
            }
        }
        return contas;
    }

}
