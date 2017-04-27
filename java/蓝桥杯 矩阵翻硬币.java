import java.math.*;
import java.util.*;

public class Main {

	public static BigInteger sqrt(BigInteger x){
	    if (x .equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
	        return x;
	    }
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    for (y = x.divide(two);
	         y.compareTo(x.divide(y)) > 0;
	         y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BigInteger n;
		Scanner s = new Scanner(System.in);
		BigInteger a = s.nextBigInteger();
		BigInteger b = s.nextBigInteger();
		BigInteger ia = sqrt(a);
		BigInteger ib = sqrt(b);
		System.out.println(ia.multiply(ib));
	}
}
