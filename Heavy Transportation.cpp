// Heavy Transportation.cpp : 定义控制台应用程序的入口点。
//

/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;

bool in[MAXN], vis[MAXN];
int w[MAXN], T, n, m, x, y, c;
int G[MAXN][MAXN];
struct edge
{
	int a, b, cost;
};
edge es[1000005];
int ran[MAXN];
int par[MAXN];

int spfa()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
	    in[tmp] = false;
		for (int i = 1; i <= n; i++)
		{
			if (min(w[tmp], G[tmp][i]) > w[i])
			{
				w[i] = min(w[tmp], G[tmp][i]);
				if (!in[i])
				{
					in[i] = true;
					q.push(i);
				}
			}
		}
	}
	return w[n];
}

int dijkstra()
{
	for (int i = 1; i < n; i++)
	{
		int maxn = 0;
		int index = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && w[j] > maxn)
			{
				maxn = w[j];
				index = j;
			}
		}
		if (index == -1)
			break;
		vis[index] = true;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && min(w[index], G[index][j]) > w[j])
			{
				w[j] = min(w[index], G[index][j]);
			}
		}
	}
	return w[n];
}

int dijkstra_heap()
{
	priority_queue<P> q;
	q.push(P(INF, 1));
	while (!q.empty())
	{
		P tmp = q.top();
		q.pop();
		int now = tmp.second;
		if (tmp.first < w[now])
			continue;
		for (int i = 1; i <= n; i++)
		{
			if (min(w[now], G[now][i]) > w[i])
			{
				w[i] = min(w[now], G[now][i]);
				q.push(P(w[i], i));
			}
		}
	}
	return w[n];
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
	return a.cost > b.cost;
}

int kruskal()
{
	init(n);
	sort(es, es + m, cmp);
	for (int i = 0; i < m; i++)
	{
		if (!same(es[i].a, es[i].b))
		{
			unite(es[i].a, es[i].b);
		}
		if (same(0, n - 1))
			return es[i].cost;
	}
	return es[m - 1].cost;
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			w[i] = (i == 1 ? INF : 0);
			in[i] = (i == 1 ? true : false);
			vis[i] = false;
			for (int j = 1; j <= n; j++)
			{
				G[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> c;
			G[x][y] = G[y][x] = c;
			es[i].a = x - 1;
			es[i].b = y - 1;
			es[i].cost = c;
		}
		cout << "Scenario #" << t << ":" << endl;
		cout << kruskal() << endl << endl;
	}
	//system("pause");
	return 0;
}
*/

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;

bool vis[MAXN];
int T, n, m, x, y, c;
int G[MAXN][MAXN];

bool dfs(int now, int x)
{
	if (now == n)
		return true;
	vis[now] = true;
	for (int i = 1; i <= n; i++)
	{
		if (G[now][i] >= x && !vis[i])
			if (dfs(i, x))
				return true;
	}
	return false;
}

bool check(int x)
{
	memset(vis, 0, sizeof(vis));
	return dfs(1, x);
}

int search(int maxn)
{
	int l = 1, r = maxn, m, res = 0;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (check(m))
		{
			l = m + 1;
			res = m;
		}
		else
		{
			r = m - 1;
		}
	}
	return res;
}
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d", &n, &m);
		memset(G, 0, sizeof(G));
		int maxn = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d", &x, &y, &c);
			G[x][y] = G[y][x] = c;
			maxn = max(maxn, c);
		}
		cout << "Scenario #" << t << ":" << endl;
		cout << search(maxn) << endl << endl;
	}
	//system("pause");
	return 0;
}
