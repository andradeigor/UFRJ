package br.com.bancoomicron.pessoas;

import br.com.bancoomicron.carteiras.IAuditoria;

public class Auditor extends Pessoa {

    public Auditor(String cpf, String nome) {
        super(cpf, nome);
    }

    public boolean auditar(IAuditoria auditado) {
        return (auditado.somaSaldo() / auditado.quantidadeContas()) > 500;
    }

}
