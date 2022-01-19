package br.com.bancoomicron.carteiras;

import br.com.bancoomicron.pessoas.Cliente;
import br.com.bancoomicron.carteiras.CarteiraContas;
import br.com.bancoomicron.contas.IConta;
import java.util.ArrayList;

public class CarteiraClientes implements IAuditoria {

    private ArrayList<Cliente> clientes;
    public CarteiraClientes() {
        this.clientes = new ArrayList<>();
    }

    public int quantidadeContas() {
        int cnt = 0;
        for (int i = 0;i<this.clientes.size();++i) {
            Cliente c = this.clientes.get(i);
            cnt += c.numContas();
        }
        return cnt;
    }

    public double somaSaldo() {
        double soma = 0;
        for (int i=0;i<this.clientes.size();++i) {
            Cliente c = this.clientes.get(i);
            soma += c.somaSaldos();
        }
        return soma;
    }

    public void adicionarCliente(Cliente c) {
        int verifica = getIndicePorCPF(c.getCpf());
        if(verifica != -1){
            throw new IllegalArgumentException("Cliente já possui uma carteira");
        }else{
            this.clientes.add(c);
        }
    }

    private int getIndicePorCPF(String cpf) {
        for (int i=0;i<this.clientes.size();++i) {
            Cliente c = this.clientes.get(i);
            if (c.getCpf().equals(cpf)) {
                return i;
            }
        }
        return -1;
    }

    public boolean removerCliente(String cpf) {
        int i = this.getIndicePorCPF(cpf);
        if (i < 0) {
            return false;
        } else {
            this.clientes.remove(i);
            return true;
        }
    }
    public CarteiraContas geraCarteiraContas(){
        CarteiraContas Carteiras = new CarteiraContas();
        for (int i = 0; i < this.clientes.size(); i++) {
            Cliente c = this.clientes.get(i);
            CarteiraContas c_contas = c.getContas();
            ArrayList<IConta> Lista_de_contas = c_contas.getContasList();
            for (int j = 0; j < Lista_de_contas.size(); j++) {
                Carteiras.adicionarConta(Lista_de_contas.get(j));
            }
        }
        return Carteiras;
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
        int i = this.getIndicePorCPF(cpf);
        if (i >= 0) {
            return this.clientes.get(i);
        } else {
            return null;
        }
    }

}
