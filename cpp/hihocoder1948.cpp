#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int n, k;
bool check(ll x)
{
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum >= x) { sum = a[i]; cnt++; }
        else sum += a[i];
    }
    if (sum >= x) cnt++;
    return cnt >= k;
}
int main()
{
    while (cin >> n >> k)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
        ll l = 0, r = sum, ans = 0;
        while (l <= r)
        {
            ll m = l + r >> 1;
            if (check(m))
            {
                ans = m; l = m + 1;
            }
            else r = m - 1;
        }
        cout << ans << endl;
    }
    return 0;
}
