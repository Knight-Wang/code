// 城市规划.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue> 
#include <vector>
#include <functional>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 100000;

struct edge
{
	int to, id;
	ll cost;
};
vector<edge> G[MAXN + 5];
ll d[MAXN + 5];
int pree[2 * MAXN + 5];
bool used[MAXN + 5];

int main()
{
	int n, m, k, a, b;
	ll l;
	cin >> n >> m >> k;
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %lld", &a, &b, &l);
		edge e;
		e.to = b;
		e.cost = l;
		e.id = 0;
		G[a].push_back(e);
		e.to = a;
		G[b].push_back(e);
	}
	for (int i = 0; i < k; i++)
	{
		scanf("%d %lld", &b, &l);
		edge e;
		e.to = b;
		e.cost = l;
		e.id = i + 1;
		G[1].push_back(e);
		e.to = 1;
		e.id = i + 1 + MAXN;
		G[b].push_back(e);
	}
	d[1] = 0;
	priority_queue <P, vector<P>, greater<P> > q;
	q.push(P(0, 1));
	while (!q.empty())
	{
		P tmp = q.top();
		q.pop();
		int v = tmp.second;
		if (d[v] < tmp.first)
		{
			continue;
		}
		for (int i = 0; i < G[v].size(); i++)
		{
        	edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost || (d[e.to] == d[v] + e.cost && pree[e.to] && !e.id))
        	{
        		d[e.to] = d[v] + e.cost;
        		pree[e.to] = e.id;
        		q.push(P(d[e.to], e.to));
        	}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (pree[i] > MAXN)
			pree[i] -= MAXN;
		used[pree[i]] = true;
	}
	for (int i = 1; i <= k; i++)
	{
		cnt += !used[i];
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

