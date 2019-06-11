#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> G[N];
int col[N];
void dfs(int u, int c)
{
    col[u] = c;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (col[v] != -1) continue;
        dfs(v, 1 - c);
    }
}
int main()
{
    int q, n, m, a, b;
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) { G[i].clear(); col[i] = -1; }
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1, 1);
        int cnt = 0, s = 1;
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == 1) cnt++;
        }
        if (cnt > n / 2) { s = 0; cnt = n - cnt; }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == s) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}