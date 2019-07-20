#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int a[N][N], b[N][N], c[N], d[N];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(c, 0, sizeof c); memset(d, 0, sizeof d);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> b[i][j]; b[i][j] ^= a[i][j];
                if (b[i][j]) { c[i]++; d[j]++; }
            }
        }
        bool flg = true;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] & 1) { flg = false; break; }
        }
        for (int i = 1; i <= m; i++)
        {
            if (d[i] & 1) { flg = false; break; }
        }
        cout << (flg ? "Yes" : "No") << endl;
    }
    return 0;
}