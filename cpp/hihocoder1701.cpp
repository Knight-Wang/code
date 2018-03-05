#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MOD = 1000000009;
int a[MAXN], c[MAXN][MAXN], n, m, k;
bool vis[MAXN];
void init()
{
	c[0][0] = c[1][0] = c[1][1] = 1;
	for (int i = 1; i < MAXN; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}
int main()
{
	init();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (vis[i]) continue;
		vis[i] = true;
		int tmp = a[i], cnt = 1;
		for (int j = i + 1; j < n; j++)
		{
			if ((a[j] - tmp) % k == 0) { cnt++; vis[j] = true; }
		}
		if (cnt >= m) ans = (ans + c[cnt][m]) % MOD;
	}
	cout << ans << endl;
	return 0;
}