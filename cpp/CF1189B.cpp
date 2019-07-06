#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        if (a[n - 2] <= a[n] - a[n - 1]) { cout << "NO" << endl; continue; }
        else
        {
            int p = upper_bound(a + 1, a + n + 1, a[n] - a[n - 1]) - a;
            for (int i = 1; i <= p / 2; i++) swap(a[i], a[p - i + 1]);
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}