#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll cal(ll x, ll y, ll i, ll & minn, ll & ans)
{
    if (i > x)
    {
        if (y + i - x < minn)
        {
            minn = y + i - x;
            ans = i - x;
        }
    }
    else
    {
        ll k = 0;
        if (x % i) k = (x / i + 1) * i - x;
        ll t = (x + k) * (y + k) / __gcd(y - x, x + k);
        if (t < minn)
        {
            minn = t;
            ans = k;
        }
    }
}
int main()
{
    ll a, b;
    while (cin >> a >> b)
    {
        ll x = min(a, b), y = max(a, b);
        if (y % x == 0) { cout << 0 << endl; continue; }
        ll minn = INF, ans = 0;
        for (int i = 1; i * i <= y - x; i++)
        {
            if ((y - x) % i == 0)
            {
                cal(x, y, i, minn, ans);
                if ((y - x) / i != i) cal(x, y, (y - x) / i, minn, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}