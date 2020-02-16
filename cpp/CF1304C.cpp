#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q; cin >> q;
    while (q--)
    {
        int n, m, x, y, l, r, t, T = 0; cin >> n >> m;
        x = m; y = m;
        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            cin >> t >> l >> r;
            x -= t - T; y += t - T;
            if (x > r || y < l) flg = false;
            else
            {
                x = max(x, l); y = min(y, r);
            }
            T = t; 
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}