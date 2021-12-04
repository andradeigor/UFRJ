import java.util.Scanner;

public class alomundo{
    public static void main(String args[]){
        Scanner strInput = new Scanner(System.in);
        System.out.println("digita ai pra gente ver se tu é bom mesmo:");
        String scan = strInput.nextLine();
        strInput.close();
        System.out.println("tu digitou que eu sei "+scan);
    }
}