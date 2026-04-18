import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static Map<Character, Integer> map = new HashMap();

    public static void main(String[] args) {
        
        String s = sc.next();
        String ret ="";
        char temp = s.charAt(0);
        int cnt = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);

            if(temp == ch){
                cnt++;
            }
            else{

                ret += (temp+"") + cnt;
                

                temp=ch;
                cnt=1;
            }
        }
        ret += (temp+"") + cnt;
        System.out.println(ret.length() + "\n" + ret);   
        
    }
}