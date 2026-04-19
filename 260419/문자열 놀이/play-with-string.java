import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static void print(Object o){
        System.out.println(o);
    }

    public static void main(String[] args) {
        
        String str = sc.next();
        int cnt = sc.nextInt();

        for(int i=0; i< cnt ; i++){

            int idx = sc.nextInt();
            
            char[] arr = str.toCharArray();

            if(idx==1){
                int a = sc.nextInt()-1;
                int b = sc.nextInt()-1;

                char temp = arr[a];

                arr[a] = arr[b];
                arr[b] = temp;


                

            }else{
                char x = sc.next().charAt(0);
                char y = sc.next().charAt(0);
                

                for(int k=0; k<arr.length;k++){
                    if(arr[k] == x) arr[k] = y;
                }
            }

            str = String.valueOf(arr);


            print(str);

        }

        

    }
}