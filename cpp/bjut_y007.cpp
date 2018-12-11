// seven.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int par[100005];
int ran[100005];
int x, y, m, n;

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

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	cin >> m >> n;
	init(100005);
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x != y)
			unite(x, y);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (same(x, y) || x == y)
			cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

