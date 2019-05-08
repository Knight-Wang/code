#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> G[N];
int num[N];
bool ok[N];
int cnt = 0;
void dfs(int u, int f, int n)
{
    int maxn = 0;
    for (int i = 0; i < (int)G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u, n);
        maxn = max(maxn, num[v]);
        num[u] += num[v];
    }
    maxn = max(maxn, n - num[u]);
    if (n - maxn > n / 2) { ok[u] = true; cnt++; }
}
int main()
{
    int n, x;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) { G[i].clear(); num[i] = 1; ok[i] = false; }
        for (int i = 1; i <= n; i++) { cin >> x; G[x].push_back(i); }
        cnt = 0;
        dfs(1, 0, n);
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
        {
            if (ok[i]) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}