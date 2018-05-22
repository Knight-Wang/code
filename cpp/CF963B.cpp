#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<int> G[MAXN], G2[MAXN];
int in[MAXN], n;
int build(int u, int p)
{
	if (!G[u].size()) { G2[p].push_back(u); in[u]++; return 1; }
	int cnt = 0;
	for (int i = 0; i < G[u].size(); i++) cnt += build(G[u][i], u);
	if (cnt & 1) { G2[u].push_back(p); in[p]++; return 0; }
	else { G2[p].push_back(u); in[u]++; return 1; }
}
void toposort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
	while (!q.empty())
	{
		int x = q.front(); q.pop();
		cout << x << endl;
		for (auto it: G2[x])
		{
			in[it]--;
			if (!in[it]) q.push(it);
		}
	}
}
int main()
{
	int x, root;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			G[i].clear(); G2[i].clear();
		}
		memset(in, 0, sizeof in);
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x) G[x].push_back(i);
			else root = i;
		}
		int ans = build(root, 0);
		if (G2[0].size()) in[root]--;
		if (ans & 1)
		{
			cout << "YES" << endl;
			toposort();
		}
		else cout << "NO" << endl;
	}
	return 0;
}