#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int dp[4 * N], v[4 * N], p[4 * N], a[4 * N];
int main()
{
    int t, h, n; cin >> t;
    while (t--)
    {
        memset(v, 0, sizeof v);
        memset(dp, 0x3f, sizeof dp);
        cin >> h >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[n + 1] = 0;
        vector<int> vv;
        for (int i = n; i >= 1; i--)
        {
            vv.push_back(a[i + 1]);
            if (a[i] > a[i + 1] + 1) vv.push_back(a[i + 1] + 1);
        }
        vv.push_back(a[1]);
        for (int i = 1; i <= n; i++) p[i] = lower_bound(vv.begin(), vv.end(), a[i]) - vv.begin();
        for (int i = 1; i <= n; i++) v[p[i]] = 1;
        h = vv.size() - 1;
        dp[h] = 0;
        if (v[h - 1] == 0) dp[h - 1] = 0;
        else dp[h - 1] = 1;
        for (int i = h - 2; i >= 1; i--)
        {
            if (v[i] == 0)
            {
                dp[i] = min(dp[i], dp[i + 1]);
                if (v[i + 1] == 0) dp[i] = min(dp[i], dp[i + 2] + 2);
                else dp[i] = min(dp[i], dp[i + 2] + 1);
            }
            else
            {
                dp[i] = min(dp[i], dp[i + 1] + 1);
                if (v[i + 1] == 0) dp[i] = min(dp[i], dp[i + 2] + 1);
                else dp[i] = min(dp[i], dp[i + 2]);
            }
        }
        int ans = min(dp[1], dp[2] + (v[1] == 0));
        cout << ans << endl;
    }
    return 0;
}