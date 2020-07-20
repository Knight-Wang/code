#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x, y; cin >> n >> m;
        int res = INF;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y;
            res = min(res, (m + x - 1) / x * y);
        }
        cout << res << endl;
    }
    return 0;
}