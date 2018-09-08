#include <bits/stdc++.h>
using namespace std;
const int MAXN = 705;
int a[MAXN], g[MAXN][MAXN], dp[2][MAXN][MAXN];
int check(int p, int s, int l, int r)
{
	if (l == r) return g[p][l] != 1;
	if (dp[s][l][r] != -1) return dp[s][l][r];
	int flg = 0;
	for (int i = l; i <= r; i++)
	{
		if (g[p][i] == 1) continue;
		if (i > l && !check(i, 0, l, i - 1)) continue;
		if (i < r && !check(i, 1, i + 1, r)) continue;
		flg = 1; break;
	}
	return dp[s][l][r] = flg;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				g[i][j] = __gcd(a[i], a[j]);
		}
		memset(dp, -1, sizeof dp);
		int flg = 0;
		for (int i = 1; i <= n; i++)
		{
			if (i > 1 && !check(i, 0, 1, i - 1)) continue;
			if (i < n && !check(i, 1, i + 1, n)) continue;
			flg = 1; break;
		}
		cout << (flg ? "Yes" : "No") << endl;
	}
	return 0;
}