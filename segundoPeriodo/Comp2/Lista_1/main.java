public class main {
    public static void main(String[] args){
        Veiculo v1;
        v1 = new Veiculo("abluble", "aloalo", "ratinhooo", 30, 5);
        System.out.println(v1.LerAutonomia());
        System.out.println(v1.LerRodagem());
        v1.atualizarTanque(10);
        v1.fazerViagem(30);
        System.out.println(v1.LerTanqueAtual());
        System.out.println(v1.LerTanqueCapacid());
        
        

    }

}
