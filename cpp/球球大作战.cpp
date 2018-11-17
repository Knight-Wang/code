#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[100005];
int n, k;
bool check(ll x)
{
	int cnt = 0;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >= x) continue;
		sum = a[i++];
		while (i <= n && sum < x)
		{
			sum += a[i++]; cnt++;
		}
		if (i > n && sum < x) cnt++;
		i--;
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