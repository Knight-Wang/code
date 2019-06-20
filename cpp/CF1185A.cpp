#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5];
ll cal(ll a, ll b, ll d)
{
    if (b - a >= d) return 0;
    return d - (b - a);
}
int main()
{
    ll d;
    while (cin >> a[0] >> a[1] >> a[2] >> d)
    {
        sort(a, a + 3);
        cout << cal(a[0], a[1], d) + cal(a[1], a[2], d) << endl;
    }
    return 0;
}