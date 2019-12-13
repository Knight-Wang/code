#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 0x3f3f3f3f;
vector<int> G[N];
int a[N], vis[N], res[N], n;
void add(int x, int y)
{
    G[x].push_back(y);
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            G[i].clear();
            vis[i] = 0;
            res[i] = -1;
        }
        set<int> st;
        for (int i = 1; i <= n; i++)
        {
            if (i + a[i] <= n)
            {
                if ((a[i] + a[i + a[i]]) % 2 == 1) st.insert(i);
                else add(i + a[i], i);
            }
            if (i - a[i] >= 1)
            {
                if ((a[i] + a[i - a[i]]) % 2 == 1) st.insert(i);
                else add(i - a[i], i);
            }
        }
        queue<int> q;
        for (auto it: st) { q.push(it); res[it] = 1; vis[it] = 1; }
        while (!q.empty())
        {
            int x = q.front(); q.pop();
            for (int j = 0; j < G[x].size(); j++)
            {
                if (vis[G[x][j]]) continue;
                res[G[x][j]] = res[x] + 1;
                q.push(G[x][j]);
                vis[G[x][j]] = 1;
            }
        }
        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}