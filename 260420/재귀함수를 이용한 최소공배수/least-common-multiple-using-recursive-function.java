import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();



        System.out.println(recur(arr[0] , 0, arr));
    }


    static int gcd(int a,int b){

        if(b==0)return a;

        return gcd(b, a%b);

    }

    static int recur(int sum,int idx,int[] arr){

        if(idx == arr.length){
            return sum;
        }

        int ret = (sum * arr[idx]) / gcd(sum, arr[idx]);

        return recur(ret, idx+1, arr);

    }
}