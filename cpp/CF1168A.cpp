#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], n, m;
bool check(int x)
{
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] + x < cur) return false;
        else if (a[i] > cur)
        {
            if (a[i] + x < m || (a[i] + x) % m < cur)
                cur = a[i];
        }
    }
    return true;
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int l = 0, r = m, ans = m;
        while (l <= r)
        {
            int mi = l + r >> 1;
            if (check(mi))
            {
                ans = mi;
                r = mi - 1;
            }
            else l = mi + 1;
        }
        cout << ans << endl;
    }
    return 0;
}