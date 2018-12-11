#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
ll a[1005], s;
int n;
bool check(ll x)
{
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += a[i] - x;
	return sum >= s;
}
int main()
{
	while (cin >> n >> s)
	{
		ll sum = 0, minn = INF;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i]; sum += a[i]; minn = min(minn, a[i]);
		}
		if (sum < s) { cout << -1 << endl; continue; }
		ll l = 0, r = minn, ans = 0;
		while (l <= r)
		{
			ll m = l + r >> 1;
			if (check(m)) { ans = m; l = m + 1; }
			else r = m - 1;
		}
		cout << ans << endl;
	}
	return 0;
}