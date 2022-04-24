import java.util.HashMap;
import java.util.Map;
import java.util.Set;
/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class Main {
    public static void main(String[] args) {
        long Numero = 9000010011l;
        System.out.println(Main.numeroParaTexto(Numero));
    }
    public static String numeroParaTexto(long Numero){

        String string_number = String.valueOf(Numero);
        System.out.println(string_number);
        Integer base = string_number.length()-1;
        if(base >=12){
            return "Um Trilhão";
        }
        Map<String, String> string_numeros = new HashMap<>();
        string_numeros.put("0",""); string_numeros.put("00","");        string_numeros.put("000","");

        string_numeros.put("1", "Um "); string_numeros.put("2", "Dois ");
        string_numeros.put("3", "Três "); string_numeros.put("4", "Quatro "); string_numeros.put("5", "Cinco "); string_numeros.put("6", "Seis ");
        string_numeros.put("7", "Sete "); string_numeros.put("8", "Oito "); string_numeros.put("9", "Nove "); string_numeros.put("10", "Dez ");

        string_numeros.put("11", "Onze ");string_numeros.put("12", "Doze ");string_numeros.put("13", "Treze ");string_numeros.put("14", "Catorze ");
        string_numeros.put("15", "Quinze ");string_numeros.put("16", "Dezesseis ");string_numeros.put("17", "Dezessete ");string_numeros.put("18", "Dezoito ");
        string_numeros.put("19", "Deznove ");

        string_numeros.put("20", "Vinte ");string_numeros.put("30", "Trinta ");string_numeros.put("40", "Quarenta ");string_numeros.put("50", "Cinquenta ");
        string_numeros.put("60", "Sessenta ");string_numeros.put("70", "Setenta ");string_numeros.put("80", "Oitenta ");string_numeros.put("90", "Noventa ");

        string_numeros.put("100", "Cento ");string_numeros.put("200", "Duzentos ");string_numeros.put("300", "Trezentos ");string_numeros.put("400", "Quatrocentos ");
        string_numeros.put("500", "Quinhentos ");string_numeros.put("600", "Seiscentos ");string_numeros.put("700", "Setecentos ");string_numeros.put("800", "Oitocentos ");
        string_numeros.put("900", "Novecentos ");
        String numero_estenso = "";
        for(char c:string_number.toCharArray()){

            Long num = (long) (Character.getNumericValue(c) * Math.pow(10, base));
            if((double) (base+1)/3 <=1){
                if(num!=0){
                    if((base+1)%3==0){
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                    }else if ((base+1)%3==2) {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");

                    } else {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + " ");
                    }
                }

            }else if((double)(base+1)/3>1 && (double) (base+1)/3<=2 ){
                num = num/(int) Math.pow(10,3);
                if(num!=0){
                    if((base+1)%3==0){
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                        if(base+1>3){
        
                        }
                    }else if ((base+1)%3==2) {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                    } else {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "Mil e ");
                    }

                }
            }else if((double)(base+1)/3>2 && (double) (base+1)/3<=3 ){
                num = num/(int) Math.pow(10,6);
                if(num!=0){
                    if((base+1)%3==0){
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                        if(base+1>3){
        
                        }
                    }else if ((base+1)%3==2) {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                    } else {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "Milhões, ");
                    }

                }
            }
            else if((double)(base+1)/3>3 && (double) (base+1)/3<=4 ){
                num = num/(int) Math.pow(10,9);
                if(num!=0){
                    if((base+1)%3==0){
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                        if(base+1>3){
        
                        }
                    }else if ((base+1)%3==2) {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "e ");
                    } else {
                        numero_estenso += (string_numeros.get(Long.toString(num)) + "Bilhões, ");
                    }

                }
            }
            base-=1;
        }
        return numero_estenso;
    }

}
