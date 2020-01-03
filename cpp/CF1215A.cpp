#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, k1, k2, n;
    while (cin >> a1 >> a2 >> k1 >> k2 >> n)
    {
        int tmp = (k1 - 1) * a1 + (k2 - 1) * a2;
        int minn = n <= tmp ? 0 : n - tmp;
        if (k1 > k2) { swap(k1, k2); swap(a1, a2); }
        tmp = min(a1, n / k1);
        n -= tmp * k1;
        int maxn = tmp + min(n / k2, a2);
        cout << minn << " " << maxn << endl;
    }
    return 0;
}