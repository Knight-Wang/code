#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll dp[200005][3], c[3];

int main()
{
	int n;
	ll l, r; 
	while (cin >> n >> l >> r)
	{
		memset(c, 0, sizeof c);
		memset(dp, 0, sizeof dp);
		ll t = r - l + 1;
		if (t <= 100) for (ll i = l; i <= r; i++) c[(int)i % 3]++;
		else
		{
			ll L = l, R = r;
			while (L % 3 != 0) L++;
			while (R % 3 != 2) R--;
			c[0] = c[1] = c[2] = (R - L + 1) / 3;
			for (ll i = l; i < L; i++) c[(int)i % 3]++;
			for (ll i = R + 1; i <= r; i++) c[(int)i % 3]++;
		}
		dp[1][0] = c[0]; dp[1][1] = c[1]; dp[1][2] = c[2];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				for (int k = 0; k <= 2; k++)
				{
					if (k >= j)
						dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * c[k - j] % MOD) % MOD;
					else
						dp[i + 1][k] = (dp[i + 1][k] + dp[i][j] * c[(3 - (j - k)) % 3] % MOD) % MOD;
				}
			}
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}