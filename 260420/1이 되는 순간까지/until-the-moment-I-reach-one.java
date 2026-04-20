import java.util.*;
public class Main {
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);

       int n = sc.nextInt();

        System.out.println(recur(n,0));

    }


    static int  recur(int n , int deep){
        if(n == 1){

            return deep;
        }

       
        if(n%2 == 0){
            n /= 2;
        }
        else{
            n /= 3;
        }


        return recur(n,deep+1);

    }
}