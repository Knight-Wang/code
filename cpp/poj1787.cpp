#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int v[4] = {1, 5, 10, 25};
int c[4], m;
int dp[10005], used[10005], path[10005];
int main()
{
	while (cin >> m >> c[0] >> c[1] >> c[2] >> c[3], m || c[0] || c[1] || c[2] || c[3])
	{
		memset(used, 0, sizeof used);
		memset(path, 0, sizeof path);
		path[0] = -1;
		for (int i = 0; i <= m; i++) dp[i] = -INF;
		dp[0] = 0;
		for (int i = 0; i < 4; i++)
		{
			memset(used, 0, sizeof used);
			for (int j = v[i]; j <= m; j++)
			{
				if (dp[j - v[i]] != -INF && dp[j - v[i]] + 1 > dp[j] && used[j - v[i]] < c[i])
				{
					dp[j] = dp[j - v[i]] + 1;
					used[j] = used[j - v[i]] + 1;
					path[j] = j - v[i];
				}
			}
		}
		if (dp[m] <= -INF) { cout << "Charlie cannot buy coffee." << endl; }
		else 
		{
			int ans[26]; memset(ans, 0, sizeof ans);
			while (path[m] != -1)
			{
				ans[m - path[m]]++;
				m = path[m];
			}
			cout << "Throw in " << ans[v[0]] << " cents, " << ans[v[1]] << " nickels, " << ans[v[2]] << " dimes, and " << ans[v[3]] << " quarters." << endl;
		}
	}
	return 0;
}