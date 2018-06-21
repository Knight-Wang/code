#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 100005;
vector<pii> G[MAXN];
int dp[MAXN][11], n, s, k;

void dfs(int u, int f)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first, w = G[u][i].second;
        if (v == f) continue;
        dfs(v, u);
        for (int j = k; j >= 0; j--)
        {
            dp[u][j] += dp[v][0] + 2 * w;
            for (int l = 1; l <= j; l++)
            {
                dp[u][j] = min(dp[u][j], dp[v][l] + l * w + dp[u][j - l]);
            }
        }
    }
}

int main()
{
    while (scanf("%d %d %d", &n, &s, &k) != EOF)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) G[i].clear();
        int a, b, w;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d %d %d", &a, &b, &w);
            G[a].push_back(pii(b, w));
            G[b].push_back(pii(a, w));
        }
        dfs(s, 0);
        printf("%d\n", dp[s][k]);
    }
    return 0;
}