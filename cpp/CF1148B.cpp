#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll a[N], b[N];
int c[N];
int main()
{
    int n, m, k;
    ll ta, tb;
    while (cin >> n >> m >> ta >> tb >> k)
    {
        for (int i = 1; i <= n; i++) { cin >> a[i]; a[i] += ta; }
        for (int i = 1; i <= m; i++) cin >> b[i];
        int minn = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            int tmp = lower_bound(b + 1, b + m + 1, a[i]) - b;
            minn = min(minn, i + m - tmp);
        }
        int tmp = upper_bound(b + 1, b + m + 1, a[n]) - b;
        minn = min(minn, n);
        if (minn <= k) { cout << -1 << endl; continue; }
        c[0] = -1;
        for (int i = 1; i <= m; i++)
        {
            int tmp = upper_bound(a + 1, a + n + 1, b[i - 1]) - a - 1;
            c[i] = min(tmp, c[i - 1] + 1);
        }
        int i = m;
        for ( ; i >= 1; i--)
        {
            if (c[i] <= k) break;
        }
        if (i == 0) cout << b[1] + tb << endl;
        else cout << b[i] + tb << endl;
    }
    return 0;
}