#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int cur = a[n];
        long long ans = a[n];
        for (int i = n - 1; i >= 1; i--)
        {
            cur = max(0, min(cur - 1, a[i]));
            ans += cur;
        }
        cout << ans << endl;
    }
    return 0;
}