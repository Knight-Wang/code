// poj1182.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#define MAXN 50000
using namespace std;
int a[MAXN + 10];
int par[3 * MAXN + 10];
int ran[3 * MAXN + 10];
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
	int n, k, t, x, y;
	cin >> n >> k;
	int cnt = 0;
	init(3 * n);
	for (int i = 0; i < k; i++)
	{
		scanf("%d %d %d", &t, &x, &y);
		if (x <= 0 || x > n || y <= 0 || y > n)
		{
			cnt++;
			continue;
		}
		x--;
		y--;
		if (t == 1)
		{
			if (same(x + n, y + 2 * n) || same(x + n, y))
			{
				cnt++;
			}
			else
			{
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		}
		else
		{
			if (same(x + n, y) || same(x + 2 * n, y + 2 * n))
			{
				cnt++;
			}
			else
			{
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}