import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static void print(Object o){
        System.out.println(o);
    }

    public static void main(String[] args) {

        String str = sc.next();
        String find = sc.next();
        

        while(true){
            int idx = str.indexOf(find);

            if(idx == -1) break;

            str = str.substring(0,idx) + str.substring(idx+find.length());
        }

        print(str);

    }
}