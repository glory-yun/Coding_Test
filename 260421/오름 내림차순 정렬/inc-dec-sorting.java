import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Integer[] arr = new Integer[n];

        for(int i=0; i<n;i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);
        
        for(int a : arr){
            System.out.print(a + " ");
        }

        Arrays.sort(arr, Collections.reverseOrder());
        
        System.out.println();
        for(int a : arr){
            System.out.print(a + " ");
        }

    }
}