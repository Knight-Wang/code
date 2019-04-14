#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int f[N], l[N], t[N][N], ans[N][N];
int main()
{
    int n, m, h;
    while (cin >> n >> m >> h)
    {
        memset(ans, 0, sizeof ans);
        for (int i = 1; i <= m; i++) cin >> f[i];
        for (int i = 1; i <= n; i++) cin >> l[i];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> t[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (t[i][j])
                {
                    ans[i][j] = min(l[i], f[j]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}