#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int p[N], c[N];
vector<int> G[N];
void dfs(int u, int f, vector<int> & ans)
{
    bool flg = true;
    if (c[u] == 0) flg = false;
    if (flg)
    {
        for (int i = 0; i < G[u].size(); i++)
        {
            if (G[u][i] == f) continue;
            else if (c[G[u][i]] == 0) { flg = false; break; }
        }
    }
    if (flg) ans.push_back(u);
    for (int i = 0; i < G[u].size(); i++)
    {
        if (G[u][i] == f) continue;
        dfs(G[u][i], u, ans);
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> p[i] >> c[i];
        for (int i = 1; i <= n; i++) G[i].clear();
        int root = 0;
        for (int i = 1; i <= n; i++)
        {
            if (p[i] != -1) G[p[i]].push_back(i);
            else root = i;
        }
        vector<int> ans;
        dfs(root, -1, ans);
        if (ans.empty()) cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end());
            for (auto it: ans) cout << it << " ";
            cout << endl;
        }
    }
    return 0;
}