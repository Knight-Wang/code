#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q, n, x;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int c0 = 0, c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (x % 3 == 0) c0++;
            else if (x % 3 == 1) c1++;
            else c2++;
        }
        if (c1 > c2) cout << c0 + c2 + (c1 - c2) / 3 << endl;
        else cout << c0 + c1 + (c2 - c1) / 3 << endl;
    }
    return 0;
}