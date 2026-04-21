import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        String t = sc.next();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = sc.next();
        }


        String[] ret = Arrays.stream(words).filter(s -> s.indexOf(t) ==0).toArray(String[]::new);
        
        Arrays.sort(ret);

        System.out.println(ret[k-1]);


    }
}