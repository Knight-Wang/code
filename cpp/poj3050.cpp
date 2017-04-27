// poj3050.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int a[5][5];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool vis[1000000];
int now[6];
void dfs(int x, int y, int d)
{
	if (d == 6)
	{
		int tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			tmp += now[i];
			if (i != 5)
				tmp *= 10;
		}
		vis[tmp] = true;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
		{
			now[d] = a[nx][ny];
			dfs(nx, ny, d + 1);
		}
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			dfs(i, j, 0);
		}
	}
	int cnt = 0;
	for (int i = 0; i <= 999999; i++)
	{
		if (vis[i])
			cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

