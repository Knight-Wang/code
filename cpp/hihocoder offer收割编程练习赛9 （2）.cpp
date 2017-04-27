// hihocoder offer收割编程练习赛9 （2）.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

char a[805][805];
int n, m, d[805][805];
bool vis[805][805];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct node
{
	int x, y;
};
void solve()
{
	queue<node> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '0')
			{
				vis[i][j] = true;
				q.push(node{i, j});
			}
		}
	}
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == '1')
			{
				vis[nx][ny] = true;
				d[nx][ny] = d[tmp.x][tmp.y] + 1;
				q.push(node{nx, ny});
			}
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
	solve();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << d[i][j] << " ";
		}
		puts("");
	}
	//system("pause");
	return 0;
}