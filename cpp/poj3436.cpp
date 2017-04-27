// poj3436.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;

int g[105][15], p, n, q[55];
int G[105][105], G_copy[105][105], layer[105], vis[105];

struct node
{
	int x, y, c;
};

bool countLayer(int s, int e)
{
	layer[s] = 0;
	queue<int> q;
	q.push(s);
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= e; i++)
		{
			if (G[tmp][i] && !vis[i])
			{
				layer[i] = layer[tmp] + 1;
				if (i == e)
				{
					return true;
				}
				vis[i] = true;
				q.push(i);
			}
		}
	}
	return false;
}

int dinic(int s, int e)
{
	int flow = 0;
	deque<int> q;
	while (countLayer(s, e))
	{
		memset(vis, 0, sizeof(vis));
		vis[s] = true;
		q.push_back(s);
		while (!q.empty())
		{
			int tmp = q.back();
			if (tmp == e)
			{
				int minn = INF;
				int min_index = 0;
				for (int i = 1; i < q.size(); i++)
				{
					if (G[q[i - 1]][q[i]] && G[q[i - 1]][q[i]] < minn)
					{
						minn = G[q[i - 1]][q[i]];
						min_index = i - 1;
					}
				}
				for (int i = 1; i < q.size(); i++)
				{
					G[q[i - 1]][q[i]] -= minn;
					G[q[i]][q[i - 1]] += minn;
				}
				while (q.size() && q.back() != min_index)
				{
					vis[q.back()] = false;
					q.pop_back();
				}
				flow += minn;
			}
			else
			{
				bool flag = false;
				for (int i = 1; i <= e; i++)
				{
					if (G[tmp][i] && !vis[i] && layer[i] == layer[tmp] + 1)
					{
						vis[i] = true;
						q.push_back(i);
						flag = true;
						break;
					}
				}
				if (!flag && q.size())
				{
					q.pop_back();
				}
			}
		}
	}
	return flow;
}

int main()
{
	while (cin >> p >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> q[i];
			for (int j = 0; j < p; j++)
			{
				cin >> g[i][j];
			}
			for (int j = 0; j < p; j++)
			{
				cin >> g[i + n][j];
			}
		}
		memset(G, 0, sizeof(G));
		for (int i = 2; i < n + 2; i++)
		{
			G[i][i + n] = q[i - 2];
		}
		for (int i = 2; i < n + 2; i++)
		{
			bool flag = true;
			for (int j = 0; j < p; j++)
			{
				if (g[i - 2][j] != 0 && g[i - 2][j] != 2)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				G[1][i] = INF;
			}
		}
		for (int i = n + 2; i < 2 * n + 2; i++)
		{
			bool flag = true;
			for (int j = 0; j < p; j++)
			{
				if (g[i - 2][j] != 1)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				G[i][2 * n + 2] = INF;
			}
		}
		for (int i = n + 2; i < 2 * n + 2; i++)
		{
			for (int j = 2; j < n + 2; j++)
			{
				bool flag = true;
				for (int k = 0; k < p; k++)
				{
					if (!(g[i - 2][k] == g[j - 2][k] || g[j - 2][k] == 2))
					{
						flag = false;
						break;
					}
				}
				if (flag)
				{
					G[i][j] = INF;
				}
			}
		}
		for (int i = 1; i <= 2 * n + 2; i++)
		{
			for (int j = 1; j <= 2 * n + 2; j++)
			{
				G_copy[i][j] = G[i][j];
			}
		}
		cout << dinic(1, 2 * n + 2) << " ";
		int cnt = 0;
		vector<node> v;
		for (int i = n + 2; i < 2 * n + 2; i++)
		{
			for (int j = 2; j < n + 2; j++)
			{
				if (i - n != j && G[i][j] != G_copy[i][j])
				{
					cnt++;
					node tmp;
					tmp.x = i - n - 1;
					tmp.y = j - 1;
					tmp.c = G_copy[i][j] - G[i][j];
					v.push_back(tmp);
				}
			}
		}
		cout << cnt << endl;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].x << " " << v[i].y << " " << v[i].c << endl;
		}
	}
	//system("pause");
	return 0;
}
