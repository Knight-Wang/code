#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i) sum += abs(a[i] - a[i - 1]);
        }
        ll maxn = 0;
        for (int i = 0; i < n; i++)
        {
            ll tmp = 0;
            if (i != 0 && i != n - 1) tmp = abs(a[i + 1] - a[i - 1]);
            ll x = (i < n - 1 ? abs(a[i + 1] - a[i]) : 0);
            ll y = (i > 0 ? abs(a[i] - a[i - 1]) : 0);
            maxn = max(maxn, x + y - tmp);
        }
        cout << sum - maxn << endl;
    }   
    return 0;
}
