#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3005;
ll a[N], dp[N][N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) { cin >> a[i]; a[i] -= i; }
        vector<ll> v(a + 1, a + n + 1);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int m = v.size();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = dp[i - 1][j] + abs(a[i] - v[j]);
                if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][m - 1] << endl;
    }
    return 0;
}