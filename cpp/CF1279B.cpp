#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, f; cin >> n >> f;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (accumulate(a, a + n, 0ll) <= f) { cout << 0 << endl; continue; }
        int sum = 0, maxn = 0, id = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > maxn) { maxn = a[i]; id = i + 1; }
            if ((long long)sum + a[i] > f) break;
            sum += a[i];
        }
        cout << id << endl;
    }
    return 0;
}