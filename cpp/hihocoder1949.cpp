#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
char a[1005][1005];
int vis[1005][1005], d[1005][1005];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(vis, 0, sizeof vis);
        memset(d, 0, sizeof d);
        queue<pii> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '1') { q.push(make_pair(i, j)); vis[i][j] = 1; }
            }
        }
        while (!q.empty())
        {
            pii tmp = q.front(); q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = tmp.first + dx[i], ny = tmp.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    d[nx][ny] = d[tmp.first][tmp.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        int minn = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '2') minn = min(minn, d[i][j]);
            }
        }
        cout << minn + 1 << endl;
    }
    return 0;
}