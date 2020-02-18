#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, d; cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int res = 0;
        for (int i = 2; i <= n; i++)
        {
            int t = min(a[i], d / (i - 1));
            res += t;
            d -= t * (i - 1);
        }
        cout << a[1] + res << endl;
    }
    return 0;
}