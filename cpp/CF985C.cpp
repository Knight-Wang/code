#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll a[MAXN], b[MAXN];
int main()
{
	ll n, k, l;
	while (cin >> n >> k >> l)
	{
		memset(b, 0, sizeof b);
		for (int i = 0; i < n * k; i++) cin >> a[i];
		sort(a, a + n * k);
		ll tmp = a[0] + l;
		int pos = upper_bound(a, a + n * k, tmp) - a;
		if (pos < n) cout << 0 << endl;
		else
		{
			ll p = pos / k + (pos % k ? 1 : 0), m = n;
			for (int i = 0; i < p && n > 0; i++) { b[i * k] = 1; n--; }
			int now = pos - 1;
			while (n > 0)
			{
				if (b[now] == 1) { now--; continue; }
				b[now] = 1; now--; n--;
			}
			ll ans = 0;
			for (int i = 0; i < m * k; i++) if (b[i]) ans += a[i];
			cout << ans << endl;
		}
	}
	return 0;
}