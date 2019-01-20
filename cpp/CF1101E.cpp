#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, a, b, x = 0, y = 0; char t;
	cin >> n;
	while (n--)
	{
		cin >> t >> a >> b;
		int p = min(a, b), q = max(a, b);
		if (t == '+')
		{
			x = max(x, p); y = max(y, q);
		}
		else
		{
			if (x <= p && y <= q) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}