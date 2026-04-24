import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m1 = sc.nextInt();
        int d1 = sc.nextInt();
        int m2 = sc.nextInt();
        int d2 = sc.nextInt();

        int[] month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        String[] days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

        int cnt1 = d1;
        int cnt2 = d2;
        int month1 = 1, month2 = 1;
        while (month1 < m1) {
            cnt1 += month[month1++];
        }

        while (month2 < m2) {
            cnt2 += month[month2++];
        }

        int diff =cnt2-cnt1;

        diff %= 7;
        diff = diff < 0 ? diff +=7 : diff;

        System.out.println(days[diff]);


    }
}