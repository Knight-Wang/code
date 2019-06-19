#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 255;
const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char a[N][N];
int dis[N][N], vis[N][N];
bool check(int k, int r, int c)
{
    memset(dis, 0, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == '1')
            {
                q.push(pii(i, j));
                vis[i][j] = 1;
                dis[i][j] = 0;
            }
        }
    }
    int maxn = 0;
    while (!q.empty())
    {
        pii tmp = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.first + dx[i], ny = tmp.second + dy[i];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && !vis[nx][ny])
            {
                vis[nx][ny] = 1;
                q.push(pii(nx, ny));
                dis[nx][ny] = dis[tmp.first][tmp.second] + 1;
                maxn = max(maxn, dis[nx][ny]);
            }
        }
    }
    if (maxn <= k) return true;
    int maxx = -INF, maxy = -INF, minx = INF, miny = INF;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (dis[i][j] > k)
            {
                maxx = max(maxx, i + j);
                minx = min(minx, i + j);
                maxy = max(maxy, i - j);
                miny = min(miny, i - j);
            }
        }
    }
    int ans = maxn;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == '1') continue;
            int tx = i + j, ty = i - j, maxd = -INF;
            maxd = max(maxd, abs(maxx - tx));
            maxd = max(maxd, abs(minx - tx));
            maxd = max(maxd, abs(maxy - ty));
            maxd = max(maxd, abs(miny - ty));
            ans = min(ans, maxd);
        }
    }
    return ans <= k;
}
int main()
{
    int T, r, c;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];
        int L = 0, R = r + c, ans = INF;
        while (L <= R)
        {
            int m = L + R >> 1;
            if (check(m, r, c))
            {
                R = m - 1;
                ans = m;
            }
            else L = m + 1;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}