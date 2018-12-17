#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300000;
int n, m;
int vis[MAXN + 5];
ll ans[MAXN + 5], bit[MAXN + 5];
vector<int> G[MAXN + 5];
vector<pair<int, ll>> upd[MAXN + 5];

inline int lowbit(int x) { return x & -x; }

void add(int x, ll d)
{
	while (x <= MAXN)
	{
		bit[x] += d;
		x += lowbit(x);
	}
}

ll sum(int x)
{
	ll ans = 0;
	while (x)
	{
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

void dfs(int u, int d)
{
	vis[u] = 1;
	for (int i = 0; i < upd[u].size(); i++)
	{
		add(d, upd[u][i].second);
		add(d + upd[u][i].first + 1, -upd[u][i].second);
	}
	ans[u] = sum(d);
	for (int i = 0; i < G[u].size(); i++)
	{
		if (vis[G[u][i]]) continue;
		dfs(G[u][i], d + 1);
	}
	for (int i = 0; i < upd[u].size(); i++)
	{
		add(d, -upd[u][i].second);
		add(d + upd[u][i].first + 1, upd[u][i].second);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int v, d, a, b; ll x;
	while (cin >> n)
	{
		memset(bit, 0, sizeof bit);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) { G[i].clear(); upd[i].clear(); }
		for (int i = 1; i < n; i++)
		{
			cin >> a >> b;
			G[a].push_back(b); G[b].push_back(a);
		}
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> v >> d >> x;
			upd[v].push_back(make_pair(d, x));
		}
		dfs(1, 1);
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}