#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, p, k;
        cin >> n >> p >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int res = 0, sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += i ? a[i - 1] : 0;
            if (sum > p) continue;
            int j = i + k - 1, tmp = i - 1, tot = sum;
            for ( ; j < n; j += k)
            {
                if (tot + a[j] > p) break;
                tot += a[j];
                tmp = j;
            }
            res = max(res, tmp + 1);
        }
        cout << res << endl;
    }
    return 0;
}