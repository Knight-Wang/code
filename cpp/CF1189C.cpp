#include <bits/stdc++.h>
using namespace std;
int a[100005], sum[100005];
int main()
{
    int n, q, l, r;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) { cin >> a[i]; sum[i] = sum[i - 1] + a[i]; }
        cin >> q;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            cout << (sum[r] - sum[l - 1]) / 10 << endl;
        }
    }
    return 0;
}