#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n, k, a, b;
	while (cin >> n >> k >> a >> b)
	{
		if (k == 1 || k > n) { cout << (n - 1) * a << endl; continue; }
		ll ans = 0;
		while (n > 1)
		{
			while (n >= k && n % k == 0) 
			{
				ll x = (n - n / k) * a;
				if (x < b) ans += x;
				else ans += b;
				n /= k;
			}
			if (n < k) break;
			ll x = n % k; n -= x; ans += x * a;
		}
		if (n > 1) ans += (n - 1) * a;
		cout << ans << endl;
	}
	return 0;
}