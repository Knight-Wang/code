#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;

int dp[10005];

int main()
{
    int n, k; string s;
    while (cin >> n >> k >> s)
    {
        k++;
        fill(dp, dp + k + 1, -INF);
        vector<pii> v;
        int begin = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && s[j] == '1') j++;
            if (j - i)
            {
                if (i == 0) { v.push_back(pii(1, j - i)); begin = j - i; }
                else if (j == n) v.push_back(pii(1, j - i));
                else v.push_back(pii(2, j - i));
                i = j;
            }
        }
        if (k == 1) { cout << begin << endl; continue; }
        dp[0] = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = k; j >= 0; j--)
                if (j >= v[i].first)
                    dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
        }
        int ans = 0;
        for (int i = 0; i <= k; i++) ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    return 0;
}
