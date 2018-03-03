#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll k, d, t;
	while (cin >> k >> d >> t)
	{
		if (d < k) d = (k + d - 1) / d * d;
		if (d == k || t <= k) { cout << t << endl; continue; }
		double once = k + 0.5 * (d - k);
		ll times = t / once;
		double ans = times * d;
		double res = t - times * once;
		if (res <= k) ans += res;
		else ans += k + (res - k) * 2.0;
		printf("%.10f\n", ans);
	}
	return 0;
}