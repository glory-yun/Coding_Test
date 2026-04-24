import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m1 = sc.nextInt();
        int d1 = sc.nextInt();
        int m2 = sc.nextInt();
        int d2 = sc.nextInt();
        String find = sc.next();
        int[] month = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        String[] days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

        int dayCnt1 = d1, dayCnt2 = d2;
        int mon1 = 1, mon2 = 1;


        while (mon1 < m1) dayCnt1 += month[mon1++];
        while (mon2 < m2) dayCnt2 += month[mon2++];

        int diff = dayCnt2 - dayCnt1+1;

        int idx = 0;
        for (int i = 0; i < days.length; i++) {
            if (days[i].equals(find)) {
                idx = i;
                break;
            }
        }

        int startIdx = 0,ret=0;
        for (int i = 0; i < diff; i++) {
            if(i%7 == idx) ret++;
        }

        System.out.println(ret);


    }
}