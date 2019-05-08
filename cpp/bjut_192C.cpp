#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[200005];
bool check(int x, int n)
{
    int now = -INF;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] + x < now) return false;
        now = max(now, a[i] - x);
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, x;
    while (cin >> n)
    {
        int l = 0, r = INF, ans = INF;
        for (int i = 1; i <= n; i++) cin >> a[i];
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m, n)) { r = m - 1; ans = m; }
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}