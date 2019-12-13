#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N], l[N], r[N];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        int res = 1;
        l[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1;
            else l[i] = 1;
            res = max(res, l[i]);
        }
        r[n] = 1;
        for (int i = n - 1; i >= 1; i--)
        {
            if (a[i] < a[i + 1]) r[i] = r[i + 1] + 1;
            else r[i] = 1;
            res = max(res, r[i]);
        }
        for (int i = 2; i < n; i++)
        {
            if (a[i - 1] < a[i + 1]) res = max(res, l[i - 1] + r[i + 1]);
        }
        cout << res << endl;
    }
    return 0;
}