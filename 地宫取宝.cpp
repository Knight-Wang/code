// 地宫取宝.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int a[55][55], dp[55][55][15][15], n, m, k;
bool vis[55][55];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int dfs(int x, int y, int maxn, int t)
{
	if (dp[x][y][maxn + 1][t] != -1)
		return dp[x][y][maxn + 1][t];
	if (x == n - 1 && y == m - 1)
	{
		if (a[x][y] > maxn)
		{
			return t == k - 1 || t == k;
		}
		else
		{
			return t == k;
		}
	}
	int cnt = 0;
	if (a[x][y] > maxn)
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < n && ny < m && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				cnt = (cnt + dfs(nx, ny, a[x][y], t + 1)) % mod;
				cnt = (cnt + dfs(nx, ny, maxn, t)) % mod;
				vis[nx][ny] = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < n && ny < m && !vis[nx][ny])
			{
				vis[nx][ny] = true;
				cnt = (cnt + dfs(nx, ny, maxn, t)) % mod;
				vis[nx][ny] = false;
			}
		}
	}
	return dp[x][y][maxn + 1][t] = cnt;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0, -1, 0) << endl;
	//system("pause");
	return 0;
}

