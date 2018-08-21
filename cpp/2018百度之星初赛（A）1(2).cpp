#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int ans = -1;
        for (int i = n - 1; i >= 2; i--)
        {
            if (a[i - 2] + a[i - 1] > a[i])
            {
                ans = a[i - 2] + a[i - 1] + a[i];
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}