// 蓝桥杯 方格分割.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 6;
const int dx[4] = { 0, 1, -1, 0 };
const int dy[4] = { 1, 0, 0, -1 };

bool vis[6][6];

int dfs(int x, int y)
{
	if (x == 0 || x == N || y == 0 || y == N)
	{
		return 1;
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx <= N && ny >= 0 && ny <= N && !vis[nx][ny])
		{
			vis[nx][ny] = true;
			vis[N - nx][N - ny] = true;
			cnt += dfs(nx, ny);
			vis[nx][ny] = false;
			vis[N - nx][N - ny] = false;
		}
	}
	return cnt;
}

int main()
{
	vis[3][3] = true;
	cout << dfs(3, 3) / 4 << endl;
	system("pause");
	return 0;
}

