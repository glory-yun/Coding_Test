import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static void print(Object o){
        System.out.println(o);
    }

    public static void main(String[] args) {
        
        String str = sc.next();
        String find = sc.next();

        int cnt =0;

        while(str.indexOf(find) != -1)
        {
            cnt++;
            str = str.substring(str.indexOf(find+1));
        }


        print(cnt);
    }
}