#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, f, k;
	while (cin >> a >> b >> f >> k)
	{
		int now = b, j = 1, cnt = 0;
		if (k == 1 && (b < f || b < a - f)) { puts("-1"); continue; }
		else if (k == 2 && (b < f || b < 2 * (a - f))) { puts("-1"); continue; }
		else if (k > 2 && (b < 2 * f || b < 2 * (a - f))) { puts("-1"); continue; }
		while (j <= k)
		{
			if (j & 1) 
			{ 
				if (now < f) { now = b - 2 * f; cnt++; }
				else now -= f;
				if (now < a - f) { now = b - a + f; cnt++; }
				else now -= a - f; 
			}
			else 
			{ 
				if (now < a - f) { now = b - 2 * (a - f); cnt++; }
				else now -= a - f;
				if (now < f) { now = b - f; cnt++; }
				else now -= f;
			}
			j++;
		}
		cout << (cnt <= k ? cnt : -1) << endl;
	}
	return 0;
}
