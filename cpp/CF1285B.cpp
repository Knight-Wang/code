#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main()
{
    int t, n; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        ll maxn = -INF, s = 0, ss = 0;
        int b = 0;
        for (int i = 0; i < n; i++)
        {
            if (s <= 0) { s = a[i]; b = i; }
            else s += a[i];
            ss += a[i];
            if (!(i == n - 1 && b == 0)) maxn = max(maxn, s);
        }
        maxn = max(maxn, ss - a[0]);
        cout << (maxn < ss ? "YES" : "NO") << endl;
    }
    return 0;
}