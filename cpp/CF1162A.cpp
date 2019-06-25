#include <bits/stdc++.h>
using namespace std;

int maxn[55];
int main()
{
    int n, m, h, l, r, x;
    while (cin >> n >> h >> m)
    {
        for (int i = 1; i <= n; i++) maxn[i] = h;
        for (int i = 0; i < m; i++)
        {
            cin >> l >> r >> x;
            for (int j = l; j <= r; j++) maxn[j] = min(maxn[j], x);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += maxn[i] * maxn[i];
        cout << ans << endl;
    }
    return 0;
}