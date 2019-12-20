#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        a = abs(a - b);
        ll res = 0;
        for (int i = 0; i <= 100000; i++)
        {
            ll tmp = (ll)i * (i + 1) / 2;
            if (tmp >= a && (tmp - a) % 2 == 0)
            {
                res = i; break;
            }
        }
        cout << res << endl;
    }
    return 0;
}