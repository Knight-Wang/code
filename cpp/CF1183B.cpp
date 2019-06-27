#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int q, n, k;
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        if (a[1] + k < a[n] - k) { cout << -1 << endl; continue; }
        cout << a[1] + k << endl;
    }
    return 0;
}