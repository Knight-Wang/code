#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll dp[2005][2005];

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		memset(dp, 0, sizeof dp);
		dp[1][0] = m;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i][j] = dp[i - 1][j];
				if (j > 0)
				{
					dp[i][j] += dp[i - 1][j - 1] * (m - 1);
					dp[i][j] %= MOD;
				}
			}
		}
		cout << dp[n][k] << endl;
	}
	return 0;
}