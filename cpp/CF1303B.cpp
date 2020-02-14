#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll n, g, b; cin >> n >> g >> b;
        ll m = (n + 1) / 2;
        ll res = (m + g - 1) / g;
        ll r = m % g;
        if (r == 0) r = g;
        if ((res - 1) * b >= n - m)
        {
            cout << (res - 1) * (g + b) + r << endl;
        }
        else cout << n << endl;
    }
    return 0;
}