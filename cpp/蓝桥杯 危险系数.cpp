#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int a[MAXN][MAXN], tmp[MAXN][MAXN], n, m;
bool vis[MAXN];
bool dfs(int now, int end)
{
	if (now == end) return true;
	vis[now] = true;
	for (int i = 1; i <= n; i++)
	{
		if (tmp[now][i] && !vis[i]) if (dfs(i, end)) return true;
	}
	return false;
}
int main()
{
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) { cin >> x >> y; a[x][y] = a[y][x] = 1; }
	cin >> x >> y;
	memcpy(tmp, a, sizeof a);
	memset(vis, 0, sizeof vis);	
	if (!dfs(x, y)) { cout << -1 << endl; return 0; }
	int cnt = 0;
	for (int k = 1; k <= n; k++)
	{
		if (k == x || k == y) continue;
		memcpy(tmp, a, sizeof a);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) tmp[k][i] = tmp[i][k] = 0;
		if (!dfs(x, y)) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
