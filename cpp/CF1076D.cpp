#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 300005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

bool in[MAXN];
int par[MAXN], cnt[MAXN];
int n, m, k, a, b, w;
ll dis[MAXN];

struct node
{
	int to;
	ll cost;
};
vector<node> G[MAXN];
vector<int> tree[MAXN];

void spfa()
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = (i == 1 ? 0 : INF);
		in[i] = (i == 1 ? true : false);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
	    in[tmp] = false;
		for (int i = 0; i < G[tmp].size(); i++)
		{
			int to = G[tmp][i].to;
			if (dis[tmp] + G[tmp][i].cost < dis[to])
			{
				dis[to] = dis[tmp] + G[tmp][i].cost;
				par[to] = tmp;
				if (!in[to])
				{
					in[to] = true;
					q.push(to);
				}
			}
		}
	}
}

void dfs(int x)
{
	if (tree[x].size() == 0) { cnt[x] = 1; return; }
	int ans = 0;
	for (int i = 0; i < tree[x].size(); i++)
	{
	 	dfs(tree[x][i]);
		ans += cnt[tree[x][i]];
	}
	cnt[x] = ans + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> k)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear(); tree[i].clear(); par[i] = 0; cnt[i] = 0;
		}
		map<pair<int, int>, int> mp;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> w;
			mp[make_pair(a, b)] = i + 1;
			mp[make_pair(b, a)] = i + 1;
			node tmp;
			tmp.to = b;
			tmp.cost = w;
			G[a].push_back(tmp);
			tmp.to = a;
			G[b].push_back(tmp);
		}
		spfa();
		for (int i = 1; i <= n; i++) { tree[par[i]].push_back(i); cnt[i] = 0; }
		dfs(1);
		priority_queue<pair<int, int>> q;
		for (int i = 1; i <= n; i++) q.push(make_pair(cnt[i], i));
		q.pop();
		cout << min(k, n - 1) << endl;
		for (int i = 0; i < min(k, n - 1); i++)
		{
			pair<int, int> tmp = q.top(); q.pop();
			cout << mp[make_pair(tmp.second, par[tmp.second])] << " ";
		}
		cout << endl;
	}
	return 0;
}