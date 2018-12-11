#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 300005;
vector<pair<int, ll>> G[MAXN];
ll w[MAXN], a[MAXN], b[MAXN];
int vis[MAXN];

void dfs(int x)
{
	vis[x] = 1;
	for (int i = 0; i < G[x].size(); i++)
	{
		if (!vis[G[x][i].first])
		{
			dfs(G[x][i].first);
			ll tmp = a[G[x][i].first] - G[x][i].second;
			if (tmp >= a[x]) { b[x] = a[x]; a[x] = tmp; }
			else if (tmp > b[x]) b[x] = tmp;
		}
	}
	a[x] += w[x]; b[x] += w[x];
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		int u, v; ll c;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear(); cin >> w[i];
			a[i] = b[i] = vis[i] = 0;
		}
		for (int i = 0; i < n - 1; i++)
		{
			cin >> u >> v >> c;
			G[u].push_back(make_pair(v, c));
			G[v].push_back(make_pair(u, c));
		}
		dfs(1);
		ll ans = 0;
		for (int i = 1; i <= n; i++) ans = max(ans, a[i] + b[i] - w[i]);
		cout << ans << endl;
	}
	return 0;
}