// poj3259.cpp : 定义控制台应用程序的入口点。
//

/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[505];
struct edge
{
	int s, t, w;
	edge(int a, int b, int c)
	{
		s = a; t = b; w = c;
	}
};
vector<edge> es;
int t, n, m, w, a, b, l;
bool bellman_ford(int s)
{
	for (int i = 1; i <= n; i++)
	{
		d[i] = INF;
	}
	d[s] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < es.size(); j++)
		{
			if (d[es[j].s] + es[j].w < d[es[j].t])
			{
				d[es[j].t] = d[es[j].s] + es[j].w;
			}
		}
	}
	for (int i = 0; i < es.size(); i++)
	{
		if (d[es[i].s] + es[i].w < d[es[i].t])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> t;
	while (t--)
	{
		es.clear();
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &l);
			edge e(a, b, l);
			es.push_back(e);
			edge e1(b, a, l);
			es.push_back(e1);
		}
		for (int i = 0; i < w; i++)
		{
			scanf("%d %d %d", &a, &b, &l);
			edge e(a, b, -l);
			es.push_back(e);
		}
		if (bellman_ford(1))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	//system("pause");
	return 0;
}

*/

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[505], times[505];
bool in[505];
struct edge
{
	int t, w;
	edge(int b, int c)
	{
		t = b; w = c;
	}
};
vector<edge> G[505];
int t, n, m, w, a, b, l;

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
	cin >> t;
	while (t--)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		cin >> n >> m >> w;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &a, &b, &l);
			edge e(b, l);
			G[a].push_back(e);
			edge e1(a, l);
			G[b].push_back(e1);
		}
		for (int i = 0; i < w; i++)
		{
			scanf("%d %d %d", &a, &b, &l);
			edge e(b, -l);
			G[a].push_back(e);
		}
		if (spfa(1))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	//system("pause");
	return 0;
}