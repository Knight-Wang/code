#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 100005;
vector<int> G[MAXN], qry[MAXN];
int par[MAXN], vis[MAXN];
void init(int n)
{
	for (int i = 0; i <= n; i++) par[i] = i;
}
int find(int x)
{
	if (par[x] == x) return par[x];
	return par[x] = find(par[x]);
}
int uni(int x, int y)
{
	x = find(x); y = find(y);
	if (x == y) return x;
	par[x] = y; return y;
}
void dfs(int u, int f, map<pii, int> & ans)
{
	vis[u] = 1;
	for (auto it: qry[u])
	{
		int tmp = vis[it];
		if (!tmp) continue;
		if (tmp == 1)
			ans[pii(u, it)] = it;
		else if (tmp == 2)
			ans[pii(u, it)] = find(it);
	}
	for (int i = 0; i < G[u].size(); i++)
		if (!vis[G[u][i]]) dfs(G[u][i], u, ans);
	vis[u] = 2;
	uni(u, f);
}
int main()
{
	int n, q;
	cin >> n;
	string x, y;
	map<string, int> mp;
	map<int, string> mp2;
	int id = 1, root = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		int pid = -1, sid = -1;
		if (!mp.count(x)) { mp[x] = pid = id; mp2[id] = x; id++; }
		else pid = mp[x];
		if (!mp.count(y)) { mp[y] = sid = id; mp2[id] = y; id++; }
		else sid = mp[y];
		if (i == 0) root = pid;
		G[pid].push_back(sid);
	}
	cin >> q;
	vector<pii> v;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		int xid = mp[x], yid = mp[y];
		qry[xid].push_back(yid);
		qry[yid].push_back(xid);
		v.push_back(pii(xid, yid));
	}
	init(n);
	map<pii, int> ans;
	dfs(root, 0, ans);
	for (auto it: v)
	{
		int xid = it.first, yid = it.second;
		pii a(xid, yid), b(yid, xid);
		if (ans.count(a)) cout << mp2[ans[a]] << endl;
		else cout << mp2[ans[b]] << endl;
	}
	return 0;
}