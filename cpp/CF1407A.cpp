#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int c1 = 0, x;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; c1 += x;
        }
        if (c1 <= n / 2)
        {
            cout << n - c1 << endl;
            for (int i = 1; i <= n - c1; i++) cout << "0 ";
            cout << endl;
        }
        else
        {
            c1 -= c1 & 1;
            cout << c1 << endl;
            for (int i = 1; i <= c1; i++) cout << "1 ";
            cout << endl;
        }
    }
    return 0;
}
