import java.util.HashMap;
import java.util.Map;
import java.util.Set;
/* Infelizmente precisei usar o path completo dos arquivos, no meu pc não funcionou de outra maneira, acredito que seja algo relacionado a
distro linux que uso. Comentei com o professor e ele falou que não teria problema, repare que não só nesse arquivo tem um path, mas
também no AnalisaTexto.java. */ 
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class Main {
    public static void main(String[] args) {
        AnalisaTexto analisaTexto = new AnalisaTexto("/home/igor/COMP/UFRJ/segundoPeriodo/Comp2/Lista_4/Questão_2/poema-tabacaria.txt");
        String invertido = analisaTexto.getTextoInvertido();
        Set<String> sem_repeticao = analisaTexto.palavrasSemRepeticao();
        System.out.println(sem_repeticao.size()/(double) analisaTexto.quebrarTextoEmPalavras().size());
        Map<String, Integer> freq = analisaTexto.computarFrequenciaDasPalavras(false);
        System.out.println(freq.size());
        analisaTexto.imprimePalavraMaisFrequente();
    }

}
