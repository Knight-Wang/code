#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 55;
ll a[MAXN], b[MAXN], c[MAXN][MAXN];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				c[i][j] = a[i] * b[j]; 
			}
		}
		ll ans = INF;
		for (int k = 0; k < n; k++)
		{
			ll maxn = -INF;
			for (int i = 0; i < n; i++)
			{
				if (i == k) continue;
				for (int j = 0; j < m; j++)
				{
					maxn = max(maxn, c[i][j]);
				}
			}
			ans = min(ans, maxn);
		}
		cout << ans << endl;
	}
	return 0;
}