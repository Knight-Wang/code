#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
    ll n, m, k;
    while (cin >> n >> m >> k)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<pair<ll, int>> v;
        for (int i = 1; i < n; i++) v.push_back(pair<ll, int>(a[i + 1] - a[i], i));
        sort(v.begin(), v.end());
        vector<int> g;
        ll ans = 0;
        for (int i = n - 2; i > n - 1 - k; i--) g.push_back(v[i].second);
        g.push_back(0); g.push_back(n);
        sort(g.begin(), g.end());
        for (int i = 0; i < k; i++) ans += a[g[i + 1]] - a[g[i] + 1] + 1;
        cout << ans << endl;
    }
    return 0;
}