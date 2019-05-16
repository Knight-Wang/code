#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[300005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int minn = INF, ans = INF;
        int cnt = n - 1;
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            minn = min(minn, a[i]);
            minn = min(minn, a[n - i + 1]);
            ans = min(ans, minn / cnt);
            cnt--;
        }
        cout << ans << endl;
    }
    return 0;
}