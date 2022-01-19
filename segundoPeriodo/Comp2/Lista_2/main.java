public class main{
    public static void main(String[] args){
        Caminhao r1;
        r1 = new Caminhao("fiat", "r2s","ricardo", 50, 10, 5,3);
        System.out.println(r1.lerCapacidCarga()); 
        System.out.println(r1.lerAutonomia()); 
        r1.abastecerTanque(50);
        r1.fazerViagem(20,5);
        System.out.println(r1.lerTanqueAtual()); 
        System.out.println(r1.lerRodagem()); 
    }
}