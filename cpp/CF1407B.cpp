#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int p = max_element(a, a + n) - a;
        int last = a[p];
        cout << a[p] << " ";
        a[p] = 0;
        for (int i = 1; i < n; i++)
        {
            int maxn = 0, p = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j] == 0) continue;
                int tmp = __gcd(last, a[j]);
                if (tmp > maxn || (tmp == maxn && a[j] >= a[p]))
                {
                    maxn = tmp; p = j;
                }
            }
            cout << a[p] << " ";
            last = maxn;
            a[p] = 0;
        }
        cout << endl;
    }
    return 0;
}
