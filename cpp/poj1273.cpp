// poj1273.cpp : 定义控制台应用程序的入口点。
//

/*
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int m, n, x, y, c;
int G[205][205], pre[205];
bool vis[205];

int argument()
{
	queue<int> q;
	q.push(1);
	memset(pre, 0, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	vis[1] = true;
	bool flag = false;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (G[tmp][i] && !vis[i])
			{
				pre[i] = tmp;
				vis[i] = true;
				if (i == n)
				{
					flag = true;
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				else
					q.push(i);
			}
		}
	}
	if (!flag)
	{
		return 0;
	}
	int now = n;
	int minn = INF;
	while (pre[now])
	{
		minn = min(minn, G[pre[now]][now]);
		now = pre[now];
	}
	now = n;
	while (pre[now])
	{
		G[pre[now]][now] -= minn;
		G[now][pre[now]] += minn;
		now = pre[now];
	}
	return minn;
}
int main()
{
	while (cin >> m >> n)
	{
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> c;
			G[x][y] += c;
		}
		int ans = 0;
		int res = argument();
		while (res)
		{
			ans += res;
			res = argument();
		}
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}
*/

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
int G[205][205];
int layer[205], n, m, a, b, l;
bool vis[205];

bool countLayer()
{
	layer[1] = 0;
	queue<int> q;
	q.push(1);
	memset(vis, 0, sizeof(vis));
	vis[1] = true;
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (G[tmp][i] && !vis[i])
			{
				layer[i] = layer[tmp] + 1;
				if (i == n)
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

int dinic()
{
	int flow = 0;
	deque<int> q;
	while (countLayer())
	{
		memset(vis, 0, sizeof(vis));
		vis[1] = true;
		q.push_back(1);
		while (!q.empty())
		{
			int tmp = q.back();
			if (tmp == n)
			{
				int minn = INF;
				int min_index;
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
				for (int i = 1; i <= n; i++)
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
	while (cin >> m >> n)
	{
		memset(G, 0, sizeof(G));
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> l;
			G[a][b] += l;
		}
		cout << dinic() << endl;
	}
	//system("pause");
	return 0;
}
