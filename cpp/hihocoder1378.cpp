#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 505;

int n, m;
int G[N][N], pre[N];
bool vis[N];

int augment(int s, int t)
{
    queue<int> q;
    q.push(s);
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    bool flg = false;
    while (!q.empty())
    {
        int tmp = q.front(); q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (G[tmp][i] && !vis[i])
            {
                pre[i] = tmp;
                vis[i] = true;
                if (i == t) { flg = true; break; }
                else q.push(i);
            }
        }
        if (flg) break;
    }
    if (!flg) return 0;
    int now = t;
    int minn = INF;
    while (pre[now])
    {
        minn = min(minn, G[pre[now]][now]);
        now = pre[now];
    }
    now = t;
    while (pre[now])
    {
        G[pre[now]][now] -= minn;
        G[now][pre[now]] += minn;
        now = pre[now];
    }
    return minn;
}
int main()
{
    while (cin >> n >> m)
    {
        memset(G, 0, sizeof(G));
        int a, b, c;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;
            G[a][b] += c;
        }
        int ans = 0;
        int res = augment(1, n);
        while (res)
        {
            ans += res;
            res = augment(1, n);
        }
        cout << ans << " ";
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) cnt++;
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}