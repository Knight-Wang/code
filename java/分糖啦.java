import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int t, n, m; String s;
		t = in.nextInt();
		while (t != 0) {
			n = in.nextInt();
			m = in.nextInt();
			s = in.next();
			if (n < m || n % (m + 1) != 0) {
				System.out.println(s);
			}
			else {
				if (s.equals("Cw")) {
					System.out.println("ACSync");
				}
				else {
					System.out.println("Cw");
				}
			}
			t--;
		}
	}
}
