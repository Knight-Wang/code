#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[1005], b[1005];
int c[1005][1005];
int main()
{
    int h, w;
    while (cin >> h >> w)
    {
        memset(c, -1, sizeof c);
        for (int i = 0; i < h; i++) cin >> a[i];
        for (int i = 0; i < w; i++) cin >> b[i];
        bool flg = true;
        for (int j = 0; j < w; j++)
        {
            for (int i = 0; i < b[j]; i++)
            {
                c[i][j] = 1;
            }
            if (b[j] < h) c[b[j]][j] = 0;
        }
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                if (c[i][j] == 0) { flg = false; break; }
                c[i][j] = 1;
            }
            if (a[i] < w)
            {
                if (c[i][a[i]] == 1) { flg = false; break; }
                else c[i][a[i]] = 0;
            }
            if (!flg) break;
        }
        if (!flg) cout << 0 << endl;
        else
        {
            int ans = 1;
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    if (c[i][j] == -1) ans = ans * 2 % MOD;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}