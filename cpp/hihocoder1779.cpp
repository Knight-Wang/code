#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[1005], cnt[1005], buf[2005];
int n, k;
struct edge
{
	int id, to; ll cost;
	edge(int id, int to, ll cost): id(id), to(to), cost(cost) {}
};
vector<edge> G[1005];
void dfs(int u, int f)
{
	for (int i = 0; i < G[u].size(); i++)
	{
		int id = G[u][i].id, v = G[u][i].to; ll c = G[u][i].cost;
		if (v == f) continue;
		dfs(v, u);
		cnt[u] += cnt[v];
		buf[id] = cnt[v] * c;
	}
	cnt[u] += a[u];
}
bool cmp(ll a, ll b)
{
	return a > b;
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int x, y; ll w;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y >> w;
		edge e(i, y, w);
		G[x].push_back(e);
		edge e1(i + n - 1, x, w);
		G[y].push_back(e1);
	}
	ll ans = INF;
	for (int i = 1; i <= n; i++)
	{
		memset(buf, 0, sizeof buf);
		memset(cnt, 0, sizeof cnt);
		dfs(i, 0);
		sort(buf, buf + 2 * n - 2, cmp);
		ll tmp = 0;
		for (int i = 0; i < 2 * n - 2; i++)
		{
			if (i < k) continue;
			tmp += buf[i];
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}