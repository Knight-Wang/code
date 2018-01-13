#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

#define N (398)
#define M (N * N + 4 * N)
const int INF = 0x3f3f3f3f;
typedef long long LL;

using namespace std;

struct edge 
{
	int v, cap, next;
};
edge e[M];

int head[N], level[N], cur[N];
int num_of_edges;

void dinic_init(void) 
{
	num_of_edges = 0;
	memset(head, -1, sizeof(head));
	return;
}

int add_edge(int u, int v, int c1, int c2) 
{
	int& i = num_of_edges;

	assert(c1 >= 0 && c2 >= 0 && c1 + c2 >= 0); // check for possibility of overflow
	e[i].v = v;
	e[i].cap = c1;
	e[i].next = head[u];
	head[u] = i++;

	e[i].v = u;
	e[i].cap = c2;
	e[i].next = head[v];
	head[v] = i++;
	return i;
}

int dfs(int u, int t, int bn) 
{
	if (u == t) return bn;
	int left = bn;
	for (int &i = cur[u]; i >= 0; i = e[i].next) 
	{
		int v = e[i].v;
		int c = e[i].cap;
		if (c > 0 && level[u] + 1 == level[v]) 
		{
			int flow = dfs(v, t, min(left, c));
			if (flow > 0) 
			{
				e[i].cap -= flow;
				e[i ^ 1].cap += flow;
				cur[u] = i;
				left -= flow;
				if (!left) break;
			}
		}
	}
	if (left > 0) level[u] = 0;
	return bn - left;
}

bool bfs(int s, int t) 
{
	memset(level, 0, sizeof(level));
	level[s] = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) 
	{
		int u = q.front();
		q.pop();
		if (u == t) return true;
		for (int i = head[u]; i >= 0; i = e[i].next) 
		{
			int v = e[i].v;
			if (!level[v] && e[i].cap > 0) 
			{
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
	return false;
}

LL dinic(int s, int t) 
{
	LL max_flow = 0;

	while (bfs(s, t)) 
	{
		memcpy(cur, head, sizeof(head));
		max_flow += dfs(s, t, INT_MAX);
	}
	return max_flow;
}

int n, p, t;
struct Edge
{
	int a, b, cost;
};
Edge es[40005];

bool check(int x)
{
	dinic_init();
	for (int i = 0; i < p; i++)
	{
		if (es[i].cost <= x)
		{
			add_edge(es[i].a, es[i].b, 1, 0);
			add_edge(es[i].b, es[i].a, 1, 0);			
		}
	}
	return dinic(1, n) >= t;
}

int main()
{
	scanf("%d %d %d", &n, &p, &t);
	int maxn = 0;
	for (int i = 0; i < p; i++)
	{
		scanf("%d %d %d", &es[i].a, &es[i].b, &es[i].cost);
		maxn = max(maxn, es[i].cost);
	}
	int l = 0, r = maxn, ans = INF;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (check(m))
		{
			r = m - 1; ans = m;
		}
		else l = m + 1;
	}
	printf("%d\n", ans);
	return 0;
}