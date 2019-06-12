#include <bits/stdc++.h>
using namespace std;
const int N = 505;
char a[N][N];
int l[N][N], r[N][N], u[N][N], d[N][N];
int main()
{
    int h, w;
    while (cin >> h >> w)
    {
        memset(l, 0, sizeof l);
        memset(r, 0, sizeof r);
        memset(u, 0, sizeof u);
        memset(d, 0, sizeof d);
        int cnt = 0;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '*') cnt++;
            }
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++) l[i][j] = (a[i][j] == '*' ? l[i][j - 1] + 1 : 0);
            for (int j = w; j >= 1; j--) r[i][j] = (a[i][j] == '*' ? r[i][j + 1] + 1 : 0);
        }
        for (int j = 1; j <= w; j++)
        {
            for (int i = 1; i <= h; i++) u[i][j] = (a[i][j] == '*' ? u[i - 1][j] + 1 : 0);
            for (int i = h; i >= 1; i--) d[i][j] = (a[i][j] == '*' ? d[i + 1][j] + 1 : 0);
        }
        bool flg = false;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (l[i][j] > 1 && r[i][j] > 1 && u[i][j] > 1 && d[i][j] > 1 && l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3 == cnt)
                {
                    flg = true; break;
                }
            }
            if (flg) break;
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}