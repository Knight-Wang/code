#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], l[N], r[N];
int main()
{
    int q; cin >> q;
    while (q--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> v(a, a + n);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        int m = v.size();
        for (int i = 1; i <= m; i++) { l[i] = n + 1; r[i] = 0; }
        for (int i = 0; i < n; i++)
        {
            l[a[i]] = min(l[a[i]], i + 1);
            r[a[i]] = max(r[a[i]], i + 1);
        }
        int ans = m - 1, tmp = 1;
        for (int i = m - 1; i >= 1; i--)
        {
            if (r[i] < l[i + 1]) tmp++;
            else tmp = 1;
            ans = min(ans, m - tmp);
        }
        cout << ans << endl;
    }
    return 0;
}