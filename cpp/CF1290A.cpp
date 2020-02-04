#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[3505];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m, k; cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (m - k <= 1) { k = m - 1; m = 1; }
        else m -= k;
        int res = -INF;
        for (int i = 0; i <= k; i++)
        {
            int minn = INF;
            for (int j = i + 1; j - m <= i; j++)
            {
                int e = j + n - k - m;
                int t = max(a[j], a[e]);
                minn = min(minn, t);
            }
            res = max(res, minn);
        }
        cout << res << endl;
    }
    return 0;
}