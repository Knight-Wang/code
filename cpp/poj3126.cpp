// poj3126.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 10000;
bool check[MAXN + 5];
bool vis[MAXN + 5];

struct node
{
	int now, d;
};

void init()
{
	for (int i = 0; i <= MAXN; i++)
	{
		check[i] = true;
	}
	check[0] = check[1] = false;
	for (int i = 2; i <= MAXN; i++)
	{
		if (check[i])
		{
			for (int j = 2 * i; j <= MAXN; j += i)
				check[j] = false;
		}
	}
}

bool is_prime(int x)
{
	return check[x];
}

int solve(int x, int t)
{
	node start;
	start.now = x;
	start.d = 0;
	vis[x] = true;
	queue<node> q;
	q.push(start);
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();
		if (tmp.now == t)
		{
			return tmp.d;
		}
		int u = tmp.now;
		int t = 1000;
		int last = 0;
		for (int i = 0; i < 4; i++)
		{
			int now = u / t % 10;
			for (int j = 0; j <= 9; j++)
			{
				if ((i == 0 && j == 0) || j == now)
					continue;
				int n = last + j * t + u % t;
				if (is_prime(n) && !vis[n])
				{
					vis[n] = true;
					node son;
					son.now = n;
					son.d = tmp.d + 1;
					q.push(son);
				}
			}
			last += now * t;
			t /= 10;
		}
	}
	return -1;
}

int main()
{
	int t, x, y;
	cin >> t;
	init();
	while (t--)
	{
		cin >> x >> y;
		memset(vis, 0, sizeof(vis));
		int res = solve(x, y);
		if (res != -1)
			cout << res << endl;
		else
			cout << "Impossible" << endl;
	}
	//system("pause");
	return 0;
}

