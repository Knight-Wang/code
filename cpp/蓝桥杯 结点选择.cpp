// 结点选择.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
const int INF = 0x3f3f3f3f;

int n, x, y;
int dp[MAXN + 5][2], a[MAXN + 5], f[MAXN + 5], vis[MAXN + 5];
vector<int> G[MAXN + 5];

void trans(int root, int p)
{
	for (int i = 0; i < G[root].size(); i++)
	{
		int tmp = G[root][i];
		if (tmp != p)
			trans(tmp, f[tmp] = root);
	}
}

void build()
{
	for (int i = 1; i <= n; i++)
		G[i].clear();
	for (int i = 2; i <= n; i++)
	{
		G[f[i]].push_back(i);
	}
}

void dfs(int now)
{
	vis[now] = 1;
	for (int i = 0; i < G[now].size(); i++)
	{
		int tmp = G[now][i];
		if (!vis[tmp])
		{
			dfs(tmp);
		}
		dp[now][1] += dp[tmp][0];
		dp[now][0] += max(dp[tmp][1], dp[tmp][0]);
	}
	dp[now][1] += a[now];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = -INF;
	trans(1, -1);
	build();
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	dfs(1);
	ans = max(ans, max(dp[1][0], dp[1][1]));
	printf("%d\n", ans);
	//system("pause");
	return 0;
}