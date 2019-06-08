#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[300005];
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n - 1; i >= 1; i--) a[i] += a[i + 1];
        ll ans = a[1];
        sort(a + 2, a + n + 1);
        for (int i = n; i >= n - k + 2; i--) ans += a[i];
        cout << ans << endl;
    }
    return 0;
}