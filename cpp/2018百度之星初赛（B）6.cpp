#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int T, n, mx, my, a, b;
    scanf("%d", &T);
    while (T--)
    {
        ll ans = 0;
        scanf("%d %d %d", &mx, &my, &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &a, &b);
            int d1 = a, d2 = mx - a, d3 = b, d4 = my - b;
            ans += min(d4, min(d3, min(d1, d2)));
        }
        cout << ans << endl;
    }
    return 0;
}