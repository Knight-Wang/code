#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
pii a[100005];
bool cmp(pii & a, pii & b)
{
    return a.first - a.second > b.first - b.second;
}
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
        ll ans = 0;
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            ans += (ll)a[i].first * (i - 1) + (ll)a[i].second * (n - i);
        }
        cout << ans << endl;
    }
    return 0;
}