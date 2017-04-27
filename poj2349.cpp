// poj2349.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int x, y;
};
struct edge
{
	int a, b;
	double cost;
};
vector<node> ns;
vector<edge> es;
int ran[505];
int par[505];
int t, k, n, x, y;

int square(int x)
{
	return x * x;
}

bool cmp1(const double & x, const double & y)
{
	return x > y;
}

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

bool cmp(edge a, edge b)
{
	return a.cost < b.cost;
}

void kru(vector<double> & res, int m)
{
	init(n);
	sort(es.begin(), es.end(), cmp);
	for (int i = 0; i < m; i++)
	{
		if (!same(es[i].a, es[i].b))
		{
			unite(es[i].a, es[i].b);
			res.push_back(es[i].cost);
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		ns.clear();
		es.clear();
		cin >> k >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			node tmp;
			tmp.x = x;
			tmp.y = y;
			ns.push_back(tmp);
		}
		for (int i = 0; i < ns.size(); i++)
		{
			for (int j = i + 1; j < ns.size(); j++)
			{
				edge e;
				e.a = i;
				e.b = j;
				e.cost = sqrt(square(ns[i].x - ns[j].x) + square(ns[i].y - ns[j].y));
				es.push_back(e);
				e.a = j;
				e.b = i;
				es.push_back(e);
			}
		}
		vector<double> res;
		kru(res, es.size());
		sort(res.begin(), res.end(), cmp1);
		printf("%.2f\n", res[k - 1]);
	}
	//system("pause");
	return 0;
}
