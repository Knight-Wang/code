#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long x, k;
	cin >> t;
	while (t--)
	{
		cin >> x >> k;
		if (k == 1) { cout << x << endl; continue; }
		long long now = x % 10;
		bool flg = false;
		for (int i = 0; i < 10; i++)
		{
			if (now == k) { flg = true; break; }
			x -= 2;
			if (x <= 1) break;
			now *= x % 10;
			now %= 10;
		}
		if (flg) cout << x - 2 << endl;
		else cout << -1 << endl;
	}
	return 0;
}