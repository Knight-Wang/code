#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][105], sum[105];
int last[30];
int main()
{
    int n; ll m; string s;
    while (cin >> n >> m >> s)
    {
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        memset(last, -1, sizeof last);
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = 1;
            for (int j = 2; j <= i; j++)
            {
                for (int k = 0; k < 26; k++)
                {
                    if (last[k] != -1)
                    {
                        int p = last[k];
                        dp[i][j] += dp[p][j - 1];
                    }
                }
            }
            last[s[i - 1] - 'a'] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (last[j] != -1) sum[i] += dp[last[j]][i];
            }
        }
        sum[0] = 1;
        ll ans = 0;
        bool flg = false;
        for (int i = n; i >= 0; i--)
        {
            if (m - sum[i] <= 0) { ans += m * ((ll)n - i); flg = true; break; }
            ans += sum[i] * ((ll)n - i); m -= sum[i];
        }
        cout << (flg ? ans : -1) << endl;
    }
    return 0;
}