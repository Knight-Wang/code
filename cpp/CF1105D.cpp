#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
char a[1005][1005];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int s[10], ans[10], l[10], d[1005][1005];
inline bool check(int x, int y, int n, int m)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '.';
}
int main()
{
    int n, m, p;
    while (cin >> n >> m >> p)
    {
        memset(ans, 0, sizeof ans);
        memset(d, 0, sizeof d);
        memset(l, 0, sizeof l);
        for (int i = 0; i < p; i++) cin >> s[i];
        vector<queue<pii>> v(p);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] >= '1' && a[i][j] <= '9')
                {
                    v[a[i][j] - '1'].push(make_pair(i, j));
                }
            }
        }
        while (true)
        {
            bool flg = true;
            for (int i = 0; i < p; i++)
            {
                while (!v[i].empty())
                {
                    pii t = v[i].front();
                    int x = t.first, y = t.second;
                    if (d[x][y] >= l[i] + s[i]) break;
                    v[i].pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (check(nx, ny, n, m))
                        {
                            v[i].push(make_pair(nx, ny));
                            a[nx][ny] = char('1' + i);
                            d[nx][ny] = d[x][y] + 1;
                        }
                    }
                }
                l[i] += s[i];
                if (v[i].size() > 0) flg = false;
            }
            if (flg) break;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] >= '1' && a[i][j] <= '9') ans[a[i][j] - '0']++;
            }
        }
        for (int i = 1; i <= p; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}