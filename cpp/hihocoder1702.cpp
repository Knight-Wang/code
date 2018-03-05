#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105][105], dp[101][101][2][21], n;
bool vis[105][105];
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dfs(int x, int y, int last, int t)
{
	if (dp[x][y][last][t] != -1) return dp[x][y][last][t];
	if (x == n - 1 && y == n - 1) return a[x][y];
	ll minn = INF;
	for (int i = 0; i < 2; i++)
	{
		if (t > 20 && i != last) continue;
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && !vis[nx][ny])
		{
			vis[nx][ny] = true;
			minn = min(minn, dfs(nx, ny, i, t + (i != last)) + a[x][y] + (i == last ? 0ll : (1ll << t)));
			vis[nx][ny] = false;
		}
	}
	return dp[x][y][last][t] = minn;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	ll ans = INF;
	ans = min(ans, dfs(0, 1, 0, 0) + a[0][0]);
	memset(vis, 0, sizeof vis);
	ans = min(ans, dfs(1, 0, 1, 0) + a[0][0]);
	cout << ans << endl;
	return 0;
}