#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll get(ll x)
{
    ll res = 1;
    while (x >= 10) { x /= 10; res *= 10; }
    return res;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        ll c = get(n);        
        ll res = 0;
        while (n)
        {
            res += n / c * c;
            n = n % c + n / c * c / 10;
            c = get(n);
        }
        cout << res << endl;
    }
    return 0;
}