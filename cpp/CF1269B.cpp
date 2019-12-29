#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[2005], b[2005];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n); sort(b, b + n);
        int ans = INF;
        for (int i = 0; i < n; i++)
        {
            int d = a[i] > b[0] ? m - (a[i] - b[0]) : b[0] - a[i];
            bool flg = true;
            for (int j = i; j <= i + n - 1; j++)
            {
                if ((a[j % n] + d) % m != b[j - i]) { flg = false; break; }
            }
            if (flg) ans = min(ans, d);
        }
        cout << ans << endl;
    }
    return 0;
}