#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int w[1005], v[1005], sum[1005];
double dp[1005];
int main()
{
	int b, l, n;
	while (cin >> b >> l >> n, b || l || n)
	{
		for (int i = 1; i <= n; i++) dp[i] = INF;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i] >> v[i];
			sum[i] = sum[i - 1] + w[i];
		}
		dp[1] = (double)l / v[1];
		for (int i = 2; i <= n; i++)
		{
			int minn = v[i];
			for (int j = i; j >= 1; j--)
			{
				if (sum[i] - sum[j - 1] > b) continue;
				minn = min(minn, v[j]);
				dp[i] = min(dp[i], dp[j - 1] + (double)l / minn);
			}
		}
		printf("%.1f\n", dp[n] * 60);
	}
	return 0;
}