#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int q;
    ll k, n, a, b;
    cin >> q;
    while (q--)
    {
        cin >> k >> n >> a >> b;
        if (k <= b * n) { cout << -1 << endl; continue; }
        ll t = (k - b * n) / (a - b);
        if ((k - b * n) % (a - b) == 0) t--;
        cout << min(t, n) << endl;
    }
    return 0;
}