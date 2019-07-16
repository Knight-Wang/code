#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50005;
ll sum[N];
int main()
{
    int n, x;
    while (cin >> n)
    {
        ll maxn = 0, minn = 0, ans = 0, mins = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; sum[i] = sum[i - 1] + x;
            ans = max(ans, sum[i] - minn);
            mins = min(mins, sum[i] - maxn);
            maxn = max(maxn, sum[i]); minn = min(minn, sum[i]);
        }
        ans = max(ans, sum[n] - mins);
        cout << ans << endl;
    }
    return 0;
}