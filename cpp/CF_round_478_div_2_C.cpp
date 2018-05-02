#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
ll a[200005], k[200005], sum[200005], tot[200005];
int main()
{
	while (cin >> n >> q)
	{
		for (int i = 1; i <= n; i++) { cin >> a[i]; tot[i] = tot[i - 1] + a[i]; }
		for (int i = 1; i <= q; i++)
		{
			cin >> k[i];
			if (sum[i - 1] + k[i] <= tot[n] || (sum[i - 1] < tot[n] && sum[i - 1] + k[i] >= tot[n]))
				sum[i] = sum[i - 1] + k[i];
			else sum[i] = k[i];
		}
		for (int i = 1; i <= q; i++)
		{
			int pos = lower_bound(tot + 1, tot + n + 1, sum[i]) - tot;
			if (pos == n + 1 || (pos == n && tot[n] == sum[i])) { cout << n << endl; continue; }
			if (tot[pos] == sum[i]) cout << n - pos << endl;
			else cout << n - pos + 1 << endl;
		}
	}
	return 0;
}