import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        AnalisaTexto analisaTexto = new AnalisaTexto("/home/igor/COMP/UFRJ/segundoPeriodo/Comp2/Lista_4/Questão_2/poema-tabacaria.txt");
        String invertido = analisaTexto.getTextoInvertido();
        Set<String> sem_repeticao = analisaTexto.palavrasSemRepeticao();
        System.out.println(sem_repeticao.size()/(double) analisaTexto.quebrarTextoEmPalavras().size());
        Map<String, Integer> freq = analisaTexto.computarFrequenciaDasPalavras(true);
        System.out.println(freq.size());
        analisaTexto.imprimePalavraMaisFrequente();
    }

}
