// poj3268.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[1005], back[1005], times[1005];
bool in[1005];
struct edge
{
	int t, w;
	edge(int b, int c)
	{
		t = b; w = c;
	}
};
vector<edge> G[1005];
int n, m, x, a, b, l;

bool spfa(int s)
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
		in[i] = false;
		times[i] = 0;
	}
	queue<int> q;
	q.push(s);
	in[s] = true;
	d[s] = 0;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		in[tmp] = false;
		for (int i = 0; i < G[tmp].size(); i++)
		{
			if (d[tmp] + G[tmp][i].w < d[G[tmp][i].t])
			{
				d[G[tmp][i].t] = d[tmp] + G[tmp][i].w;
				times[G[tmp][i].t]++;
				if (times[G[tmp][i].t] == n)
				{
					return false;
				}
				if (!in[G[tmp][i].t])
				{
					in[G[tmp][i].t] = true;
					q.push(G[tmp][i].t);
				}
			}
		}
	}
	return true;
}

int main()
{
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &l);
		edge e(b, l);
		G[a].push_back(e);
	}
	int maxn = 0;
	spfa(x);
	memcpy(back, d, (n + 1) * sizeof(int));
	for (int i = 1; i <= n; i++)
	{
		spfa(i);
		maxn = max(maxn, d[x] + back[i]);
	}
	cout << maxn << endl;
	//system("pause");
	return 0;
}

