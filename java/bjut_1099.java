import java.util.*;
import java.io.*;

public class Main {
	
	static long [] num = new long [100010];
	static long [] dp = new long [100010];
    static int n;
    
    private static InputStream is;
    
	private static byte[] inbuf = new byte[1024];
    static int lenbuf = 0, ptrbuf = 0;

    private static int readByte() {
        if(lenbuf == -1) throw new InputMismatchException();
        if(ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0) return -1;
        }
        return inbuf[ptrbuf++];
    }

	private static int ni()
	{
		int num = 0, b;
	    boolean minus = false;
	    while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
	    if(b == '-') {
	        minus = true;
	        b = readByte();
	    }
	    while(true) {
	        if(b >= '0' && b <= '9') {
	            num = num * 10 + (b - '0');
	        }
	        else {
	            return minus ? -num : num;
	        }
	        b = readByte();
	    }
	}
	
	public static void main(String[] args) {
		is = System.in;
		n = ni();
		int maxn = 0;
		for (int i = 0; i < n; i++) {
			int tmp = ni();
			maxn = Math.max(maxn, tmp);
			num[tmp]++;
		}
		dp[1] = num[1];
		for (int i = 2; i <= maxn; i++) {
			dp[i] = Math.max(dp[i - 2] + num[i] * (long)i, dp[i - 1]);
		}
		System.out.println(dp[maxn]);
	}

}
