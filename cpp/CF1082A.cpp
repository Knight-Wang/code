#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
	int t, n, x, y, d;
	cin >> t;
	while (t--)
	{
		cin >> n >> x >> y >> d;
		if (x == y) { cout << 0 << endl; continue; }
		if (abs(x - y) >= d && abs(x - y) % d == 0) cout << abs(x - y) / d << endl;
		else
		{
			int ans = INF;
			if ((y - 1) % d == 0) ans = min(ans, (x - 1 + d - 1) / d + (y - 1) / d);
			if ((n - y) % d == 0) ans = min(ans, (n - x + d - 1) / d + (n - y) / d);
			cout << (ans == INF ? -1 : ans) << endl;
		}
	}
	return 0;
}