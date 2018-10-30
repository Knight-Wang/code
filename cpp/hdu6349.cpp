#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct edge
{
    int a, b, w;
    char c;
};
edge es[111];
int par[111], n, m;
int find(int x)
{
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}
bool uni(int a, int b)
{
    a = find(a), b = find(b);
    if (a != b) { par[b] = a; return true; }
    return false;
}
bool same(int a, int b)
{
    return find(a) == find(b);
}
bool cmp(const edge& x, const edge& y)
{
    return x.w <= y.w;
}
vector<int> kru(char col)
{
    for (int i = 1; i <= n; i++) par[i] = i;
    int cost = 0, used = 0, cnt = n;
    vector<int> v(m + 1, INF);
    vector<int> vis(m + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        if (es[i].c == col) continue;
        if (!same(es[i].a, es[i].b))
        {
            uni(es[i].a, es[i].b);
            cost += es[i].w;
            used++;
            cnt--;
            vis[i] = 1;
            if (cnt == 1) v[used] = cost;
        }
    }
    if (cnt == 1)
    {
        for (int i = 1; i <= m; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                used++;
                cost += es[i].w;
                v[used] = cost;
            }
        }
    }
    return v;
}
int main()
{
    int T, a, b, w;
    char c;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> es[i].a >> es[i].b >> es[i].w >> es[i].c;
        }
        sort(es + 1, es + m + 1, cmp);
        vector<int> ans1 = kru('B');
        vector<int> ans2 = kru('R');
        vector<int> ans(m + 1, INF);
        for (int i = 1; i <= m; i++) ans[i] = min(ans1[i], ans2[i]);
        cout << "Case #" << t << ":" << endl;
        for (int i = 1; i <= m; i++) 
            cout << (ans[i] == INF ? -1 : ans[i]) << endl;
    }
    return 0;
}