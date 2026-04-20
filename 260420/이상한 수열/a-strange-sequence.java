import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(recur(n));
    }


    static int recur(int n){
        if( n<=2){
            return n;
        }


        return recur(n/3) + recur(n-1);

    }
}