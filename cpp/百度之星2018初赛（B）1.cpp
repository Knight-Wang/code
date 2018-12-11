#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<int> G[MAXN];
int vis[MAXN], in[MAXN], maxd[MAXN];
void dfs(int u, int c)
{
    vis[u] = c;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (!vis[v]) dfs(v, c);
    }
}
int main()
{
    int T, n, m, k, a, b;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        memset(vis, 0, sizeof vis);
        memset(in, 0, sizeof in);
        memset(maxd, 0, sizeof maxd);
        for (int i = 0; i < n; i++) G[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            in[a]++; in[b]++;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]) { cnt++; dfs(i, cnt); }
        }
        for (int i = 0; i < n; i++)
        {
            maxd[vis[i]] = max(maxd[vis[i]], in[i]);
        }
        int ans = 0;
        for (int i = 1; i <= cnt; i++)
        {
            ans = max(ans, maxd[i]);
        }
        cout << ans + min(k, m - ans) + cnt - 1 << endl;
    }
    return 0;
}