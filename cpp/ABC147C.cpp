#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][N], b[N][N];
bool check(int x, int n)
{
    memset(b, -1, sizeof b);
    for (int i = 0; i < n; i++)
    {
        int msk = 1 << i;
        if (x & msk)
        {
            for (int j = 0; j < n; j++)
            {
                b[i][j] = a[i][j];
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        int p = 0, q = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i][j] == -1) continue;
            else if (b[i][j] == 0) p++;
            else q++;
        }
        if (p > 0 && q > 0) return false;
        int g = 1 << j & x;
        if (p && g) return false;
        else if (q && !g) return false;
    }
    return true;
}
int main()
{
    int n, t, p, x;
    while (cin >> n)
    {
        memset(a, -1, sizeof a);
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            for (int j = 0; j < t; j++)
            {
                cin >> p >> x; p--;
                a[i][p] = x;
            }
        }
        int ans = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            if (check(i, n)) ans = max(ans, __builtin_popcount(i));
        }
        cout << ans << endl;
    }
    return 0;
}