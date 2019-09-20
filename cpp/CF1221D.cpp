#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll a[N], b[N];
ll dp[N][11];
int main()
{
    ios::sync_with_stdio(false);
    int q, n; cin >> q;
    while (q--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        for (int i = 0; i <= 10; i++) dp[1][i] = i * b[1];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                dp[i][j] = INF;
                for (int k = 0; k <= 10; k++)
                {
                    if (a[i - 1] + k == a[i] + j) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * b[i]);
                }
            }
        }
        ll res = *min_element(dp[n], dp[n] + 11);
        cout << res << endl;
    }
    return 0;
}