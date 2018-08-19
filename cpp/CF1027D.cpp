#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int INF = 0x3f3f3f3f;
int a[MAXN], c[MAXN], vis[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	while (cin >> n)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) cin >> c[i];
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i]) continue;
			int u = i;
			while (!vis[u])
			{
				vis[u] = i;
				u = a[u];
			}
			if (vis[u] == i)
			{
				int minn = c[u], v = a[u];
				while (v != u)
				{
					minn = min(minn, c[v]);
					v = a[v];
				}
				ans += minn;
			}
		}
		cout << ans << endl;
	}
	return 0;
}