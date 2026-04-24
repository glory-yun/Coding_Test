import java.util.*;

public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int m1 = sc.nextInt();
        int d1 = sc.nextInt();
        int m2 = sc.nextInt();
        int d2 = sc.nextInt();
        int[] month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] days = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
        String[] days2 = {"Mon", "Sun", "Sat", "Fri", "Thu", "Wed", "Tue"};

        int cnt = 0;


        if (m1 <= m2 && d1 <= d2) {
            while (true) {
                cnt++;
                d1++;

                if (m1 == m2 && d1 == d2) break;

                if (d1 == month[m1]) {
                    m1++;
                    d1 = 1;
                }
            }

            cnt %= 7;

            System.out.println(days[cnt]);


        } else if (m1 >= m2 && d1 >= d2) {
            while (true) {
                cnt++;
                d2++;

                if (m1 == m2 && d1 == d2) break;

                if (d2 == month[m2]) {
                    m2++;
                    d2 = 1;
                }
            }

            cnt %= 7;
            System.out.println(days2[cnt]);


        }
    }
}