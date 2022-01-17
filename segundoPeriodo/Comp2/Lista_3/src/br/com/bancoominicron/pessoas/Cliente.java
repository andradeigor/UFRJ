package br.com.bancoominicron.pessoas;

public class Cliente extends Pessoa{
    private int matricula;
    static public int gerador_matricula = 1;
    public Cliente(String cpf, String nome){
        super(cpf,nome);
        this.matricula = Cliente.geraMatricula();

    }
    public static int geraMatricula(){
        int matricula = Cliente.gerador_matricula;
        Cliente.gerador_matricula +=1;
        return matricula;

    }

    public int getMatricula(){
        return this.matricula;
    }
}