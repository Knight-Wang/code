#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
vector<int> G[N];
ll cnt[N], dp[N];
int n;
void dfs(int u, int p)
{
    cnt[u] = 1;
    for (int i = 0; i < G[u].size(); i++)
    {
        int t = G[u][i];
        if (t == p) continue;
        dfs(t, u);
        cnt[u] += cnt[t];
        dp[u] += dp[t];
    }
    dp[u] += cnt[u];
}
void dfs2(int u, int p, ll x, ll& ans)
{
    ans = max(ans, dp[u] - cnt[u] + x + n);
    for (int i = 0; i < G[u].size(); i++)
    {
        int t = G[u][i];
        if (t == p) continue;
        dfs2(t, u, dp[u] - cnt[u] - dp[t] + x + n - cnt[t], ans);
    }
}
int main()
{
    int a, b;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        memset(cnt, 0, sizeof cnt); memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> a >> b;
            G[a].push_back(b); G[b].push_back(a);
        }
        dfs(1, 0);
        ll maxn = dp[1];
        for (int i = 0; i < G[1].size(); i++)
        {
            int t = G[1][i];
            dfs2(t, 1, dp[1] - dp[t] - cnt[t], maxn);
        }
        cout << maxn << endl;
    }
    return 0;
}