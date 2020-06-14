#include <bits/stdc++.h>
using namespace std;
int a[35][35];
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        int res = 0;
        for (int k = 0; k < (n + m - 1) / 2; k++)
        {
            int c0 = 0, c1 = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (i + j == k || n + m - 2 - i - j == k)
                    {
                        if (a[i][j] == 0) c0++;
                        else c1++;
                    }
                }
            }
            res += min(c0, c1);
        }
        cout << res << endl;
    }
    return 0;
}