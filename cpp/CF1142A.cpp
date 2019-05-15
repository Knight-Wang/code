#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n, k;
void solve(ll r, ll & minn, ll & maxn)
{
    for (int x = r ? 0 : 1; k * x + r <= n * k; x++)
    {
        ll ans = n * k / __gcd(n * k, k * x + r);
        minn = min(minn, ans);
        maxn = max(maxn, ans);
    }
}
int main()
{
    ll a, b;
    while (cin >> n >> k >> a >> b)
    {
        ll minn = INF, maxn = 0;
        solve((a + b) % k, minn, maxn);
        solve(((-a + b) % k + k) % k, minn, maxn);
        solve(((a - b) % k + k) % k, minn, maxn);
        solve(((-a - b) % k + k) % k, minn, maxn);
        cout << minn << " " << maxn << endl;
    }
    return 0;
}