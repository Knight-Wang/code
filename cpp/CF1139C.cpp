#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 100005;
vector<int> G[N];
int b[N], c[N];
ll my_pow(ll x, int k)
{
    ll ans = 1;
    for (int i = 0; i < k; i++) ans = ans * x % mod;
    return ans;
}
void dfs(int u, int f, int col)
{
    c[u] = col;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        if (v == f) continue;
        dfs(v, u, col);
    }
}
int main()
{
    int n, k, x, y, col;
    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        memset(c, 0, sizeof c);
        memset(b, 0, sizeof b);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x >> y >> col;
            if (col == 1) continue;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            if (c[i]) continue;
            dfs(i, 0, cnt++);
        }
        ll bad = 0;
        for (int i = 1; i <= n; i++) b[c[i]]++;
        for (int i = 1; i < cnt; i++)
        {
            bad = (bad + my_pow(b[i], k)) % mod;
        }
        ll ans = 1;
        for (int i = 0; i < k; i++) ans = ans * n % mod;
        cout << ((ans - bad) % mod + mod) % mod << endl;
    }
    return 0;
}