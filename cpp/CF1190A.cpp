#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll my_ceil(ll x, ll y)
{
    return (x + y - 1) / y;
}
int main()
{
    ll n, m, k, x;
    while (cin >> n >> m >> k)
    {
        queue<ll> q;
        for (int i = 1; i <= m; i++) { cin >> x; q.push(x); }
        ll sum = 0, ans = 0;
        ll cur = my_ceil(q.front() - sum, k);
        while (!q.empty())
        {
            ll tmp = sum;
            while (!q.empty() && my_ceil(q.front() - tmp, k) == cur) { q.pop(); sum++; }
            if (!q.empty()) cur = my_ceil(q.front() - sum, k);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}