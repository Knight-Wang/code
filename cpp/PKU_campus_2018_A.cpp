#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005, INF = 0x3f3f3f3f;
int a[MAXN], dp[2][1 << 7];
int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int msk = (1 << 7) - 1;
		memset(dp, 0x3f, sizeof dp);
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 0; i < 1 << 7; i++) dp[0][i] = 0;
		for (int i = 0; i < n; i++)
		{
			memset(dp[i + 1 & 1], 0x3f, sizeof dp[i + 1 & 1]);
			for (int j = 0; j < 1 << 7; j++)
			{
				int tmp = j << 1 & msk;
				dp[i + 1 & 1][tmp | 1] = min(dp[i + 1 & 1][tmp | 1], dp[i & 1][j] + 7 * a[i + 1]);
				if (i >= 6 && !tmp) continue;
				dp[i + 1 & 1][tmp] = min(dp[i + 1 & 1][tmp], dp[i & 1][j]);
			}
		}
		int minn = INF;
		for (int i = 1; i < 1 << 7; i++) minn = min(minn, dp[n & 1][i]);
		cout << minn << endl;
	}
	return 0;
}