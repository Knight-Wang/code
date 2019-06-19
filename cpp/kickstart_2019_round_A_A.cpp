#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
int a[N], sum[N];
int main()
{
    int T, n, p;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> p;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
        int ans = INF;
        for (int i = 1; i <= n - p + 1; i++)
        {
            int tmp = a[i + p - 1] * p - (sum[i + p - 1] - sum[i - 1]);
            ans = min(ans, tmp);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}