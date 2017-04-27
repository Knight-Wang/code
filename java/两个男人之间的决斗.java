import java.util.*;

public class Main 
{	
	public static boolean fuck(String x, String y)
	{
		if (x.equals("R"))
		{
			return y.equals("S") ? true : false;
		}
		else if (x.equals("S"))
		{
			return y.equals("P") ? true : false;
		}
		else
		{
			return y.equals("R") ? true : false;
		}
	}	
	public static void main(String[] args) 
	{
		int t = 0, x = 0;
		String p, q;
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		for (int i = 0; i < t; i++)
		{
			int cnt1 = 0, cnt2 = 0;
			x = in.nextInt();
			for (int j = 0; j < x; j++)
			{
				p = in.next();
				q = in.next();
				if (p.equals(q))
					continue;
				boolean res = fuck(p, q);
				if (res)
					cnt1++;
				else
					cnt2++;
			}
			if (cnt1 > cnt2) System.out.println("Cw");
			else if (cnt1 < cnt2) System.out.println("FanZzz");
			else System.out.println("ACSync");
		}
	}
}
