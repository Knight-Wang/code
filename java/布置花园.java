import java.util.*;

public class Main {
	
    static final int MAXN = 80;
	static char [][] a = new char [MAXN + 5][MAXN + 5];
	
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		int n = 0; 
		char p = ' ', q = ' ';
		
		while (true) {
			n = in.nextInt();
			if (n == 0)
				break;
			p = in.next().charAt(0);
			q = in.next().charAt(0);
			if (n == 1) {
				System.out.println("" + p + "\n");
				continue;
			}
			int start = n - 1 >> 1, len = 1, type = 0;
			for (int i = n - 1 >> 1; i < n; i++) {
				for (int j = start; j < start + len; j++) {
					a[i][j] = a[n - 1 - i][j] = a[j][i] = a[n - 1 - j][n - 1 - i] = (type == 0 ? p : q);
				}
				if (i == n - 1) {
					a[i][0] = a[i][n - 1] = a[0][0] = a[0][n - 1] = ' ';
				}
				start--;
				len += 2;
				type = 1 - type;
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(a[i][j]);
				}
				System.out.println();
			}
			System.out.println();
		}
	}
}
