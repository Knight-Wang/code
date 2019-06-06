#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int p = 1, minn = a[1 + k] - a[1];
        for (int i = 2; i <= n - k; i++)
        {
            if (a[i + k] - a[i] < minn)
            {
                minn = a[i + k] - a[i];
                p = i;
            }
        }
        cout << (a[p] + a[p + k]) / 2 << endl;
    }
    return 0;
}