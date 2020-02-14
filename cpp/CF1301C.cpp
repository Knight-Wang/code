#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n, m; cin >> n >> m;
        if (m >= n - m - 1) cout << n * (n + 1) / 2 - n + m << endl;
        else
        {
            ll x = (n - m) / (m + 1), y = (n - m) % (m + 1);
            ll res = y * (x + 1) * (x + 2) / 2 + (m + 1 - y) * x * (x + 1) / 2;
            cout << n * (n + 1) / 2 - res << endl;
        }
    }
    return 0;
}