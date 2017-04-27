// poj2377.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge
{
	int a, b, cost;
};
edge es[20005];
int ran[1005];
int par[1005];
int n, m, x, y, c;

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		ran[i] = 0;
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

bool cmp(const edge & a, const edge & b)
{
	return a.cost > b.cost;
}

int kru()
{
	init(n);
	sort(es, es + m, cmp);
	int res = 0, cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (!same(es[i].a, es[i].b))
		{
			unite(es[i].a, es[i].b);
			cnt += 1;
			res += es[i].cost;
		}
	}
	return cnt < n - 1 ? -1 : res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &x, &y, &c);
		es[i].a = x;
		es[i].b = y;
		es[i].cost = c;
	}
	int tmp = kru();
	printf("%d\n", tmp);
	//system("pause");
	return 0;
}

