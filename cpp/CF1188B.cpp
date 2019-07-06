#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    ll p, k, x;
    while (cin >> n >> p >> k)
    {
        map<ll, ll> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            x = x * (x * x % p * x % p - k) % p;
            x = (x + p) % p;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
        ll ans = 0;
        for (auto it: mp)
        {
            ans += it.second * (it.second - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}