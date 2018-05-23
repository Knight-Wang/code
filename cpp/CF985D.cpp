#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x7f7f7f7f;
ll n, H;
bool check(ll m)
{
	ll tmp = min(m, H);
	return m * m - tmp * (tmp - 1) / 2 <= n;
}
ll solve(ll n, ll H)
{
	ll l = 1, r = INF, ans = -1;
	while (l <= r)
	{
		ll m = l + r >> 1;
		if (check(m))
		{
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return ans;
}
int main()
{
	while (cin >> n >> H)
	{
		ll k = solve(n, H);
		ll t = min(k, H);
		ll ans = 2 * k - 1 - t;
		ll rem = n - (k * k - t * (t - 1) / 2);
		ans += (rem + k - 1) / k;
		cout << ans + 1 << endl;
	}
	return 0;
}