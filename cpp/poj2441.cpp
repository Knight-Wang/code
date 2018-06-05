#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> G[21];
int n, m, dp[1 << 21];
int main()
{
	int p, x;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &p);
		for (int j = 0; j < p; j++)
		{
			scanf("%d", &x);
			G[i].push_back(x);
		}
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = (1 << m + 1) - 1; j >= 0; j--)
		{
			if (__builtin_popcount(j) != i) continue;
			for (int k = 0; k < G[i + 1].size(); k++)
			{
				int tmp = G[i + 1][k];
				if (!(j >> tmp & 1)) dp[j | 1 << tmp] += dp[j];
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j < (1 << m + 1) - 1; j++) 
		if (__builtin_popcount(j) == n) cnt += dp[j];
	printf("%d\n", cnt);
	return 0;
}