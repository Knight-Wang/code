#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll my_pow(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return my_pow(x, mod - 2);
}

ll cal(ll x)
{
    if (x == 0) return 0;
    ll cnt = 0, y = x;
    while (y) { y >>= 1; cnt++; }
    ll n1 = cnt / 2, n2 = cnt / 2;
    ll ans = 0, l1, l2;
    if (cnt % 2 == 1)
    {
        l1 = (my_pow(4, n1) - 1) * inv(3) % mod; l2 = 2 * (my_pow(4, n2) - 1) % mod * inv(3) % mod;
        l1 = (l1 + x - ((1ll << cnt - 1) - 1)) % mod;
    }
    else
    {
        n2--;
        l1 = (my_pow(4, n1) - 1) * inv(3) % mod; l2 = 2 * (my_pow(4, n2) - 1) % mod * inv(3) % mod;
        l2 = (l2 + x - ((1ll << cnt - 1) - 1)) % mod;
    }
    ans = (ans + l1 * l1 % mod) % mod;
    ans = (ans + l2 * (l2 + 1) % mod) % mod;
    return ans;
}

int main()
{
    ll l, r;
    while (cin >> l >> r)
    {
        cout << ((cal(r) - cal(l - 1)) % mod + mod) % mod << endl;
    }
    return 0;
}