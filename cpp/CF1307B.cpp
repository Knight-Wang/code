#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x, a, maxn = 0; cin >> n >> x;
        bool flg = false;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a == x) flg = true;
            maxn = max(maxn, a);
        }
        if (flg) cout << 1 << endl;
        else cout << max(2, (x + maxn - 1) / maxn) << endl;
    }
    return 0;
}