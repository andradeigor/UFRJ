import br.com.bancoomicron.carteiras.CarteiraContas;
import br.com.bancoomicron.contas.*;
import br.com.bancoomicron.pessoas.Auditor;
import br.com.bancoomicron.pessoas.Cliente;

public class Main {
    public static void main(String[] args) {
        CarteiraContas carteira = new CarteiraContas();
        Cliente cliente = new Cliente("9999999999","Matheus Fernandes");
        ContaCorrente corrente = new ContaCorrente(123, cliente.getMatricula());
        ContaPoupanca poupanca = new ContaPoupanca(999, cliente.getMatricula());
        ContaEspecial especial = new ContaEspecial(888, cliente.getMatricula(),1000);
        carteira.adicionarConta(corrente);
        carteira.adicionarConta(poupanca);
        carteira.adicionarConta(especial);
        Auditor auditor = new Auditor("123456575","Tomas Loureiro");
        System.out.println(auditor.auditar(carteira));
    }
}
