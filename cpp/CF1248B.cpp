#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        long long sum = accumulate(a, a + n, 0);
        long long x = 0;
        for (int i = n - 1; i >= n / 2; i--)
        {
            x += a[i];
        }
        cout << x * x + (sum - x) * (sum - x) << endl;
    }
    return 0;
}