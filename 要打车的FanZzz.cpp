// 要打车的FanZzz.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 200;
int n, m;
double v, dis[MAXN + 5][MAXN + 5], edges[MAXN * MAXN + 5];
vector<int> G[MAXN + 5];
bool used[MAXN + 5];
int match[MAXN + 5];

struct point
{
	int x, y;
};
point man[MAXN / 2 + 5], car[MAXN / 2 + 5];

bool dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++)
	{
		int u = G[v][i];
		int w = match[u];
		if (w == -1 || !used[w] && dfs(w))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int max_match()
{
	int res = 0;
	for (int i = 1; i <= n + m; i++)
	{
		if (match[i] == -1)
		{
			memset(used, 0, sizeof(used));
			if (dfs(i))
				res++;
		}
	}
	return res;
}

bool check(double len)
{
	for (int i = 1; i <= n + m; i++)
		match[i] = -1;
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n + m; i++)
		G[i].clear();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dis[i][j] <= len)
			{
				G[i + 1].push_back(j + n + 1);
				G[j + n + 1].push_back(i + 1);
			}
		}
	}
	return max_match() >= n;
}

int square(int x)
{
	return x * x;
}

double cal_cost(int i, int j)
{
	return sqrt(square(man[i].x - car[j].x) + square(man[i].y - car[j].y));
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> man[i].x >> man[i].y;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> car[i].x >> car[i].y;
		}
		cin >> v;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				edges[cnt++] = dis[i][j] = cal_cost(i, j);
			}
		}
		sort(edges, edges + cnt);
		int l = 0, r = cnt - 1, res = cnt - 1;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (check(edges[mid]))
			{
				res = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		printf("%.2lf\n", edges[res] / v);
	}
	//system("pause");
	return 0;
}