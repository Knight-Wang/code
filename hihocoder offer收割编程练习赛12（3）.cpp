// hihocoder offer收割编程练习赛12（3）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int n, m, cnt = 0;
int a[305][305];
bool vis[305][305];

void dfs(int x, int y)
{
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 3 * n && ny >= 0 && ny < 3 * m && !a[nx][ny] && !vis[nx][ny])
		{
			dfs(nx, ny);
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c = getchar();
			if (c == '/')
			{
				a[3 * i][3 * j] = 0;
				a[3 * i][3 * j + 1] = 0;
				a[3 * i][3 * j + 2] = 1;
				a[3 * i + 1][3 * j] = 0;
				a[3 * i + 1][3 * j + 1] = 1;
				a[3 * i + 1][3 * j + 2] = 0;
				a[3 * i + 2][3 * j] = 1;
				a[3 * i + 2][3 * j + 1] = 0;
				a[3 * i + 2][3 * j + 2] = 0;
			}
			else if (c == '\\')
			{
				a[3 * i][3 * j] = 1;
				a[3 * i][3 * j + 1] = 0;
				a[3 * i][3 * j + 2] = 0;
				a[3 * i + 1][3 * j] = 0;
				a[3 * i + 1][3 * j + 1] = 1;
				a[3 * i + 1][3 * j + 2] = 0;
				a[3 * i + 2][3 * j] = 0;
				a[3 * i + 2][3 * j + 1] = 0;
				a[3 * i + 2][3 * j + 2] = 1;
			}
		}
		getchar();
	}

	for (int i = 0; i < 3 * n; i++)
	{
		for (int j = 0; j < 3 * m; j++)
		{
			if (!a[i][j] && !vis[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}
