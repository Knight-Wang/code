#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
bool vis[MAXN];
int ans = 0;
int dfs(int u)
{
	vis[u] = true;
	int cnt = 0;
	for (int i = 0; i < G[u].size(); i++)
	{
		int tmp = G[u][i];
		if (!vis[tmp]) cnt += dfs(tmp);
	}
	if (cnt & 1) ans++;
	return cnt + 1;
}
int main()
{
	int n, x, y;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) G[i].clear();
		memset(vis, 0, sizeof vis);
		ans = 0;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> x >> y;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		if (n & 1) { cout << -1 << endl; continue; }
		dfs(1);
		cout << ans - 1 << endl;
	}
	return 0;
}