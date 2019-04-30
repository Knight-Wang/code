#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, r, x;
    while (cin >> n >> m >> r)
    {
        int minn = 1001, maxn = 0;
        for (int i = 0; i < n; i++) { cin >> x; minn = min(minn, x); }
        for (int i = 0; i < m; i++) { cin >> x; maxn = max(maxn, x); }
        if (maxn > minn)
        {
            int tmp = r / minn;
            cout << r - minn * tmp + tmp * maxn << endl;
        }
        else cout << r << endl;

    }
    return 0;
}