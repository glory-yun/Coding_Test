import java.util.*;

public class Main {

    static Stack<Integer> stk;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Integer> list = new ArrayList<>();

        while (n >= 10) {
            list.add(n % 10);
            n = n / 10;
        }
        list.add(n);

        Collections.reverse(list);


        n=0;

        for (int i = 0; i < list.size(); i++) {
            n = n*2 + list.get(i);
        }


        n *= 17;

        Stack<Integer>stk = new Stack<>();

        while(n>=2){
            stk.push(n%2);
            n = n/2;
        }

        stk.push(n);

        while (!stk.isEmpty()){
            System.out.print(stk.pop());
        }

    }
}