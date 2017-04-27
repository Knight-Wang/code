// CF741B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m, w, a[1005], b[1005], x, y, group[1005], value[1005], fuck[1005][1005], cnt = 0, dp[1005], shit[1005][1005], p = 0, size[1005];
bool vis[1005];
int max(int a, int b)
{
	return a > b ? a : b;
}
void divide(int now)
{
	vis[now] = true;
	shit[cnt][p++] = now;
	group[cnt] += a[now];
	value[cnt] += b[now];
	for (int i = 0; i < n; i++)
	{
		if (fuck[now][i] && !vis[i])
		{
			divide(i);
		}
	}
}
/*
int dfs(int cur, int w)
{
	if (dp[cur][w] != -1)
		return dp[cur][w];
	if (cur == cnt)
	{
		return 0;
	}
	int maxn = 0;
	if (w - group[cur] >= 0)
		maxn = max(maxn, dfs(cur + 1, w - group[cur]) + value[cur]);
	maxn = max(maxn, dfs(cur + 1, w));
	for (int i = 0; i < size[cur]; i++)
	{
		int tmp = shit[cur][i];
		if (w - a[tmp] >= 0)
			maxn = max(maxn, dfs(cur + 1, w - a[tmp]) + b[tmp]);
	}
	return dp[cur][w] = maxn;
}
*/
void solve()
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (j + group[i] <= w)
				dp[j] = max(dp[j], dp[j + group[i]] + value[i]);
			for (int k = 0; k < size[i]; k++)
			{
				int tmp = shit[i][k];
				if (j + a[tmp] <= w)
					dp[j] = max(dp[j], dp[j + a[tmp]] + b[tmp]);
			}
		}
	}
	cout << dp[0] << endl;
}
int main()
{
	cin >> n >> m >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		fuck[x - 1][y - 1] = fuck[y - 1][x - 1] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			p = 0;
			divide(i);
			size[cnt++] = p;
		}
	}
	/*记忆化搜索
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, w) << endl;
	*/
	//dp
	solve();
	//system("pause");
	return 0;
}

