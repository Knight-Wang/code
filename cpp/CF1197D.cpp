#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 300005;
ll a[N], dp[N][11];
int main()
{
    int n; ll m, k;
    while (cin >> n >> m >> k)
    {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll res = 0;
        dp[0][0] = -k;
        for (int i = 1; i < m; i++) dp[0][i] = -INF;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j == (m == 1 ? 0 : 1))
                {
                    dp[i][j] = max(dp[i - 1][0] + a[i] - k, a[i] - k);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][(j - 1 + m) % m] + a[i], a[i] - k);
                }
                res = max(res, dp[i][j]);
            }
        }
        cout << res << endl;
    }
    return 0;
}