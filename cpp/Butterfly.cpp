// Butterfly.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#define MAXN 1000
using namespace std;
int n, m, x, y, t;
int a[MAXN + 10];
int par[2 * MAXN + 10];
int ran[2 * MAXN + 10];
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
			ran[x]++;
		}
	}
}
bool same(int x, int y)
{
	return find(x) == find(y);
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init(2 * n);
		bool flag = true;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &x, &y, &t);
			if (!flag)
				continue;
			if (t == 0)
			{
				if (same(x, y + n) || same(x + n, y))
				{
					flag = false;
				}
				unite(x, y);
				unite(x + n, y + n);
			}
			else
			{
				if (same(x, y) || same(x + n, y + n))
				{
					flag = false;
				}
				unite(x + n, y);
				unite(x, y + n);
			}
		}
		if (flag)
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	//system("pause");
	return 0;
}

