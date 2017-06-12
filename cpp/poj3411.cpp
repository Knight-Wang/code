#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 15, INF = 0x3f3f3f3f;
int n, m;
struct edge
{
	int to, c, p, r;
};
vector<edge> G[MAXN];
int vis[MAXN];

int dfs(int now)
{
	if (now == n)
		return 0;
	int ans = INF;
	for (int i = 0; i < G[now].size(); i++)
	{
		if (vis[G[now][i].to] > 3) continue;
		vis[G[now][i].to]++;
		int x = dfs(G[now][i].to) + G[now][i].r;
		ans = min(ans, x);
		int y = INF;
		if (vis[G[now][i].c])
			y = dfs(G[now][i].to) + G[now][i].p;
		ans = min(ans, y);
		vis[G[now][i].to]--;
	}
	return ans;
}

int main()
{
	//freopen("d:\\codes\\tmp\\in.txt", "r", stdin);
	cin >> n >> m;
	int a, b, c, p, r;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c >> p >> r;
		G[a].push_back(edge{b, c, p, r});
	}
	vis[1] = true;
	int ans = dfs(1);
	if (ans == INF) puts("impossible");
	else cout << ans << endl;
	return 0;
}