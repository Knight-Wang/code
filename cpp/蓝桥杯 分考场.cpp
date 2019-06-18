#include <bits/stdc++.h>
using namespace std;
const int N = 105, INF = 0x3f3f3f3f;

int G[N][N], n, m, ans = INF;
vector<int> r[N];

bool check(int x, int y)
{
    for (int i = 0; i < r[y].size(); i++)
    {
        if (G[x][r[y][i]]) return false;
    }
    return true;
}

void dfs(int cur, int cnt)
{
    if (cnt >= ans) return;
    if (cur == n + 1) { ans = min(ans, cnt); return; }
    for (int i = 1; i <= cnt + 1; i++)
    {
        if (check(cur, i))
        {
            r[i].push_back(cur);
            dfs(cur + 1, max(i, cnt));
            r[i].pop_back();
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}