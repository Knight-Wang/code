#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
vector<int> G[N], F[N], dp[N];
void fac(int x)
{
    for (int i = 2; i * i <= a[x]; i++)
    {
        if (a[x] % i == 0)
        {
            F[x].push_back(i);
            dp[x].push_back(1);
        }
        while (a[x] % i == 0) a[x] /= i;
    }
    if (a[x] != 1) { F[x].push_back(a[x]); dp[x].push_back(1); }
}
void dfs(int u, int f, int& maxn)
{
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u, maxn);
        for (int j = 0; j < F[u].size(); j++)
        {
            for (int k = 0; k < F[v].size(); k++)
            {
                if (F[u][j] == F[v][k])
                {
                    maxn = max(maxn, dp[u][j] + dp[v][k]);
                    dp[u][j] = max(dp[u][j], dp[v][k] + 1);
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n, x, y;
    while (cin >> n)
    {
        bool flg = true;
        for (int i = 1; i <= n; i++)
        {
            F[i].clear(); dp[i].clear(); G[i].clear();
            cin >> a[i];
            if (a[i] != 1) flg = false;
            fac(i);
        }
        for (int i = 1; i < n; i++)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if (flg) { cout << 0 << endl; continue; }
        int maxn = 1;
        dfs(1, 0, maxn);
        cout << maxn << endl;
    }
    return 0;
}