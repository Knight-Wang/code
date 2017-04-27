// poj1703.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100000;

int a[MAXN + 10];
int par[2 * MAXN + 10];
int ran[2 * MAXN + 10];
int t, n, m, x, y;
char p;

void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		par[i] = i;
		ran[i] = 0;
	}
}

int find(int x)
{
	if (x == par[x])
		return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return;
	}
	if (ran[x] < ran[y])
	{
		par[x] = y;
	}
	else
	{
		par[y] = x;
		if (ran[x] == ran[y])
		{
			ran[x] ++;
		}
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		getchar();
		init(2 * n);
		for (int i = 0; i < m; i++)
		{
			scanf("%c %d %d", &p, &x, &y);
			getchar();
			x--;
			y--;
			if (p == 'D')
			{
				unite(x, y + n);
				unite(x + n, y);
			}
			else
			{
				if (same(x, y) || same(x + n, y + n))
				{
					puts("In the same gang.");
				}
				else if (same(x + n, y) || same(x, y + n))
				{
					puts("In different gangs.");
				}
				else
				{
					puts("Not sure yet.");
				}
			}
		}
	}
	//system("pause");
	return 0;
}