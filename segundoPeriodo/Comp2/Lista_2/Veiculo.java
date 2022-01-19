/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class Veiculo {

    public String marca;
    public String modelo;
    public String dono;
    private double tanque_capacidad;
    private double autonomia_km_l;
    private double tanque_atual;
    private double km_rodados;

    public Veiculo(String marca, String modelo, String dono, double tanque_capacidad, double autonomia_km_l) {

        this.tanque_atual = 0.0;
        this.km_rodados = 0.0;
        this.marca = marca;
        this.modelo = modelo;
        this.dono = dono;

        if (!validarProp(autonomia_km_l)){
            System.out.println("Parametro Inválido!");
            autonomia_km_l = 10;
        }
        this.autonomia_km_l = autonomia_km_l;

        if (!validarProp(tanque_capacidad)){
            System.out.println("Parametro Inválido!");
            tanque_capacidad = 10;
        }
        this.tanque_capacidad = tanque_capacidad;
    }

    public double lerTanqueAtual(){
        return this.tanque_atual;
    }
    public double lerTanqueCapacidad(){
        return this.tanque_capacidad;
    }
    public double lerAutonomia(){
        return this.autonomia_km_l;
    }
    public double lerRodagem(){
        return this.km_rodados;
    }

    public boolean alterarAutonomia(double autonomia){
        if (validarProp(autonomia)){
            autonomia_km_l = autonomia;
            return true;
        } else {
            return false;
        }
    }

    public boolean abastecerTanque(double litros){
        if (validarProp(litros) && tanque_atual + litros <=tanque_capacidad){
            tanque_atual += litros;
            return true;
        } else {
            return false;
        }
    }

    public boolean fazerViagem (double km){
        if (km / autonomia_km_l <= tanque_atual){
            this.tanque_atual -= (km / autonomia_km_l);
            this.km_rodados += km;
            return true;
        } else {
            return false;
        }
    }

    private boolean validarProp(double prop){
        return prop > 0;
    }
    public void alterarKMRodados(double km_rodados){this.km_rodados = km_rodados;}
    

    
}
