import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        recur(n);
    }


    static void recur(int n){

        if(n == 0 ){
            return;
        }

        System.out.print(n + " ");
        recur(n-1);
        System.out.print(n+ " ");

    }
}