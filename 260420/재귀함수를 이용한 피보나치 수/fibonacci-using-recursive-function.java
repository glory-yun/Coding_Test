import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc=  new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(recur(n));
    }

    static int recur(int n){

    if(n <= 2){
        return 1;
    }

    return recur(n-1) + recur(n-2);
    }
}