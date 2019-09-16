#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[1005];
int dp[1005][4005];
int main()
{
    ios::sync_with_stdio(false);
    int T, n; cin >> T;
    while (T--)
    {
        cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first >> a[i].second;
            v.push_back(a[i].first);
            v.push_back(a[i].second);
            if (a[i].first < a[i].second - 1)
            {
                v.push_back(a[i].first + 1);
                v.push_back(a[i].second - 1);
            }
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int m = v.size();
        for (int i = 1; i <= n; i++)
        {
            a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
            a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
        }
        for (int i = 0; i < m; i++) dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = a[i].first, r = a[i].second;
            for (int j = l; j <= r; j++) dp[i][j] = dp[i - 1][j];
            for (int j = 0; j < l; j++)
            {
                dp[i][j] = dp[i][l] + (abs(v[j] - v[l]) + 1 >> 1);
                if (l < r) dp[i][j] = min(dp[i][j], dp[i][l + 1] + (abs(v[j] - v[l + 1]) + 1 >> 1));
            }
            for (int j = r + 1; j < m; j++)
            {
                dp[i][j] = dp[i][r] + (abs(v[j] - v[r] + 1) >> 1);
                if (l < r) dp[i][j] = min(dp[i][j], dp[i][r - 1] + (abs(v[j] - v[r - 1]) + 1 >> 1));
            }
        }
        cout << *min_element(dp[n], dp[n] + m) << endl;
    }
    return 0;
}