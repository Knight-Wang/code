// hihocoder编程练习赛8(2).cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char a[505][505];
int n, m, minx, miny, maxx, maxy;
bool vis[505][505], ok[505][505];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void dfs(int x, int y)
{
	ok[x][y] = vis[x][y] = true;
	minx = min(x, minx);
	miny = min(y, miny);
	maxx = max(x, maxx);
	maxy = max(y, maxy);
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == '1')
		{
			dfs(nx, ny);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (!vis[i][j] && a[i][j] == '1')
			{
				minx = maxx = i, miny = maxy = j;
				memset(ok, 0, sizeof(ok));
				dfs(i, j);
				cout << maxx - minx + 1 << " " << maxy - miny + 1 << endl;
				for (int j = minx; j <= maxx; j++)
				{
					for (int k = miny; k <= maxy; k++)
					{
						cout << ok[j][k];
					}
					cout << endl;
				}
			}
		}
	}
	//system("pause");
	return 0;
}
