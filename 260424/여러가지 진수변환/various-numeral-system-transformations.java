import java.util.*;

public class Main {

    static Stack<Integer> stk;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        stk = new Stack<>();

        change(n, b);

        while(!stk.isEmpty()){
            System.out.print(stk.pop());
        }
    }

    static void change(int n, int b) {

        while (n >= b) {
            stk.push(n % b);
            n/=b;
        }
        stk.push(n);
    }
}