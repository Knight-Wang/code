// CF_round_403_C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> G[200005];
int color[200005];
int ans = 1;
void dfs(int now, int f)
{
	int x = 0;
	for (int i = 0; i < G[now].size(); i++)
	{
		if (G[now][i] == f || color[G[now][i]])
			continue;
		x++;
		while (x == color[now] || x == color[f])
			x++;
		color[G[now][i]] = x;
		dfs(G[now][i], now);
	}
	if (x > ans)
		ans = x;
}
int n, x, y;
int main()
{
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	color[1] = 1;
	dfs(1, 0);
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << color[i] << " ";
	}
	cout << endl;
	//system("pause");
	return 0;
}

