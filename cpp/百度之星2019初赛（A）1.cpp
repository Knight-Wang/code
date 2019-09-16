#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n, a, b, p, q, x; cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x) { a = x; p = i; }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x) { b = x; q = i; }
        }
        if (p > q) cout << "1/0" << endl;
        else if (p < q) cout << "0/1" << endl;
        else
        {
            int g = __gcd(a, b);
            a /= g; b /= g;
            cout << a << "/" << b << endl;
        }
    }
    return 0;
}