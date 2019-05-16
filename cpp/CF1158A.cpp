#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int b[N], c[N];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            sum += b[i];
        }
        sort(b + 1, b + n + 1);
        bool flg = true;
        for (int i = 1; i <= m; i++)
        {
            cin >> c[i];
            if (c[i] < b[n]) flg = false;
        }
        if (!flg) { cout << -1 << endl; continue; }
        sort(c + 1, c + m + 1);
        ll ans = sum * m;
        for (int i = m; i > 1; i--) ans += c[i] - b[n];
        if (c[1] > b[n]) ans += c[1] - b[n - 1];
        cout << ans << endl;
    }
    return 0;
}