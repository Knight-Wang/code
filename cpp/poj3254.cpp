#include <iostream>
using namespace std;
const int MOD = 100000000;
int m, n, a[13][13], dp[13][13][1 << 13];
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 1 << n; i++)
	{
		bool flg = true;
		for (int j = 0; j < n; j++)
		{
			if (a[m - 1][j] == 0 && i >> j & 1) 
			{
				flg = false;
				break;
			}
		}
		dp[m][0][i] = flg;
	}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			for (int k = 0; k < 1 << n; k++)
			{
				int ni = i, nj = j + 1;
				if (j == n - 1) { ni = i + 1; nj = 0; }
				dp[i][j][k] += dp[ni][nj][k & ~(1 << j)];
				dp[i][j][k] %= MOD;
				bool ok = true;
				if (a[i][j] == 0) ok = false;
				if (j && k >> (j - 1) & 1) ok = false;
				if (k >> j & 1) ok = false;
				if (ok) 
				{
					dp[i][j][k] += dp[ni][nj][k | 1 << j];
					dp[i][j][k] %= MOD;
				}
			}
		}
	}
	cout << dp[0][0][0] << endl;
	return 0;
}