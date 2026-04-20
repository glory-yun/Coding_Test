import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        
       

        System.out.println( fact(n));
    }

    static long fact(long n){
        if(n < 10){
            return n*n;
        }

        long next = fact(n/10);
        return next + (n%10)*(n%10);

    }
}