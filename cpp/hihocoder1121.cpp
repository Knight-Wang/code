#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
vector<int> G[MAXN];
int color[MAXN], n, m;
bool dfs(int u, int c)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int tmp = G[u][i];
		if (color[tmp] == c) return false;
		else if (color[tmp] == 1 - c) continue;
		else 
		{ 
			color[tmp] = 1 - c;
			if (!dfs(tmp, 1 - c)) return false;
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		fill(color + 1, color + n + 1, -1);
		for (int i = 1; i <= n; i++) G[i].clear();
		int a, b;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		bool flg = true;
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == -1)
			{
				color[i] = 1;
				if (!dfs(i, 1)) { flg = false; break; }
			}
		}
		cout << (flg ? "Correct" : "Wrong") << endl;
	}
	return 0;
}