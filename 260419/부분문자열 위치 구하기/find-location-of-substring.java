import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static void print(Object o){
        System.out.println(o);
    }
    public static void main(String[] args) {
        
        String str = sc.next();
        String find = sc.next();

        print(str.indexOf(find));


    }
}