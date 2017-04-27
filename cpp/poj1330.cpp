// poj1330.cpp : 定义控制台应用程序的入口点。
//

//基础版本
/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[10005];
int t, n, x, y;
int in[10005], parent[10005], depth[10005];

void dfs(int v, int p, int d)
{
	parent[v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
	}
}

void init(int root)
{
	dfs(root, -1, 0);
}

int lca(int root, int x, int y)
{
	while (depth[x] > depth[y])
	{
		x = parent[x];
	}
	while (depth[y] > depth[x])
	{
		y = parent[y];
	}
	while (x != y)
	{
		x = parent[x];
		y = parent[y];
	}
	return x;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		memset(depth, 0, sizeof(depth));
		memset(in, 0, sizeof(depth));
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			in[y]++;
		}
		int root = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				root = i;
				break;
			}
		}
		cin >> x >> y;
		init(root);
		cout << lca(root, x, y) << endl;
	}
	//system("pause");
	return 0;
}
*/

//二分版本
/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_LOG_N = 14;

vector<int> G[10005];
int t, n, x, y;
int in[10005], parent[MAX_LOG_N][10005], depth[10005];

void dfs(int v, int p, int d)
{
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
	}
}

void init(int root)
{
	dfs(root, -1, 0);
	for (int k = 0; k < MAX_LOG_N - 1; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (parent[k][i] < 0)
			{
				parent[k + 1][i] = -1;
			}
			else
			{
				parent[k + 1][i] = parent[k][parent[k][i]];
			}
		}
	}
}

int lca(int root, int x, int y)
{
	if (depth[x] > depth[y])
		swap(x, y);
	for (int k = 0; k < MAX_LOG_N; k++)
	{
		if ((depth[y] - depth[x]) >> k & 1)
		{
			y = parent[k][y];
		}
	}
	if (x == y)
	{
		return x;
	}
	for (int k = MAX_LOG_N - 1; k >= 0; k--)
	{
		if (parent[k][x] != parent[k][y])
		{
			x = parent[k][x];
			y = parent[k][y];
		}
	}
	return parent[0][y];
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		memset(depth, 0, sizeof(depth));
		memset(in, 0, sizeof(depth));
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			in[y]++;
		}
		int root = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				root = i;
				break;
			}
		}
		cin >> x >> y;
		init(root);
		cout << lca(root, x, y) << endl;
	}
	//system("pause");
	return 0;
}
*/

//RMQ版本
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
vector<int> G[MAXN];
int t, n, x, y;
int in[MAXN], depth[2 * MAXN - 1], id[MAXN], vs[2 * MAXN - 1];

const int MAXM = 32768;
const int INF = 0x3f3f3f3f;
struct node
{
	int index, d;
};
node data[2 * MAXM - 1];

void update(int k, int a)
{
	int tmp = k;
	k += n - 1;
	data[k].index = tmp;
	data[k].d = a;
	while (k)
	{
		k = (k - 1) / 2;
		if (data[2 * k + 1].d < data[2 * k + 2].d)
		{
			data[k].d = data[2 * k + 1].d;
			data[k].index = data[2 * k + 1].index;
		}
		else
		{
			data[k].d = data[2 * k + 2].d;
			data[k].index = data[2 * k + 2].index;
		}
	}
}

void rmq_init(int * depth, int k)
{
	n = 1;
	while (n < k) n <<= 1;
	for (int i = 0; i < 2 * n; i++)
	{
		data[i].d = INF;
	}
	for (int i = 0; i < k; i++)
	{
		update(i, *(depth + i));
	}
}

node query(int a, int b, int k, int l, int r)
{
	if (b <= l || a >= r)
	{
		node res;
		res.index = -1;
		res.d = INF;
		return res;
	}
	if (l >= a && r <= b)
		return data[k];
	node x = query(a, b, 2 * k + 1, l, (l + r) / 2);
	node y = query(a, b, 2 * k + 2, (l + r) / 2, r);
	if (x.d < y.d)
		return x;
	return y;
}

void dfs(int v, int p, int d, int & k)
{
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	for (int i = 0; i < G[v].size(); i++)
	{
		if (G[v][i] != p)
		{
			dfs(G[v][i], v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
		}
	}
}

int init(int root)
{
	int k = 0;
	dfs(root, -1, 0, k);
	rmq_init(depth, k);
	return k;
}

int lca(int root, int x, int y)
{
	node res = query(min(id[x], id[y]), max(id[x], id[y]) + 1, 0, 0, n);
	return vs[res.index];
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		memset(depth, 0x3f, sizeof(depth));
		memset(in, 0, sizeof(depth));
		memset(id, 0, sizeof(id));
		memset(vs, 0, sizeof(vs));
		for (int i = 0; i < n - 1; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			in[y]++;
		}
		int root = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!in[i])
			{
				root = i;
				break;
			}
		}
		int res = init(root);
		cin >> x >> y;
		cout << lca(root, x, y) << endl;
	}
	//system("pause");
	return 0;
}