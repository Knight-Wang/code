#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int m, n, x, y, c;
int G[205][205], pre[205];
bool vis[205];
using namespace std;

int augment()
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
		for (int i = 1; i <= m; i++)
		{
			if (G[tmp][i] && !vis[i])
			{
				pre[i] = tmp;
				vis[i] = true;
				if (i == m)
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
	int now = m;
	int minn = INF;
	while (pre[now])
	{
		minn = min(minn, G[pre[now]][now]);
		now = pre[now];
	}
	now = m;
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
	while (cin >> n >> m)
	{
		memset(G, 0, sizeof G);
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> c;
			G[x][y] += c;
		}
		int ans = 0;
		int res = augment();
		while (res)
		{
			ans += res;
			res = augment();
		}
		cout << ans << endl;
	}
	return 0;
}