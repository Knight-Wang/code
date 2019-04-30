#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 200005;
vector<int> G[N];
int c[N];
bool dfs(int u, int x)
{
    c[u] = x;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (c[v] == x) return false;
        else if (c[v] == -1 && !dfs(v, 1 - x)) return false;
    }
    return true;
}
int main()
{
    int n, m, u, v;
    while (cin >> n >> m)
    {
        memset(c, -1, sizeof c);
        for (int i = 1; i <= n; i++) G[i].clear();
        unordered_map<int, pii> mp;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            mp[cnt++] = pii(u, v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (!dfs(1, 0)) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        for (int i = 0; i < cnt; i++)
        {
            pii tmp = mp[i];
            if (c[tmp.first] == 1) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}