#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

int n, c[MAXN], a[MAXN][3], dp[MAXN][2][2][2];

int cut(int x)
{
	return x >= 1 ? 1 : 0;
}

int dfs(int now, int x, int y, int z)
{
	if (now == n)
	{
		if (x == 1 && y == 1 && z == 1) return 0;
		return INF;
	}
	if (dp[now][x][y][z] != -1) return dp[now][x][y][z];
	int ans = INF;
	ans = min(ans, c[now] + dfs(now + 1, cut(x + a[now][0]), cut(y + a[now][1]), cut(z + a[now][2])));
	ans = min(ans, dfs(now + 1, x, y, z));
	return dp[now][x][y][z] = ans;
}

int main()
{
	string s;
	while (cin >> n)
	{
		memset(dp, -1, sizeof dp);
		memset(a, 0, sizeof a);
		
		for (int i = 0; i < n; i++)
		{
			cin >> c[i] >> s;
			for (int j = 0; j < s.length(); j++)
			{
				a[i][s[j] - 'A']++;
			}
		}
		int ans = dfs(0, 0, 0, 0);
		if (ans >= INF) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}