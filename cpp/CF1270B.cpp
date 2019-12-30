#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int res = -1;
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(a[i + 1] - a[i]) > 1) { res = i; break; }
        }
        if (res == -1) cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << res + 1 << " " << res + 2 << endl;
        }
    }
    return 0;
}