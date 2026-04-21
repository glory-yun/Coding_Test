import java.util.*;


class Number implements Comparable<Number>{
    int idx,num;

    public Number(int idx,int num){
        this.idx=idx;
        this.num = num;
    }


    public int compareTo(Number o){
        return Integer.compare(this.num, o.num);
    }

}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Number[] arr = new Number[n];
        for(int i = 0; i < n; i++){
            arr[i] = new Number(i, sc.nextInt());
        }
        
        Number[]  temp = arr.clone();

        Arrays.sort(temp);

        
        int[] ret = new int [n];

        for(int i=0; i< n;i++){
            ret[temp[i].idx] = i+1;
        }
        
        for(int i=0; i< n;i++){
            System.out.print(ret[i] + " ");
        }



    }
}