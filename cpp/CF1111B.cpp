#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
ll a[MAXN], sum[MAXN];
int main()
{
	int n;
	ll k, m;
	while (cin >> n >> k >> m)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		memset(sum, 0, sizeof sum);
		for (int i = n; i >= 1; i--) sum[i] = sum[i + 1] + a[i];
		long double maxn = 0;
		for (int i = 0; i < min((int)m + 1, n); i++)
		{
			ll tmp = min(m - i, ((ll)n - i) * k);
			maxn = max(maxn, ((long double)tmp + sum[i + 1]) / ((long double)n - i));
		}
		printf("%.20Lf\n", maxn);
	}	
	return 0;
}