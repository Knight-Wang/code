#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005];
int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        if (n < (ll)k * (k + 1) / 2) { cout << "NO" << endl; continue; }
        if (k == 1) { cout << "YES\n" << n << endl; continue; }
        if (k == 2 && n == 4) { cout << "NO" << endl; continue; }
        for (int i = 1; i <= k; i++) a[i] = i;
        ll r = n - k * (k + 1) / 2;
        int d = r / k, t = r % k;
        for (int i = 1; i <= k; i++) a[i] += d;
        while (t && a[k] < a[k - 1] * 2) { a[k]++; t--; }
        int i = k - 1;
        for ( ; i > k - 1 - t; i--) a[i]++;
        if (a[i + 1] > a[i] * 2) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            for (int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}