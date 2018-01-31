#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, m;
ll cal(ll i, ll j)
{
	return i * i + i * 100000 + j * j - j * 100000 + i * j;
}
bool check(ll x)
{
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = n, ans = 0;
		while (l <= r)
		{
			int m = l + r >> 1;
			ll tmp = cal(m, i);
			if (tmp <= x) { ans = m; l = m + 1; }
			else r = m - 1;
		}
		sum += ans;
	}
	return sum >= m;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &n, &m);
		ll l = INF, r = -INF, ans = -INF;
		for (int i = 1; i <= n; i++)
		{
			l = min(l, cal(1, i));
			r = max(r, cal(n, i));
		}
		while (l <= r)
		{
			ll m = l + r >> 1;
			if (check(m)) { ans = m; r = m - 1; }
			else l = m + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}