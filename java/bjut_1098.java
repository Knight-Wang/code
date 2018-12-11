import java.util.*;
import java.io.*;

public class Main {

	public static final int MAXN = 100000;
	public static int[] a = new int[MAXN + 5];
	public static int[] b = new int[MAXN + 5];
	
	private static InputStream is;
    private static PrintWriter out;
    
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
	 
	public static int binary_search(int i, int len) {
		int left = 0, right = len;    
	    while (left < right) {  
	        int mid = left + right >> 1;  
	        if (b[mid] >= a[i]) right = mid;  
	        else left = mid+1;  
	    }  
	    return left;
	}
	
	public static int solve(int n) {
		b[1] = a[1];  
        int len = 1;  
        for (int i = 2; i <= n; i++) {  
            if (a[i] > b[len])  
                b[++len] = a[i];  
            else {  
                int pos = binary_search(i, len);      
                b[pos] = a[i];  
            }
        }
        return len; 
	}
	
	public static void main(String[] args) {
		is = System.in;
        out = new PrintWriter(System.out);
		int t = ni();
		for (int i = 0; i < t; i++) {
			int n = ni();
			for (int j = 0; j < n; j++) {
				a[n - j] = ni();
			}
			out.println(solve(n));
		}
		out.flush();
	}
}
