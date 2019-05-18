#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        ll ans = 0;
        for (int i = 0; i < n; i++) { cin >> a[i]; a[i] = abs(a[i]); }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            ans += upper_bound(a + i + 1, a + n, 2 * a[i]) - a - i - 1;
        }
        cout << ans << endl;
    }
    return 0;
}