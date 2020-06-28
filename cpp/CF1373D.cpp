#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
ll a[N], dp[N];
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        ll tot = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i & 1) tot += a[i];
        }
        for (int i = 0; i <= n; i++) dp[i] = 0;
        ll res = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1) dp[i] = max(max(dp[i - 2] - a[i] + a[i - 1], -a[i] + a[i - 1]), 0ll);   
            else dp[i] = max(max(dp[i - 2] + a[i] - a[i - 1], a[i] - a[i - 1]), 0ll);
            res = max(res, dp[i]);
        }
        cout << tot + res << endl;
    }
    return 0;
}