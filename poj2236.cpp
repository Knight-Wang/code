// poj2236.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct node
{
	int x, y;
};
node a[1005];
char t;
int n, p, q;
double d;
int ran[1005];
int par[1005];
bool ok[1005];

double dis[1005][1005];

double square(int a)
{
	return a * a;
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dis[i][j] = sqrt(square(a[i].x - a[j].x) + square(a[i].y - a[j].y));
		}
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
	scanf("%d %lf", &n, &d);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	getchar();
	init();
	while (scanf("%c", &t) != EOF)
	{
		if (t == 'O')
		{
			scanf("%d", &p);
			getchar();
			for (int j = 1; j <= n; j++)
			{
				if (dis[p][j] <= d && ok[j])
				{
					unite(p, j);
				}
			}
			ok[p] = true;
		}
		else
		{
			scanf("%d %d", &p, &q);
			getchar();
			if (same(p, q))
				puts("SUCCESS");
			else
				puts("FAIL");
		}
	}
	//system("pause");	
	return 0;
}

