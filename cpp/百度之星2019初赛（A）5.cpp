#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[10];
int main()
{
    int T; cin >> T;
    ll n;
    b[1] = 1; b[2] = 1; b[3] = 0; b[4] = 3; b[5] = 0; b[6] = 3;
    map<ll, ll> mp;
    mp[1] = 4; mp[2] = 3; mp[3] = 1; mp[4] = 6; mp[5] = 1; mp[6] = 3;
    while (T--)
    {
        cin >> n;
        ll ans = 0;
        if (n <= 6) ans = b[n];
        else
        {
            ll t = n % 6;
            if (t == 0) t = 6;
            ans = b[t];
            ans += (t == 6 ? (n - 6) / 6 : n / 6) * mp[t];
        }
        cout << ans << endl;
    }
    return 0;
}
