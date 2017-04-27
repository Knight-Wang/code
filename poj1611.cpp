// poj1611.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int par[30005];
int ran[30005];

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		ran[i] = 0;
		par[i] = i;
	}
}

int find(int x)
{
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}


void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (ran[x] < ran[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (ran[x] == ran[y])
			ran[x]++;
	}
}

int n, m, p, x, y;
int main()
{
	while (cin >> n >> m, n || m)
	{
		init(n + 1);
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &p);
			if (!p)
				continue;
			scanf("%d", &x);
			for (int j = 0; j < p - 1; j++)
			{
				scanf("%d", &y);
				unite(x, y);
			}
		}
		int tmp = find(0);
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (find(j) == tmp)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	//system("pause");
	return 0;
}

