#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll a[MAXN], n;
ll check(ll x) //大于等于x的差值的个数
{
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll cnt = lower_bound(a, a + n, a[i] + x) - a;
		sum += n - cnt;
		if (x == 2) { printf("fucker here: %lld\n", cnt); }
	}
	return sum >= n * (n - 1) / 4 + 1;
}
int main()
{
	while (scanf("%lld", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
		sort(a, a + n);
		ll l = 0, r = a[n - 1] - a[0], ans = -1;
		while (l <= r)
		{
			ll m = (l + r) >> 1;
			if (check(m)) { ans = m; l = m + 1; }
			else r = m - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}