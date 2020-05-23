#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, ll> cal(ll x)
{
    pair<ll, ll> res(10, 0);
    while (x)
    {
        res.first = min(res.first, x % 10);
        res.second = max(res.second, x % 10);
        x /= 10;
    }
    return res;
}
int main()
{
    int t; ll a, k;
    cin >> t;
    while (t--)
    {
        cin >> a >> k;
        for (int i = 1; i < min(k, 100ll); i++)
        {
            pair<ll, ll> tmp = cal(a);
            a += tmp.first * tmp.second;
        }
        cout << a << endl;
    }
    return 0;
}