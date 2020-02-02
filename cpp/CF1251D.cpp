#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll l[N], r[N];
bool check(ll x, int n, ll s)
{
    ll tmp = 0;
    int low = 0, up = 0;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        if (r[i] < x) { low++; tmp += l[i]; }
        else if (l[i] >= x) { up++; tmp += l[i]; }
        else v.push_back(make_pair(l[i], r[i]));
    }
    if (up >= (n + 1) / 2) return true;
    int r = (n + 1) / 2 - up;
    if (v.size() < r) return false;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - r; i++) tmp += v[i].first;
    tmp += r * x;
    return tmp <= s;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; ll s; cin >> n >> s;
        ll L = 0, R = 0;
        for (int i = 0; i < n; i++) { cin >> l[i] >> r[i]; R = max(R, r[i]); }
        int res = 0;
        while (L <= R)
        {
            ll m = L + R >> 1;
            if (check(m, n, s)) { res = m; L = m + 1; }
            else R = m - 1;
        }
        cout << res << endl;
    }
    return 0;
}