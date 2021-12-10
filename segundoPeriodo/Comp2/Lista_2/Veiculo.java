public class Veiculo {
    public String marca;
    public String modelo;
    public String dono;
    private double tanque_capacid;
    private double tanque_atual;
    private double km_rodados;
    private double autonomia_km_l;
    private boolean iswrong;
    public Veiculo(String marca, String modelo,String dono, double tanque_capacid, double autonomia_km_l){
        this.marca = marca;
        this.modelo = modelo;
        this.dono = dono;
        this.tanque_atual =0;
        this.km_rodados =0;
        this.iswrong = validarProp(tanque_capacid);
        this.tanque_capacid = !this.iswrong?  10:  tanque_capacid;
        this.iswrong = validarProp(autonomia_km_l);
        this.autonomia_km_l = !this.iswrong? 10:autonomia_km_l;

    }
    public double LerTanqueAtual(){
        return this.tanque_atual;
    }
    public double LerTanqueCapacid(){
        return this.tanque_capacid;
    }
    public double LerAutonomia(){
        return this.autonomia_km_l;
    }
    public double LerRodagem(){
        return this.km_rodados;
    }
    public boolean alterarAutonomia(double NovaAutonimia){
        this.iswrong = validarProp(NovaAutonimia);
        if(this.iswrong){
            this.autonomia_km_l = NovaAutonimia;
            return true;
        }else{
            return false;
        }
    }
    public boolean atualizarTanque(double LitrosCombustivel){
        this.iswrong = validarProp(LitrosCombustivel);
        if(!this.iswrong){
            return false;
        }
        if(this.tanque_atual + LitrosCombustivel<=this.tanque_capacid){
            this.tanque_atual+=LitrosCombustivel;
            return true;
        }
        return false;
    }
    public boolean fazerViagem(double km){
        this.iswrong = validarProp(km);
        if(!this.iswrong){
            return false;
        }
        double litros = km/this.autonomia_km_l ; 
        if(litros<=this.tanque_atual){
            this.tanque_atual -= litros;
            this.km_rodados += litros;
            return true;
        }
        return false;
    }
    private boolean validarProp(double prop){
        if(prop<=0 ){
            System.out.println("Parâmetro inválido!");
            return false;
        }
        return true;
    }
    public void alterarKmRodados(double km_rodados){this.km_rodados = km_rodados;}
    
    public double LerKmRodados(){return this.km_rodados;}

    
}
