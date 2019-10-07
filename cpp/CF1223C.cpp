#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll p[N], sum[N];
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
bool check(ll c, ll k, ll x, ll y, ll a, ll b)
{
    ll ca = c / a, cc = c / lcm(a, b);
    ll tmp = sum[ca] * x + sum[cc] * y;
    ll cb = c / b - cc;
    tmp += (sum[min(c, ca + cb)] - sum[ca]) * y;
    return tmp >= k * 100;
}
bool cmp(ll a, ll b)
{
    return a > b;
}
int main()
{
    int q, n;
    ll x, y, a, b, k;
    cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> p[i];
        sort(p + 1, p + n + 1, cmp);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + p[i];
        cin >> x >> a >> y >> b >> k;
        if (x < y) { swap(x, y); swap(a, b); }
        ll l = 1, r = n, res = -1;
        while (l <= r)
        {
            ll m = l + r >> 1;
            if (check(m, k, x, y, a, b))
            {
                res = m; r = m - 1;
            }
            else l = m + 1;
        }
        cout << res << endl;
    }
    return 0;
}