#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 30, INF = 0x3f3f3f3f;

int G[MAXN][MAXN], color[MAXN], n, ans;
string s;

void dfs(int now, int c)
{
	if (now == n)
	{
		ans = min(ans, c);
		return;
	}
	int * buf = new int[MAXN];
	for (int i = 0; i < MAXN; i++) buf[i] = 0;
	int maxn = 0;
	for (int i = 0; i < now; i++)
	{
		if (G[now][i] && color[i])
		{
			maxn = max(maxn, color[i]);
			buf[color[i]] = 1;
		}
	}
	for (int i = 1; i <= maxn + 1; i++)
	{
		if (!buf[i])
		{
			color[now] = i;
			dfs(now + 1, max(i, c));
		}
	}
	delete buf;
}

int main()
{
	while (cin >> n, n)
	{
		memset(G, 0, sizeof(G));
		memset(color, 0, sizeof(color));
		ans = INF;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			int l = s.length();
			for (int j = 2; j < l; j++)
			{
				int tmp = s[j] - 'A';
				G[i][tmp] = G[tmp][i] = 1;
			}
		}
		dfs(0, 0);
		cout << ans << " channel" << (ans > 1 ? "s" : "") << " needed." << endl;	
	}
	return 0;
}