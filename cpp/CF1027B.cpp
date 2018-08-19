#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, Q, x, y;
	while (cin >> n >> Q)
	{
		while (Q--)
		{
			cin >> x >> y;
			long long p = x % 2, q = y % 2, sum = 0;
			if ((p && q) || (!p && !q))
			{
				if (n & 1) 
				{
					sum += (x - 1) / 2 * n;
					if (x % 2 == 0) sum += (n + 1) / 2;
				}
				else sum += (x - 1) * n / 2;
				sum += (y + 1) / 2;
			}
			else
			{
				sum += (n * n + 1) / 2;
				if (n & 1)
				{
					sum += (x - 1) / 2 * n;
					if (x % 2 == 0) sum += n / 2;
				}
				else sum += (x - 1) * n / 2;
				sum += (y + 1) / 2;
			}
			cout << sum << endl;
		}
		
	}
	return 0;
}