// CF540C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };

char a[505][505];
int r, c, sx, sy, ex, ey;

bool dfs(int x, int y)
{
	if (x == ex && y == ey && a[x][y] == 'X')
	{
		return true;
	}
	a[x][y] = 'X';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= r && ny >= 1 && ny <= c && (a[nx][ny] == '.' || (nx == ex && ny == ey)))
		{
			if (dfs(nx, ny))
				return true;
		}
	}
	return false;
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> sx >> sy >> ex >> ey;
	a[sx][sy] = '.';
	if (dfs(sx, sy))
		puts("YES");
	else
		puts("NO");
	//system("pause");
	return 0;
}
