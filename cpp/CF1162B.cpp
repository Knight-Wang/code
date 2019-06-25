#include <bits/stdc++.h>
using namespace std;

int a[55][55], b[55][55], n, m;

bool check(int c[][55])
{
    bool flg = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] <= c[i][j - 1] || c[i][j] <= c[i - 1][j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> b[i][j];

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int x = min(a[i][j], b[i][j]), y = max(a[i][j], b[i][j]);
                a[i][j] = x; b[i][j] = y;
            }
        }
        if (check(a) && check(b)) cout << "Possible" << endl;
        else cout << "Impossible" << endl;
    }
    return 0;
}