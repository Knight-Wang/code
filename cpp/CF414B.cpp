#include <iostream>
#include <cstdio>
using namespace std;

const int MOD = 1e9 + 7;

int n, k, dp[2005][2005];

int solve()
{
	for (int i = 1; i <= n; i++) dp[0][i] = 1;
	for (int i = 1; i < k; i++)
	{
		/*
		for (int j = 1; j <= n; j++)
		{
			for (int p = 1; p * p <= j; p++)
			{
				if (j % p == 0) 
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][p]) % MOD;
					if (p * p != j) dp[i][j] = (dp[i][j] + dp[i - 1][j / p]) % MOD;
				}
			}
		}*/
		for (int j = 1; j <= n; j++)
		{
			for (int p = j; p <= n; p += j)
			{
				dp[i][p] = (dp[i][p] + dp[i - 1][j]) % MOD;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) sum = (sum + dp[k - 1][i]) % MOD;
	return sum;
}

int main()
{
	cin >> n >> k;
	cout << solve() << endl;
	return 0;
}