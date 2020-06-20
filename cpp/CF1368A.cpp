#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        ll a, b, n;
        cin >> a >> b >> n;
        if (a > b) swap(a, b);
        if (a > n) { cout << 0 << endl; continue; }
        ll x1 = 0, x2 = 1, y1 = 1, y2 = 1; int c = 1;
        while (x2 * a + y2 * b <= n)
        {
            ll x3 = x1 + x2;
            x1 = x2; x2 = x3;
            ll y3 = y1 + y2;
            y1 = y2; y2 = y3;
            c++;
        }
        cout << c << endl;
    }
    return 0;
}