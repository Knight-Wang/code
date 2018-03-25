#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, a[MAXN], in[MAXN];
vector<int> G[MAXN];
double dp[MAXN][2];
bool vis[MAXN];
void dfs(int now)
{
	vis[now] = true;
	for (int i = 0; i < G[now].size(); i++)
	{
		int tmp = G[now][i];
		if (!vis[tmp]) dfs(tmp);
		dp[now][0] += max(dp[tmp][0], dp[tmp][1] + a[tmp]);
		dp[now][1] += max(dp[tmp][0], dp[tmp][1] + (double)a[tmp] / 2.0);
	}	
}
int main()
{
	cin >> n;
	int u, v;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++) { cin >> u >> v; in[v]++; G[u].push_back(v); }
	int i = 1;
	for (; i <= n; i++) if (!in[i]) break;
	dfs(i);
	printf("%.1f\n", max(dp[i][0], dp[i][1] + a[i]));
	return 0;
}
