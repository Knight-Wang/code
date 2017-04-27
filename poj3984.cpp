// poj3984.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int a[5][5];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[5][5];
struct node
{
	int x, y;
};
node father[5][5];
void print(int x, int y)
{
	if (x == 0 && y == 0)
	{
		cout << "(0, 0)" << endl;
		return;
	}
	print(father[x][y].x, father[x][y].y);
	cout << "(" << x << ", " << y << ")" << endl;
}
void solve()
{
	queue<node> q;
	node s;
	s.x = s.y = 0;
	vis[0][0] = true;
	q.push(s);
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if (tmp.x == 4 && tmp.y == 4)
		{
			print(4, 4);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !vis[nx][ny] && a[nx][ny] == 0)
			{
				node son;
				son.x = nx;
				son.y = ny;
				q.push(son);
				vis[nx][ny] = true;
				father[nx][ny].x = tmp.x;
				father[nx][ny].y = tmp.y;
			}
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
	solve();
	//system("pause");
	return 0;
}

