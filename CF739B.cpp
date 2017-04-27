// CF739B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 200000
using namespace std;
typedef long long ll;
int n, a[MAXN + 5], res[MAXN + 5], path[MAXN + 5];
ll sum[MAXN + 5], ans[MAXN + 5];
struct node
{
	int to, cost;
};
vector<node> G[MAXN + 5];
void solve(int x, int d, ll s)
{
	sum[d] = s;
	path[d] = x;
	int l = lower_bound(sum + 1, sum + d + 1, s - a[x]) - sum - 1;
	res[path[d]]++;
	res[path[l]]--;
	for (int i = 0; i < G[x].size(); i++)
	{
		solve(G[x][i].to, d + 1, s + G[x][i].cost);
	}
}
void dfs(int x)
{
	ans[x] = res[x];
	for (int i = 0; i < G[x].size(); i++)
	{
		dfs(G[x][i].to);
		ans[x] += ans[G[x][i].to];
	}
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
		int x, y;
		scanf("%d %d", &x, &y);
		node tmp;
		tmp.to = i+2;
		tmp.cost = y;
		G[x].push_back(tmp);
	}
	solve(1, 1, 0);
	dfs(1);
	for (int i = 1; i <= n; i++)
		printf("%I64d ", ans[i]-1);
	puts("");
	//("pause");
	return 0;
}

