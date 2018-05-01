#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, m, k;
	while (cin >> n >> m >> k)
	{
		if (k < n) cout << 1 + k << " " << 1 << endl;
		else if (k == n) cout << n << " " << 2 << endl;
		else
		{
			ll x, y;
			ll p = (k - n) / (2 * m - 2);
			ll rem = (k - n) % (2 * m - 2);
			if (rem >= m - 1)
			{
				x = n - 2 * p - 1;
				y = m - rem + m - 1;
			}
			else
			{
				x = n - 2 * p;
				y = rem + 2;
			}				
			cout << x << " " << y << endl;
		}
	}
	return 0;
}