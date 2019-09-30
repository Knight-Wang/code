#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
 
ll my_pow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
ll work(ll x, ll n)
{
    ll ans = 0, cur = x;
    while (cur <= n)
    {
        ans = (ans + n / cur) % (MOD - 1);
        ll new_cur = cur * x;
        if (new_cur < cur) break;
        cur = new_cur;
    }
    return my_pow(x, ans);
}
int main()
{
    ll x, n;
    while (cin >> x >> n)
    {
        ll ans = 1;
        for (ll i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                while (x % i == 0) x /= i;
                ans = ans * work(i, n) % MOD;
            }
        }
        if (x != 1) ans = ans * work(x, n) % MOD;
        cout << ans << endl;
    }
    return 0;
}