import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class AnalisaTexto {

    private String texto;
    public static final String PONTUACAO = "[!\\\"#$%&'()*+,-./:;<=>?@\\\\[\\\\]^_`{|}~]";

    public AnalisaTexto(String caminhoarq) {
        try {
            FileReader leitorarq = new FileReader(caminhoarq);
            BufferedReader leitorbuf = new BufferedReader(leitorarq);
            String linha = leitorbuf.readLine();
            String texto_nao_tratado = "";
            while (linha != null) {
                texto_nao_tratado += linha + " ";
                linha = leitorbuf.readLine();
            }
            this.texto = this.tratarTexto(texto_nao_tratado);
        } catch (IOException ioe) {
            throw new IllegalArgumentException("Arquivo não pode ser lido!");
        }
    }

    private String tratarTexto(String texto_nao_tratado) {
        String texto_tratado = texto_nao_tratado.toUpperCase();
        texto_tratado = texto_tratado.replaceAll(AnalisaTexto.PONTUACAO,"");
        return texto_tratado;
    }

    public String getTexto() {
        return texto;
    }

    public ArrayList<String> quebrarTextoEmPalavras() {
        String[] arr = this.texto.split("\\s+");
        ArrayList<String> palavras = new ArrayList<>(List.of(arr));
        return palavras;
    }

    public String getTextoInvertido() {
        ArrayList<String> palavras = this.quebrarTextoEmPalavras();
        String texto_invertido = "";
        for(int i = palavras.size()-1; i >= 0; --i) {
            texto_invertido += palavras.get(i) + " ";
        }
        return texto_invertido;
    }

    public Set<String> palavrasSemRepeticao() {
        Set<String> conjunto_palavras = new HashSet<>();
        ArrayList<String> palavras = this.quebrarTextoEmPalavras();
        for (int i = 0;i < palavras.size(); ++i) {
            conjunto_palavras.add(palavras.get(i));
        }
        return conjunto_palavras;
    }

    public void imprimePalavrasSemRepeticao() {
        Set<String> conjunto_palavras = this.palavrasSemRepeticao();
        for (String palavra : conjunto_palavras) {
            System.out.println(palavra);
        }
    }

    public Map<String, Integer> computarFrequenciaDasPalavras() {
        Map<String, Integer> frequencia_palavras = new HashMap<>();
        ArrayList<String> palavras = this.quebrarTextoEmPalavras();
        for (String palavra : palavras) {
            if (frequencia_palavras.containsKey(palavra)) {
                Integer freq = frequencia_palavras.get(palavra);
                freq += 1;
                frequencia_palavras.put(palavra,freq);
            } else {
                frequencia_palavras.put(palavra,1);
            }
        }
        return frequencia_palavras;
    }
    public Map<String, Integer> computarFrequenciaDasPalavras(boolean remover_stop_words) {
        return remover_stop_words? this.computarFrequenciaDasPalavrasHelper(): this.computarFrequenciaDasPalavras();
    }
    public Map<String, Integer> computarFrequenciaDasPalavrasHelper(){
        Map<String, Integer> frequencia_palavras = new HashMap<>();
        ArrayList<String> palavras = this.quebrarTextoEmPalavras();
        String string_stop_words = "";
        try {
            FileReader leitorarq2 = new FileReader("../stop_words.txt");
            BufferedReader leitorbuf2 = new BufferedReader(leitorarq2);
            String linha = leitorbuf2.readLine();
            String texto_nao_tratado = "";
            while (linha != null) {
                texto_nao_tratado += linha + " ";
                linha = leitorbuf2.readLine();
            }
            string_stop_words = this.tratarTexto(texto_nao_tratado);
        } catch (IOException ioe) {
            throw new IllegalArgumentException("Arquivo não pode ser lido!");
        }
        String[] arr = string_stop_words.split("\\s+");
        ArrayList<String> lista_stop_words = new ArrayList<>(List.of(arr));
        palavras.removeAll(lista_stop_words);
        for (String palavra : palavras) {
            if (frequencia_palavras.containsKey(palavra)) {
                Integer freq = frequencia_palavras.get(palavra);
                freq += 1;
                frequencia_palavras.put(palavra,freq);
            } else {
                frequencia_palavras.put(palavra,1);
            }
        }
        return frequencia_palavras;
    }
    public void imprimePalavraMaisFrequente() {
        Map<String, Integer> frequencia_palavras = this.computarFrequenciaDasPalavras();
        int freq_max = 0;
        String palavra_mais_freq = "";
        for (String palavra: frequencia_palavras.keySet()) {
            int freq = frequencia_palavras.get(palavra);
            if (freq > freq_max) {
                freq_max = freq;
                palavra_mais_freq = palavra;
            }
        }
        System.out.println("A palavra " + palavra_mais_freq + " é a mais frequente.");
        System.out.print("Sua frequência é de: ");
        System.out.println(freq_max);
    }
}
