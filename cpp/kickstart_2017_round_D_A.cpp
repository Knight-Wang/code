#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 2005, INF = 0x3f3f3f3f;
int n, ts, tf, s[MAXN], f[MAXN], d[MAXN], dp[MAXN][MAXN];

int cal(int now, int i)
{
	if (s[i] >= now) return s[i] + d[i];
	return now + (f[i] - (now - s[i]) % f[i]) % f[i] + d[i];
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> ts >> tf;
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> s[i] >> f[i] >> d[i];
		}
		dp[0][0] = 0;
		for (int i = 0; i <= n - 1; i++)
			for (int j = i + 1; j <= n - 1; j++)
				dp[i][j] = INF;
		for (int i = 1; i <= n - 1; i++)
		{
			dp[i][0] = cal(dp[i - 1][0], i);
			for (int j = 1; j <= i; j++)
				dp[i][j] = min(cal(dp[i - 1][j], i), cal(dp[i - 1][j - 1] + ts, i));
		}
		cout << "Case #" << t << ": ";
		bool flg = false;
		for (int i = n - 1; i >= 0; i--)
		{
			if (dp[n - 1][i] <= tf)
			{
				flg = true; 
				cout << i << endl;
				break;
			}
		}
		if (!flg) puts("IMPOSSIBLE");
	}
	return 0;
}