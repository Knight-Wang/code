import java.util.*;

public class Main {

	public static String solve(String now, String duration) {
		int nh = Integer.parseInt(now.substring(0, 2));
		int nm = Integer.parseInt(now.substring(3, 5));
		int dh = Integer.parseInt(duration.substring(0, 2));
		int dm = Integer.parseInt(duration.substring(3, 5));
		int lm = nm + 60 - dm;
		int lh = (nh - 1 - dh + 24 + lm / 60) % 24;
		lm = lm >= 60 ? lm - 60 : lm;
		String x = lh < 10 ? "0" + String.valueOf(lh) : String.valueOf(lh);
		String y = lm < 10 ? "0" + String.valueOf(lm) : String.valueOf(lm);
		return x + ":" + y; 
		
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		String now, duration;
		while (t != 0) {
			now = in.next();
			duration = in.next();
			System.out.println(solve(now, duration));
			t--;
		}
	}
}
