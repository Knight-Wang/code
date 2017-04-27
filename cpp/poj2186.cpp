// poj2186.cpp : 定义控制台应用程序的入口点。
//

/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

vector<int> G[10005], G_t[10005], res;
int n, m, x, y, cmp[10005];
bool vis[10005];
void dfs(int x)
{
	vis[x] = true;
	for (int i = 0; i < G[x].size(); i++)
	{
		if (!vis[G[x][i]])
			dfs(G[x][i]);
	}
	res.push_back(x);
}

void rdfs(int x, int k)
{
	vis[x] = true;
	cmp[x] = k;
	for (int i = 0; i < G_t[x].size(); i++)
	{
		if (!vis[G_t[x][i]])
		{
			rdfs(G_t[x][i], k);
		}
	}
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
			G_t[i].clear();
		}
		res.clear();
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
			G_t[y].push_back(x);
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
				dfs(i);
		}
		memset(vis, 0, sizeof(vis));
		int k = 0;
		for (int i = res.size() - 1; i >= 0; i--)
		{
			if (!vis[res[i]])
			{
				rdfs(res[i], k++);
			}
		}
		int cnt = 0, tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cmp[i] == k - 1)
			{
				cnt++;
				tmp = i;
			}
		}
		memset(vis, 0, sizeof(vis));
		rdfs(tmp, 0);
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				cnt = 0;
				break;
			}
		}
		printf("%d\n", cnt);
	}
	//system("pause");
	return 0;
}
*/

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> G[10005];
int index = 1, now = 1, low[10005], dfn[10005], in[10005], cmp[10005], out[10005];
int n, m, x, y;
stack<int> s;

void tarjan(int x)
{
	dfn[x] = low[x] = index++;
	s.push(x);
	in[x] = true;
	for (int i = 0; i < G[x].size(); i++)
	{
		int v = G[x][i];
		if (!dfn[v])
		{
			tarjan(v);
			low[x] = min(low[x], low[v]);
		}
		else if (in[v])
		{
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (low[x] == dfn[x])
	{
		while (s.top() != x)
		{
			cmp[s.top()] = now;
			in[s.top()] = false;
			s.pop();
		}
		cmp[s.top()] = now++;
		in[s.top()] = false;
		s.pop();
	}
}

int main()
{
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		memset(cmp, 0, sizeof(cmp));
		memset(out, 0, sizeof(out));
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		memset(in, 0, sizeof(in));
		index = now = 1;
		while (!s.empty())
		{
			s.pop();
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			G[x].push_back(y);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i])
			{
				tarjan(i);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (cmp[i] == 1)
				cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < G[i].size(); j++)
			{
				int v = G[i][j];
				if (cmp[i] != cmp[v])
				{
					out[cmp[i]]++;
				}
			}
		}
		int num = 0;
		for (int i = 1; i < now; i++)
		{
			if (!out[i])
			{
				if (!num)
					num++;
				else
				{
					cnt = 0;
					break;
				}
			}
		}
		printf("%d\n", cnt);
	}
	//system("pause");
	return 0;
}
