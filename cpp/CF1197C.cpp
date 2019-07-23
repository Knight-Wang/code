#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
ll a[N];
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ans = a[n] - a[1];
        vector<ll> v;
        for (int i = 1; i <= n - 1; i++)
        {
            v.push_back(a[i] - a[i + 1]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k - 1; i++) ans += v[i];
        cout << ans << endl;
    }
    return 0;
}