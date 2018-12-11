#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n;
    while (cin >> n)
    {
        int maxn = -1;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int pos = lower_bound(a + j + 1, a + n, a[i] + a[j]) - a;
                if (pos - 1 > j)
                {
                    maxn = max(maxn, a[i] + a[j] + a[pos - 1]);
                }
            }
        }
        cout << maxn << endl;
    }
    return 0;
}