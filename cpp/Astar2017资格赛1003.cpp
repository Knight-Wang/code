#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[11][1001], A[100005], B[100005], K[1005], P[1005], n, m; 

int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d %d", &A[i], &B[i]);
		for (int i = 0; i < m; i++) scanf("%d %d", &K[i], &P[i]);
		memset(dp, 0x3f, sizeof dp);
		for (int j = 0; j <= 10; j++)
		{
			dp[j][0] = 0;
			for (int i = 0; i < m; i++)
			{
				if (P[i] > j)
				{
					for (int k = 1; k <= 1000; k++)
					{
						dp[j][k] = min(dp[j][k], K[i] * ((k + P[i] - j - 1) / (P[i] - j)));
					}
				}
			}
		}
		
		for (int j = 0; j <= 10; j++)
		{
			for (int i = 1; i < m; i++)
			{
				for (int k = 1; k <= 1000; k++)
				{
					if (P[i] > j && k - (P[i] - j) >= 0)
					{
						dp[j][k] = min(dp[j][k], dp[j][k - (P[i] - j)] + K[i]);
					}
				}
			}
		}
		
		long long sum = 0;
		bool flg = true;
		for (int i = 0; i < n; i++)
		{
			if (dp[B[i]][A[i]] >= INF)
			{
				flg = false; break;
			}
			sum += (long long)dp[B[i]][A[i]];
		}
		if (!flg) puts("-1");
		else printf("%I64d\n", sum);
	}
	return 0;
}