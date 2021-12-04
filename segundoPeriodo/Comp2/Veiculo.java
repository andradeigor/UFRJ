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
        iswrong = validarProp(tanque_capacid);
        if(iswrong){
            this.tanque_capacid = 10;
        }else{
            this.tanque_capacid = tanque_capacid;
        }
        iswrong = validarProp(autonomia_km_l);
        if(iswrong){
            this.autonomia_km_l = 10;
        }else{
            this.autonomia_km_l = autonomia_km_l;
        }

    }
    public void printei(){
        System.out.println(this.marca);
    }
    private boolean validarProp(double prop){
        if(prop<=0){
            return false;
        }
        return true;
    }

}
