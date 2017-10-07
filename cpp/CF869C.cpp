#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll dp[5005][5005];
int main()
{
	ll a, b, c;
	while (cin >> a >> b >> c)
	{
		for (int i = 0; i <= 5000; i++) dp[i][0] = dp[0][i] = 1;
		for (int i = 1; i <= 5000; i++)
		{
			for (int j = 1; j <= 5000; j++)
			{
				dp[i][j] = (dp[i - 1][j] + j * 1LL * dp[i - 1][j - 1] % mod) % mod;
			}
		}
		cout << dp[a][b] * dp[a][c] % mod * dp[b][c] % mod << endl;
	}
	return 0;
}