public class Veiculo {
    public String marca;
    public String modelo;
    public String dono;
    private double tanque_capacid;
    private double tanque_atual;
    private double km_rodado;
    private double autonomia_km_l;
    private boolean iswrong;
    public Veiculo(String marca, String modelo,String dono, double tanque_capacid, double autonomia_km_l){
        this.marca = marca;
        this.modelo = modelo;
        this.dono = dono;
        this.tanque_atual =0;
        this.km_rodado =0;
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
        return this.km_rodado;
    }
    public boolean alterarAutonomia(double prop){
        this.iswrong = validarProp(prop);
        if(this.iswrong){
            this.autonomia_km_l = prop;
            return true;
        }else{
            return false;
        }
    }
    public boolean AtualizarTanque(double prop){
        this.iswrong = validarProp(prop);
        if(!this.iswrong){
            return false;
        }
        if(this.tanque_atual + prop<=this.tanque_capacid)
    }
    private boolean validarProp(double prop){
        if(prop<=0 ){
            System.out.println("Parâmetro inválido!");
            return false;
        }
        return true;
    }

}
