#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void dfs(int cur, ll p, vector<ll>& v, ll x, ll& res)
{
    if (cur == v.size()) return;
    res = min(res, max(p, x / p));
    dfs(cur + 1, p * v[cur], v, x, res);
    dfs(cur + 1, p, v, x, res);
}
int main()
{
    ll x, y;
    while (cin >> x)
    {
        y = x;
        map<ll, ll> mp;
        for (ll i = 2; i * i <= x; i++)
        {
            while (x % i == 0) { x /= i; mp[i]++; }
        }
        if (x != 1) mp[x]++;
        vector<ll> v;
        for (auto it: mp)
        {
            ll tmp = 1;
            for (int i = 0; i < it.second; i++) tmp *= it.first;
            v.push_back(tmp);
        }
        ll res = y;
        sort(v.begin(), v.end());
        dfs(0, 1, v, y, res);
        cout << res << " " << y / res << endl;
    }
    return 0;
}