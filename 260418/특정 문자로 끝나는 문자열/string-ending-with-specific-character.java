import java.util.*;

public class Main {

     static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String[] s = new String[10];

        for(int i=0; i< 10;i++){
            s[i] = sc.next();
        }

        char ch  =sc.next().charAt(0);


        int cnt =0;
        for(String str : s){
            if(str.charAt(str.length()-1) == ch){
                System.out.println(str);
                cnt++;
            }
        }
        
        if(cnt ==0 )System.out.println("None");
    }
}