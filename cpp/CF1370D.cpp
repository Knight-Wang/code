#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool check(int x, int n, int k)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
        {
            if (i == n - 1) c++;
            else { c += 2; i++; }
            if (c >= k) return true;
        }
    }
    c = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= x)
        {
            if (i == n - 1) c++;
            else { c += 2; i++; }
            if (c >= k) return true;
        }
    }
    return false;
}
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        int l = 1, r = 1e9, res = 1e9;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(m, n, k))
            {
                res = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << res << endl;
    }
    return 0;
}