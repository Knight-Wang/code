// CF750D.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int n, a[35], m[305][305], vis[35][305][305][8];

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void dfs(int cur, int x, int y, int dir)
{
	if (cur == n || vis[cur][x][y][dir])
		return;
	vis[cur][x][y][dir] = m[x][y] = 1;
	for (int i = 1; i < a[cur]; i++)
	{
		x += dx[dir];
		y += dy[dir];
		m[x][y] = 1;
	}
	int nd = (dir + 1) & 7;
	dfs(cur + 1, x + dx[nd], y + dy[nd], nd);
	nd = (dir + 7) & 7;
	dfs(cur + 1, x + dx[nd], y + dy[nd], nd);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	dfs(0, 150, 150, 4);
	int cnt = 0;
	for (int i = 0; i < 305; i++)
	{
		for (int j = 0; j < 305; j++)
		{
			if (m[i][j])
				cnt++;
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

