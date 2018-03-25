#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
vector<int> G[MAXN];
int n, m;
bool vis[MAXN];
int dfs(int s, int now, int c)
{
	if (c == 3) return 1;
	int cnt = 0;
	for (int i = 0; i < G[now].size(); i++)
	{
		int tmp = G[now][i];
		if (!vis[tmp]) 
		{
			if (c == 1 && tmp == s) continue;
			vis[tmp] = true;
			cnt += dfs(s, tmp, c + 1);
			vis[tmp] = false;
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	int x, y;
	long long cnt = 0;
	for (int i = 0; i < m; i++) 
	{	
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof vis);
		cnt += dfs(i, i, 0);
	}
	cout << cnt << endl;
	return 0;
}
