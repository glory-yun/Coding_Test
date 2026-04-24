import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int day = sc.nextInt();
		int hour = sc.nextInt();
		int minute = sc.nextInt();

		int d = 11;
		int h = 11;
		int m = 11;

		int cnt = 0;

		while (true) {
			if (d == day && h == hour && m == minute)
				break;
			cnt++;

			m++;

			if (m == 60) {
				h++;
				m = 0;
			}

			if (h == 24) {
				d++;
				h = 0;

			}
		}

		cnt = cnt == 0 ? -1 : cnt;
		System.out.println(cnt);

	}
}
