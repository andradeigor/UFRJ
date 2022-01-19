/*
Nome: Igor de Andrade Assunção de Almeida
DRE:121095736
*/
public class Caminhao extends Veiculo{
    public int qnt_eixos;
    private double capacid_carga;
    public Caminhao(String marca, String modelo,String dono, double tanque_capacid, double autonomia_km_l, double capacid_carga, int qnt_eixos){
        super(marca,modelo,dono,tanque_capacid,autonomia_km_l);
        this.qnt_eixos = qnt_eixos;
        this.capacid_carga = capacid_carga;
    }
    public Caminhao(String marca, String modelo,String dono, double tanque_capacid, double autonomia_km_l, double capacid_carga, int qnt_eixos, double km_rodados){
        this(marca,modelo,dono,tanque_capacid,autonomia_km_l,capacid_carga,qnt_eixos);
        super.alterarKMRodados(km_rodados);
    }
    public double lerCapacidCarga(){return this.capacid_carga;}

    public boolean fazerViagem(double km, double carga){
        return this.capacid_carga >=carga? super.fazerViagem(km):false;
    }
}
