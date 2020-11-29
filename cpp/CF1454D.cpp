#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll x; cin >> x;
        ll y = x;
        map<ll, int> mp;
        for (ll i = 2; i * i <= x; i++)
        {
            while (x % i == 0) { mp[i]++; x /= i; }
        }
        if (x != 1) mp[x]++;
        int res = 0; ll fac = 0;
        for (auto& it: mp)
        {
            if (it.second > res)
            {
                res = it.second;
                fac = it.first;
            }
        }
        cout << res << endl;
        for (int i = 0; i < res - 1; i++)
        {
            cout << fac << " ";
            y /= fac;
        }
        cout << y << endl;
    }
    return 0;
}