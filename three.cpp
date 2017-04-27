// three.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

char a[25][25];
bool vis[25][25];
int dis[25][25];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int m, n, sx, sy;
struct node
{
	int x, y;
};
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '@')
			{
				sx = i;
				sy = j;
			}
		}
	}
	queue<node> q;
	node s;
	s.x = sx;
	s.y = sy;
	q.push(s);
	vis[sx][sy] = true;
	bool flag = false;
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if (a[tmp.x][tmp.y] == '*')
		{
			cout << dis[tmp.x][tmp.y] << endl;
			flag = true;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny] && a[nx][ny] != '#')
			{
				vis[nx][ny] = true;
				node son;
				son.x = nx;
				son.y = ny;
				dis[nx][ny] = dis[tmp.x][tmp.y] + 1;
				q.push(son);
			}
		}
	}
	if (!flag)
	{
		cout << "-1" << endl;
	}
	//system("pause");
	return 0;
}

