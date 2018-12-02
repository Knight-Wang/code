#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[33];
int main()
{
	int cnt = 0;
	for (int i = 1; i <= 32; i++)
	{
		sum[i] = (sum[i - 1] + (1ll << cnt));
		cnt += 2;
	}
	int t;
	ll n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (n >= 32) { cout << "YES " << n - 1 << endl; continue; }
		if (n == 1)
		{
			if (k == 1) cout << "YES 0" << endl;
			else cout << "NO" << endl;
			continue;
		}
		ll minn = 0, d = 0, s1 = 1, s2 = 2;
		bool flg = false;
		int i = n - 1;
		for ( ; i >= 0; i--)
		{
			minn += (1ll << s1) - 1;
			s1++;
			d += ((1ll << s2) - 3) * sum[i];
			s2++;
			ll maxn = minn + d;
			if (k >= minn && k <= maxn) { flg = true; break; }
		}
		if (flg) cout << "YES " << i << endl;
		else cout << "NO" << endl;
	}
	return 0;
}