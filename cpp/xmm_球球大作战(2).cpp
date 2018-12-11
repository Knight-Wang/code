#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[100005], b[100005];
int n, k;
bool check(ll x)
{
	for (int i = 1; i <= n; i++) b[i] = a[i];
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (b[i] >= x) continue;
		b[i + 1] += b[i];
		cnt++;
	}
	return cnt <= k;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ll l = INF, r;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i];
			l = min(l, a[i]);
			r += a[i];
		}
		ll ans = l;
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
		cout << ans << endl;
	}
	return 0;
}